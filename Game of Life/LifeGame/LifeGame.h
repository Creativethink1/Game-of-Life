#ifndef LIFEGAME_H
#define LIFEGAME_H

#include "main.h"
#include "key_bsp.h"
#include "oled_bsp.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
/*  Defines  */

//#define PI    3.141592653589793
#define LIFEGAME_WIDTH  128
#define LIFEGAME_HEIGHT 64
#define ALIVE  1
#define DEAD  0

/*  title  */
void initTitle(void);
bool updateTitle(void);
void drawTitle(void);
/*  game  */
void initGame(void);
bool updateGame(void);
void drawGame(void);

void SetFrameRate(uint8_t rate);
bool NextFrame(void);
/*  Global Variables  */
void LifeGame(void);


/*  For Debugging  */

#endif
