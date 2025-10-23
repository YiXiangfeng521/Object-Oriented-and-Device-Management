#include "module_key.h"

static void key_init(struct DEV_GPIO *pDev)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE); 
    
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin  =  pDev->GPIO_Pin;
    GPIO_Init(pDev->GPIOx, &GPIO_InitStructure);
}

 static int key_Read(struct DEV_GPIO *pDev)
 {
    if(pDev == NULL) return -1;
    return GPIO_ReadInputDataBit(pDev->GPIOx, pDev->GPIO_Pin);
 }
void key_dev_init_and_register(void)
{   
    dev_gpio key;
    
    dev_gpio_init(&key);
    key.name = "KEY1";
    key.GPIOx = GPIOA;
    key.GPIO_Pin = GPIO_Pin_0;
    key.Init = key_init;
    key.Read = key_Read;
    key.Write = NULL;
    dev_gpio_register(&key);

    key.name = "KEY2";
    key.GPIOx = GPIOC;
    key.GPIO_Pin = GPIO_Pin_13;
    key.Init = key_init;
    key.Read = key_Read;
    key.Write = NULL;
    dev_gpio_register(&key);

   
}
