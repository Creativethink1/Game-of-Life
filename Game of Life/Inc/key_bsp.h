
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __key_bsp_H
#define __key_bsp_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

//extern SPI_HandleTypeDef hspi1;
//extern SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN Private defines */
#define LEFT_BUTTON _BV(0)
#define RIGHT_BUTTON _BV(1)
#define UP_BUTTON _BV(2)
#define DOWN_BUTTON _BV(3)
#define A_BUTTON _BV(4)
#define B_BUTTON _BV(5)
	 
/* USER CODE END Private defines */


/* USER CODE BEGIN Prototypes */

uint8_t ButtonsState(void);
void KeyScan(void);
bool ButtonDown(uint8_t buttons);
bool ButtonPressed(uint8_t buttons);
bool ButtonUp(uint8_t buttons);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ spi_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
