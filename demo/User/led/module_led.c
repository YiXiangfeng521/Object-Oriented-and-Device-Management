#include "module_led.h"

static void led_init(struct DEV_GPIO *pDev)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin  =  pDev->GPIO_Pin;
    GPIO_Init(pDev->GPIOx, &GPIO_InitStructure);
}
 static int led_Write(struct DEV_GPIO *pDev,unsigned char sta)
 {
    if(pDev == NULL) return -1;
    GPIO_WriteBit(pDev->GPIOx, pDev->GPIO_Pin, (BitAction)sta);
    return 0;
 }
 static int led_Read(struct DEV_GPIO *pDev)
 {
    if(pDev == NULL) return -1;
    return GPIO_ReadOutputDataBit(pDev->GPIOx, pDev->GPIO_Pin);
 }
void led_dev_init_and_register(void)
{   
    dev_gpio led;
    
    dev_gpio_init(&led);
    led.name = "LED1";
    led.GPIOx = GPIOB;
    led.GPIO_Pin = GPIO_Pin_5;
    led.Init = led_init;
    led.Read = led_Read;
    led.Write = led_Write;
    dev_gpio_register(&led);

    led.name = "LED2";
    led.GPIOx = GPIOB;
    led.GPIO_Pin = GPIO_Pin_0;
    led.Init = led_init;
    led.Read = led_Read;
    led.Write = led_Write;
    dev_gpio_register(&led);

    led.name = "LED3";
    led.GPIOx = GPIOB;
    led.GPIO_Pin = GPIO_Pin_1;
    led.Init = led_init;
    led.Read = led_Read;
    led.Write = led_Write;
    dev_gpio_register(&led);
      
}
