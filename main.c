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
    
unsigned int second = 0;
unsigned int minute1, minute2 = 0;
unsigned int hour1, hour2 = 0;

void RTC_PITInterrupt(void)
{
    if(IO_PC6_GetValue() == 0)
    {
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

    /* Replace with your application code */
    while (1)
    {
        display_control(hour1, hour2, minute1, minute2);
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
        
        case 1:
            SEG1B_SetHigh();
            SEG1C_SetHigh();
            
            SEG1G_SetLow();
            SEG1A_SetLow();
            SEG1F_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            
        case 2:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1E_SetHigh();
            SEG1D_SetHigh();
            
            SEG1F_SetLow();
            SEG1C_SetLow();   
            
        case 3:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            
            SEG1F_SetLow();
            SEG1E_SetLow();
            
        case 4:
            SEG1F_SetHigh();
            SEG1B_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            
            SEG1A_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            
        case 5:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            
            SEG1B_SetLow();
            SEG1E_SetLow();
            
        case 6:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1E_SetHigh();
            
            SEG1B_SetLow();
            
        case 7:
            SEG1A_SetHigh();
            SEG1B_SetHigh();
            SEG1C_SetHigh();
            
            SEG1F_SetLow();
            SEG1G_SetLow();
            SEG1E_SetLow();
            SEG1D_SetLow();
            
        case 8:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1E_SetHigh();
            SEG1B_SetHigh();
            
        case 9:
            SEG1A_SetHigh();
            SEG1F_SetHigh();
            SEG1G_SetHigh();
            SEG1C_SetHigh();
            SEG1D_SetHigh();
            SEG1B_SetHigh();
            
            SEG1E_SetLow();
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
        
        case 1:
            SEG2B_SetHigh();
            SEG2C_SetHigh();
            
            SEG2G_SetLow();
            SEG2A_SetLow();
            SEG2F_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            
        case 2:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2E_SetHigh();
            SEG2D_SetHigh();
            
            SEG2F_SetLow();
            SEG2C_SetLow();   
            
        case 3:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            
            SEG2F_SetLow();
            SEG2E_SetLow();
            
        case 4:
            SEG2F_SetHigh();
            SEG2B_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            
            SEG2A_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            
        case 5:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            
            SEG2B_SetLow();
            SEG2E_SetLow();
            
        case 6:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2E_SetHigh();
            
            SEG2B_SetLow();
            
        case 7:
            SEG2A_SetHigh();
            SEG2B_SetHigh();
            SEG2C_SetHigh();
            
            SEG2F_SetLow();
            SEG2G_SetLow();
            SEG2E_SetLow();
            SEG2D_SetLow();
            
        case 8:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2E_SetHigh();
            SEG2B_SetHigh();
            
        case 9:
            SEG2A_SetHigh();
            SEG2F_SetHigh();
            SEG2G_SetHigh();
            SEG2C_SetHigh();
            SEG2D_SetHigh();
            SEG2B_SetHigh();
            
            SEG2E_SetLow();
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
        
        case 1:
            SEG3B_SetHigh();
            SEG3C_SetHigh();
            
            SEG3G_SetLow();
            SEG3A_SetLow();
            SEG3F_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            
        case 2:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3E_SetHigh();
            SEG3D_SetHigh();
            
            SEG3F_SetLow();
            SEG3C_SetLow();   
            
        case 3:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            
            SEG3F_SetLow();
            SEG3E_SetLow();
            
        case 4:
            SEG3F_SetHigh();
            SEG3B_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            
            SEG3A_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            
        case 5:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            
            SEG3B_SetLow();
            SEG3E_SetLow();
            
        case 6:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3E_SetHigh();
            
            SEG3B_SetLow();
            
        case 7:
            SEG3A_SetHigh();
            SEG3B_SetHigh();
            SEG3C_SetHigh();
            
            SEG3F_SetLow();
            SEG3G_SetLow();
            SEG3E_SetLow();
            SEG3D_SetLow();
            
        case 8:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3E_SetHigh();
            SEG3B_SetHigh();
            
        case 9:
            SEG3A_SetHigh();
            SEG3F_SetHigh();
            SEG3G_SetHigh();
            SEG3C_SetHigh();
            SEG3D_SetHigh();
            SEG3B_SetHigh();
            
            SEG3E_SetLow();
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
        
        case 1:
            SEG4B_SetHigh();
            SEG4C_SetHigh();
            
            SEG4G_SetLow();
            SEG4A_SetLow();
            SEG4F_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            
        case 2:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4E_SetHigh();
            SEG4D_SetHigh();
            
            SEG4F_SetLow();
            SEG4C_SetLow();   
            
        case 3:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            
            SEG4F_SetLow();
            SEG4E_SetLow();
            
        case 4:
            SEG4F_SetHigh();
            SEG4B_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            
            SEG4A_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            
        case 5:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            
            SEG4B_SetLow();
            SEG4E_SetLow();
            
        case 6:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4E_SetHigh();
            
            SEG4B_SetLow();
            
        case 7:
            SEG4A_SetHigh();
            SEG4B_SetHigh();
            SEG4C_SetHigh();
            
            SEG4F_SetLow();
            SEG4G_SetLow();
            SEG4E_SetLow();
            SEG4D_SetLow();
            
        case 8:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4E_SetHigh();
            SEG4B_SetHigh();
            
        case 9:
            SEG4A_SetHigh();
            SEG4F_SetHigh();
            SEG4G_SetHigh();
            SEG4C_SetHigh();
            SEG4D_SetHigh();
            SEG4B_SetHigh();
            
            SEG4E_SetLow();
    }
}
/**
    End of File
*/
