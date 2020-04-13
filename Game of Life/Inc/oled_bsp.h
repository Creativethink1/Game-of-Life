
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __oled_bsp_H
#define __oled_bsp_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN Private defines */
//OLED �˿ڶ���	 
#define OLED_CS_Clr()  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET)//CS
#define OLED_CS_Set()  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET)

#define OLED_RST_Clr() HAL_GPIO_WritePin(GPIOC, OLED_RST_Pin, GPIO_PIN_RESET)//RST
#define OLED_RST_Set() HAL_GPIO_WritePin(GPIOC, OLED_RST_Pin, GPIO_PIN_SET)

#define OLED_DC_Clr() HAL_GPIO_WritePin(GPIOC, OLED_DC_Pin, GPIO_PIN_RESET)//DC
#define OLED_DC_Set() HAL_GPIO_WritePin(GPIOC, OLED_DC_Pin, GPIO_PIN_SET)

#define OLED_WIDTH  128
#define OLED_HEIGHT 64

#define WHITE 1 
#define BLACK 0 


#define min(a,b) ((a)<=(b)?(a):(b))
#define max(a,b) ((a)>=(b)?(a):(b))
#define ABS(x) (((x) > 0) ? (x) : -(x))
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))	
/* USER CODE END Private defines */


/* USER CODE BEGIN Prototypes */

void Init_OLED(void);//��ʼ��OLED
void OLED_Refresh_Gram(void);//����OLED�Դ�
void OLED_FillScreen(u8 color);//OLED�������
void OLED_DrawPixel(u8 x, u8 y, u8 color);//����
u8 OLED_GetPixel(u8 x, u8 y);//����
void OLED_DrawCircle(int16_t x0, int16_t y0, uint8_t r, uint8_t color);//��Բ
void OLED_ClearDisplay(void);//OLED����
void OLED_DrawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color);//OLED��ͼ
void DrawChar(int16_t x, int16_t y, unsigned char c, uint8_t color, uint8_t bg, uint8_t size);//���ַ�
void FillRect2(int16_t x, int16_t y, uint8_t w, int8_t h, uint8_t color);////��ʵ�ľ��� �������������
void OLED_ShowString(u8 x,u8 y,char *chr);//OLED��ʾ�ַ���
void DrawRect(int16_t x, int16_t y, uint8_t w, int8_t h, uint8_t color);//�����ľ���
void FillPatternedRect(int16_t x, int16_t y, uint8_t w, int8_t h, const uint8_t *ptn);
void OLED_DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);//����
void OLED_DrawFastVLine(int16_t x, int16_t y, int8_t h, uint8_t color);//����ֱ��
void OLED_DrawFastHLine(int16_t x, int16_t y, uint8_t w, uint8_t color);//��ˮƽ��
void SetCursor(int16_t x, int16_t y);//��������
void OLED_PrintChar( char *chr);//��ӡ�ַ���
void OLED_PrintNum(u16 num);//��ӡ����
size_t OLED_PrintCharEx(int16_t x, int16_t y,char *chr);////�������ӡ�ַ���

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
