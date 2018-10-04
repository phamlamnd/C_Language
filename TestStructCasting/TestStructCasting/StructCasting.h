#ifndef _STRUCT_CASTING_H_
#define _STRUCT_CASTING_H_

typedef struct
{
	volatile unsigned int MODER;	//GPIO port mode register
	volatile unsigned int OTYPER;	//GPIO port output type register
	volatile unsigned int OSPEEDR;	//GPIO port output speed register
	volatile unsigned int PUPDR;	//GPIO port pull-up/pull-down register	
	volatile unsigned int IDR;		//GPIO port input data register
	volatile unsigned int ODR;		//GPIO port output data register 
	volatile unsigned int BSRR;		//GPIO port bit set/reset register
	volatile unsigned int LCKR;		//GPIO port configuration lock register
	volatile unsigned int AFRL;		//GPIO alternate function low register
	volatile unsigned int AFRH;		//GPIO alternate function high register
	volatile unsigned int BRR;		//GPIO port bit reset register
}GPIO_TypeDef;

/*=======================GPIO=======================*/
#define GPIOA_BASE			(unsigned int)0x48000000U
#define GPIOB_BASE			(unsigned int)0x48000400U
#define GPIOC_BASE			(unsigned int)0x48000800U
#define GPIOD_BASE			(unsigned int)0x48000C00U
#define GPIOE_BASE			(unsigned int)0x48001000U
#define GPIOF_BASE			(unsigned int)0x48001400U
#define GPIOA				((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB				((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC				((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD				((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE				((GPIO_TypeDef*)GPIOE_BASE)
#define GPIOF				((GPIO_TypeDef*)GPIOF_BASE)

#endif
