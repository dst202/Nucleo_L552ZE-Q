//where is led connected
//port :pb,pa
//pin :7,9
#define PERIPH_BASE 			(0x40000000UL)
#define AHB2PERIPH_OFFSET		(0x02020000UL)
#define AHB2PERIPH_BASE 		(PERIPH_BASE + AHB2PERIPH_OFFSET)
#define GPIOA_OFFSET 			(0x00000000UL)

#define GPIOA_BASE				(AHB2PERIPH_BASE+GPIOA_OFFSET)

#define RCC_OFFSET 				(0X00021000UL)
#define RCC_BASE				(PERIPH_BASE + RCC_OFFSET)

#define AHB2EN_R_OFFSET			(0x04CUL)
#define RCC_AHB2EN_R			(*(volatile unsigned int *) (RCC_BASE + AHB2EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define ODR_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE+ODR_OFFSET))

#define GPIOAEN					(1U<<0)// 0b 0000 0000 0000 0000 0000 0000 0000 0001


#define PIN_9					(1U<<9)
#define LED_PIN					PIN_9

int main(void)
{

	RCC_AHB2EN_R |= GPIOAEN;
	GPIOA_MODE_R |=(1U<<18);
	GPIOA_MODE_R &=~(1U<<19);
		while(1)
		{
			GPIOA_OD_R |= LED_PIN;
		}
}


