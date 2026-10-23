/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32g4xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_3);

  /* System interrupt init*/

  /** Disable the internal Pull-Up in Dead Battery pins of UCPD peripheral
  */
  HAL_PWREx_DisableUCPDDeadBattery();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
  * @brief COMP MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hcomp: COMP handle pointer
  * @retval None
  */
void HAL_COMP_MspInit(COMP_HandleTypeDef* hcomp)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hcomp->Instance==COMP4)
  {
    /* USER CODE BEGIN COMP4_MspInit 0 */

    /* USER CODE END COMP4_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**COMP4 GPIO Configuration
    PB0     ------> COMP4_INP
    PB2     ------> COMP4_INM
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USER CODE BEGIN COMP4_MspInit 1 */

    /* USER CODE END COMP4_MspInit 1 */

  }

}

/**
  * @brief COMP MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hcomp: COMP handle pointer
  * @retval None
  */
void HAL_COMP_MspDeInit(COMP_HandleTypeDef* hcomp)
{
  if(hcomp->Instance==COMP4)
  {
    /* USER CODE BEGIN COMP4_MspDeInit 0 */

    /* USER CODE END COMP4_MspDeInit 0 */

    /**COMP4 GPIO Configuration
    PB0     ------> COMP4_INP
    PB2     ------> COMP4_INM
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_2);

    /* USER CODE BEGIN COMP4_MspDeInit 1 */

    /* USER CODE END COMP4_MspDeInit 1 */
  }

}

/**
  * @brief DAC MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hdac: DAC handle pointer
  * @retval None
  */
void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac)
{
  if(hdac->Instance==DAC3)
  {
    /* USER CODE BEGIN DAC3_MspInit 0 */

    /* USER CODE END DAC3_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_DAC3_CLK_ENABLE();
    /* USER CODE BEGIN DAC3_MspInit 1 */

    /* USER CODE END DAC3_MspInit 1 */

  }

}

/**
  * @brief DAC MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hdac: DAC handle pointer
  * @retval None
  */
void HAL_DAC_MspDeInit(DAC_HandleTypeDef* hdac)
{
  if(hdac->Instance==DAC3)
  {
    /* USER CODE BEGIN DAC3_MspDeInit 0 */

    /* USER CODE END DAC3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DAC3_CLK_DISABLE();
    /* USER CODE BEGIN DAC3_MspDeInit 1 */

    /* USER CODE END DAC3_MspDeInit 1 */
  }

}

/**
  * @brief OPAMP MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hopamp: OPAMP handle pointer
  * @retval None
  */
void HAL_OPAMP_MspInit(OPAMP_HandleTypeDef* hopamp)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hopamp->Instance==OPAMP3)
  {
    /* USER CODE BEGIN OPAMP3_MspInit 0 */

    /* USER CODE END OPAMP3_MspInit 0 */

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**OPAMP3 GPIO Configuration
    PA1     ------> OPAMP3_VINP
    PB1     ------> OPAMP3_VOUT
    PB10     ------> OPAMP3_VINM
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USER CODE BEGIN OPAMP3_MspInit 1 */

    /* USER CODE END OPAMP3_MspInit 1 */

  }

}

/**
  * @brief OPAMP MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hopamp: OPAMP handle pointer
  * @retval None
  */
void HAL_OPAMP_MspDeInit(OPAMP_HandleTypeDef* hopamp)
{
  if(hopamp->Instance==OPAMP3)
  {
    /* USER CODE BEGIN OPAMP3_MspDeInit 0 */

    /* USER CODE END OPAMP3_MspDeInit 0 */

    /**OPAMP3 GPIO Configuration
    PA1     ------> OPAMP3_VINP
    PB1     ------> OPAMP3_VOUT
    PB10     ------> OPAMP3_VINM
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_1|GPIO_PIN_10);

    /* USER CODE BEGIN OPAMP3_MspDeInit 1 */

    /* USER CODE END OPAMP3_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
