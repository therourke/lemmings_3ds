#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <3ds.h>
#include <sf2d.h>

#include "decode.h"
#include "import.h"
#include "import_level.h"
#include "import_main.h"
#include "draw.h"
#include "control.h"
#include "settings.h"
#include "gamespecific.h"
#include "savegame.h"
#include "ingame.h"
#include "audio.h"
#include "menu.h"

const char* PATH_ROOT = LEMMINGS_DIR;


// TODO:
// make xmas91 and xmas92 distinguishable in main menu (maybe add info to top screen)

/*
	original order of actions (not taken care of yet):

	process_skill_assignment
	add_new_lemming
	update_lemmings
*/

void die(int sf2d_initialied) {
	if (sf2d_initialied) {
		// clear screen
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_end_frame();
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_end_frame();
		sf2d_swapbuffers();
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_end_frame();
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_end_frame();
		sf2d_swapbuffers();
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_end_frame();
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_end_frame();
		sf2d_swapbuffers();
		if (!aptMainLoop()) {
			deinit_audio();
			sf2d_fini();
			exit(1);
		}
		deinit_audio();
		sf2d_fini();
		// init console to display message
		gfxInitDefault();
	}
	consoleInit(GFX_TOP, NULL);
	consoleClear();
	printf(CONSOLE_RED);
	printf("\n                An error occured.\n\n");
	printf(CONSOLE_RESET);
	printf("Maybe some file of the original Lemmings game you\n");
	printf("tried to load is missing.\n");
	printf("Please make sure that ");
	printf(CONSOLE_RED);
	printf("all");
	printf(CONSOLE_RESET);
	printf(" files are in the\n");
	printf("correct directory and that no file is corrupted.\n\n\n");
	printf("Directories for DOS Lemmings games:\n\n");
	printf("Original Lemmings           /lemmings/orig\n");
	printf("Original Lemmings Demo      /lemmings/orig_demo\n");
	printf("Oh No! More Lemmings        /lemmings/ohno\n");
	printf("Oh No! More Lemmings Demo   /lemmings/ohno_demo\n");
	printf("Xmas Lemmings 1991          /lemmings/xmas91\n");
	printf("Xmas Lemmings 1992          /lemmings/xmas91\n");
	printf("Holiday Lemmings 1993       /lemmings/holi93\n");
	printf("Holiday Lemmings 1993 Demo  /lemmings/holi93_demo\n");
	printf("Holiday Lemmings 1994       /lemmings/holi94\n");
	printf("Holiday Lemmings 1994 Demo  /lemmings/holi94_demo\n\n\n");
	printf(CONSOLE_RED);
	printf("Besides that, this error may occur when the game\n");
	printf("runs out of memory.\n\n");
	printf(CONSOLE_RESET);
	printf("Press any button to exit.");
	while (aptMainLoop()) {

		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & (~KEY_TOUCH)) {
			break;
		}
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	// exit game
	gfxExit();
	exit(1);
}

int main() {
	// INITIALIZATION

	int i;

	gfxInitDefault();
	//sf2d_init();
	consoleInit(GFX_TOP, NULL);
	consoleClear();
	printf("\n");
	printf("        ------ 3DS Lemmings Loading ------  \n");
	printf("        ---------- Please Wait -----------  \n");
	gfxFlushBuffers();
	gfxSwapBuffers();

	u8 games[LEMMING_GAMES];
	memset(games,0,LEMMING_GAMES);
	u8 game = 0;

	// count number of levels
	u16 overall_num_of_levels = 0;
	u16 overall_num_of_difficulties = 0;
	for (i=0;i<LEMMING_GAMES;i++) {
		overall_num_of_levels +=
				(u16)import[i].num_of_difficulties *
				(u16)import[i].num_of_level_per_difficulty;
		overall_num_of_difficulties += import[i].num_of_difficulties;
	}


	// test whether PATH_ROOT is a directory, otherwise set it to "."
	struct stat s;
	int err = stat(PATH_ROOT, &s);
	if(err == -1) {
		PATH_ROOT = ".";
	}else{
		if(!S_ISDIR(s.st_mode)) {
			PATH_ROOT = ".";
		}
	}

	// read level names
	char* level_names = (char*)malloc(33*overall_num_of_levels);
	if (!level_names) {
		die(0);
		return 0; // error
	}
	u16 offset = 0;
	for (i=0;i<LEMMING_GAMES;i++) {
		games[i] = read_level_names(i, level_names + offset);
		offset += 33*
				(u16)import[i].num_of_difficulties *
				(u16)import[i].num_of_level_per_difficulty;
	}

	// find first game the LEVEL files of which have been scanned successfully
	// and start with this game
	while (!games[game] && game < LEMMING_GAMES) {
		game++;
	}
	if (game == LEMMING_GAMES) {
		// no game data has been found
		// TODO: display error message
		printf(CONSOLE_RED);
		printf("\nTo run this game, you need to copy the files of\n");
		printf("at least one DOS Lemmings game to your SD card.\n");
		printf("Please make sure to copy the data into the\n");
		printf("correct directory corresponding to the game.\n\n\n");
		printf(CONSOLE_RESET);
		printf("Directories for DOS Lemmings games:\n\n");
		printf("Original Lemmings           /lemmings/orig\n");
		printf("Original Lemmings Demo      /lemmings/orig_demo\n");
		printf("Oh No! More Lemmings        /lemmings/ohno\n");
		printf("Oh No! More Lemmings Demo   /lemmings/ohno_demo\n");
		printf("Xmas Lemmings 1991          /lemmings/xmas91\n");
		printf("Xmas Lemmings 1992          /lemmings/xmas91\n");
		printf("Holiday Lemmings 1993       /lemmings/holi93\n");
		printf("Holiday Lemmings 1993 Demo  /lemmings/holi93_demo\n");
		printf("Holiday Lemmings 1994       /lemmings/holi94\n");
		printf("Holiday Lemmings 1994 Demo  /lemmings/holi94_demo\n\n\n");
		printf("You may check out the \"demos\" folder at\n");
		printf(CONSOLE_GREEN);
		printf("http://github.com/esoteric-programmer/lemmings_3ds");
		printf(CONSOLE_RESET);
		printf("to download free demo versions of Lemmings.\n\n");
		printf("Press any button to exit.");

		while (aptMainLoop()) {
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & (~KEY_TOUCH)) {
				break;
			}
			gfxFlushBuffers();
			gfxSwapBuffers();
		}
		gfxExit();
		return 0; // error
	}

	// TODO: read configuration file
	// LEFTHANDED.DAT hack; TODO: remove once configuration file is implemented
	char lh_fn[64];
	sprintf(lh_fn,"%s/LEFTHANDED.DAT", PATH_ROOT);
	FILE* lefthand = fopen(lh_fn,"r");
	if (lefthand) {
		controls[0].forbidden_keys = KEY_L;
		controls[10].held_keys = KEY_R;
		controls[11].held_keys = KEY_L;
		controls[12].held_keys = KEY_CPAD_DOWN | KEY_L;
		controls[13].held_keys = KEY_CPAD_UP | KEY_L;
		fclose(lefthand);
	}

	// read save file
	u8* progress = (u8*)malloc(overall_num_of_difficulties);
	if (!progress) {
		die(0); // error
	}
	read_savegame(progress);

	// initialize variables
	struct MainMenuData* menu_data = (struct MainMenuData*)malloc(sizeof(struct MainMenuData));
	if (!menu_data) {
		die(0); // error
	}
	memset(menu_data,0,sizeof(struct MainMenuData));

	struct RGB_Image* logo_scaled = (struct RGB_Image*)malloc(sizeof(struct RGB_Image)+sizeof(u32)*380*57);
	if (!logo_scaled) {
		die(0); // error
	}
	logo_scaled->width = 380;
	logo_scaled->height = 57;

	struct RGB_Image* im_top = (struct RGB_Image*)malloc(sizeof(struct RGB_Image)+sizeof(u32)*400*320);
	if (!im_top) {
		die(0); // error
	}
	im_top->width = 400;
	im_top->height = 320;

	struct MainInGameData* main_data = (struct MainInGameData*)malloc(sizeof(struct MainInGameData));
	if (!main_data) {
		die(0); // error
	}
	memset(main_data,0,sizeof(struct MainInGameData));

	// initialize sf2d, create textures
	gfxExit();
	sf2d_init();
	sf2d_texture* texture_logo = 0;
	sf2d_texture* texture_top_screen = 0;

	init_audio();
	if (!read_gamespecific_data(game, menu_data, main_data)) {
		// error!
		die(1); // error
	}
	if (!draw_topscreen(menu_data, im_top, &texture_top_screen, logo_scaled, &texture_logo)) {
		// error!
		die(1); // error
	}

	// begin with first level
	int lvl = 0;


	// GAME LOOP
	while(1) {
		int menu_selection = main_menu(games, &game, &lvl, menu_data, main_data, im_top, logo_scaled, &texture_logo, &texture_top_screen);


		if (menu_selection == MENU_ACTION_SELECT_LEVEL_SINGLE_PLAYER) {
			int level_selection = level_select_menu(games, &game, &lvl,
					progress, level_names,
					menu_data, main_data,
					im_top, logo_scaled,
					&texture_logo, &texture_top_screen);
			switch (level_selection) {
				case MENU_EXIT_GAME:
					menu_selection = MENU_EXIT_GAME;
					break;
				case MENU_ACTION_EXIT:
					break;
				case MENU_ACTION_LEVEL_SELECTED:
					menu_selection = MENU_ACTION_START_SINGLE_PLAYER;
					break;
				case MENU_ERROR:
				default:
					die(1); // error
			}
		}

		if (menu_selection == MENU_ERROR) {
			die(1); // error
		}

		if (menu_selection == MENU_ACTION_START_SINGLE_PLAYER) {
			while(1) {
				struct LevelResult lev_result = run_level(game, lvl, main_data,
						texture_top_screen, texture_logo);
				if (lev_result.exit_reason == LEVEL_ERROR) {
					// an error occured
					// error code may be coded in lev_result.lvl
					die(1);
					break;
				}
				if (lev_result.exit_reason == LEVEL_EXIT_GAME) {
					menu_selection = MENU_EXIT_GAME;
					break;
				}

				// process result
				// find out whether level has been solved successful
				if (lev_result.percentage_rescued >= lev_result.percentage_needed) {
					// increment lvl counter to read next level
					u8 progress_offset = 0;
					u8 i;
					for (i=0;i<game;i++) {
						progress_offset += import[i].num_of_difficulties;
					}
					progress_offset += lvl/import[game].num_of_level_per_difficulty;

					if (progress[progress_offset] < lvl%import[game].num_of_level_per_difficulty+1) {
						progress[progress_offset] = lvl%import[game].num_of_level_per_difficulty+1;
						write_savegame(progress);
					}
					lvl = (lvl+1)%(import[game].num_of_difficulties*import[game].num_of_level_per_difficulty);
					if (lvl == 0) {
						// TODO: show congratulation message
						// TODO: increase game variable?
					}
				}

				int result_screen = show_result(game,
						lev_result,
						menu_data, &texture_logo, &texture_top_screen);
				if (result_screen == RESULT_ACTION_NEXT) {
					continue;
				}
				if (result_screen == RESULT_ACTION_CANCEL) {
					break;
				}
				if (result_screen == MENU_EXIT_GAME) {
					menu_selection = MENU_EXIT_GAME;
					break;
				}
				die(1); // error
			}
		}

		if (menu_selection == MENU_ACTION_EXIT || menu_selection == MENU_EXIT_GAME) {
			break;
		}
	}

	deinit_audio();
	sf2d_fini();
	return 0;
}

