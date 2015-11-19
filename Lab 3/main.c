/**************************************************
 * EE312 Lab 2
 *
 * Copyright 2015 University of Strathclyde
 *
 *
 **************************************************/
#include <msp430.h>
#include <driverlib.h>
#include "LedDriver.h"

int main(void)
{
  //Default MCLK = 1MHz
  
  unsigned int i = 0;
  unsigned char dialValue = 0x00;
  unsigned char buttonValue;
  unsigned char dialDirection = 0x00;
  WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

  initialiseLedDial();
  
  //switch
   GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN3);
   
  // Disable the GPIO power-on default high-impedance mode
  // to activate previously configured port settings
  PMM_unlockLPM5();

  while(1)
  {buttonValue =  GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN3);
       if (!buttonValue)  
       {
         dialDirection ^=0x01;
       }
       
       if (dialDirection == 0x00)
       {
       
      dialValue = dialValue + 0x01;
      
      if(0x09 == dialValue)
         dialValue = 0x01;
       }
       
      if (dialDirection == 0x01)
       {

        dialValue = dialValue - 0x01;
      
      if(0x00 == dialValue)
         dialValue = 0x08;
      }
    //Set value
    setLedDial(dialValue);
    
    //Refresh display (10 times for each position)
    for(i = 0; i < 10; i++)
      refreshLedDial();

  }
  }
  
