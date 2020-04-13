#include "lifegame.h"


u8 Display_Temp[LIFEGAME_WIDTH][LIFEGAME_HEIGHT];

  uint8_t frameRate;
  uint16_t frameCount;
  uint8_t eachFrameMillis;
  long lastFrameStart;
  long nextFrameStart;
  bool post_render;
  uint8_t lastFrameDurationMs;
  static bool   toDraw;
  uint16_t Counter;

/*  Defines  */
/* Frame management */
void SetFrameRate(uint8_t rate)
{
  frameRate = rate;
  eachFrameMillis = 1000/rate;
}
static bool nextFrame(void)
{
  long now = HAL_GetTick();//当前毫秒数
  //uint8_t remaining;

  // post render
  if (post_render) {
    lastFrameDurationMs = now - lastFrameStart;
    frameCount++;
    post_render = false;
  }

  // if it's not time for the next frame yet
  if (now < nextFrameStart) {
    //remaining = nextFrameStart - now;

    return false;
  }

  nextFrameStart = now + eachFrameMillis;
  lastFrameStart = now;
  post_render = true;
  return post_render;
}

bool NextFrame(void)
{
    bool ret = nextFrame();
    if (ret) {
      KeyScan();
    }
    return ret;
}
int NeighborCount( int x, int y)//判断当前细胞周围存活个数
{
    int i;       
    int j;       
    int count = 0;
  if ( x >= (LIFEGAME_WIDTH-1)||y >= (LIFEGAME_HEIGHT-1)||x <=0||y <=0)//边界处理
  {
	return 0xff;
  }
    for (i = x-1; i <= x+1; i++)
		{
					for (j = y-1; j <= y+1; j++)
							if (OLED_GetPixel(i,j) == ALIVE)
							{
									count++;
							}
		}
	if (OLED_GetPixel(x,y) == ALIVE)
		count --;

    return count;
}
void UpDate(void)
{
	int i,j;
	for(i=0;i<LIFEGAME_WIDTH;i++)
	{
		for(j=0;j<LIFEGAME_HEIGHT;j++)
		{
			if(Display_Temp[i][j]==ALIVE)
			{
			OLED_DrawPixel(i,j,ALIVE);
			}
			else
			{
			OLED_DrawPixel(i,j,DEAD);
			}
		}
	}
}

void initGame(void)
{
	int i,j;
	Counter=0;
	for(i=0;i<LIFEGAME_WIDTH;i++)
	{
		for(j=0;j<LIFEGAME_HEIGHT;j++)
		{
		Display_Temp[i][j]=0;
		}
	}
}

bool updateGame(void)
{
int i,j,ret;
	Counter++;
	if(Counter>=5)//12
	{
		Counter=0;
		toDraw=true;		
		for(i=0;i<LIFEGAME_WIDTH;i++)
		{
		for(j=0;j<LIFEGAME_HEIGHT;j++)
		{
			if (OLED_GetPixel(i,j) == ALIVE)
			{
				switch(NeighborCount(i,j))
				{
				 case 0:
					 Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 1:
					 Display_Temp[i][j]=DEAD;
				 break;
					
				 case 2:
					 Display_Temp[i][j]=ALIVE;
				 break;
						
				 case 3:
					 Display_Temp[i][j]=ALIVE;
				 break;
						
				 case 4:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 5:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 6:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 7:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 8:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 default:
					Display_Temp[i][j]=DEAD; 
				 break;
				 
				}
			}
			else
			{
				switch(NeighborCount(i,j))
				{
				 case 0:
					 Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 1:
					 Display_Temp[i][j]=DEAD;
				 break;
					
				 case 2:
					 Display_Temp[i][j]=DEAD;
				 break;
						
				 case 3:
					 Display_Temp[i][j]=ALIVE;
				 break;
						
				 case 4:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 5:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 6:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 7:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 case 8:
					  Display_Temp[i][j]=DEAD;
				 break;
				 
				 default:
					 Display_Temp[i][j]=DEAD; 
				 break;
				}
			}
		}
	
		}
	}
	if(ButtonDown(B_BUTTON))
	{
		ret=true;
	}
	else
	{
		ret=false;	
	}	
return ret;
}

void drawGame(void)
{
	if(toDraw)
	{
	UpDate();
	toDraw=false;
	}
}


