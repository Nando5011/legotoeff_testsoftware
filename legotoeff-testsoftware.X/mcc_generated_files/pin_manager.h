/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set MDRIVER1PWM aliases
#define MDRIVER1PWM_TRIS                 TRISAbits.TRISA0
#define MDRIVER1PWM                      LATAbits.LATA0
#define MDRIVER1PWM_PORT                 PORTAbits.RA0
#define MDRIVER1PWM_WPU                  WPUAbits.WPUA0
#define MDRIVER1PWM_OD                   ODCONAbits.ODCA0
#define MDRIVER1PWM_ANS                  ANSELAbits.ANSELA0
#define MDRIVER1PWM_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define MDRIVER1PWM_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define MDRIVER1PWM_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define MDRIVER1PWM_GetValue()           PORTAbits.RA0
#define MDRIVER1PWM_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define MDRIVER1PWM_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define MDRIVER1PWM_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define MDRIVER1PWM_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define MDRIVER1PWM_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define MDRIVER1PWM_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define MDRIVER1PWM_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define MDRIVER1PWM_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set MDRIVER1IN1 aliases
#define MDRIVER1IN1_TRIS                 TRISAbits.TRISA1
#define MDRIVER1IN1                      LATAbits.LATA1
#define MDRIVER1IN1_PORT                 PORTAbits.RA1
#define MDRIVER1IN1_WPU                  WPUAbits.WPUA1
#define MDRIVER1IN1_OD                   ODCONAbits.ODCA1
#define MDRIVER1IN1_ANS                  ANSELAbits.ANSELA1
#define MDRIVER1IN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define MDRIVER1IN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define MDRIVER1IN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define MDRIVER1IN1_GetValue()           PORTAbits.RA1
#define MDRIVER1IN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define MDRIVER1IN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define MDRIVER1IN1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define MDRIVER1IN1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define MDRIVER1IN1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define MDRIVER1IN1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define MDRIVER1IN1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define MDRIVER1IN1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set MDRIVER1IN2 aliases
#define MDRIVER1IN2_TRIS                 TRISAbits.TRISA2
#define MDRIVER1IN2                      LATAbits.LATA2
#define MDRIVER1IN2_PORT                 PORTAbits.RA2
#define MDRIVER1IN2_WPU                  WPUAbits.WPUA2
#define MDRIVER1IN2_OD                   ODCONAbits.ODCA2
#define MDRIVER1IN2_ANS                  ANSELAbits.ANSELA2
#define MDRIVER1IN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define MDRIVER1IN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define MDRIVER1IN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define MDRIVER1IN2_GetValue()           PORTAbits.RA2
#define MDRIVER1IN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define MDRIVER1IN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define MDRIVER1IN2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define MDRIVER1IN2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define MDRIVER1IN2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define MDRIVER1IN2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define MDRIVER1IN2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define MDRIVER1IN2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set MDRIVER1STBY aliases
#define MDRIVER1STBY_TRIS                 TRISAbits.TRISA3
#define MDRIVER1STBY                      LATAbits.LATA3
#define MDRIVER1STBY_PORT                 PORTAbits.RA3
#define MDRIVER1STBY_WPU                  WPUAbits.WPUA3
#define MDRIVER1STBY_OD                   ODCONAbits.ODCA3
#define MDRIVER1STBY_ANS                  ANSELAbits.ANSELA3
#define MDRIVER1STBY_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define MDRIVER1STBY_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define MDRIVER1STBY_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define MDRIVER1STBY_GetValue()           PORTAbits.RA3
#define MDRIVER1STBY_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define MDRIVER1STBY_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define MDRIVER1STBY_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define MDRIVER1STBY_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define MDRIVER1STBY_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define MDRIVER1STBY_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define MDRIVER1STBY_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define MDRIVER1STBY_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set MDRIVER2PWM aliases
#define MDRIVER2PWM_TRIS                 TRISAbits.TRISA4
#define MDRIVER2PWM                      LATAbits.LATA4
#define MDRIVER2PWM_PORT                 PORTAbits.RA4
#define MDRIVER2PWM_WPU                  WPUAbits.WPUA4
#define MDRIVER2PWM_OD                   ODCONAbits.ODCA4
#define MDRIVER2PWM_ANS                  ANSELAbits.ANSELA4
#define MDRIVER2PWM_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define MDRIVER2PWM_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define MDRIVER2PWM_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define MDRIVER2PWM_GetValue()           PORTAbits.RA4
#define MDRIVER2PWM_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define MDRIVER2PWM_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define MDRIVER2PWM_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define MDRIVER2PWM_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define MDRIVER2PWM_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define MDRIVER2PWM_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define MDRIVER2PWM_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define MDRIVER2PWM_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set MDRIVER2IN1 aliases
#define MDRIVER2IN1_TRIS                 TRISAbits.TRISA5
#define MDRIVER2IN1                      LATAbits.LATA5
#define MDRIVER2IN1_PORT                 PORTAbits.RA5
#define MDRIVER2IN1_WPU                  WPUAbits.WPUA5
#define MDRIVER2IN1_OD                   ODCONAbits.ODCA5
#define MDRIVER2IN1_ANS                  ANSELAbits.ANSELA5
#define MDRIVER2IN1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define MDRIVER2IN1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define MDRIVER2IN1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define MDRIVER2IN1_GetValue()           PORTAbits.RA5
#define MDRIVER2IN1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define MDRIVER2IN1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define MDRIVER2IN1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define MDRIVER2IN1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define MDRIVER2IN1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define MDRIVER2IN1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define MDRIVER2IN1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define MDRIVER2IN1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set MDRIVER2IN2 aliases
#define MDRIVER2IN2_TRIS                 TRISAbits.TRISA6
#define MDRIVER2IN2                      LATAbits.LATA6
#define MDRIVER2IN2_PORT                 PORTAbits.RA6
#define MDRIVER2IN2_WPU                  WPUAbits.WPUA6
#define MDRIVER2IN2_OD                   ODCONAbits.ODCA6
#define MDRIVER2IN2_ANS                  ANSELAbits.ANSELA6
#define MDRIVER2IN2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define MDRIVER2IN2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define MDRIVER2IN2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define MDRIVER2IN2_GetValue()           PORTAbits.RA6
#define MDRIVER2IN2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define MDRIVER2IN2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define MDRIVER2IN2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define MDRIVER2IN2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define MDRIVER2IN2_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define MDRIVER2IN2_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define MDRIVER2IN2_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define MDRIVER2IN2_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set MDRIVER2STBY aliases
#define MDRIVER2STBY_TRIS                 TRISAbits.TRISA7
#define MDRIVER2STBY                      LATAbits.LATA7
#define MDRIVER2STBY_PORT                 PORTAbits.RA7
#define MDRIVER2STBY_WPU                  WPUAbits.WPUA7
#define MDRIVER2STBY_OD                   ODCONAbits.ODCA7
#define MDRIVER2STBY_ANS                  ANSELAbits.ANSELA7
#define MDRIVER2STBY_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define MDRIVER2STBY_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define MDRIVER2STBY_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define MDRIVER2STBY_GetValue()           PORTAbits.RA7
#define MDRIVER2STBY_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define MDRIVER2STBY_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define MDRIVER2STBY_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define MDRIVER2STBY_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define MDRIVER2STBY_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define MDRIVER2STBY_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define MDRIVER2STBY_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define MDRIVER2STBY_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set TASTER2 aliases
#define TASTER2_TRIS                 TRISBbits.TRISB2
#define TASTER2_LAT                  LATBbits.LATB2
#define TASTER2                      PORTBbits.RB2
#define TASTER2_WPU                  WPUBbits.WPUB2
#define TASTER2_OD                   ODCONBbits.ODCB2
#define TASTER2_ANS                  ANSELBbits.ANSELB2
#define TASTER2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define TASTER2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define TASTER2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define TASTER2_GetValue()           PORTBbits.RB2
#define TASTER2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define TASTER2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define TASTER2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define TASTER2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define TASTER2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define TASTER2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define TASTER2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define TASTER2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set TASTER1 aliases
#define TASTER1_TRIS                 TRISBbits.TRISB3
#define TASTER1_LAT                  LATBbits.LATB3
#define TASTER1                      PORTBbits.RB3
#define TASTER1_WPU                  WPUBbits.WPUB3
#define TASTER1_OD                   ODCONBbits.ODCB3
#define TASTER1_ANS                  ANSELBbits.ANSELB3
#define TASTER1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define TASTER1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define TASTER1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define TASTER1_GetValue()           PORTBbits.RB3
#define TASTER1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define TASTER1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define TASTER1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define TASTER1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define TASTER1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define TASTER1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define TASTER1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define TASTER1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set TASTER0 aliases
#define TASTER0_TRIS                 TRISBbits.TRISB4
#define TASTER0_LAT                  LATBbits.LATB4
#define TASTER0                      PORTBbits.RB4
#define TASTER0_WPU                  WPUBbits.WPUB4
#define TASTER0_OD                   ODCONBbits.ODCB4
#define TASTER0_ANS                  ANSELBbits.ANSELB4
#define TASTER0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define TASTER0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define TASTER0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define TASTER0_GetValue()           PORTBbits.RB4
#define TASTER0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define TASTER0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define TASTER0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define TASTER0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define TASTER0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define TASTER0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define TASTER0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define TASTER0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LCDRESET aliases
#define LCDRESET_TRIS                 TRISCbits.TRISC2
#define LCDRESET                      LATCbits.LATC2
#define LCDRESET_PORT                 PORTCbits.RC2
#define LCDRESET_WPU                  WPUCbits.WPUC2
#define LCDRESET_OD                   ODCONCbits.ODCC2
#define LCDRESET_ANS                  ANSELCbits.ANSELC2
#define LCDRESET_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCDRESET_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCDRESET_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCDRESET_GetValue()           PORTCbits.RC2
#define LCDRESET_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCDRESET_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCDRESET_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCDRESET_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCDRESET_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCDRESET_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCDRESET_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCDRESET_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set BTRESET aliases
#define BTRESET_TRIS                 TRISCbits.TRISC3
#define BTRESET                      LATCbits.LATC3
#define BTRESET_PORT                 PORTCbits.RC3
#define BTRESET_WPU                  WPUCbits.WPUC3
#define BTRESET_OD                   ODCONCbits.ODCC3
#define BTRESET_ANS                  ANSELCbits.ANSELC3
#define BTRESET_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define BTRESET_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define BTRESET_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define BTRESET_GetValue()           PORTCbits.RC3
#define BTRESET_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define BTRESET_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define BTRESET_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define BTRESET_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define BTRESET_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define BTRESET_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define BTRESET_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define BTRESET_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set BTWAKEUP aliases
#define BTWAKEUP_TRIS                 TRISCbits.TRISC4
#define BTWAKEUP                      LATCbits.LATC4
#define BTWAKEUP_PORT                 PORTCbits.RC4
#define BTWAKEUP_WPU                  WPUCbits.WPUC4
#define BTWAKEUP_OD                   ODCONCbits.ODCC4
#define BTWAKEUP_ANS                  ANSELCbits.ANSELC4
#define BTWAKEUP_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define BTWAKEUP_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define BTWAKEUP_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BTWAKEUP_GetValue()           PORTCbits.RC4
#define BTWAKEUP_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define BTWAKEUP_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define BTWAKEUP_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define BTWAKEUP_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define BTWAKEUP_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define BTWAKEUP_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define BTWAKEUP_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define BTWAKEUP_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set UBATLOW aliases
#define UBATLOW_TRIS                 TRISCbits.TRISC5
#define UBATLOW_LAT                  LATCbits.LATC5
#define UBATLOW                      PORTCbits.RC5
#define UBATLOW_WPU                  WPUCbits.WPUC5
#define UBATLOW_OD                   ODCONCbits.ODCC5
#define UBATLOW_ANS                  ANSELCbits.ANSELC5
#define UBATLOW_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define UBATLOW_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define UBATLOW_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define UBATLOW_GetValue()           PORTCbits.RC5
#define UBATLOW_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define UBATLOW_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define UBATLOW_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define UBATLOW_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define UBATLOW_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define UBATLOW_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define UBATLOW_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define UBATLOW_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCDD0 aliases
#define LCDD0_TRIS                 TRISDbits.TRISD0
#define LCDD0                      LATDbits.LATD0
#define LCDD0_PORT                 PORTDbits.RD0
#define LCDD0_WPU                  WPUDbits.WPUD0
#define LCDD0_OD                   ODCONDbits.ODCD0
#define LCDD0_ANS                  ANSELDbits.ANSELD0
#define LCDD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCDD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCDD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCDD0_GetValue()           PORTDbits.RD0
#define LCDD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCDD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCDD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LCDD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LCDD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LCDD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LCDD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define LCDD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LCDD1 aliases
#define LCDD1_TRIS                 TRISDbits.TRISD1
#define LCDD1                      LATDbits.LATD1
#define LCDD1_PORT                 PORTDbits.RD1
#define LCDD1_WPU                  WPUDbits.WPUD1
#define LCDD1_OD                   ODCONDbits.ODCD1
#define LCDD1_ANS                  ANSELDbits.ANSELD1
#define LCDD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LCDD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LCDD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LCDD1_GetValue()           PORTDbits.RD1
#define LCDD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LCDD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LCDD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LCDD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LCDD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LCDD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LCDD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LCDD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set LCDD2 aliases
#define LCDD2_TRIS                 TRISDbits.TRISD2
#define LCDD2                      LATDbits.LATD2
#define LCDD2_PORT                 PORTDbits.RD2
#define LCDD2_WPU                  WPUDbits.WPUD2
#define LCDD2_OD                   ODCONDbits.ODCD2
#define LCDD2_ANS                  ANSELDbits.ANSELD2
#define LCDD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LCDD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LCDD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LCDD2_GetValue()           PORTDbits.RD2
#define LCDD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LCDD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LCDD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LCDD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LCDD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LCDD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LCDD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define LCDD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set LCDD3 aliases
#define LCDD3_TRIS                 TRISDbits.TRISD3
#define LCDD3                      LATDbits.LATD3
#define LCDD3_PORT                 PORTDbits.RD3
#define LCDD3_WPU                  WPUDbits.WPUD3
#define LCDD3_OD                   ODCONDbits.ODCD3
#define LCDD3_ANS                  ANSELDbits.ANSELD3
#define LCDD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LCDD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LCDD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LCDD3_GetValue()           PORTDbits.RD3
#define LCDD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LCDD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LCDD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LCDD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LCDD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define LCDD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define LCDD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define LCDD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set LCDD4 aliases
#define LCDD4_TRIS                 TRISDbits.TRISD4
#define LCDD4                      LATDbits.LATD4
#define LCDD4_PORT                 PORTDbits.RD4
#define LCDD4_WPU                  WPUDbits.WPUD4
#define LCDD4_OD                   ODCONDbits.ODCD4
#define LCDD4_ANS                  ANSELDbits.ANSELD4
#define LCDD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LCDD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LCDD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LCDD4_GetValue()           PORTDbits.RD4
#define LCDD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LCDD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LCDD4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define LCDD4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define LCDD4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define LCDD4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define LCDD4_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define LCDD4_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set LCDD5 aliases
#define LCDD5_TRIS                 TRISDbits.TRISD5
#define LCDD5                      LATDbits.LATD5
#define LCDD5_PORT                 PORTDbits.RD5
#define LCDD5_WPU                  WPUDbits.WPUD5
#define LCDD5_OD                   ODCONDbits.ODCD5
#define LCDD5_ANS                  ANSELDbits.ANSELD5
#define LCDD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LCDD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LCDD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LCDD5_GetValue()           PORTDbits.RD5
#define LCDD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LCDD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LCDD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define LCDD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define LCDD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define LCDD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define LCDD5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define LCDD5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set LCDD6 aliases
#define LCDD6_TRIS                 TRISDbits.TRISD6
#define LCDD6                      LATDbits.LATD6
#define LCDD6_PORT                 PORTDbits.RD6
#define LCDD6_WPU                  WPUDbits.WPUD6
#define LCDD6_OD                   ODCONDbits.ODCD6
#define LCDD6_ANS                  ANSELDbits.ANSELD6
#define LCDD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LCDD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define LCDD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LCDD6_GetValue()           PORTDbits.RD6
#define LCDD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LCDD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define LCDD6_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define LCDD6_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define LCDD6_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define LCDD6_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define LCDD6_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define LCDD6_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set LCDD7 aliases
#define LCDD7_TRIS                 TRISDbits.TRISD7
#define LCDD7                      LATDbits.LATD7
#define LCDD7_PORT                 PORTDbits.RD7
#define LCDD7_WPU                  WPUDbits.WPUD7
#define LCDD7_OD                   ODCONDbits.ODCD7
#define LCDD7_ANS                  ANSELDbits.ANSELD7
#define LCDD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define LCDD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define LCDD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define LCDD7_GetValue()           PORTDbits.RD7
#define LCDD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define LCDD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define LCDD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define LCDD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define LCDD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define LCDD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define LCDD7_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define LCDD7_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set LCDREADWRITE aliases
#define LCDREADWRITE_TRIS                 TRISEbits.TRISE0
#define LCDREADWRITE                      LATEbits.LATE0
#define LCDREADWRITE_PORT                 PORTEbits.RE0
#define LCDREADWRITE_WPU                  WPUEbits.WPUE0
#define LCDREADWRITE_OD                   ODCONEbits.ODCE0
#define LCDREADWRITE_ANS                  ANSELEbits.ANSELE0
#define LCDREADWRITE_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LCDREADWRITE_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LCDREADWRITE_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LCDREADWRITE_GetValue()           PORTEbits.RE0
#define LCDREADWRITE_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LCDREADWRITE_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LCDREADWRITE_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LCDREADWRITE_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LCDREADWRITE_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LCDREADWRITE_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LCDREADWRITE_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LCDREADWRITE_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set LCDENABLE aliases
#define LCDENABLE_TRIS                 TRISEbits.TRISE1
#define LCDENABLE                      LATEbits.LATE1
#define LCDENABLE_PORT                 PORTEbits.RE1
#define LCDENABLE_WPU                  WPUEbits.WPUE1
#define LCDENABLE_OD                   ODCONEbits.ODCE1
#define LCDENABLE_ANS                  ANSELEbits.ANSELE1
#define LCDENABLE_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LCDENABLE_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LCDENABLE_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LCDENABLE_GetValue()           PORTEbits.RE1
#define LCDENABLE_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LCDENABLE_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LCDENABLE_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define LCDENABLE_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define LCDENABLE_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define LCDENABLE_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define LCDENABLE_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define LCDENABLE_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set LCDREGISTERSELECT aliases
#define LCDREGISTERSELECT_TRIS                 TRISEbits.TRISE2
#define LCDREGISTERSELECT                      LATEbits.LATE2
#define LCDREGISTERSELECT_PORT                 PORTEbits.RE2
#define LCDREGISTERSELECT_WPU                  WPUEbits.WPUE2
#define LCDREGISTERSELECT_OD                   ODCONEbits.ODCE2
#define LCDREGISTERSELECT_ANS                  ANSELEbits.ANSELE2
#define LCDREGISTERSELECT_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LCDREGISTERSELECT_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LCDREGISTERSELECT_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LCDREGISTERSELECT_GetValue()           PORTEbits.RE2
#define LCDREGISTERSELECT_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LCDREGISTERSELECT_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LCDREGISTERSELECT_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LCDREGISTERSELECT_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LCDREGISTERSELECT_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define LCDREGISTERSELECT_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define LCDREGISTERSELECT_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define LCDREGISTERSELECT_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/