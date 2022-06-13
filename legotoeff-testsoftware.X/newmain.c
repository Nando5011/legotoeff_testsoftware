/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

//Author: Nando Imboden
//Software: Legotoeff Testsoftware

/******************************************************************************/
/***/                                                                      /***/
/***/       //Loopdelay angeben                                            /***/
/***/       #define LOOPDELAY_INIT_TIME_MS      100                        /***/
/***/                                                                      /***/ 
/***/                                                                      /***/   
/******************************************************************************/

/******************************************************************************/
//Include Files & weitere Definitionen

#include "mcc_generated_files/mcc.h"
#include "inc/legotoeff_loopdelay.h"
#include "inc/legotoeff_helpers.h"
#include "inc/legotoeff_lcddriver.h"
#include "inc/legotoeff_mux.h"

#define _XTAL_FREQ 64000000

#define DELAY_1S_COUNTER_GOAL       (1000/loopdelayInitTimeMS)
#define DELAY_3S_COUNTER_GOAL       (3000/loopdelayInitTimeMS)

#define RGB_SENSOR_1                1
#define RGB_SENSOR_2                2
#define RGB_SENSOR_3                3
#define DISTANCESENSOR_SENSOR       4 

#define RGB_ADDRESS                 0x29
#define DISTANCESENSOR_ADDRESS      0x40
#define MUX_ADDRESS                 0x70

#define RGB_ENABLE                  0x80
#define RGB_ATIME                   0x81
#define RGB_WTIME                   0x83
#define RGB_CONFIG                  0x8D
#define RGB_CONTROL                 0x8F
#define RGB_STATUS                  0x93
#define RGB_CDATAL                  0x94
#define RGB_CDATAH                  0x95
#define RGB_RDATAL                  0x96
#define RGB_RDATAH                  0x97
#define RGB_GDATAL                  0x98
#define RGB_GDATAH                  0x99
#define RGB_BDATAL                  0x9A
#define RGB_BDATAH                  0x9B


/******************************************************************************/
//State-Deklaration & Variablendeklaration

typedef enum
{
    RGB_COLORS_CLEAR,RGB_COLORS_RED,RGB_COLORS_GREEN,RGB_COLORS_BLUE
} type_rgb_colors;

typedef enum
{
    I2CTEST,BATLOW,PWMTEST,MDRIVER1TEST,MDRIVER2TEST
} state_t;
state_t testState = I2CTEST;

typedef enum{
        DC_20_t, DC_33_t, DC_50_t, DC_60_t, DC_66_t, DC_100_t
    }type_duty_cycles;
    type_duty_cycles currentDutyCycles = DC_20_t;

uint16_t loopdelayInitTimeMS = LOOPDELAY_INIT_TIME_MS;
uint16_t delay3sCounter = 0;
uint8_t TASTER0Flag = 0, TASTER1Flag = 0, TASTER2Flag = 0;
uint8_t i = 0;
uint8_t i2cCurrentSensor = 1;

/******************************************************************************/
//Funktionsprototypen

void testUBATLOW(void);
void checkPosFlankButtons(void);
void rgbSensorInit(void);
uint8_t rgbReadColor (uint8_t channel, type_rgb_colors rgbColor);
uint8_t distancesensorReadDistance(void);

/******************************************************************************/
/******************** Hauptfunktion *******************************************/
/******************************************************************************/

void main(void)
{
    
    uint8_t rgbClearData = 0;
    uint8_t rgbRedData = 0;
    uint8_t rgbGreenData = 0;
    uint8_t rgbBlueData = 0;
    uint8_t distancesensorData = 0;
    
    SYSTEM_Initialize();                                            // Initialize the device  

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    LOOPDELAY_Init(loopdelayInitTimeMS);
    TMR6_SetInterruptHandler(LOOPDELAY_TimerISR);                   //Loopdelay
    rgbSensorInit();                                                //RGB Sensoren initialisieren 
    muxSetChannel(4);
    I2C1_Write1ByteRegister(DISTANCESENSOR_ADDRESS,0xE8,0x00);      //Distanzsensor initialisieren
    LCD_Init();                                                     //LCD Inititalisieren
    
    
    MDRIVER1STBY = 0;                                               //Motortreiber 1 deaktivieren
    MDRIVER2STBY = 0;                                               //Motortreiber 2 deaktivieren   
    
    
    while (1)
    {
        
        switch(testState)
        {   

/******************************************************************************/
//I2C Test 
            
            case I2CTEST:              
                delay3sCounter++;
                if(delay3sCounter==DELAY_3S_COUNTER_GOAL)           //Alle 3 Sekunden Sensoren 1-4 durchwechseln 
                {
                    i2cCurrentSensor++;
                    if(i2cCurrentSensor==5){
                        i2cCurrentSensor = 1;
                    }
                    delay3sCounter = 0;
                }
                switch(i2cCurrentSensor)                                                    //RGB Sensor:
                {
                    case 1:
                    case 2:
                    case 3:
                        rgbClearData = rgbReadColor(i2cCurrentSensor,RGB_COLORS_CLEAR);
                        rgbRedData   = rgbReadColor(i2cCurrentSensor,RGB_COLORS_RED);
                        rgbGreenData = rgbReadColor(i2cCurrentSensor,RGB_COLORS_GREEN);
                        rgbBlueData  = rgbReadColor(i2cCurrentSensor,RGB_COLORS_BLUE);      //Daten einlesen
                                                                                            /*Formatierte Ausgabe************/
                                                                                            /*                              */
                                                                                            /*      1: C:0xA5 R:0x82        */
                                                                                            /*         G:0xFF B:0xE2        */
                                                                                            /*                              */
                                                                                            /********************************/
                        LCD_Clear();
                        printf("%i  C:0x%02X R:0x%02X\n   G:0x%02X B:0x%02X",i2cCurrentSensor,rgbClearData,rgbRedData,rgbGreenData,rgbBlueData);
                        break;
                    case 4:                                                                 //Distanzsensor:
                        distancesensorData = distancesensorReadDistance();                  //Daten einlesen
                        LCD_Clear();
                        if(distancesensorData<50){
                        printf("Infrared:\n %u cm",distancesensorData);                     //Daten ausgeben
                        }
                        else{
                            printf("Infrared\nOut Of Range!");
                        }
                        break;
                    default:
                        break;
                }                                                        
                testUBATLOW();                  //Prüft auf BATLOW state
                checkPosFlankButtons();         //Prüft auf state-Änderungen aufgrund T0-T2
                break;
                
/******************************************************************************/
//Batterie Low
                
            case BATLOW:
                if(UBATLOW == 0)                //Falls UBATLOW = 0 (Batterie (wieder) genug geladen)
                {
                    testState = I2CTEST;
                    LCD_Clear();
                }
                break;
                
/******************************************************************************/
//PWM Test
                
            case PWMTEST:             
                delay3sCounter++;
                if(delay3sCounter==DELAY_3S_COUNTER_GOAL)           //Alle 3 Sekunden PWM DC ändern
                {
                    switch(currentDutyCycles)
                    {
                        case DC_20_t:
                            PWM3_LoadDutyValue(0x32);               //PWM3 Duty Cycle auf 20%
                            PWM4_LoadDutyValue(0x32);               //PWM4 Duty Cycle auf 20%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 20");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_33_t;            //Duty cycle state auf 33%
                            break;
                        case DC_33_t:
                            PWM3_LoadDutyValue(0x56);               //PWM3 Duty Cycle auf 33%
                            PWM4_LoadDutyValue(0x56);               //PWM4 Duty Cycle auf 33%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 33");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_50_t;            //Duty cycle state auf 50%
                            break;
                        case DC_50_t:
                            PWM3_LoadDutyValue(0x7F);               //PWM3 Duty Cycle auf 50%
                            PWM4_LoadDutyValue(0x7F);               //PWM4 Duty Cycle auf 50%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 50");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_60_t;            //Duty cycle state auf 60%
                            break;
                        case DC_60_t:
                            PWM3_LoadDutyValue(0x99);               //PWM3 Duty Cycle auf 60%
                            PWM4_LoadDutyValue(0x99);               //PWM4 Duty Cycle auf 60%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 60");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_66_t;            //Duty cycle state auf 66%
                            break;
                        case DC_66_t:
                            PWM3_LoadDutyValue(0xA8);               //PWM3 Duty Cycle auf 66%
                            PWM4_LoadDutyValue(0xA8);               //PWM4 Duty Cycle auf 66%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 66");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_100_t;           //Duty cycle state auf 100%
                            break;
                        case DC_100_t:
                            PWM3_LoadDutyValue(0xFF);               //PWM3 Duty Cycle auf 100%
                            PWM4_LoadDutyValue(0xFF);               //PWM4 Duty Cycle auf 100%
                            LCD_Clear();
                            printf("PWM Duty\nCycle: 100");          //LCD Ausgabe
                            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
                            currentDutyCycles = DC_20_t;            //Duty cycle state auf 20%
                            break;                              
                        default:
                            break;                      
                    }
                    delay3sCounter = 0;             //Delay cntr resetten    
                }              
                if(!TASTER0 && TASTER0Flag)     //Neg. Flanke Taster 0
                {
                    testState = I2CTEST;            //Zu I2C Test wechseln
                    MDRIVER1STBY = 0;               //Motortreiber 1 deaktivieren
                    MDRIVER2STBY = 0;               //Motortreiber 2 deaktivieren
                    delay3sCounter = 0;             //Delay cntr resetten    
                }
                TASTER0Flag = TASTER0;
                break;
                
/******************************************************************************/
//Motortreiber 1 Test
                
            case MDRIVER1TEST:                
                delay3sCounter++;
                if(delay3sCounter==DELAY_3S_COUNTER_GOAL)       //3s warten
                {
                    MDRIVER1IN1 = !MDRIVER1IN1;
                    MDRIVER1IN2 = !MDRIVER1IN2;                 //Inputs invertieren (Vorwärts <-> Rückwärts)
                    LCD_Clear();
                    printf("M1IN1:%i M1IN2:%i",MDRIVER1IN1,MDRIVER1IN2); //Status IN1/IN2 auf LCD ausgeben
                    if(MDRIVER1IN1 == 1 && MDRIVER1IN2 == 0){
                        printf("\nVorwärts");
                    }
                    if(MDRIVER1IN1 == 0 && MDRIVER1IN2 == 1){
                        printf("\nRückwärts");
                    }
                    delay3sCounter = 0;                         //Delay cntr resetten                   
                }
                
                if(!TASTER1 && TASTER1Flag)     //Neg. Flanke Taster 1
                {
                    testState = I2CTEST;            //Zu I2C Test wechseln
                    MDRIVER1STBY = 0;               //Motortreiber 1 deaktivieren
                    MDRIVER2STBY = 0;               //Motortreiber 2 deaktivieren
                    delay3sCounter = 0;             //Delay cntr resetten                  
                }
                TASTER1Flag = TASTER1;  
                break;
          
/******************************************************************************/
//Motortreiber 2 Test
                
            case MDRIVER2TEST:                             
                delay3sCounter++;
                if(delay3sCounter==DELAY_3S_COUNTER_GOAL)       //3s warten
                {
                    MDRIVER2IN1 = !MDRIVER2IN1;
                    MDRIVER2IN2 = !MDRIVER2IN2;                 //Inputs invertieren (Vorwärts <-> Rückwärts)                   
                    LCD_Clear();
                    printf("M2IN1:%i M2IN2:%i",MDRIVER2IN1,MDRIVER2IN2); //Status IN1/IN2 auf LCD ausgeben
                    if(MDRIVER2IN1 == 1 && MDRIVER2IN2 == 0){
                        printf("\nVorwärts");
                    }
                    if(MDRIVER2IN1 == 0 && MDRIVER2IN2 == 1){
                        printf("\nRückwärts");
                    }
                    delay3sCounter = 0;                         //Delay cntr resetten
                }
                
                if(!TASTER2 && TASTER2Flag)     //Neg. Flanke Taster 2
                {
                    testState = I2CTEST;            //Zu I2C Test wechseln
                    MDRIVER1STBY = 0;               //Motortreiber 1 deaktivieren
                    MDRIVER2STBY = 0;               //Motortreiber 2 deaktivieren
                    delay3sCounter = 0;             //Delay cntr resetten
                }
                TASTER2Flag = TASTER2;
                break;       

/******************************************************************************/

        } 
        LOOPDELAY_Wait();           //Loopdelay Zeit abwarten (Ganz oben definiert)
    }
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
//Unterfunktionen


//Liest Daten des Distanzschallsensors
//
//param uint8_t: Rückgabe der 8bit daten
uint8_t distancesensorReadDistance(void)
{
    uint8_t upperData = 0;
    uint8_t data = 0;
    
    muxSetChannel(DISTANCESENSOR_ADDRESS);                              //Mux auf Distanzschallsensor setzen
    
    upperData = I2C1_Read1ByteRegister(DISTANCESENSOR_ADDRESS,0x5E);    //upperData auf Sensor auslesen   
    data = (upperData / 4);                                             //Berechnung Distanz 
    
    return data;
}


//Initalisiert RGB Sensoren 1-3, setzt ENABLE, ATIME und CONTROL Register
void rgbSensorInit(void)
{
    uint8_t slaveAddress;
    
    for(i=1;i<4;i++)
    {
        slaveAddress = muxSetChannel(i);            //Sensor auf Mux anwählen
        
        I2C1_Write1ByteRegister(slaveAddress,RGB_ENABLE,0b00000011);        //Interrupt Off, Wait off, RGBC + Power ON
        __delay_ms(3);       
        I2C1_Write1ByteRegister(slaveAddress,RGB_ATIME,0xFF);               //Internal Intergration time 2.4ms (min)
        I2C1_Write1ByteRegister(slaveAddress,RGB_CONTROL,0x00000011);       //Gain              
    }
}


//Liest Farbdaten von entsprechendem Sensor und gibt sie als 16Bit Wert zurück
//
//
//channel:  Welcher Sensor gelesen werden soll
//rgbColor: Welche Farbwerte gelesen werden sollen
//uin16_t:  Rückgabewert
uint8_t rgbReadColor(uint8_t channel, type_rgb_colors rgbColor)
{
    uint8_t readData;
    
    muxSetChannel(channel);
    
    switch(rgbColor)
    {
        case RGB_COLORS_CLEAR:       
            readData = I2C1_Read1ByteRegister(RGB_ADDRESS,RGB_CDATAL);
            break;
        case RGB_COLORS_RED:     
            readData = I2C1_Read1ByteRegister(RGB_ADDRESS,RGB_RDATAL);
            break;
        case RGB_COLORS_GREEN:
            readData = I2C1_Read1ByteRegister(RGB_ADDRESS,RGB_GDATAL);
            break;
        case RGB_COLORS_BLUE:
            readData = I2C1_Read1ByteRegister(RGB_ADDRESS,RGB_BDATAL);
            break;
        default:                                                //Farbwert auslesen, je nach übergebener Farbe
            break;    
    }
    return readData;
}


//Tested ob UBATLOW = 1, falls ja LCD anzeige und state-wechsel
void testUBATLOW(void)
{ 
    if(UBATLOW == 1)
    {
        testState = BATLOW;
        delay3sCounter = 0;                 //Delay counter zurücksetzen
        LCD_Clear();
        printf("Bat Low!\nBat Low!");
    }
}


//Überprüft auf pos. Flanken Taster 0-2, und setzt entsprechenden Status
void checkPosFlankButtons(void)
{
    if(testState==I2CTEST)
    {
        if(TASTER0 && !TASTER0Flag)     //Pos. Flanke Taster 0
        {
            testState = PWMTEST;
            delay3sCounter = 0;             //Delay counter zurücksetzen
            MDRIVER1STBY = 1;               //Motortreiber 1 aktivieren
            MDRIVER2STBY = 1;               //Motortreiber 2 aktivieren
            MDRIVER1IN1 = 1;
            MDRIVER1IN2 = 0;                //Motortreiber 1 Forward
            MDRIVER2IN1 = 1;
            MDRIVER2IN2 = 0;                //Motortreiber 2 Forward
            PWM3_LoadDutyValue(0x32);               //PWM3 Duty Cycle auf 20%
            PWM4_LoadDutyValue(0x32);               //PWM4 Duty Cycle auf 20%
            LCD_Clear();
            printf("PWM Duty\nCycle: 20");          //LCD Ausgabe
            LCD_SEND_DATA(0b00100101);              //'%' ausgeben
            currentDutyCycles = DC_33_t;            //Duty cycle state auf 33%
        }
        TASTER0Flag = TASTER0;

        if(TASTER1 && !TASTER1Flag)     //Pos. Flanke Taster 1
        {
            testState = MDRIVER1TEST;
            delay3sCounter = 0;                 //Delay counter zurücksetzen
            MDRIVER1STBY = 1;                   //Motortreiber 1 aktivieren
            MDRIVER2STBY = 0;                   //Motortreiber 2 deaktivieren
            MDRIVER1IN1 = 1;
            MDRIVER1IN2 = 0;                    //Motortreiber 1 Forward
            LCD_Clear();
            printf("M1IN1:%i M1IN2:%i",MDRIVER1IN1,MDRIVER1IN2); //Status IN1/IN2 auf LCD ausgeben
            if(MDRIVER1IN1 == 1 && MDRIVER1IN2 == 0){
                    printf("\nVorwärts");
                }
            if(MDRIVER1IN1 == 0 && MDRIVER1IN2 == 1){
                printf("\nRückwärts");
            }
        }
        TASTER1Flag = TASTER1;  

        if(TASTER2 && !TASTER2Flag)     //Pos. Flanke Taster 2
        {
            testState = MDRIVER2TEST;
            delay3sCounter = 0;                 //Delay counter zurücksetzen
            MDRIVER1STBY = 0;                   //Motortreiber 1 deaktivieren
            MDRIVER2STBY = 1;                   //Motortreiber 2 aktivieren
            MDRIVER2IN1 = 1;
            MDRIVER2IN2 = 0;                    //Motortreiber 2 Forward
            LCD_Clear();
            printf("M2IN1:%i M2IN2:%i",MDRIVER2IN1,MDRIVER2IN2); //Status IN1/IN2 auf LCD ausgeben
            if(MDRIVER2IN1 == 1 && MDRIVER2IN2 == 0){
                    printf("\nVorwärts");
                }
            if(MDRIVER2IN1 == 0 && MDRIVER2IN2 == 1){
                printf("\nRückwärts");
            }
        }
        TASTER2Flag = TASTER2;   
    }
}
