#include "yk_4.h"
#include "split_util.h"  // for isLeftHand

/*
Logical Layout
Left:
R\C 0  1  2  3  4  5
0  05 ----------- 00
1  06 ----------- 11
2  17 ----------- 12
3           18 19 20
*/

#ifdef RGB_MATRIX_ENABLE

#define NOD NO_LED

#define KEY_2_LED_LEFT \
	{  5,  4,  3,  2,NOD,  1,  0 }, \
	{  6,  7,  8,NOD,  9, 10, 11 }, \
	{ 17, 16, 15,NOD, 14, 13, 12 }, \
	{NOD,NOD,NOD,NOD, 18, 19, 20 }

#define KEY_2_LED_RIGHT \
	{ 26, 25, 24, 23,NOD, 22, 21 }, \
	{ 27, 28, 29,NOD, 30, 31, 32 }, \
	{ 38, 37, 36,NOD, 35, 34, 33 }, \
	{ 39, 40, 41,NOD,NOD,NOD,NOD }

#define POS_LED \
{0,0}, \
{20,0}, \
{41,0}, \
{61,0}, \
{81,0}, \
{102,0}, \
{122,0}, \
{143,0}, \
{163,0}, \
{183,0}, \
{204,0}, \
{224,0}, \
{0,21}, \
{20,21}, \
{41,21}, \
{61,21}, \
{81,21}, \
{102,21}, \
{122,21}, \
{143,21}, \
{163,21}, \
{183,21}, \
{204,21}, \
{224,21}, \
{0,43}, \
{20,43}, \
{41,43}, \
{61,43}, \
{81,43}, \
{102,43}, \
{122,43}, \
{143,43}, \
{163,43}, \
{183,43}, \
{204,43}, \
{224,43}, \
{61,64}, \
{81,64}, \
{102,64}, \
{122,64}, \
{143,64}, \
{163,64}, \



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
