#include "yk_4.h"
#include "split_util.h"  // for isLeftHand

/*
Logical Layout
Left:
R\C 0  1  2  3  4  5
0  00 ----------- 05
1  11 ----------- 06
2  12 ----------- 17
3           20 19 18
*/

#ifdef RGB_MATRIX_ENABLE

#define NOD NO_LED

#define KEY_2_LED_LEFT \
	{  0,  1,  2,  3,NOD,  4,  5 }, \
	{ 11, 10,  9,NOD,  8,  7,  6 }, \
	{ 12, 13, 14,NOD, 15, 16, 17 }, \
	{NOD,NOD,NOD,NOD, 20, 19, 18 }

#define KEY_2_LED_RIGHT \
	{ 21, 22, 23, 24,NOD, 25, 26 }, \
	{ 32, 31, 30,NOD, 29, 28, 27 }, \
	{ 33, 34, 35,NOD, 36, 37, 38 }, \
	{ 41, 40, 39,NOD,NOD,NOD,NOD }

#define POS_LED \
{0,0}, \
{20,0}, \
{41,0}, \
{61,0}, \
{81,0}, \
{102,0}, \
{102,21}, \
{81,21}, \
{61,21}, \
{41,21}, \
{20,21}, \
{0,21}, \
{0,43}, \
{20,43}, \
{41,43}, \
{61,43}, \
{81,43}, \
{102,43}, \
{102,64}, \
{81,64}, \
{61,64}, \
{122,0}, \
{143,0}, \
{163,0}, \
{183,0}, \
{204,0}, \
{224,0}, \
{224,21}, \
{204,21}, \
{183,21}, \
{163,21}, \
{143,21}, \
{122,21}, \
{122,43}, \
{143,43}, \
{163,43}, \
{183,43}, \
{204,43}, \
{224,43}, \
{163,64}, \
{143,64}, \
{122,64}

#define LED_FLAG \
	4, 4, 4, 4, 4, 4, \
	4, 4, 4, 4, 4, 4, \
	4, 4, 4, 4, 4, 4, \
	         4, 4, 4


led_config_t g_led_config = { {
	KEY_2_LED_LEFT,
	KEY_2_LED_RIGHT
}, {
	POS_LED
}, {
	LED_FLAG, LED_FLAG
}};

#undef NOD
#undef KEY_2_LED_LEFT
#undef KEY_2_LED_RIGHT
#undef POS_LED_LEFT
#undef POS_LED_RIGHT
#undef LED_FLAG

#endif
