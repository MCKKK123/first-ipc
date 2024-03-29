#include "oled.h"

uint8_t u8x8_stm32_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr){
    switch (msg)
    {
    case U8X8_MSG_DELAY_100NANO: // delay arg_int * 100 nano seconds
		__NOP();
        break;
    case U8X8_MSG_DELAY_10MICRO: // delay arg_int * 10 micro seconds
        for (uint16_t n = 0; n < 320; n++){
            __NOP();
        }
        break;
    case U8X8_MSG_DELAY_MILLI: // delay arg_int * 1 milli second
        OLED_Delay_ms(arg_int);
        break;
		case U8X8_MSG_GPIO_I2C_CLOCK:		// arg_int=0: Output low at I2C clock pin
			if(arg_int) GPIO_SetBits(OLED_SCL_GPIO,OLED_SCL_PIN);
			else GPIO_ResetBits(OLED_SCL_GPIO,OLED_SCL_PIN);
      break;							// arg_int=1: Input dir with pullup high for I2C clock pin
    case U8X8_MSG_GPIO_I2C_DATA:			// arg_int=0: Output low at I2C data pin
			if(arg_int) GPIO_SetBits(OLED_SDA_GPIO,OLED_SDA_PIN);
			else GPIO_ResetBits(OLED_SDA_GPIO,OLED_SDA_PIN);
      break;							// arg_int=1: Input dir with pullup high for I2C data pin
    }
    return 1;
}


void u8g2_gpio_init(void){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = OLED_SCL_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(OLED_SCL_GPIO, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin   = OLED_SDA_PIN;
    GPIO_Init(OLED_SDA_GPIO, &GPIO_InitStructure);
}

void u8g2Init(u8g2_t *u8g2){
    u8g2_gpio_init();
	u8g2_Setup_ssd1306_i2c_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_sw_i2c,u8x8_stm32_gpio_and_delay);  // 初始化 u8g2 结构体
	u8g2_InitDisplay(u8g2); // 根据所选的芯片进行初始化工作，初始化完成后，显示器处于关闭状态
	u8g2_SetPowerSave(u8g2, 0); // 打开显示器                                                                   // 打开显示器
	u8g2_ClearBuffer(u8g2);

}

void draw(u8g2_t *u8g2){
    u8g2_ClearBuffer(u8g2);
    u8g2_SetFontMode(u8g2, 1); /*字体模式选择*/
    u8g2_SetFontDirection(u8g2, 0); /*字体方向选择*/
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf); /*字库选择*/
    u8g2_DrawStr(u8g2, 0, 20, "U");
    
    u8g2_SetFontDirection(u8g2, 1);
    u8g2_SetFont(u8g2, u8g2_font_inb30_mn);
    u8g2_DrawStr(u8g2, 21,8,"8");
        
    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
    u8g2_DrawStr(u8g2, 51,30,"g");
    u8g2_DrawStr(u8g2, 67,30,"\xb2");
    
    u8g2_DrawHLine(u8g2, 2, 35, 47);
    u8g2_DrawHLine(u8g2, 3, 36, 47);
    u8g2_DrawVLine(u8g2, 45, 32, 12);
    u8g2_DrawVLine(u8g2, 46, 33, 12);
    u8g2_SendBuffer(u8g2);
    //u8g2_SetFont(u8g2, u8g2_font_4x6_tr);
    // u8g2_DrawStr(u8g2, 1,54,"github.com/olikraus/u8g2");
}
 

