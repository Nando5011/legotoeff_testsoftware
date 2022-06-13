/**
 * @addtogroup PBA_LCD
 * @{
 *******************************************************************************
 * @file            PBA_driver_lcd.h
 * @brief           LCD-Library für das PBA6
 * @author          ICT Berufsbildungscenter AG
 *******************************************************************************
 *
 * @copyright
 * @{
 *
 * Diese Software kann unter den Bedingungen der MIT-Lizenz verwendet werden.
 *
 * Copyright &copy; 2016 ICT Berufsbildungscenter AG
 *
 * #####MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @}
 */


#include <stdint.h>
#include <xc.h>
#include "legotoeff_helpers.h"

#define _XTAL_FREQ 64000000
/*Display-Pins*/

/**
 * @name Display Pins
 * Zuordnung der Pins zur Ansteuerung des LCD
 * @{
 */

#define LCDD0                      LATDbits.LATD0
#define LCDD1                      LATDbits.LATD1
#define LCDD2                      LATDbits.LATD2
#define LCDD3                      LATDbits.LATD3
#define LCDD4                      LATDbits.LATD4
#define LCDD5                      LATDbits.LATD5
#define LCDD6                      LATDbits.LATD6
#define LCDD7                      LATDbits.LATD7
#define LCDENABLE                  LATEbits.LATE1
#define LCDREGISTERSELECT          LATEbits.LATE2
#define LCDREADWRITE               LATEbits.LATE0
#define LCDRESET                   LATCbits.LATC2


/**
 * @}
 */

/*Defines für Curson-Funktion (dispcurs(mode);)*/
/**
 * @name Cursor Modi
 * Defintion der verschiedenen Cursor-Modi
 * @see lcd_curs
 * @{
 */
#define CURSOR_ON           0x06
#define CURSOR_OFF          0x04
#define CURSOR_OFF_BLINK    0x05
#define CURSOR_ON_BLINK     0x07
/**
 * @}
 */


/**
 * @brief Senden eines Befehls ans LCD
 */
#define LCD_SEND_COMMAND(Command)   LCD_SendByte(Command)

/**
 * @brief Senden eines Datenbytes (Zeichen) ans LCD
 */
#define LCD_SEND_DATA(value)        LCDREGISTERSELECT=1;LCD_SendByte(value);LCDREGISTERSELECT=0

void LCD_SendNibble(uint8_t value);

void LCD_SendByte(uint8_t value);

void LCD_Clear(void);

void LCD_Home(void);

void LCD_ShiftLeft(uint8_t numPos);

void LCD_ShiftRight(uint8_t numPos);

void LCD_GotoXY(uint8_t posX, uint8_t posY);

void LCD_Putc(uint8_t ch);

void LCD_Puts(uint8_t *p_string);

void LCD_PutsRom(const uint8_t *p_romString);

void LCD_SetCursorMode(uint8_t cursorMode);

void LCD_Init(void);

/**
 * @}
 */


