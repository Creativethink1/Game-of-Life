#include "lifegame.h"
/*  Defines  */

enum MODE {
    TITLE_MODE,
    GAME_MODE
};

/*  Typedefs  */

typedef struct {
    void (*initFunc)(void);
    bool (*updateFunc)(void);
    void (*drawFunc)(void);
} MODULE_FUNCS;

/*  Global Variables  */

/*  Local Variables  */

static const MODULE_FUNCS moduleTable[] = {
    { initTitle, updateTitle, drawTitle },
    { initGame,  updateGame,  drawGame },
};

static enum MODE mode = TITLE_MODE;
bool isDone;


void LifeGame(void)
{
	SetFrameRate(60);
	moduleTable[TITLE_MODE].initFunc();
	while(1)
	{
	if (!(NextFrame())) return;
	bool isDone = moduleTable[mode].updateFunc();
	moduleTable[mode].drawFunc();

	OLED_Refresh_Gram();//¸üÐÂOLEDÏÔ´æ
	if (isDone) {
		mode = (mode == TITLE_MODE) ? GAME_MODE : TITLE_MODE;
		moduleTable[mode].initFunc();
	}
	}	
}

