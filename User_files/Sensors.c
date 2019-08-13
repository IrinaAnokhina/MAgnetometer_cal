#include "i2c.h"
#include "Sensors.h"

extern I2C_HandleTypeDef hi2c1;
extern  HAL_StatusTypeDef status;
extern SPI_HandleTypeDef hspi1;
void init_acc_mag()
{
		uint8_t data[1];
	data[0] = 0x00;
	status = HAL_I2C_Mem_Write(&hi2c1, 0x3D, 0x60, I2C_MEMADD_SIZE_8BIT , data, 0x01, 100); //mag = 10Hz(high resolution + continuous mode)
		data[0] = 0x01;
	status = HAL_I2C_Mem_Write(&hi2c1, 0x3D, 0x62, I2C_MEMADD_SIZE_8BIT , data, 0x01, 100); // mag data ready interrupt enable

		/*data[0] = 0x57;
 HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET); 
    HAL_SPI_Transmit(&hspi1, (uint8_t *) &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_SET); */
		data[0] = 0x57;
	HAL_Delay(10);
	status = HAL_I2C_Mem_Write(&hi2c1, 0x33, 0x20, I2C_MEMADD_SIZE_8BIT , data, 0x01, 100); // accel = 100Hz (normal mode)
		data[0] = 0x01;
	status = HAL_I2C_Mem_Write(&hi2c1, 0x33, 0x23, I2C_MEMADD_SIZE_8BIT , data, 0x01, 100); // accel SPI enable*/
		data[0] = 0x0C;
	HAL_Delay(10);
	status = HAL_I2C_Mem_Write(&hi2c1, 0x3D, 0x60, I2C_MEMADD_SIZE_8BIT , data, 0x01, 100); // mag ODR = 100 Hz
}



void init_sensors()
{
	init_acc_mag();	
}