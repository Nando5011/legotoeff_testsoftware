/*
 * File:   legotoeff_mux.c
 * Author: bimbon
 *
 * Created on 19. März 2021, 11:19
 */

#include "../inc/legotoeff_mux.h"

#define RGB_SENSOR_MUX_1            1
#define RGB_SENSOR_MUX_2            2
#define RGB_SENSOR_MUX_3            4
#define DISTANCESENSOR_SENSOR_MUX   8 

#define MUX_ADDRESS                 0x70
#define RGB_ADDRESS                 0x29
#define DISTANCESENSOR_ADDRESS      0x40

uint8_t i = 0;


//Schreibt übergebene Daten auf entsprechenden Sensor
//
//param channel: Sensor auf welcher Daten geschrieben werden sollen (1-3 = RGB Sensoren, 4 = Ultraschall)
//param data: Pointer von zu schreibenden Daten (8Bit-array)
void muxWriteSetChannel(uint8_t channel, uint8_t* data, uint8_t dataLength)
{
    uint8_t muxSlaveAddress;
    uint8_t slaveAddress;
    
    switch(channel)     //Mux-Slaveaddresse und Slaveaddresse entsprechend Kanal/Sensor einstellen
    {
        case 1:     muxSlaveAddress = RGB_SENSOR_MUX_1;             slaveAddress = RGB_ADDRESS;             break;
        case 2:     muxSlaveAddress = RGB_SENSOR_MUX_2;             slaveAddress = RGB_ADDRESS;             break;
        case 3:     muxSlaveAddress = RGB_SENSOR_MUX_3;             slaveAddress = RGB_ADDRESS;             break;
        case 4:     muxSlaveAddress = DISTANCESENSOR_SENSOR_MUX;    slaveAddress = DISTANCESENSOR_ADDRESS;      break;
        default:                                break;            
    }      
    I2C1_WriteNBytes(MUX_ADDRESS,&muxSlaveAddress,1);                //MUX einstellen
    I2C1_WriteNBytes(slaveAddress, data, dataLength);                //Daten auf Sensor geben          
}


void muxReadSetChannel(uint8_t channel, uint8_t* readData, uint8_t numberOfBytes)
{
    uint8_t muxSlaveAddress;
    uint8_t slaveAddress;

    switch(channel)     //Mux-Slaveaddresse und Slaveaddresse entsprechend Kanal/Sensor einstellen
    {
        case 1:     muxSlaveAddress = RGB_SENSOR_MUX_1;             slaveAddress = RGB_ADDRESS;             break;
        case 2:     muxSlaveAddress = RGB_SENSOR_MUX_2;             slaveAddress = RGB_ADDRESS;             break;
        case 3:     muxSlaveAddress = RGB_SENSOR_MUX_3;             slaveAddress = RGB_ADDRESS;             break;
        case 4:     muxSlaveAddress = DISTANCESENSOR_SENSOR_MUX;    slaveAddress = DISTANCESENSOR_ADDRESS;      break;
        default:                                break;            
    }
    I2C1_WriteNBytes(MUX_ADDRESS, &muxSlaveAddress, 1);              //MUX einstellen
    I2C1_ReadNBytes(slaveAddress, readData, numberOfBytes);         //Daten auf Sensor geben
}


uint8_t muxSetChannel(uint8_t channel)
{
    uint8_t muxSlaveAddress;
    uint8_t slaveAddress;
    
    switch(channel)
    {
        case 1:     muxSlaveAddress = RGB_SENSOR_MUX_1;             slaveAddress = RGB_ADDRESS;             break;
        case 2:     muxSlaveAddress = RGB_SENSOR_MUX_2;             slaveAddress = RGB_ADDRESS;             break;
        case 3:     muxSlaveAddress = RGB_SENSOR_MUX_3;             slaveAddress = RGB_ADDRESS;             break;
        case 4:     muxSlaveAddress = DISTANCESENSOR_SENSOR_MUX;    slaveAddress = DISTANCESENSOR_ADDRESS;      break;            
    }
    I2C1_WriteNBytes(MUX_ADDRESS,&muxSlaveAddress,1);
    return slaveAddress;
}