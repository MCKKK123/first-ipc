#define _LED_C_
#include "led.h"
#include "string.h"
#include "stdlib.h"

void led_set_level(pLED_Class pthis, const int led_n, const led_bit led_level);
void led_set_level_arr(pLED_Class pthis, const led_bits led_sta);

pLED_Class createLedClass(void){
	pLED_Class led_c=(pLED_Class)malloc(sizeof(LED_Class));
	if(led_c==NULL){
		return NULL;
	}
	
	led_c ->set_level = led_set_level;
	led_c ->set_level_arr = led_set_level_arr;
	
	//led_c ->led_amount=0;
	led_c ->led_curent_level=(led_bits)0;
  led_c->set_level_arr(led_c,(led_bits)0x00);
	return led_c;
}

pLED_Class createLedClassWtihArgs(int Led_amount){
	pLED_Class led_c =createLedClass();
	if(led_c==NULL){
		return NULL;	
	}
	led_c->led_amount=Led_amount;
  return led_c;	
}

void led_set_level(pLED_Class pthis, const int Led_n, const led_bit Led_level){
	led_out_gpio((uint8_t)Led_level,Led_n);
	pthis->led_curent_level&=~(0x01<<Led_n);
	pthis->led_curent_level|=(Led_level<<Led_n);
}


void led_set_level_arr(pLED_Class pthis, const led_bits Led_sta){
	for(int i=0;i<pthis ->led_amount;++i){
		led_out_gpio((uint8_t)(Led_sta>>i)&1,i);
	}
	pthis->led_curent_level=Led_sta;
}
