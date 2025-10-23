#ifndef __DEV_GPIO_H
#define __DEV_GPIO_H

#include "stm32f10x.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct DEV_GPIO
{
    char *name;
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
    void (*Init)(struct DEV_GPIO *pDev);
    int (*Write)(struct DEV_GPIO *pDev,unsigned char sta);
    int (*Read)(struct DEV_GPIO *pDev);
    list_item list;
}dev_gpio;

void dev_gpio_init(dev_gpio *pDev);
void dev_gpio_register(dev_gpio *dev);
dev_gpio *dev_gpio_find(const char *name);

#endif /*__DEV_GPIO_H*/

