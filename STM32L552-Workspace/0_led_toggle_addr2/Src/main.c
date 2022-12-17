/*bare metal code to light a led on Nucleo L552ZE-Q dev board
 * locate the port and pin connected to led
 * Port-B and Pin-7 PB7 */

#define PERIPH_BASE			(0x40000000UL)							// peripheral base address//
#define AHB2PERIPH_OFFSET	(0x02020000UL)							// AHB2 offset from peripheral base
#define AHB2_BASE			(PERIPH_BASE + AHB2PERIPH_OFFSET)		//AHB2 base address

#define GPIOB_OFFSET		(0x0400UL)								//offset to reach GPIO port B from AHB2PERIPH_BASE
#define GPIOB_BASE			(AHB2_BASE + GPIOB_OFFSET)				// base address for GPIO port B  pins

#define RCC_OFFSET          (0X00021000UL)							// find the off set of RCC respective to AHB2 base
#define RCC_BASE			(PERIPH_BASE + RCC_OFFSET)				//get the RCC base by adding PERIPH base and offset

#define AHB2EN_R_OFFSET     (0x04C)									//get offset of AHB2ENR register
#define RCC_AHB2EN_R		(*(volatile unsigned int*)(RCC_BASE + AHB2EN_R_OFFSET))		//create AHB2NR address

#define GPIOBEN				(1U<<1)									//shift 1 to enable clock for port B bit

#define MODE_R_OFFSET		(0x00UL)								//get the adress of moder to set GPIO mode of operation
#define GPIOB_MODE_R		(*(volatile unsigned int*)(GPIOB_BASE + MODE_R_OFFSET))			//set the adress to moder of GPIOB

#define OD_R_OFFSET         (0x14UL)								// get the offset for GPIOB ODR offset
#define GPIOB_OD_R			(*(volatile unsigned int*)(GPIOB_BASE	+ OD_R_OFFSET))			//create the adress for ODR
#define PIN7                (1U<<7)
#define LED_PIN				PIN7

int main(void)
{
	RCC_AHB2EN_R |= GPIOBEN;
	GPIOB_MODE_R |=(1U<<14);
	GPIOB_MODE_R &=~(1U<<15);
		while(1)
		{
			GPIOB_OD_R |= PIN7;
		}
}
