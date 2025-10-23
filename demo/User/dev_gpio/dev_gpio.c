#include "dev_gpio.h"

static list_item dev_gpio_list = {
    .pxNext = &dev_gpio_list,
    .pxPrevious = &dev_gpio_list
};

void dev_gpio_init(dev_gpio *pDev)
{
    pDev->name = " ";
    pDev->GPIOx = NULL;
    pDev-> GPIO_Pin = 0;
    pDev->Init = NULL;
    pDev->Write = NULL;
    pDev->Read = NULL;  
}

void dev_gpio_register(dev_gpio *dev)
{
    dev_gpio *pnew_dev_gpio;

    if(dev == NULL) return;

    pnew_dev_gpio = (dev_gpio *)malloc(sizeof(dev_gpio));
    pnew_dev_gpio->name = dev->name;
    pnew_dev_gpio->GPIOx = dev->GPIOx;
    pnew_dev_gpio-> GPIO_Pin = dev->GPIO_Pin;
    pnew_dev_gpio->Init = dev->Init;
    pnew_dev_gpio->Write = dev->Write;
    pnew_dev_gpio->Read = dev->Read;  
    list_init(&pnew_dev_gpio->list);
    list_insert_tail(&dev_gpio_list,&pnew_dev_gpio->list);
}
void dev_gpio_unregister(dev_gpio *dev)
{
    
    if(dev->list.pxNext == &dev->list) return;

    list_remove(&dev->list);
    free(dev);
    
}
dev_gpio *dev_gpio_find(const char *name)
{
    list_item *p = &dev_gpio_list;
    dev_gpio *dev;

    while(p->pxNext != &dev_gpio_list)
    {
        p = p->pxNext;
        dev = ((dev_gpio *)((char *)(p) - (unsigned long) &((dev_gpio*)0)->list));
        if(strstr(dev->name,name)) return dev;
    }
    return NULL;
}

