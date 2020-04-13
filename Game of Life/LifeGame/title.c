#include "lifegame.h"

/*  Defines  */


static const u8 GliderGun_Map[]=//列行式，低位在前
{
0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x88,0x04,0x04,0x20,0x88,0x70,0x20,0x00,0x00,0x1C,0x1C,0x22,0x00,
0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
const u8 BlibliTv_Map[512] = { 
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X38,0X38,0X70,0X70,0XE0,0XE0,0XC0,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X80,0XC0,0XF0,0X78,0X3E,0X1F,0X07,0X03,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0XF8,0XF8,0X18,0X18,0X18,0X98,0X98,
0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X99,0X9B,0X9B,0X9F,0X9F,0X9E,0X9E,0X9C,0X9C,
0X98,0X98,0X98,0X9C,0X9E,0X9F,0X9B,0X99,0X98,0X98,0X98,0X98,0X98,0X98,0X98,0X98,
0X98,0X98,0X18,0X18,0X18,0XF8,0XF8,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0X03,
0X03,0X03,0X03,0X03,0X03,0X03,0X83,0X83,0XC3,0XC3,0X83,0X03,0X03,0X03,0X03,0X03,
0X03,0X03,0X03,0X03,0X03,0XC3,0XC3,0XC3,0X83,0X83,0X03,0X03,0X03,0X03,0X03,0X03,
0X03,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0X00,
0X00,0X00,0X06,0X06,0X07,0X07,0X03,0X03,0X01,0XE1,0XE0,0X00,0X00,0X00,0X00,0XC0,
0XE0,0XC0,0X00,0X00,0X00,0X80,0XE1,0XE1,0X03,0X03,0X07,0X0E,0X0E,0X0C,0X00,0X00,
0X00,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0X80,
0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X83,0X87,0X87,0X8E,0X8E,0X87,0X87,
0X83,0X87,0X86,0X8E,0X86,0X87,0X83,0X81,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
0X80,0XFF,0XFF,0X00,0X00,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0X3F,0X3F,0X38,0X38,0X39,0X39,0XF9,
0XF9,0XB9,0XB9,0XF9,0XF9,0XF9,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,
0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0X39,0XF9,0XF9,0XF9,0XB9,0XB9,
0XF9,0XF9,0X39,0X38,0X38,0X3F,0X3F,0X1F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X01,0X01,0X01,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,0X01,0X01,
0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
static uint8_t  state;
static bool   toDraw;
static void draw_blinker(int16_t x0, int16_t y0);
static void draw_beehive(int16_t x0, int16_t y0);
static void draw_block(int16_t x0, int16_t y0);
static void draw_boat(int16_t x0, int16_t y0);
static void draw_toad(int16_t x0, int16_t y0);
static void draw_glider(int16_t x0, int16_t y0);
static void draw_spaceship(int16_t x0, int16_t y0);
static void draw_GliderGun(int16_t x0, int16_t y0);
static void draw_TV(int16_t x0, int16_t y0);
/*---------------------------------------------------------------------------*/
/*                              Main Functions                               */
/*---------------------------------------------------------------------------*/

void initTitle(void)
{
 
   // state = 0;
	toDraw = true;
}

bool updateTitle(void)
{
    bool ret = false;

	if (ButtonDown(UP_BUTTON))
	{
		
		if(state==0)
		state=5;
		else
		state--;
		
		toDraw = true;
	}
	if (ButtonDown(DOWN_BUTTON))
	{
	
		if(state>=5)
		state=0;
		else
		state++;	
		toDraw = true;
	}
	if (ButtonDown(A_BUTTON))
	{
	ret = true;
	}
	if(ButtonDown(B_BUTTON))
	{
	
	}

    return ret;
}

void drawTitle(void)
{
    if (toDraw) {
        OLED_ClearDisplay();
        switch (state) {
        case 0:
            draw_blinker(62,30);
						draw_blinker(32,30);
						draw_blinker(92,30);
						draw_toad(62,15);
						draw_toad(32,15);
						draw_toad(92,15);
            break;
        case 1:
						draw_beehive(62,45);
						draw_beehive(32,45);
						draw_beehive(92,45);
						draw_block(62,30);
						draw_block(32,30);
						draw_block(92,30);
						draw_boat(62,15);
						draw_boat(32,15);
						draw_boat(92,15);
            break;
        case 2:  
		  draw_glider(32,30);
		  draw_glider(92,30);
			draw_glider(62,30);
            break;
		case 3:
					draw_spaceship(32,30);
          draw_spaceship(62,30);
					draw_spaceship(92,30);
            break;
		case 4:
          draw_GliderGun(30,30);
            break;
		case 5:
          draw_TV(31,0);
            break;
		default:
			break;
        }
        toDraw = false;
    }
}

/*---------------------------------------------------------------------------*/
/*                              Draw Functions                               */
/*---------------------------------------------------------------------------*/


static void draw_blinker(int16_t x0, int16_t y0)//闪光灯 3x1
{	
OLED_DrawLine(x0,y0,x0+2,y0,1);
}
static void draw_beehive(int16_t x0, int16_t y0)//蜂窝 3x4
{	
OLED_DrawPixel(x0,y0+1,1);	
OLED_DrawPixel(x0,y0+2,1);
OLED_DrawPixel(x0+1,y0,1);
OLED_DrawPixel(x0+1,y0+3,1);
OLED_DrawPixel(x0+2,y0+1,1);	
OLED_DrawPixel(x0+2,y0+2,1);
}
static void draw_block(int16_t x0, int16_t y0)//小区 2x2
{	
FillRect2(x0,y0,2,2,1);	
}
static void draw_boat(int16_t x0, int16_t y0)//小船 3x3
{	
OLED_DrawPixel(x0,y0,1);	
OLED_DrawPixel(x0,y0+1,1);
OLED_DrawPixel(x0+1,y0,1);	
OLED_DrawPixel(x0+2,y0+1,1);
OLED_DrawPixel(x0+1,y0+2,1);	
}
static void draw_toad(int16_t x0, int16_t y0)//蛤蟆 4x2
{
OLED_DrawLine(x0+1,y0,x0+3,y0,1);
OLED_DrawLine(x0,y0+1,x0+2,y0+1,1);
}
static void draw_glider(int16_t x0, int16_t y0)//滑翔机 3x3
{
OLED_DrawLine(x0,y0,x0+2,y0,1);
OLED_DrawPixel(x0,y0+1,1);
OLED_DrawPixel(x0+1,y0+2,1);
}
static void draw_spaceship(int16_t x0, int16_t y0)//太空船 5x4
{
OLED_DrawLine(x0,y0+3,x0+3,y0+3,1);
	
OLED_DrawPixel(x0,y0+1,1);
OLED_DrawPixel(x0,y0+2,1);	
	
OLED_DrawPixel(x0+1,y0,1);
OLED_DrawPixel(x0+4,y0,1);
	
OLED_DrawPixel(x0+4,y0+2,1);
}
static void draw_GliderGun(int16_t x0, int16_t y0)//滑翔机枪 36x9
{
OLED_DrawBitmap(x0,y0,GliderGun_Map,36,9,1);
}
static void draw_TV(int16_t x0, int16_t y0)//小电视 64x64
{
OLED_DrawBitmap(x0,y0,BlibliTv_Map,64,64,1);
}
