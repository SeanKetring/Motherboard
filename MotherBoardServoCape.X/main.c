/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC24FJ64GB202
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#include "mcc_generated_files/mcc.h"

int TimerVariable,cycles,TransmitComplete, i = 0; 
uint8_t LocalMemory[6]; 

//============================================================
//Functions 
void OneMsDelay(int); 
void StateMaker(int);
void SelectionMaker(int);

/*
                         Main application
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    TimerVariable = 0; 
    int SwitchCount = 1;
    LATAbits.LATA3 = 0; 
    OneMsDelay(50);
    LATBbits.LATB7 = 0;
    OneMsDelay(20);
    LATBbits.LATB6 = 0;
    OneMsDelay(30);
    LATBbits.LATB5 = 0;
   
    OneMsDelay(100);
    
    int Temp; 
    
    while (1) {
        // Add your application code
        
        
        if(TransmitComplete){
            TransmitComplete = 0; 
                                           
            if(LocalMemory[0]== 0x00){

            }
            else if(LocalMemory[0] != 0x00){
                
                switch(LocalMemory[0]){
                    case 1: 
                        break;
                    case 2: 
                        break;
                    case 3: 
                        break;
                    case 4: 
                        break;
                    case 5: 
                        break;
                    case 6: 
                        break;
                    case 7: 
                        break;
            }
        }
            
 
        

    }
        if(PORTAbits.RA2 == 1){
            TimerVariable = 0; 
            
            while(PORTAbits.RA2 == 1);
                Temp = TimerVariable; 
            
            if(Temp > 1000){
                SelectionMaker(SwitchCount);
            }
            else{
                SwitchCount++;
                if(SwitchCount>=5)
                    SwitchCount = 1; 
                
                StateMaker(SwitchCount); 
                
            }
            OneMsDelay(500);
        
        }
        LATBbits.LATB7 = 1; 
        OneMsDelay(50);
        LATBbits.LATB7 = 0;
        OneMsDelay(10);
  }
 return -1;
}

//End of Main
//=============================================================================
//State Maker and Command Selector functions

void StateMaker(int SwitchCount){
    
    switch(SwitchCount){
        case 1:  LATBbits.LATB6 = 0; 
                 OneMsDelay(1);
                 LATBbits.LATB5 = 0;
                 break;
        case 2:  LATBbits.LATB6 = 1;
                 OneMsDelay(1);
                 LATBbits.LATB5 = 0;
                 break;
        case 3:  LATBbits.LATB6 = 0;
                 OneMsDelay(1);
                 LATBbits.LATB5 = 1;
                 break;
        case 4:  LATBbits.LATB6 = 1;
                 OneMsDelay(1);
                 LATBbits.LATB5 = 1;
                 break;        
    }
    
}

void SelectionMaker(int SwitchCount){
    
    
}

//=============================================================================
//Timer Functions

void OneMsDelay(cycles){
    TimerVariable = 0;
    
    while(TimerVariable <= cycles){
        ;
    }
    
}

//=============================================================================

/**
 End of File
 */