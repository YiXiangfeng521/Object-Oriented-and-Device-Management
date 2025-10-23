[TOC]

# �������ı��˼��
## �龰
������Ҫ����300��LED�ĵ���/Ϩ��
## �����Եı��˼ά

```c
LED1(int sta)
{
    switch(sta)
    {
        case 0: /*Ϩ��;*/break;
        case 1: /*����;*/break;
    }
}
LED2(int sta)
{
    switch(sta)
    {
        case 0: /*Ϩ��;*/break;
        case 1: /*����;*/break;
    }
}
.
.
.
LED300(int sta)
{
    switch(sta)
    {
        case 0: /*Ϩ��;*/break;
        case 1: /*����;*/break;
    }
}
```
## �����Ľ�1
```C
void LED_Ctrl(int led_no, int sta)
{
    if(sta==1)
    {
         switch(led_no)
        {
            case 0: /*����LED0;*/break;
            case 1: /*����LED1;*/break;
            .
            .
            .
            case 300: /*����LED300;*/break;
        }
    }
    else if(sta == 0)
    {
        switch(led_no)
        {
            case 0: /*Ϩ��LED0;*/break;
            case 1: /*Ϩ��LED1;*/break;
            .
            .
            .
            case 300: /*Ϩ��LED300;*/break;
        }
    }
}
```
���ַ�����Ȼ�ܹ��ṩͳһ�Ľӿڣ������ڲ�ʵ���ر��ӡ����ң��������LED�����µĹ��ܣ�����Ҫ�޸�����ӿں��������ݣ���������δ�����

## �Ľ�2

```C
typedef void (*LEDCtrl)(int,int);
LEDCtrl leds[300] = {NULL,GPIO_LEDCtrl,...,IIC_LEDCtrl,...,SPI_LEDCtrl,...};//����ָ������

void LED_Ctrl(int led_no, int sta)
{
    leds[led_no](led_no,sta);
}
```
**����������ȱ�㣺** 
1. ����ָ�������˷ѿռ䣨��ʹ��������ж�̬������
2. ������ÿһ��ֻ��һ��������ֻ�ܱ���һ����Ϊ�����ÿһ��LED���кü������ܣ���Ӧ�ü���������ô�죿��
   
## �Ľ�3

```C
typedef struct 
{
    char *name;
    void (*ONorOFF)(struct LED_Dev *p,int sta);
    void (*SetColor)(struct LED_Dev *p,int color);
}LED_Dev, *pLED_Dev;

pLED_Dev leds[300];

int Dev_cnt = 0;

void register_led(pLED_Dev p_new_dev)
{
    leds[cnt] = p_new_dev;
    Dev_cnt++;
}

LED_Dev IIC_LED = {"IIC_LED",IIC_ONorOFF,IIC_SetColor};
register_led(&IIC_LED);

LED_Dev SPI_LED = {"SPI_LED",SPI_ONorOFF,SPI_SetColor};
register_led(&SPI_LED);


```
## �Ľ�4������������豸��

![alt text](image.png)

