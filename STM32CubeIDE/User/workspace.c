/**
  ******************************************************************************
  * @file    workspace.c
  * @author  
  * @version 
  * @date    
  * @brief   
  ******************************************************************************
  * @attention

  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "workspace.h"
#include "led_module.h"
//#include "regular_conversion_manager.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/	

WKSPC_t	WKSPC;
Flag_t 	Flag;					// Global flag var

/* Exported variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/
void WKSPC_Init (void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	
	 /*Configure GPIO pin : PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	
//	WKSPC.Counter = SystemCounter + 10000; 
}
	
/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/
void WKSPC_Processing (void)
{
	static char Retval = 0;
	RegConv_t PotentiometerConv;
	uint8_t PotentiometerHandle;
	
	PotentiometerConv.regADC = ADC1;
	PotentiometerConv.channel = MC_ADC_CHANNEL_11;
	PotentiometerConv.samplingTime = LL_ADC_SAMPLINGTIME_247CYCLES_5;
	
	if(WKSPC.Counter < SystemCounter)
	{
		WKSPC.Counter = SystemCounter + 1000;
		
//		u16 AdcResult = RCM_GetUserConv();
		LED_TurnON(LED6, 50);
		__NOP();
		
		
		
	}
		
		
	if(Flag.NewAdcData == 1)
	{
		Flag.NewAdcData = 0;
	}

}


/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/
void WKSPC_WeightHandle (void)
{	
	
}


/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/

/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/

/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/

/*********************************************************************************
  * @brief  
  * @param  None
  * @retval None
*********************************************************************************/




















































/*
void WKSPC_WeightHandle (void)
{
//	static u32 Weight;
	
	if(ScalesPrmtr.MaxWeight > 0)
	{
		long tmp, tmp1;
		char neg;
		
		if(Cod < ScalesPrmtr.ZeroLevel)
		{
			tmp = ScalesPrmtr.ZeroLevel - Cod;
			neg = 1;
		}
		else
			tmp = Cod - ScalesPrmtr.ZeroLevel;
		
		tmp = (float) ((ScalesPrmtr.Coefficient[0] * tmp) + 0.5);
		tmp = (tmp/ScalesPrmtr.Discrete) * ScalesPrmtr.Discrete;
		
		if( (tmp % ScalesPrmtr.Discrete) >= ScalesPrmtr.Discrete)
			tmp += ScalesPrmtr.Discrete;
		
		if(tmp >99999)
			tmp = 99999;
		
		if(neg)
			tmp = -tmp;
				
		if(tmp > 0)
			if(ScalesPrmtr.MaxWeight > tmp)
				tmp = 0x20000000;
			
		WKSPC.Brutto = tmp;	
		WKSPC.Netto = WKSPC.Brutto - WKSPC.Tara; 
	}
	else
		WKSPC.Brutto = 0x10000000;
}*/




/*********************************************************************************
  * @brief  �������� ���� �� ���� ���.
  * @param  None
  * @retval None
*********************************************************************************/
/*void WKSPC_WeightHandle (void)
{
	u32 Weight;
	s8 Neg = 0;
	
	if(ScalesPrmtr.MaxWeight > 0)
	{
		long tmp;
		
		tmp = (float) ((ScalesPrmtr.Coefficient * Cod) + 0.5);
		tmp = (tmp/ScalesPrmtr.Discrete) * ScalesPrmtr.Discrete;
		
		if( (tmp % ScalesPrmtr.Discrete) >= ScalesPrmtr.Discrete)
			tmp += ScalesPrmtr.Discrete;
		
		if(tmp >90000)
			tmp = 90000;	
			
//		WKSPC_MakeWeight();
		
		if(tmp < ScalesPrmtr.Tara)
		{
			Weight = ScalesPrmtr.Tara - tmp;
			Neg = 1;
		}
		else
		{
			Weight = tmp - ScalesPrmtr.Tara;
		}
		
		if(Neg)
			Weight = -Weight;
		
		WKSPC.Netto = Weight;
		
//		WKSPC.Brutto = tmp;	
//		WKSPC.Netto = WKSPC.Brutto - ScalesPrmtr.Tara; 
		
		if(WKSPC.Netto > ScalesPrmtr.MaxWeight)
			WKSPC.Netto = 0x20000000;			// ������ ���������� ������������� ����
	}
	else
		WKSPC.Netto = 0x10000000;				// ������ ������������� ����
}*/




