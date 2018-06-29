#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"							//GPIO header
#include "misc.h" 


void CPU_Initialization(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//Set priority groups
		//Just for test
	//	SysTick_Config(SystemCoreClock / 50000);
}



