DHT22_HandleTypeDef dht;

int main(void) {

	HAL_Init();
	SystemClock_Config();
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 1);

	dht22.gpioPin = GPIO_PIN_6;
	dht22.gpioPort = GPIOC;
	dht22.timChannel = TIM_CHANNEL_1;
	dht22.gpioAlternateFunction = GPIO_AF2_TIM3;
	dht22.timHandle.Instance = TIM3;

	if(DHT22_Init(&dht22)!=DHT22_OK){
		// error occured
		while(1);
	}

	while (1) {
		DHT22_ReadData(&dht);
		float temp=dht.temp;
		float humidity=dht.hum;
		HAL_Delay(100);
	}
}
