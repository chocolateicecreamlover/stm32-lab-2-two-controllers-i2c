#include "L3GD20.h"

extern SPI_HandleTypeDef hspi1;
uint8_t buf2[8] = {0};
char str1[30] = {0};

static void Error() {}
	
	
uint8_t SPI1_WriteRead(uint8_t Byte) {
    uint8_t receivedbyte = 0;
    if (HAL_SPI_TransmitReceive(&hspi1, (uint8_t * ) &Byte, (uint8_t * ) &receivedbyte, 1, 0x1000) != HAL_OK) {
        Error();
    }
    return receivedbyte;
}

void L3GD20_IO_Write(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite) {
    CS_OFF;
    if (NumByteToWrite > 0x01) {
        WriteAddr |= (uint8_t) MULTIPLEBYTE_CMD;
    }
    CS_ON;
    SPI1_WriteRead(WriteAddr);
    while (NumByteToWrite >= 0x01) {
        SPI1_WriteRead(*pBuffer);
        NumByteToWrite--;
        pBuffer++;
    }
    CS_OFF;
}
	
void L3GD20_IO_Read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead) {
    if (NumByteToRead > 0x01) {
        ReadAddr |= (uint8_t)(READWRITE_CMD | MULTIPLEBYTE_CMD);
    } else {
        ReadAddr |= (uint8_t) READWRITE_CMD;
    }
    CS_ON;
    SPI1_WriteRead(ReadAddr);
    while (NumByteToRead > 0x00) {
        *pBuffer = SPI1_WriteRead(DUMMY_BYTE);
        NumByteToRead--;
        pBuffer++;
    }
    CS_OFF;
}
	
uint8_t L3GD20_ReadID(void) {
    uint8_t ctrl = 0x00;
    L3GD20_IO_Read(&ctrl, L3GD20_WHO_AM_I_ADDR, 1);
    return ctrl;
}

void L3GD20_Ini(void) {
	
    uint8_t ctrl = 0x0000;

    if (L3GD20_ReadID() == I_AM_L3GD20) {

        ctrl = (L3GD20_MODE_ACTIVE | L3GD20_AXES_ENABLE | L3GD20_OUTPUT_DATARATE_4 | L3GD20_BANDWIDTH_4);
        L3GD20_IO_Write(&ctrl, L3GD20_CTRL_REG1_ADDR, 1);

        ctrl = (L3GD20_HPM_NORMAL_MODE | L3GD20_HPFCF_0);
        L3GD20_IO_Write(&ctrl, L3GD20_CTRL_REG2_ADDR, 1);

        ctrl = (L3GD20_INT2INTERRUPT_ENABLE);
        L3GD20_IO_Write(&ctrl, L3GD20_CTRL_REG3_ADDR, 1);

        ctrl = (L3GD20_FULLSCALE_2000);
        L3GD20_IO_Write(&ctrl, L3GD20_CTRL_REG4_ADDR, 1);

        ctrl = (L3GD20_HIGHPASSFILTER_ENABLE);
        L3GD20_IO_Write(&ctrl, L3GD20_CTRL_REG5_ADDR, 1);

    }
    else {
        Error();
    }

}




void L3GD20_GetXYZ(int16_t *pData) {
    int8_t buffer[6];

    float valueinfloat = 0.0;

    L3GD20_IO_Read((uint8_t * ) & buffer[0], L3GD20_OUT_X_L_ADDR, 1);
    L3GD20_IO_Read((uint8_t * ) & buffer[1], L3GD20_OUT_X_H_ADDR, 1);
    L3GD20_IO_Read((uint8_t * ) & buffer[2], L3GD20_OUT_Y_L_ADDR, 1);
    L3GD20_IO_Read((uint8_t * ) & buffer[3], L3GD20_OUT_Y_H_ADDR, 1);
    L3GD20_IO_Read((uint8_t * ) & buffer[4], L3GD20_OUT_Z_L_ADDR, 1);
    L3GD20_IO_Read((uint8_t * ) & buffer[5], L3GD20_OUT_Z_H_ADDR, 1);

    for (int i = 0; i < 3; i++) {
        valueinfloat = ((buffer[2 * i + 1] << 8) + buffer[2 * i]);
        pData[i] = (int16_t) valueinfloat;
    }
}









