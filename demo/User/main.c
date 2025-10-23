#include "module_led.h"
#include "module_key.h"


int main()
{
	led_dev_init_and_register();
	key_dev_init_and_register();
	
	dev_gpio *pLED1,*pLED2,*pKEY1,*pKEY2;
	
	pLED1 = dev_gpio_find("LED1");
	pLED2 = dev_gpio_find("LED2");
	pKEY1 = dev_gpio_find("KEY1");
	pKEY2 = dev_gpio_find("KEY2");
	
	pLED1->Init(pLED1);pLED2->Init(pLED2);pKEY1->Init(pKEY1);pKEY2->Init(pKEY2);

	while(1)
	{
		uint8_t sta;
		
		if(pKEY1->Read(pKEY1) == 1)
		{
			sta = pLED1->Read(pLED1)^0x01;
			pLED1->Write(pLED1,sta);
			while(pKEY1->Read(pKEY1) == 1);
		}
		if(pKEY2->Read(pKEY2) == 1)
		{
			sta = pLED2->Read(pLED2)^0x01;
			pLED2->Write(pLED2,sta);
			while(pKEY2->Read(pKEY2) == 1);
		}
	}
	
}


