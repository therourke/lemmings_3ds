#include "highperf_font.h"

const u8 highperf_font_dot[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_comma[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_questionmark[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xF4, 0xF9, 0xF9, 0xF3, 0xF3, 0x00, 0x00,
	0x00, 0xF4, 0xF4, 0xF4, 0xF4, 0xF9, 0xF3, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00,
	0x00, 0x00, 0xF4, 0xF9, 0xF9, 0xF9, 0x00, 0x00,
	0x00, 0xF4, 0xF9, 0xF4, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xF4, 0xF9, 0xF3, 0xF9, 0xF9, 0xF3, 0x00,
	0x00, 0x00, 0xF4, 0xF4, 0xF4, 0xF4, 0xF4, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_exclamationmark[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF3, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_colon[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_bracket_l[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF4, 0xF9, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF3, 0xF9, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xF9, 0xF9, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF4, 0xF4, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_bracket_r[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF4, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF3, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF9, 0xF9, 0xF4, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF4, 0xF4, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_apostrophe[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF9, 0xF3, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF4, 0xF9, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const u8 highperf_font_quote[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xF9, 0xF3, 0x00, 0xF9, 0xF3, 0x00,
	0x00, 0x00, 0xF4, 0xF9, 0x00, 0xF4, 0xF9, 0x00,
	0x00, 0xF4, 0xF9, 0x00, 0xF4, 0xF9, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};