/*
 * i2c_slave.c
 *
 *  Created on: Jun 9, 2023
 *      Author: controllerstech
 */


#include "main.h"
#include "i2c_slave.h"

//extern I2C_HandleTypeDef hi2c1;

//#define RxSIZE  2
//uint8_t RxData[RxSIZE];

//uint8_t count = 0;



//extern void HAL_I2C_ListenCpltCallback (I2C_HandleTypeDef *hi2c)
//{
//	HAL_I2C_EnableListen_IT(hi2c);
//}


//extern void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
//{
//	if(TransferDirection == I2C_DIRECTION_TRANSMIT)  // if the master wants to transmit the data
//	{
//		HAL_I2C_Slave_Sequential_Receive_IT(hi2c, RxData, RxSIZE, I2C_FIRST_AND_LAST_FRAME);
//	}
//	else  // master requesting the data is not supported yet
//	{
//		Error_Handler();
//	}
//}

//extern void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	count++;
//}

//extern void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
//{
//	HAL_I2C_EnableListen_IT(hi2c);
//}

//uint8_t rxcount = 0;
//int is_first_recvd = 0;
//int countAddr = 0;
//int countrxcplt = 0;
//int counterror = 0;

//void process_data (void)
//{
//	//do something here
//	//memcpy(mainbuf, RxData+1, rxcount-1);
//}

//void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	HAL_I2C_EnableListen_IT(hi2c);
//}

//void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
//{
//	if (TransferDirection == I2C_DIRECTION_TRANSMIT)  // if the master wants to transmit the data
//	{
//		if (is_first_recvd == 0)
//		{
//			rxcount = 0;
//			countAddr++;
//			// receive using sequential function.
//			HAL_I2C_Slave_Sequential_Receive_IT(hi2c, RxData+rxcount, 1, I2C_FIRST_FRAME);
//		}

//	}
//	else  // if the master requests the data from the slave
//	{
//		Error_Handler();  // call error handler
//	}
//}

//void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	if (is_first_recvd == 0)
//	{
//		rxcount++;
//		is_first_recvd = 1;
//		HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData+rxcount, RxData[0], I2C_LAST_FRAME);
//	}

//	else
//	{
//		rxcount = rxcount+RxData[0];
//		is_first_recvd=0;
//		process_data();
//	}
//}

//void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
//{
//	counterror++;
//	uint32_t errorcode = HAL_I2C_GetError(hi2c);
//	if (errorcode == 4)  // AF error
//	{
////		process_data();
//	}
//	HAL_I2C_EnableListen_IT(hi2c);
//}
