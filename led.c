#ifndef _LED_C_
#define _LED_C_
#include "stm32f4xx.h"
#include "delay.h"
#include "u8g2.h"
#include "oled.h"
int main(void){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	//
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
	//GPIO_ResetBits(GPIOD,GPIO_Pin_14);
	//GPIO_SetBits(GPIOD, GPIO_Pin_14);
	GPIOD->BSRR = GPIO_Pin_14;
	//*(uint32_t*) (0x40000000 + 0x00020000 + 0x0C00 + 0x18) = 0x4000;
	
}
 int rea_led_level(const8=int * level){
	*level = GPIO_ReadInputDataBit(GPIOD, GPIO_PIN_14);
	 
}
