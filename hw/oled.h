#ifndef __STM32_U8G2_H
#define __STM32_U8G2_H
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "u8g2.h"
#include "delay.h"
/* USER CODE BEGIN Includes */
 
/* USER CODE END Includes */
 
 
/* USER CODE BEGIN Private defines */
 
/* USER CODE END Private defines */
#define u8         unsigned char  // ?unsigned char ????
#define MAX_LEN    128  //
#define OLED_ADDRESS  0x78 // oled
#define OLED_CMD   0x00  // 
#define OLED_DATA  0x40  // 
 
#define OLED_SCL_GPIO       GPIOB
#define OLED_SCL_PIN        GPIO_Pin_6
#define OLED_SDA_GPIO       GPIOB
#define OLED_SDA_PIN        GPIO_Pin_7

#define OLED_Delay_ms(nms)     delay_ms(nms)

/* USER CODE BEGIN Prototypes */
void u8g2_gpio_init(void);
uint8_t u8x8_stm32_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
void u8g2Init(u8g2_t *u8g2);
void draw(u8g2_t *u8g2);

#endif
