/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set SEG3F aliases
#define SEG3F_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define SEG3F_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define SEG3F_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define SEG3F_GetValue() (VPORTD.IN & (0x1 << 5))
#define SEG3F_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define SEG3F_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define SEG3F_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3F_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3F_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3F_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3F_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3F_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3F_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3F_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3F_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3F_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PB3 aliases
#define IO_PB3_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define IO_PB3_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define IO_PB3_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define IO_PB3_GetValue() (VPORTB.IN & (0x1 << 3))
#define IO_PB3_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define IO_PB3_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define IO_PB3_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB3_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB3_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB3_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB3_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB3_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB3_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB3_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB3_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB3_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3A aliases
#define SEG3A_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define SEG3A_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define SEG3A_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define SEG3A_GetValue() (VPORTD.IN & (0x1 << 4))
#define SEG3A_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define SEG3A_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define SEG3A_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3A_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3A_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3A_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3A_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3A_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3A_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3A_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3A_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3A_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2C aliases
#define SEG2C_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define SEG2C_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define SEG2C_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define SEG2C_GetValue() (VPORTB.IN & (0x1 << 2))
#define SEG2C_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define SEG2C_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define SEG2C_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2C_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2C_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2C_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2C_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2C_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2C_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2C_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2C_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2C_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEGCOL aliases
#define SEGCOL_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define SEGCOL_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define SEGCOL_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define SEGCOL_GetValue() (VPORTD.IN & (0x1 << 7))
#define SEGCOL_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define SEGCOL_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define SEGCOL_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEGCOL_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEGCOL_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define SEGCOL_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEGCOL_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEGCOL_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEGCOL_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEGCOL_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEGCOL_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEGCOL_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3D aliases
#define SEG3D_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define SEG3D_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define SEG3D_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define SEG3D_GetValue() (VPORTB.IN & (0x1 << 5))
#define SEG3D_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define SEG3D_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define SEG3D_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3D_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3D_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3D_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3D_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3D_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3D_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3D_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3D_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3D_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3G aliases
#define SEG3G_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define SEG3G_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define SEG3G_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define SEG3G_GetValue() (VPORTD.IN & (0x1 << 6))
#define SEG3G_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define SEG3G_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define SEG3G_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3G_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3G_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3G_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3G_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3G_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3G_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3G_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3G_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3G_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3E aliases
#define SEG3E_SetHigh() do { PORTB_OUTSET = 0x10; } while(0)
#define SEG3E_SetLow() do { PORTB_OUTCLR = 0x10; } while(0)
#define SEG3E_Toggle() do { PORTB_OUTTGL = 0x10; } while(0)
#define SEG3E_GetValue() (VPORTB.IN & (0x1 << 4))
#define SEG3E_SetDigitalInput() do { PORTB_DIRCLR = 0x10; } while(0)
#define SEG3E_SetDigitalOutput() do { PORTB_DIRSET = 0x10; } while(0)
#define SEG3E_SetPullUp() do { PORTB_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3E_ResetPullUp() do { PORTB_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3E_SetInverted() do { PORTB_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3E_ResetInverted() do { PORTB_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3E_DisableInterruptOnChange() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3E_EnableInterruptForBothEdges() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3E_EnableInterruptForRisingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3E_EnableInterruptForFallingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3E_DisableDigitalInputBuffer() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3E_EnableInterruptForLowLevelSensing() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2B aliases
#define SEG2B_SetHigh() do { PORTE_OUTSET = 0x1; } while(0)
#define SEG2B_SetLow() do { PORTE_OUTCLR = 0x1; } while(0)
#define SEG2B_Toggle() do { PORTE_OUTTGL = 0x1; } while(0)
#define SEG2B_GetValue() (VPORTE.IN & (0x1 << 0))
#define SEG2B_SetDigitalInput() do { PORTE_DIRCLR = 0x1; } while(0)
#define SEG2B_SetDigitalOutput() do { PORTE_DIRSET = 0x1; } while(0)
#define SEG2B_SetPullUp() do { PORTE_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2B_ResetPullUp() do { PORTE_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2B_SetInverted() do { PORTE_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2B_ResetInverted() do { PORTE_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2B_DisableInterruptOnChange() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2B_EnableInterruptForBothEdges() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2B_EnableInterruptForRisingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2B_EnableInterruptForFallingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2B_DisableDigitalInputBuffer() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2B_EnableInterruptForLowLevelSensing() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2F aliases
#define SEG2F_SetHigh() do { PORTE_OUTSET = 0x4; } while(0)
#define SEG2F_SetLow() do { PORTE_OUTCLR = 0x4; } while(0)
#define SEG2F_Toggle() do { PORTE_OUTTGL = 0x4; } while(0)
#define SEG2F_GetValue() (VPORTE.IN & (0x1 << 2))
#define SEG2F_SetDigitalInput() do { PORTE_DIRCLR = 0x4; } while(0)
#define SEG2F_SetDigitalOutput() do { PORTE_DIRSET = 0x4; } while(0)
#define SEG2F_SetPullUp() do { PORTE_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2F_ResetPullUp() do { PORTE_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2F_SetInverted() do { PORTE_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2F_ResetInverted() do { PORTE_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2F_DisableInterruptOnChange() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2F_EnableInterruptForBothEdges() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2F_EnableInterruptForRisingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2F_EnableInterruptForFallingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2F_DisableDigitalInputBuffer() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2F_EnableInterruptForLowLevelSensing() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3C aliases
#define SEG3C_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define SEG3C_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define SEG3C_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define SEG3C_GetValue() (VPORTC.IN & (0x1 << 0))
#define SEG3C_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define SEG3C_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define SEG3C_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3C_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3C_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3C_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3C_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3C_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3C_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3C_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3C_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3C_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2A aliases
#define SEG2A_SetHigh() do { PORTE_OUTSET = 0x2; } while(0)
#define SEG2A_SetLow() do { PORTE_OUTCLR = 0x2; } while(0)
#define SEG2A_Toggle() do { PORTE_OUTTGL = 0x2; } while(0)
#define SEG2A_GetValue() (VPORTE.IN & (0x1 << 1))
#define SEG2A_SetDigitalInput() do { PORTE_DIRCLR = 0x2; } while(0)
#define SEG2A_SetDigitalOutput() do { PORTE_DIRSET = 0x2; } while(0)
#define SEG2A_SetPullUp() do { PORTE_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2A_ResetPullUp() do { PORTE_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2A_SetInverted() do { PORTE_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2A_ResetInverted() do { PORTE_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2A_DisableInterruptOnChange() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2A_EnableInterruptForBothEdges() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2A_EnableInterruptForRisingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2A_EnableInterruptForFallingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2A_DisableDigitalInputBuffer() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2A_EnableInterruptForLowLevelSensing() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4E aliases
#define SEG4E_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define SEG4E_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define SEG4E_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define SEG4E_GetValue() (VPORTC.IN & (0x1 << 2))
#define SEG4E_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define SEG4E_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define SEG4E_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4E_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4E_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4E_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4E_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4E_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4E_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4E_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4E_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4E_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2G aliases
#define SEG2G_SetHigh() do { PORTE_OUTSET = 0x8; } while(0)
#define SEG2G_SetLow() do { PORTE_OUTCLR = 0x8; } while(0)
#define SEG2G_Toggle() do { PORTE_OUTTGL = 0x8; } while(0)
#define SEG2G_GetValue() (VPORTE.IN & (0x1 << 3))
#define SEG2G_SetDigitalInput() do { PORTE_DIRCLR = 0x8; } while(0)
#define SEG2G_SetDigitalOutput() do { PORTE_DIRSET = 0x8; } while(0)
#define SEG2G_SetPullUp() do { PORTE_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2G_ResetPullUp() do { PORTE_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2G_SetInverted() do { PORTE_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2G_ResetInverted() do { PORTE_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2G_DisableInterruptOnChange() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2G_EnableInterruptForBothEdges() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2G_EnableInterruptForRisingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2G_EnableInterruptForFallingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2G_DisableDigitalInputBuffer() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2G_EnableInterruptForLowLevelSensing() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC1 aliases
#define IO_PC1_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define IO_PC1_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define IO_PC1_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define IO_PC1_GetValue() (VPORTC.IN & (0x1 << 1))
#define IO_PC1_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define IO_PC1_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define IO_PC1_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC1_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC1_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC1_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC1_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC1_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC1_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC1_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC1_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC1_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4C aliases
#define SEG4C_SetHigh() do { PORTC_OUTSET = 0x10; } while(0)
#define SEG4C_SetLow() do { PORTC_OUTCLR = 0x10; } while(0)
#define SEG4C_Toggle() do { PORTC_OUTTGL = 0x10; } while(0)
#define SEG4C_GetValue() (VPORTC.IN & (0x1 << 4))
#define SEG4C_SetDigitalInput() do { PORTC_DIRCLR = 0x10; } while(0)
#define SEG4C_SetDigitalOutput() do { PORTC_DIRSET = 0x10; } while(0)
#define SEG4C_SetPullUp() do { PORTC_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4C_ResetPullUp() do { PORTC_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4C_SetInverted() do { PORTC_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4C_ResetInverted() do { PORTC_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4C_DisableInterruptOnChange() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4C_EnableInterruptForBothEdges() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4C_EnableInterruptForRisingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4C_EnableInterruptForFallingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4C_DisableDigitalInputBuffer() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4C_EnableInterruptForLowLevelSensing() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set COM2 aliases
#define COM2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define COM2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define COM2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define COM2_GetValue() (VPORTA.IN & (0x1 << 2))
#define COM2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define COM2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define COM2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define COM2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define COM2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define COM2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define COM2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define COM2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define COM2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define COM2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define COM2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define COM2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4D aliases
#define SEG4D_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define SEG4D_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define SEG4D_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define SEG4D_GetValue() (VPORTC.IN & (0x1 << 3))
#define SEG4D_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define SEG4D_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define SEG4D_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4D_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4D_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4D_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4D_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4D_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4D_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4D_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4D_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4D_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC6 aliases
#define IO_PC6_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define IO_PC6_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define IO_PC6_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define IO_PC6_GetValue() (VPORTC.IN & (0x1 << 6))
#define IO_PC6_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define IO_PC6_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define IO_PC6_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC6_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC6_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC6_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC6_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC6_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC6_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC6_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC6_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC6_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1E aliases
#define SEG1E_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define SEG1E_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define SEG1E_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define SEG1E_GetValue() (VPORTA.IN & (0x1 << 4))
#define SEG1E_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define SEG1E_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define SEG1E_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1E_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1E_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1E_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1E_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1E_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1E_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1E_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1E_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1E_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4B aliases
#define SEG4B_SetHigh() do { PORTC_OUTSET = 0x20; } while(0)
#define SEG4B_SetLow() do { PORTC_OUTCLR = 0x20; } while(0)
#define SEG4B_Toggle() do { PORTC_OUTTGL = 0x20; } while(0)
#define SEG4B_GetValue() (VPORTC.IN & (0x1 << 5))
#define SEG4B_SetDigitalInput() do { PORTC_DIRCLR = 0x20; } while(0)
#define SEG4B_SetDigitalOutput() do { PORTC_DIRSET = 0x20; } while(0)
#define SEG4B_SetPullUp() do { PORTC_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4B_ResetPullUp() do { PORTC_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4B_SetInverted() do { PORTC_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4B_ResetInverted() do { PORTC_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4B_DisableInterruptOnChange() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4B_EnableInterruptForBothEdges() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4B_EnableInterruptForRisingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4B_EnableInterruptForFallingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4B_DisableDigitalInputBuffer() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4B_EnableInterruptForLowLevelSensing() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set COM1 aliases
#define COM1_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define COM1_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define COM1_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define COM1_GetValue() (VPORTA.IN & (0x1 << 3))
#define COM1_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define COM1_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define COM1_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define COM1_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define COM1_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define COM1_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define COM1_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define COM1_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define COM1_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define COM1_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define COM1_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define COM1_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1C aliases
#define SEG1C_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define SEG1C_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define SEG1C_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define SEG1C_GetValue() (VPORTA.IN & (0x1 << 6))
#define SEG1C_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define SEG1C_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define SEG1C_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1C_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1C_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1C_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1C_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1C_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1C_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1C_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1C_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1C_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC7 aliases
#define IO_PC7_SetHigh() do { PORTC_OUTSET = 0x80; } while(0)
#define IO_PC7_SetLow() do { PORTC_OUTCLR = 0x80; } while(0)
#define IO_PC7_Toggle() do { PORTC_OUTTGL = 0x80; } while(0)
#define IO_PC7_GetValue() (VPORTC.IN & (0x1 << 7))
#define IO_PC7_SetDigitalInput() do { PORTC_DIRCLR = 0x80; } while(0)
#define IO_PC7_SetDigitalOutput() do { PORTC_DIRSET = 0x80; } while(0)
#define IO_PC7_SetPullUp() do { PORTC_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC7_ResetPullUp() do { PORTC_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC7_SetInverted() do { PORTC_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC7_ResetInverted() do { PORTC_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC7_DisableInterruptOnChange() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC7_EnableInterruptForBothEdges() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC7_EnableInterruptForRisingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC7_EnableInterruptForFallingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC7_DisableDigitalInputBuffer() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC7_EnableInterruptForLowLevelSensing() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1D aliases
#define SEG1D_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define SEG1D_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define SEG1D_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define SEG1D_GetValue() (VPORTA.IN & (0x1 << 5))
#define SEG1D_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define SEG1D_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define SEG1D_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1D_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1D_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1D_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1D_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1D_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1D_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1D_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1D_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1D_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PA7 aliases
#define IO_PA7_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define IO_PA7_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define IO_PA7_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define IO_PA7_GetValue() (VPORTA.IN & (0x1 << 7))
#define IO_PA7_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define IO_PA7_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define IO_PA7_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PA7_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PA7_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PA7_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PA7_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PA7_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PA7_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PA7_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF1 aliases
#define PF1_SetHigh() do { PORTF_OUTSET = 0x2; } while(0)
#define PF1_SetLow() do { PORTF_OUTCLR = 0x2; } while(0)
#define PF1_Toggle() do { PORTF_OUTTGL = 0x2; } while(0)
#define PF1_GetValue() (VPORTF.IN & (0x1 << 1))
#define PF1_SetDigitalInput() do { PORTF_DIRCLR = 0x2; } while(0)
#define PF1_SetDigitalOutput() do { PORTF_DIRSET = 0x2; } while(0)
#define PF1_SetPullUp() do { PORTF_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF1_ResetPullUp() do { PORTF_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF1_SetInverted() do { PORTF_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PF1_ResetInverted() do { PORTF_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF1_DisableInterruptOnChange() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF1_EnableInterruptForBothEdges() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF1_EnableInterruptForRisingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF1_EnableInterruptForFallingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF1_DisableDigitalInputBuffer() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF1_EnableInterruptForLowLevelSensing() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PF0 aliases
#define PF0_SetHigh() do { PORTF_OUTSET = 0x1; } while(0)
#define PF0_SetLow() do { PORTF_OUTCLR = 0x1; } while(0)
#define PF0_Toggle() do { PORTF_OUTTGL = 0x1; } while(0)
#define PF0_GetValue() (VPORTF.IN & (0x1 << 0))
#define PF0_SetDigitalInput() do { PORTF_DIRCLR = 0x1; } while(0)
#define PF0_SetDigitalOutput() do { PORTF_DIRSET = 0x1; } while(0)
#define PF0_SetPullUp() do { PORTF_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PF0_ResetPullUp() do { PORTF_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PF0_SetInverted() do { PORTF_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PF0_ResetInverted() do { PORTF_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PF0_DisableInterruptOnChange() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PF0_EnableInterruptForBothEdges() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PF0_EnableInterruptForRisingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PF0_EnableInterruptForFallingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PF0_DisableDigitalInputBuffer() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PF0_EnableInterruptForLowLevelSensing() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1A aliases
#define SEG1A_SetHigh() do { PORTF_OUTSET = 0x8; } while(0)
#define SEG1A_SetLow() do { PORTF_OUTCLR = 0x8; } while(0)
#define SEG1A_Toggle() do { PORTF_OUTTGL = 0x8; } while(0)
#define SEG1A_GetValue() (VPORTF.IN & (0x1 << 3))
#define SEG1A_SetDigitalInput() do { PORTF_DIRCLR = 0x8; } while(0)
#define SEG1A_SetDigitalOutput() do { PORTF_DIRSET = 0x8; } while(0)
#define SEG1A_SetPullUp() do { PORTF_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1A_ResetPullUp() do { PORTF_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1A_SetInverted() do { PORTF_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1A_ResetInverted() do { PORTF_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1A_DisableInterruptOnChange() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1A_EnableInterruptForBothEdges() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1A_EnableInterruptForRisingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1A_EnableInterruptForFallingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1A_DisableDigitalInputBuffer() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1A_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4F aliases
#define SEG4F_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define SEG4F_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define SEG4F_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define SEG4F_GetValue() (VPORTD.IN & (0x1 << 1))
#define SEG4F_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define SEG4F_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define SEG4F_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4F_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4F_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4F_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4F_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4F_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4F_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4F_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4F_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4F_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1B aliases
#define SEG1B_SetHigh() do { PORTF_OUTSET = 0x4; } while(0)
#define SEG1B_SetLow() do { PORTF_OUTCLR = 0x4; } while(0)
#define SEG1B_Toggle() do { PORTF_OUTTGL = 0x4; } while(0)
#define SEG1B_GetValue() (VPORTF.IN & (0x1 << 2))
#define SEG1B_SetDigitalInput() do { PORTF_DIRCLR = 0x4; } while(0)
#define SEG1B_SetDigitalOutput() do { PORTF_DIRSET = 0x4; } while(0)
#define SEG1B_SetPullUp() do { PORTF_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1B_ResetPullUp() do { PORTF_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1B_SetInverted() do { PORTF_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1B_ResetInverted() do { PORTF_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1B_DisableInterruptOnChange() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1B_EnableInterruptForBothEdges() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1B_EnableInterruptForRisingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1B_EnableInterruptForFallingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1B_DisableDigitalInputBuffer() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1B_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4A aliases
#define SEG4A_SetHigh() do { PORTD_OUTSET = 0x1; } while(0)
#define SEG4A_SetLow() do { PORTD_OUTCLR = 0x1; } while(0)
#define SEG4A_Toggle() do { PORTD_OUTTGL = 0x1; } while(0)
#define SEG4A_GetValue() (VPORTD.IN & (0x1 << 0))
#define SEG4A_SetDigitalInput() do { PORTD_DIRCLR = 0x1; } while(0)
#define SEG4A_SetDigitalOutput() do { PORTD_DIRSET = 0x1; } while(0)
#define SEG4A_SetPullUp() do { PORTD_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4A_ResetPullUp() do { PORTD_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4A_SetInverted() do { PORTD_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4A_ResetInverted() do { PORTD_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4A_DisableInterruptOnChange() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4A_EnableInterruptForBothEdges() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4A_EnableInterruptForRisingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4A_EnableInterruptForFallingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4A_DisableDigitalInputBuffer() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4A_EnableInterruptForLowLevelSensing() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1G aliases
#define SEG1G_SetHigh() do { PORTF_OUTSET = 0x20; } while(0)
#define SEG1G_SetLow() do { PORTF_OUTCLR = 0x20; } while(0)
#define SEG1G_Toggle() do { PORTF_OUTTGL = 0x20; } while(0)
#define SEG1G_GetValue() (VPORTF.IN & (0x1 << 5))
#define SEG1G_SetDigitalInput() do { PORTF_DIRCLR = 0x20; } while(0)
#define SEG1G_SetDigitalOutput() do { PORTF_DIRSET = 0x20; } while(0)
#define SEG1G_SetPullUp() do { PORTF_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1G_ResetPullUp() do { PORTF_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1G_SetInverted() do { PORTF_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1G_ResetInverted() do { PORTF_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1G_DisableInterruptOnChange() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1G_EnableInterruptForBothEdges() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1G_EnableInterruptForRisingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1G_EnableInterruptForFallingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1G_DisableDigitalInputBuffer() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1G_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG3B aliases
#define SEG3B_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define SEG3B_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define SEG3B_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define SEG3B_GetValue() (VPORTD.IN & (0x1 << 3))
#define SEG3B_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define SEG3B_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define SEG3B_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG3B_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG3B_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG3B_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG3B_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG3B_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG3B_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG3B_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG3B_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG3B_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2D aliases
#define SEG2D_SetHigh() do { PORTB_OUTSET = 0x2; } while(0)
#define SEG2D_SetLow() do { PORTB_OUTCLR = 0x2; } while(0)
#define SEG2D_Toggle() do { PORTB_OUTTGL = 0x2; } while(0)
#define SEG2D_GetValue() (VPORTB.IN & (0x1 << 1))
#define SEG2D_SetDigitalInput() do { PORTB_DIRCLR = 0x2; } while(0)
#define SEG2D_SetDigitalOutput() do { PORTB_DIRSET = 0x2; } while(0)
#define SEG2D_SetPullUp() do { PORTB_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2D_ResetPullUp() do { PORTB_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2D_SetInverted() do { PORTB_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2D_ResetInverted() do { PORTB_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2D_DisableInterruptOnChange() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2D_EnableInterruptForBothEdges() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2D_EnableInterruptForRisingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2D_EnableInterruptForFallingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2D_DisableDigitalInputBuffer() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2D_EnableInterruptForLowLevelSensing() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG1F aliases
#define SEG1F_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define SEG1F_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define SEG1F_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define SEG1F_GetValue() (VPORTF.IN & (0x1 << 4))
#define SEG1F_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define SEG1F_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define SEG1F_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG1F_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG1F_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG1F_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG1F_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG1F_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG1F_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG1F_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG1F_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG1F_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG4G aliases
#define SEG4G_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define SEG4G_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define SEG4G_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define SEG4G_GetValue() (VPORTD.IN & (0x1 << 2))
#define SEG4G_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define SEG4G_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define SEG4G_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG4G_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG4G_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG4G_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG4G_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG4G_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG4G_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG4G_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG4G_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG4G_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set SEG2E aliases
#define SEG2E_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define SEG2E_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define SEG2E_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define SEG2E_GetValue() (VPORTB.IN & (0x1 << 0))
#define SEG2E_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define SEG2E_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define SEG2E_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define SEG2E_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define SEG2E_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define SEG2E_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define SEG2E_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define SEG2E_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define SEG2E_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define SEG2E_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define SEG2E_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define SEG2E_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTD_SEG3F_DefaultInterruptHandler(void);
void PORTD_SEG3F_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_IO_PB3_DefaultInterruptHandler(void);
void PORTB_IO_PB3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG3A_DefaultInterruptHandler(void);
void PORTD_SEG3A_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_SEG2C_DefaultInterruptHandler(void);
void PORTB_SEG2C_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEGCOL_DefaultInterruptHandler(void);
void PORTD_SEGCOL_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_SEG3D_DefaultInterruptHandler(void);
void PORTB_SEG3D_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG3G_DefaultInterruptHandler(void);
void PORTD_SEG3G_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_SEG3E_DefaultInterruptHandler(void);
void PORTB_SEG3E_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_SEG2B_DefaultInterruptHandler(void);
void PORTE_SEG2B_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_SEG2F_DefaultInterruptHandler(void);
void PORTE_SEG2F_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_SEG3C_DefaultInterruptHandler(void);
void PORTC_SEG3C_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_SEG2A_DefaultInterruptHandler(void);
void PORTE_SEG2A_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_SEG4E_DefaultInterruptHandler(void);
void PORTC_SEG4E_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_SEG2G_DefaultInterruptHandler(void);
void PORTE_SEG2G_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC1_DefaultInterruptHandler(void);
void PORTC_IO_PC1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_SEG4C_DefaultInterruptHandler(void);
void PORTC_SEG4C_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_COM2_DefaultInterruptHandler(void);
void PORTA_COM2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_SEG4D_DefaultInterruptHandler(void);
void PORTC_SEG4D_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC6_DefaultInterruptHandler(void);
void PORTC_IO_PC6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_SEG1E_DefaultInterruptHandler(void);
void PORTA_SEG1E_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_SEG4B_DefaultInterruptHandler(void);
void PORTC_SEG4B_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_COM1_DefaultInterruptHandler(void);
void PORTA_COM1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_SEG1C_DefaultInterruptHandler(void);
void PORTA_SEG1C_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC7_DefaultInterruptHandler(void);
void PORTC_IO_PC7_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_SEG1D_DefaultInterruptHandler(void);
void PORTA_SEG1D_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_IO_PA7_DefaultInterruptHandler(void);
void PORTA_IO_PA7_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF1_DefaultInterruptHandler(void);
void PORTF_PF1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PF0_DefaultInterruptHandler(void);
void PORTF_PF0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_SEG1A_DefaultInterruptHandler(void);
void PORTF_SEG1A_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG4F_DefaultInterruptHandler(void);
void PORTD_SEG4F_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_SEG1B_DefaultInterruptHandler(void);
void PORTF_SEG1B_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG4A_DefaultInterruptHandler(void);
void PORTD_SEG4A_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_SEG1G_DefaultInterruptHandler(void);
void PORTF_SEG1G_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG3B_DefaultInterruptHandler(void);
void PORTD_SEG3B_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_SEG2D_DefaultInterruptHandler(void);
void PORTB_SEG2D_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_SEG1F_DefaultInterruptHandler(void);
void PORTF_SEG1F_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_SEG4G_DefaultInterruptHandler(void);
void PORTD_SEG4G_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_SEG2E_DefaultInterruptHandler(void);
void PORTB_SEG2E_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
