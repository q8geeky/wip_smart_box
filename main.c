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
    
#include "mcc_generated_files/mcc.h"
#include <util/atomic.h>
#include <stdint.h>
    
/* ISR-shared time digits. Each digit is one AVR-atomic byte. */
volatile uint8_t pit_ticks = 0;
volatile uint8_t second = 0;
volatile uint8_t minute1 = 0, minute2 = 0;
volatile uint8_t hour1 = 0, hour2 = 0;

void display_control(unsigned int h1, unsigned int h2, unsigned int m1, unsigned int m2);
void digit1(unsigned int nmbr);
void digit2(unsigned int nmbr);
void digit3(unsigned int nmbr);
void digit4(unsigned int nmbr);

/* The PIT is configured for 512 RTC cycles (RTC.PITCTRLA=0x41).
 * At a 32.768 kHz RTC clock this is 64 interrupts per second.
 * Confirm the board's clock source and oscillator enablement before flashing.
 */
#define PIT_CALLBACKS_PER_SECOND 64u

void RTC_PITInterrupt(void)
{
    if(IO_PC6_GetValue() == 0)
    {
        if (++pit_ticks < PIT_CALLBACKS_PER_SECOND)
        {
            return;
        }
        pit_ticks = 0;
        second++;
        if(second == 60)
        {
            minute1++;
            second = 0;
            if(minute1 == 10)
            {
                minute2++;
                minute1 = 0;
            }
        }

        if(minute2 == 6 && minute1 == 0)
        {
            hour1++;
            minute2 = 0;
            if(hour1 == 10)
            {
                hour2++;
                hour1 = 0;
            }
        }
    }else
    {
        pit_ticks = 0;
        second = 0;
        minute1 = 0;
        minute2 = 0;
        hour1 = 0;
        hour2 = 0;
    }
    
}
int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    /* Register the application callback used by the MCC RTC ISR. */
    RTC_SetPITIsrCallback(RTC_PITInterrupt);

    /* Replace with your application code */
    while (1)
    {
        /* Read the ISR-updated 4-digit counter as one consistent snapshot. */
        uint8_t h1, h2, m1, m2;
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            h1 = hour1;
            h2 = hour2;
            m1 = minute1;
            m2 = minute2;
        }
        display_control(h1, h2, m1, m2);
    }
}


void display_control(unsigned int h1, unsigned int h2, unsigned int m1, unsigned int m2)
{
    COM1_SetLow();
    COM2_SetLow();
    
    digit4(m1);
    digit3(m2);
    digit2(h1);
    digit1(h2);
    
    
}

void digit1(unsigned int nmbr){
    
    switch(nmbr)
    {
        case 0:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1E_SetHigh();
            SEG1F_SetHigh();
            
            SEG1G_SetLow();
            break;
        
        case 1:
            SEG1B_SetHigh();
            SEG1C_SetHigh();
            
            SEG1G_SetLow();
            SEG1A_SetLow();
            SEG1F_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            break;
            
        case 2:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1E_SetHigh();
            SEG1D_SetHigh();
            
            SEG1F_SetLow();
            SEG1C_SetLow();   
            break;
            
        case 3:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            
            SEG1F_SetLow();
            SEG1E_SetLow();
            break;
            
        case 4:
            SEG1F_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            
            SEG1A_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            break;
            
        case 5:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            
            SEG1B_SetLow();
            SEG1E_SetLow();
            break;
            
        case 6:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1E_SetHigh();
            
            SEG1B_SetLow();
            break;
            
        case 7:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1C_SetHigh();
            
            SEG1F_SetLow();
            SEG1G_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            break;
            
        case 8:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1E_SetHigh();
            SEG1B_SetHigh();
            break;
            
        case 9:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1B_SetHigh();
            
            SEG1E_SetLow();
            break;

    }
}

void digit2(unsigned int nmbr){
    
    switch(nmbr)
    {
        case 0:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2E_SetHigh();
            SEG2F_SetHigh();
            
            SEG2G_SetLow();
            break;
        
        case 1:
            SEG2B_SetHigh();
            SEG2C_SetHigh();
            
            SEG2G_SetLow();
            SEG2A_SetLow();
            SEG2F_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            break;
            
        case 2:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2E_SetHigh();
            SEG2D_SetHigh();
            
            SEG2F_SetLow();
            SEG2C_SetLow();   
            break;
            
        case 3:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            
            SEG2F_SetLow();
            SEG2E_SetLow();
            break;
            
        case 4:
            SEG2F_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            
            SEG2A_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            break;
            
        case 5:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            
            SEG2B_SetLow();
            SEG2E_SetLow();
            break;
            
        case 6:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2E_SetHigh();
            
            SEG2B_SetLow();
            break;
            
        case 7:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2C_SetHigh();
            
            SEG2F_SetLow();
            SEG2G_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            break;
            
        case 8:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2E_SetHigh();
            SEG2B_SetHigh();
            break;
            
        case 9:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2B_SetHigh();
            
            SEG2E_SetLow();
            break;

    }
}

void digit3(unsigned int nmbr){
    
    switch(nmbr)
    {
        case 0:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3E_SetHigh();
            SEG3F_SetHigh();
            
            SEG3G_SetLow();
            break;
        
        case 1:
            SEG3B_SetHigh();
            SEG3C_SetHigh();
            
            SEG3G_SetLow();
            SEG3A_SetLow();
            SEG3F_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            break;
            
        case 2:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3E_SetHigh();
            SEG3D_SetHigh();
            
            SEG3F_SetLow();
            SEG3C_SetLow();   
            break;
            
        case 3:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            
            SEG3F_SetLow();
            SEG3E_SetLow();
            break;
            
        case 4:
            SEG3F_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            
            SEG3A_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            break;
            
        case 5:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            
            SEG3B_SetLow();
            SEG3E_SetLow();
            break;
            
        case 6:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3E_SetHigh();
            
            SEG3B_SetLow();
            break;
            
        case 7:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3C_SetHigh();
            
            SEG3F_SetLow();
            SEG3G_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            break;
            
        case 8:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3E_SetHigh();
            SEG3B_SetHigh();
            break;
            
        case 9:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3B_SetHigh();
            
            SEG3E_SetLow();
            break;

    }
}

void digit4(unsigned int nmbr){
    
    switch(nmbr)
    {
        case 0:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4E_SetHigh();
            SEG4F_SetHigh();
            
            SEG4G_SetLow();
            break;
        
        case 1:
            SEG4B_SetHigh();
            SEG4C_SetHigh();
            
            SEG4G_SetLow();
            SEG4A_SetLow();
            SEG4F_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            break;
            
        case 2:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4E_SetHigh();
            SEG4D_SetHigh();
            
            SEG4F_SetLow();
            SEG4C_SetLow();   
            break;
            
        case 3:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            
            SEG4F_SetLow();
            SEG4E_SetLow();
            break;
            
        case 4:
            SEG4F_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            
            SEG4A_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            break;
            
        case 5:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            
            SEG4B_SetLow();
            SEG4E_SetLow();
            break;
            
        case 6:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4E_SetHigh();
            
            SEG4B_SetLow();
            break;
            
        case 7:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4C_SetHigh();
            
            SEG4F_SetLow();
            SEG4G_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            break;
            
        case 8:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4E_SetHigh();
            SEG4B_SetHigh();
            break;
            
        case 9:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4B_SetHigh();
            
            SEG4E_SetLow();
            break;

    }
}
/**
    End of File
*/
