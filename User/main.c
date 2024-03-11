#include "stm32f10x.h"
#include "Delay.h"

int main(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 		//使能GPIOB时钟
		GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13;                   //PB8引脚配置
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;            //配置PB8为推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           //GPIOB速度为50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);                       //初始化PB8
        
        while(1)
        {	
							GPIO_WriteBit(GPIOC,GPIO_Pin_13, Bit_RESET);
							Delay_ms(1000);
              GPIO_WriteBit(GPIOC,GPIO_Pin_13, Bit_SET);           //PB8输出低电平，LED点亮
							Delay_ms(1000);
        }
}
