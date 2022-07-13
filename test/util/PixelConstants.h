#ifndef _PIXEL_CONSTANTS_H_
#define _PIXEL_CONSTANTS_H_

#include <array>

#include "Apa102.h"

// Colours
const Pixel Red = { 31, 0xFF, 0x0, 0x0 };
const Pixel Orange = { 31, 0xFF, 0x7F, 0x0 };
const Pixel Yellow = { 31, 0xFF, 0xFF, 0x0 };
const Pixel Green = { 31, 0x0, 0xFF, 0x0 };
const Pixel Blue= { 31, 0x0, 0x0, 0xFF };
const Pixel Indigo= { 31, 0x4B, 0x0, 0x82 };
const Pixel Violet = { 31, 0x94, 0x0, 0xD3 };
const Pixel Black = { 31, 0x0, 0x0, 0x0 };
const Pixel White = { 31, 0xFF, 0xFF, 0xFF };

// Bitmaps
const std::array<Pixel, 8> roygbiv = { Red, Orange, Yellow, Green, Blue, Indigo, Violet, White };

const Pixel Rainbow14x10[] = {
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet,
	Red, Red, Orange, Orange, Yellow, Yellow, Green, Green, Blue, Blue, Indigo, Indigo, Violet, Violet
};

const Pixel Rainbow7x10[] = {
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet,
	Red, Orange, Yellow, Green, Blue, Indigo, Violet
};

const Pixel Smiley6x5[] = {
	Black, Yellow, Yellow, Yellow, Yellow, Black,
	Yellow, Yellow, Violet, Yellow, Violet, Yellow,
	Yellow, Yellow, Violet, Yellow, Yellow, Yellow,
	Yellow, Yellow, Violet, Yellow, Violet, Yellow,
	Black, Yellow, Yellow, Yellow, Yellow, Black,
};

const Pixel Heart7x5[] = {
	Black,	Red,	Red,	Black,	Red,	Red,	Black,
	Red,	Red,	Red,	Red,	Red,	Red,	Red,
	Black,	Red,	Red,	Red,	Red,	Red,	Black,
	Black,	Black,	Red,	Red,	Red,	Black,	Black,
	Black,	Black,	Black,	Red,	Black,	Black,	Black
};

const Pixel SimpleMap4x4[] = {
	Red, Red, Indigo, Indigo,
	Red, Red, Indigo, Indigo,
	Red, Red, Indigo, Indigo,
	Red, Red, Indigo, Indigo
};

#endif