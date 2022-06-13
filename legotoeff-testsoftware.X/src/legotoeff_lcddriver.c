/**
 * @defgroup PBA_LCD
 * @{
 *******************************************************************************
 * @file            PBA_driver_lcd.c
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
#include "../inc/legotoeff_lcddriver.h"



static uint8_t LCD_GetSpecChar(uint8_t ch);





/**
 * 
 * @brief Sendet ein Nibble ans LCD. Verwendung solange LCD noch nicht initialisiert.
 *
 * @param value Zu übertragendes Datennibble. Lower Nibble wird verwendet
 */
void LCD_SendByte(uint8_t value)
{
    LCDENABLE=1;                    /*Pos. Flanke am Enable-Pin*/
    LATD = value;
    __delay_us(5);
    LCDENABLE=0;                       //Neg. Flanke EN-Pin (daten schicken)
    __delay_us(30);                    /*Maximaler Zeitbedarf einer Übertragung (blocking)*/
 }

/**
 * @brief Display löschen.
 * Das gesamte LCD-Daten-RAM wird mit 0x20 (Leerschlag) überschrieben
 * Da der Vorgang bis zu 2ms dauern kann muss der Programmablauf nach dem Senden des
 * Befehls entsprechend lang blockiert werden (delay).
 */

void LCD_Clear(void)
{
    LCD_SEND_COMMAND(0b00000001);               /*clear display*/
    DelayUS(1100);                              /*max. Zeitbedarf des LCD-Clear-Befehls*/
}

/**
 * @brief Rurücksetzen Anzeigeberich und Cursor.
 * Display-RAM zurückschieben (Ausgangsposition). Die Funktion setzt den Anzeigebereich
 * des LCDs und den Cursor zurück auf die Anfangsposition (Adresse 0).
 */
void LCD_Home(void)
 {
    LCD_SEND_COMMAND(0b00000010);               /*return home*/
    DelayMS(2);
 }

/**
 * @brief Display-RAM im Anzeigebereich nach links schieben.
 *
 * @param numPos        Anzahl Verschiebungsschritte des Display-RAMs
 */
void LCD_ShiftLeft(uint8_t numPos)
{
    for(;numPos!=0;numPos--)
        LCD_SEND_COMMAND(0b00011000);           /*display shift left*/
}

/**
 * @brief Display-RAM im Anzeigebereich nach rechts schieben.
 *
 * @param numPos        Anzahl Verschiebungsschritte des Display-RAMs
 */
void LCD_ShiftRight(uint8_t numPos)
{
    for(;numPos!=0;numPos--)
        LCD_SEND_COMMAND(0b00011100);           /*display shift right */
}

/**
 * @brief Setzt die Cursor-Position für ein 2 Zeilen-Display.
 *
 * @param posX      X-Koordinate (0-15) resp. Spalte auf die der Cursor gesetzt werden soll
 * @param posY      Y-Koordinate (0-1) resp. Zeile auf die der Cursor gesetzt werden soll
 */
void LCD_GotoXY(uint8_t posX, uint8_t posY)
{
    uint8_t dispAddress;
    if(0 == posY) dispAddress = 0x00;                       /*Basisadresse 1. Zeile*/
    if(1 == posY) dispAddress = 0x40;                       /*Basisadresse 2. Zeile*/
    dispAddress += posX;                                    /*Basisadresse + Spaltenadresse*/
    LCD_SEND_COMMAND((0b10000000 | dispAddress));           /*Cursor-Adresse an LCD senden*/
}

/**
 * @brief Umschreiben der Umlaute für japanischen Zeichensatz.
 * Zeichen im erweiterten Zeichensatz (ä,ö,ü) für den japanischen Zeichensatz ermitteln. Falls
 * Das übergebene Zeichen kein Umlaut ist wird das Originalzeichen zurück gegeben ansonsten
 * der für den dog-m-Zeichensatz korrekte Zeichenwert.
 *
 * @param ch        Zeichen das geprüft und falls Umlaut korrigiert werden soll
 * @return          Originalzeichen oder gemäss dog-m-Zeichensatz korrigiertes Zeichen
 */
static uint8_t LCD_GetSpecChar(uint8_t ch)
{
    switch (ch)
    {
        case 0xE4: return 0x84;     /*'ä'*/
        case 0xC4: return 0x8E;     /*'Ä'*/
        case 0xF6: return 0x94;     /*'ö'*/
        case 0xD6: return 0x99;     /*'Ö'*/
        case 0xFC: return 0x81;     /*'ü'*/
        case 0xDC: return 0x9A;     /*'Ü'*/
        default:  return ch;
    }
}

/**
 * @brief Ein Zeichen an das LCD senden (inkl. Sonderzeichenbearbeitung).
 *
 * @param ch        Zeichen das ans LCD gesendet werden soll
 */

void putch(char c)
{
    LCD_Putc(c);
}

void LCD_Putc(uint8_t ch)
{
    switch (ch)
    {
        case '\r':                              /*Wenn Zeilenumbruch oder Zeilenvorschub...*/
        case '\n': LCD_GotoXY(0,1); break;      /*-> Cursor auf 1. Zeichen, 2. Zeile*/
        case '\f': LCD_Clear(); break;          /*Wenn form feed -> LCD löschen*/
        default:
            LCD_SEND_DATA(LCD_GetSpecChar(ch)); /*Zeichen an LCD senden*/
    }
}

/**
 * @brief String an LCD ausgeben mit Verwendung der lcd_putc-Funktion.
 *
 * @param *p_string     Zeiger auf den String mit Null-Terminierung
 */
void LCD_Puts(uint8_t *p_string)
{
    while(*p_string!=0)                             /*Solange Nullterminierung noch nicht erreicht*/
        LCD_Putc(*p_string++);                      /*Zeichen an LCD senden und Pointer auf nächstes Zeichen*/
}

    /**
 * @brief ROM-String an LCD ausgeben mit Verwendung der lcd_putc-Funktion.
 *
 * @param *p_romString      Zeiger auf den String mit Null-Terminierung
 */
void LCD_PutsRom(const uint8_t *p_romString)
{
    while(*p_romString!=0)                          /*Solange Nullterminierung noch nicht erreicht*/
        LCD_Putc(*p_romString++);                   /*Zeichen an LCD senden und Pointer auf nächstes Zeichen*/
}

/**
 * @brief Cursor oder blinkender Cursor ein-/ausschalten.
 *
 * @param cursorMode    Der einzustellende Cursor-Modus (CURSOR_ON, CURSOR_OFF, CURSOR_OFF_BLINK oder CURSOR_ON_BLINK)
 */
void LCD_SetCursorMode(uint8_t cursorMode)
{
    LCD_SEND_COMMAND(0b00001000|cursorMode);        /*Cursor-Wert an LCD senden*/
}

/**
 * @brief Initialisiert das dog-m-Text-LCD.
 *
 * Initialiert LCD mit 4-Bit-Modus, Cursor increment, Cursor off, Blink off,
 * Einstellungen des Boost-Converters, ...)
 *
 * Das LCD wird nach dem Initialisierungsvorgang zusätzlich gelöscht.
 * Diese Funktion sollte in einem Projekt nur einmal ausgeführt werden.
 */
void LCD_Init(void)
{        
    LCDRESET = 1;                       /*Reset aus*/
    LCDREGISTERSELECT=0;                //Write Instruction
    LCDREADWRITE=0;
    __delay_ms(40);                     //40ms VDD stable for Init
    LCD_SendByte(0x39);                 //8 bit data length, 2 line, instruction table 1
    LCD_SendByte(0x14);                 //BS: 1/5, 1 line LCD     
    LCD_SendByte(0x55);                 //booster on, contrast C5, set C4
    LCD_SendByte(0x6D);                 //set voltage follower and gain
    LCD_SendByte(0x7C);                 //set contrast C3, C2, C1
    LCD_SendByte(0x38);                 //switch back to instruction table 0
    LCD_SendByte(0x0C);                 //display on, cursor off
    LCD_SendByte(0x01);                 //delete display, cursor at home
    LCD_SendByte(0x06);                 //cursor auto-increment
}

/**
 * @}
 */
