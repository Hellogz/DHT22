/**
 * @brief TIM MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 * @param htim: TIM handle pointer
 * @retval None
 */
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim) {
	GPIO_InitTypeDef GPIO_InitStruct;

	if (htim->Instance == TIM3) {

		/*##-1- Enable peripherals and GPIO Clocks #################################*/
		/* TIMx Peripheral clock enable */
		__TIM3_CLK_ENABLE();

		/* Enable GPIO channels Clock */
		__GPIOC_CLK_ENABLE();

		/* Configure  (TIMx_Channel) in Alternate function, push-pull and 100MHz speed */
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/*##-2- Configure the NVIC for TIMx #########################################*/

		HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

		/* Enable the TIM3 global Interrupt */
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	}
}
