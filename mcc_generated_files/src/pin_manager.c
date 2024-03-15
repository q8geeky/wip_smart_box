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


#include "../include/pin_manager.h"
static void (*PORTD_SEG3F_InterruptHandler)(void);
static void (*PORTB_IO_PB3_InterruptHandler)(void);
static void (*PORTD_SEG3A_InterruptHandler)(void);
static void (*PORTB_SEG2C_InterruptHandler)(void);
static void (*PORTD_SEGCOL_InterruptHandler)(void);
static void (*PORTB_SEG3D_InterruptHandler)(void);
static void (*PORTD_SEG3G_InterruptHandler)(void);
static void (*PORTB_SEG3E_InterruptHandler)(void);
static void (*PORTE_SEG2B_InterruptHandler)(void);
static void (*PORTE_SEG2F_InterruptHandler)(void);
static void (*PORTC_SEG3C_InterruptHandler)(void);
static void (*PORTE_SEG2A_InterruptHandler)(void);
static void (*PORTC_SEG4E_InterruptHandler)(void);
static void (*PORTE_SEG2G_InterruptHandler)(void);
static void (*PORTC_IO_PC1_InterruptHandler)(void);
static void (*PORTC_SEG4C_InterruptHandler)(void);
static void (*PORTA_COM2_InterruptHandler)(void);
static void (*PORTC_SEG4D_InterruptHandler)(void);
static void (*PORTC_IO_PC6_InterruptHandler)(void);
static void (*PORTA_SEG1E_InterruptHandler)(void);
static void (*PORTC_SEG4B_InterruptHandler)(void);
static void (*PORTA_COM1_InterruptHandler)(void);
static void (*PORTA_SEG1C_InterruptHandler)(void);
static void (*PORTC_IO_PC7_InterruptHandler)(void);
static void (*PORTA_SEG1D_InterruptHandler)(void);
static void (*PORTA_IO_PA7_InterruptHandler)(void);
static void (*PORTF_PF1_InterruptHandler)(void);
static void (*PORTF_PF0_InterruptHandler)(void);
static void (*PORTF_SEG1A_InterruptHandler)(void);
static void (*PORTD_SEG4F_InterruptHandler)(void);
static void (*PORTF_SEG1B_InterruptHandler)(void);
static void (*PORTD_SEG4A_InterruptHandler)(void);
static void (*PORTF_SEG1G_InterruptHandler)(void);
static void (*PORTD_SEG3B_InterruptHandler)(void);
static void (*PORTB_SEG2D_InterruptHandler)(void);
static void (*PORTF_SEG1F_InterruptHandler)(void);
static void (*PORTD_SEG4G_InterruptHandler)(void);
static void (*PORTB_SEG2E_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0xFC;
    PORTB.DIR = 0x3F;
    PORTC.DIR = 0xBF;
    PORTD.DIR = 0xFF;
    PORTE.DIR = 0x0F;
    PORTF.DIR = 0x3C;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x00;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x00;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x00;
    PORTB.PIN2CTRL = 0x00;
    PORTB.PIN3CTRL = 0x00;
    PORTB.PIN4CTRL = 0x00;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x00;
    PORTD.PIN1CTRL = 0x00;
    PORTD.PIN2CTRL = 0x00;
    PORTD.PIN3CTRL = 0x00;
    PORTD.PIN4CTRL = 0x00;
    PORTD.PIN5CTRL = 0x00;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x00;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x00;
    PORTE.PIN2CTRL = 0x00;
    PORTE.PIN3CTRL = 0x00;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x00;
    PORTF.PIN5CTRL = 0x00;
    PORTF.PIN6CTRL = 0x00;
    PORTF.PIN7CTRL = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TWISPIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTD_SEG3F_SetInterruptHandler(PORTD_SEG3F_DefaultInterruptHandler);
    PORTB_IO_PB3_SetInterruptHandler(PORTB_IO_PB3_DefaultInterruptHandler);
    PORTD_SEG3A_SetInterruptHandler(PORTD_SEG3A_DefaultInterruptHandler);
    PORTB_SEG2C_SetInterruptHandler(PORTB_SEG2C_DefaultInterruptHandler);
    PORTD_SEGCOL_SetInterruptHandler(PORTD_SEGCOL_DefaultInterruptHandler);
    PORTB_SEG3D_SetInterruptHandler(PORTB_SEG3D_DefaultInterruptHandler);
    PORTD_SEG3G_SetInterruptHandler(PORTD_SEG3G_DefaultInterruptHandler);
    PORTB_SEG3E_SetInterruptHandler(PORTB_SEG3E_DefaultInterruptHandler);
    PORTE_SEG2B_SetInterruptHandler(PORTE_SEG2B_DefaultInterruptHandler);
    PORTE_SEG2F_SetInterruptHandler(PORTE_SEG2F_DefaultInterruptHandler);
    PORTC_SEG3C_SetInterruptHandler(PORTC_SEG3C_DefaultInterruptHandler);
    PORTE_SEG2A_SetInterruptHandler(PORTE_SEG2A_DefaultInterruptHandler);
    PORTC_SEG4E_SetInterruptHandler(PORTC_SEG4E_DefaultInterruptHandler);
    PORTE_SEG2G_SetInterruptHandler(PORTE_SEG2G_DefaultInterruptHandler);
    PORTC_IO_PC1_SetInterruptHandler(PORTC_IO_PC1_DefaultInterruptHandler);
    PORTC_SEG4C_SetInterruptHandler(PORTC_SEG4C_DefaultInterruptHandler);
    PORTA_COM2_SetInterruptHandler(PORTA_COM2_DefaultInterruptHandler);
    PORTC_SEG4D_SetInterruptHandler(PORTC_SEG4D_DefaultInterruptHandler);
    PORTC_IO_PC6_SetInterruptHandler(PORTC_IO_PC6_DefaultInterruptHandler);
    PORTA_SEG1E_SetInterruptHandler(PORTA_SEG1E_DefaultInterruptHandler);
    PORTC_SEG4B_SetInterruptHandler(PORTC_SEG4B_DefaultInterruptHandler);
    PORTA_COM1_SetInterruptHandler(PORTA_COM1_DefaultInterruptHandler);
    PORTA_SEG1C_SetInterruptHandler(PORTA_SEG1C_DefaultInterruptHandler);
    PORTC_IO_PC7_SetInterruptHandler(PORTC_IO_PC7_DefaultInterruptHandler);
    PORTA_SEG1D_SetInterruptHandler(PORTA_SEG1D_DefaultInterruptHandler);
    PORTA_IO_PA7_SetInterruptHandler(PORTA_IO_PA7_DefaultInterruptHandler);
    PORTF_PF1_SetInterruptHandler(PORTF_PF1_DefaultInterruptHandler);
    PORTF_PF0_SetInterruptHandler(PORTF_PF0_DefaultInterruptHandler);
    PORTF_SEG1A_SetInterruptHandler(PORTF_SEG1A_DefaultInterruptHandler);
    PORTD_SEG4F_SetInterruptHandler(PORTD_SEG4F_DefaultInterruptHandler);
    PORTF_SEG1B_SetInterruptHandler(PORTF_SEG1B_DefaultInterruptHandler);
    PORTD_SEG4A_SetInterruptHandler(PORTD_SEG4A_DefaultInterruptHandler);
    PORTF_SEG1G_SetInterruptHandler(PORTF_SEG1G_DefaultInterruptHandler);
    PORTD_SEG3B_SetInterruptHandler(PORTD_SEG3B_DefaultInterruptHandler);
    PORTB_SEG2D_SetInterruptHandler(PORTB_SEG2D_DefaultInterruptHandler);
    PORTF_SEG1F_SetInterruptHandler(PORTF_SEG1F_DefaultInterruptHandler);
    PORTD_SEG4G_SetInterruptHandler(PORTD_SEG4G_DefaultInterruptHandler);
    PORTB_SEG2E_SetInterruptHandler(PORTB_SEG2E_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTD_SEG3F at application runtime
*/
void PORTD_SEG3F_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG3F_InterruptHandler = interruptHandler;
}

void PORTD_SEG3F_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG3F interrupt custom code
    // or set custom function using PORTD_SEG3F_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_IO_PB3 at application runtime
*/
void PORTB_IO_PB3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_IO_PB3_InterruptHandler = interruptHandler;
}

void PORTB_IO_PB3_DefaultInterruptHandler(void)
{
    // add your PORTB_IO_PB3 interrupt custom code
    // or set custom function using PORTB_IO_PB3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG3A at application runtime
*/
void PORTD_SEG3A_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG3A_InterruptHandler = interruptHandler;
}

void PORTD_SEG3A_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG3A interrupt custom code
    // or set custom function using PORTD_SEG3A_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_SEG2C at application runtime
*/
void PORTB_SEG2C_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_SEG2C_InterruptHandler = interruptHandler;
}

void PORTB_SEG2C_DefaultInterruptHandler(void)
{
    // add your PORTB_SEG2C interrupt custom code
    // or set custom function using PORTB_SEG2C_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEGCOL at application runtime
*/
void PORTD_SEGCOL_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEGCOL_InterruptHandler = interruptHandler;
}

void PORTD_SEGCOL_DefaultInterruptHandler(void)
{
    // add your PORTD_SEGCOL interrupt custom code
    // or set custom function using PORTD_SEGCOL_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_SEG3D at application runtime
*/
void PORTB_SEG3D_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_SEG3D_InterruptHandler = interruptHandler;
}

void PORTB_SEG3D_DefaultInterruptHandler(void)
{
    // add your PORTB_SEG3D interrupt custom code
    // or set custom function using PORTB_SEG3D_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG3G at application runtime
*/
void PORTD_SEG3G_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG3G_InterruptHandler = interruptHandler;
}

void PORTD_SEG3G_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG3G interrupt custom code
    // or set custom function using PORTD_SEG3G_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_SEG3E at application runtime
*/
void PORTB_SEG3E_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_SEG3E_InterruptHandler = interruptHandler;
}

void PORTB_SEG3E_DefaultInterruptHandler(void)
{
    // add your PORTB_SEG3E interrupt custom code
    // or set custom function using PORTB_SEG3E_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_SEG2B at application runtime
*/
void PORTE_SEG2B_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_SEG2B_InterruptHandler = interruptHandler;
}

void PORTE_SEG2B_DefaultInterruptHandler(void)
{
    // add your PORTE_SEG2B interrupt custom code
    // or set custom function using PORTE_SEG2B_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_SEG2F at application runtime
*/
void PORTE_SEG2F_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_SEG2F_InterruptHandler = interruptHandler;
}

void PORTE_SEG2F_DefaultInterruptHandler(void)
{
    // add your PORTE_SEG2F interrupt custom code
    // or set custom function using PORTE_SEG2F_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SEG3C at application runtime
*/
void PORTC_SEG3C_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SEG3C_InterruptHandler = interruptHandler;
}

void PORTC_SEG3C_DefaultInterruptHandler(void)
{
    // add your PORTC_SEG3C interrupt custom code
    // or set custom function using PORTC_SEG3C_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_SEG2A at application runtime
*/
void PORTE_SEG2A_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_SEG2A_InterruptHandler = interruptHandler;
}

void PORTE_SEG2A_DefaultInterruptHandler(void)
{
    // add your PORTE_SEG2A interrupt custom code
    // or set custom function using PORTE_SEG2A_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SEG4E at application runtime
*/
void PORTC_SEG4E_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SEG4E_InterruptHandler = interruptHandler;
}

void PORTC_SEG4E_DefaultInterruptHandler(void)
{
    // add your PORTC_SEG4E interrupt custom code
    // or set custom function using PORTC_SEG4E_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_SEG2G at application runtime
*/
void PORTE_SEG2G_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_SEG2G_InterruptHandler = interruptHandler;
}

void PORTE_SEG2G_DefaultInterruptHandler(void)
{
    // add your PORTE_SEG2G interrupt custom code
    // or set custom function using PORTE_SEG2G_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC1 at application runtime
*/
void PORTC_IO_PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC1_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC1_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC1 interrupt custom code
    // or set custom function using PORTC_IO_PC1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SEG4C at application runtime
*/
void PORTC_SEG4C_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SEG4C_InterruptHandler = interruptHandler;
}

void PORTC_SEG4C_DefaultInterruptHandler(void)
{
    // add your PORTC_SEG4C interrupt custom code
    // or set custom function using PORTC_SEG4C_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_COM2 at application runtime
*/
void PORTA_COM2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_COM2_InterruptHandler = interruptHandler;
}

void PORTA_COM2_DefaultInterruptHandler(void)
{
    // add your PORTA_COM2 interrupt custom code
    // or set custom function using PORTA_COM2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SEG4D at application runtime
*/
void PORTC_SEG4D_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SEG4D_InterruptHandler = interruptHandler;
}

void PORTC_SEG4D_DefaultInterruptHandler(void)
{
    // add your PORTC_SEG4D interrupt custom code
    // or set custom function using PORTC_SEG4D_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC6 at application runtime
*/
void PORTC_IO_PC6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC6_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC6_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC6 interrupt custom code
    // or set custom function using PORTC_IO_PC6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_SEG1E at application runtime
*/
void PORTA_SEG1E_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_SEG1E_InterruptHandler = interruptHandler;
}

void PORTA_SEG1E_DefaultInterruptHandler(void)
{
    // add your PORTA_SEG1E interrupt custom code
    // or set custom function using PORTA_SEG1E_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SEG4B at application runtime
*/
void PORTC_SEG4B_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SEG4B_InterruptHandler = interruptHandler;
}

void PORTC_SEG4B_DefaultInterruptHandler(void)
{
    // add your PORTC_SEG4B interrupt custom code
    // or set custom function using PORTC_SEG4B_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_COM1 at application runtime
*/
void PORTA_COM1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_COM1_InterruptHandler = interruptHandler;
}

void PORTA_COM1_DefaultInterruptHandler(void)
{
    // add your PORTA_COM1 interrupt custom code
    // or set custom function using PORTA_COM1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_SEG1C at application runtime
*/
void PORTA_SEG1C_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_SEG1C_InterruptHandler = interruptHandler;
}

void PORTA_SEG1C_DefaultInterruptHandler(void)
{
    // add your PORTA_SEG1C interrupt custom code
    // or set custom function using PORTA_SEG1C_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC7 at application runtime
*/
void PORTC_IO_PC7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC7_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC7_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC7 interrupt custom code
    // or set custom function using PORTC_IO_PC7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_SEG1D at application runtime
*/
void PORTA_SEG1D_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_SEG1D_InterruptHandler = interruptHandler;
}

void PORTA_SEG1D_DefaultInterruptHandler(void)
{
    // add your PORTA_SEG1D interrupt custom code
    // or set custom function using PORTA_SEG1D_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_IO_PA7 at application runtime
*/
void PORTA_IO_PA7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_IO_PA7_InterruptHandler = interruptHandler;
}

void PORTA_IO_PA7_DefaultInterruptHandler(void)
{
    // add your PORTA_IO_PA7 interrupt custom code
    // or set custom function using PORTA_IO_PA7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF1 at application runtime
*/
void PORTF_PF1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF1_InterruptHandler = interruptHandler;
}

void PORTF_PF1_DefaultInterruptHandler(void)
{
    // add your PORTF_PF1 interrupt custom code
    // or set custom function using PORTF_PF1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PF0 at application runtime
*/
void PORTF_PF0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PF0_InterruptHandler = interruptHandler;
}

void PORTF_PF0_DefaultInterruptHandler(void)
{
    // add your PORTF_PF0 interrupt custom code
    // or set custom function using PORTF_PF0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_SEG1A at application runtime
*/
void PORTF_SEG1A_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_SEG1A_InterruptHandler = interruptHandler;
}

void PORTF_SEG1A_DefaultInterruptHandler(void)
{
    // add your PORTF_SEG1A interrupt custom code
    // or set custom function using PORTF_SEG1A_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG4F at application runtime
*/
void PORTD_SEG4F_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG4F_InterruptHandler = interruptHandler;
}

void PORTD_SEG4F_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG4F interrupt custom code
    // or set custom function using PORTD_SEG4F_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_SEG1B at application runtime
*/
void PORTF_SEG1B_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_SEG1B_InterruptHandler = interruptHandler;
}

void PORTF_SEG1B_DefaultInterruptHandler(void)
{
    // add your PORTF_SEG1B interrupt custom code
    // or set custom function using PORTF_SEG1B_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG4A at application runtime
*/
void PORTD_SEG4A_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG4A_InterruptHandler = interruptHandler;
}

void PORTD_SEG4A_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG4A interrupt custom code
    // or set custom function using PORTD_SEG4A_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_SEG1G at application runtime
*/
void PORTF_SEG1G_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_SEG1G_InterruptHandler = interruptHandler;
}

void PORTF_SEG1G_DefaultInterruptHandler(void)
{
    // add your PORTF_SEG1G interrupt custom code
    // or set custom function using PORTF_SEG1G_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG3B at application runtime
*/
void PORTD_SEG3B_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG3B_InterruptHandler = interruptHandler;
}

void PORTD_SEG3B_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG3B interrupt custom code
    // or set custom function using PORTD_SEG3B_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_SEG2D at application runtime
*/
void PORTB_SEG2D_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_SEG2D_InterruptHandler = interruptHandler;
}

void PORTB_SEG2D_DefaultInterruptHandler(void)
{
    // add your PORTB_SEG2D interrupt custom code
    // or set custom function using PORTB_SEG2D_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_SEG1F at application runtime
*/
void PORTF_SEG1F_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_SEG1F_InterruptHandler = interruptHandler;
}

void PORTF_SEG1F_DefaultInterruptHandler(void)
{
    // add your PORTF_SEG1F interrupt custom code
    // or set custom function using PORTF_SEG1F_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_SEG4G at application runtime
*/
void PORTD_SEG4G_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_SEG4G_InterruptHandler = interruptHandler;
}

void PORTD_SEG4G_DefaultInterruptHandler(void)
{
    // add your PORTD_SEG4G interrupt custom code
    // or set custom function using PORTD_SEG4G_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_SEG2E at application runtime
*/
void PORTB_SEG2E_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_SEG2E_InterruptHandler = interruptHandler;
}

void PORTB_SEG2E_DefaultInterruptHandler(void)
{
    // add your PORTB_SEG2E interrupt custom code
    // or set custom function using PORTB_SEG2E_SetInterruptHandler()
}
