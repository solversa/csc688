/*
 * LaunchPadModule.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Saminda
 */

#include "LaunchPadModule.h"
#if defined(ENERGIA)
#include "Wire.h"
#endif

void LaunchPadModule::init()
{
#if defined(ENERGIA)
  // Serial port
  Serial.begin(115200); //9600
  // LED
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  // Buttons
  pinMode(PUSH1, INPUT_PULLUP);// left - note _PULLUP
  pinMode(PUSH2, INPUT_PULLUP);// right - note _PULLUP
  // I2C
  Wire.begin();
#endif
}

void LaunchPadModule::update(LaunchPadRepresentation& theLaunchPadRepresentation)
{
  theLaunchPadRepresentation.serialActive = true;
  theLaunchPadRepresentation.redLEDActive = true;
  theLaunchPadRepresentation.greenLEDActive = true;
  theLaunchPadRepresentation.blueLEDActive = true;
  theLaunchPadRepresentation.push1Active = true;
  theLaunchPadRepresentation.push2Active = true;
  theLaunchPadRepresentation.wireActive = true;
}

MAKE_MODULE(LaunchPadModule)

