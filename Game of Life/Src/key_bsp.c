
#include "key_bsp.h"

/* USER CODE BEGIN 0 */
 uint8_t lastButtonState;
 uint8_t currentButtonState;

uint8_t ButtonsState(void)
{
  uint8_t buttons = 0;

  if(HAL_GPIO_ReadPin(KEY4_GPIO_Port,KEY4_Pin) == 0){//LEFT
 
		buttons = _BV(0);
  }
  if(HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin) == 0){//RIGGHT

		buttons =_BV(1);
  }
  if(HAL_GPIO_ReadPin(KEY5_GPIO_Port,KEY5_Pin) == 0){//UP

		buttons = _BV(2);
  }
  if(HAL_GPIO_ReadPin(KEY6_GPIO_Port,KEY6_Pin) == 0){//DOWN

		buttons = _BV(3);
  }
  if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin) == 0){//A

		buttons = _BV(4);
  }
  if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin) == 0){//B

		buttons = _BV(5);
  }
  
  return buttons;
}

void KeyScan(void)
{
lastButtonState = currentButtonState;
currentButtonState = ButtonsState();
}
bool ButtonDown(uint8_t buttons)
{
    return currentButtonState & ~lastButtonState & buttons;
}

bool ButtonPressed(uint8_t buttons)
{
    return currentButtonState & buttons;
}

bool ButtonUp(uint8_t buttons)
{
    return ~currentButtonState & lastButtonState & buttons;
}

/* USER CODE END 0 */



/**********************END OF FILE*******************************/
