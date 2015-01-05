extern DHT22_HandleTypeDef dht;

void TIM3_IRQHandler(void){
	HAL_TIM_IRQHandler(&dht.timHandle);
}
