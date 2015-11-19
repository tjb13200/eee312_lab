/**************************************************
 * LEDDriver.c
 * Drives LED display
 *
 * Copyright 2015 University of Strathclyde
 *
 *
 **************************************************/

#include "LedDriver.h"

//Current dial value
unsigned char ledValue_ = 0;

/**
Initialise LED Dial, setting GPIO parameters
*/
void initialiseLedDial()
{
  //GPIO 2.7
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN7);
    

  //GPIO 5.1, 5.2, 5.3
GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1  | GPIO_PIN2 | GPIO_PIN3);


    
  //GPIO 8.0
GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0);

}

/** 
Refresh the display
*/
void refreshLedDial()
{
  //Refresh lower bank (LEDs 1-4)
 
  if (ledValue_==1)
    
 {      
   GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
   
}__delay_cycles(10000);
  if (ledValue_==2)
  {  
   GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
 
  }__delay_cycles(10000);
if   (ledValue_==3)
{
   GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7); 
 
}__delay_cycles(10000);
if     (ledValue_==4)
{
   GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
}__delay_cycles(10000);
   //Refresh lower bank (LEDs 5-8)
  
if     (ledValue_==5)
{
   GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
}__delay_cycles(10000);

if     (ledValue_==6)
{
   GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
}__delay_cycles(10000);

if     (ledValue_==7)
{
   GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
}__delay_cycles(10000);

if     (ledValue_==8)
{
   GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
   GPIO_setOutputHighOnPin(GPIO_PORT_P5,  GPIO_PIN2);
   GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
   GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
}__delay_cycles(10000);
 
}

/** 
Set dial value
*/
void setLedDial(unsigned char value)
{
  ledValue_ = value;
}
