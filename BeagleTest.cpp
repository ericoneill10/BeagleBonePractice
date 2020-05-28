//============================================================================
// Name        : BeagleTest.cpp
// Author      : eric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<unistd.h> //for usleep

#include"GPIO.h"
using namespace std;
using namespace exploringBB;

int main() {
	cout << "GPIO Test Code" << endl; // prints !!!Hello World!!!


   GPIO outGPIO1(60), outGPIO2(48), outGPIO3(49), outGPIO4(117);

   // Basic Output - Flash the LED 10 times, once per second
   outGPIO1.setDirection(OUTPUT);
   outGPIO2.setDirection(OUTPUT);
   outGPIO3.setDirection(OUTPUT);
   outGPIO4.setDirection(OUTPUT);
   for (int i=0; i<10; i++){
	  outGPIO1.setValue(HIGH);
	  outGPIO2.setValue(HIGH);
	  outGPIO3.setValue(HIGH);
	  outGPIO4.setValue(HIGH);
	  usleep(500000); //micro-second sleep 0.5 seconds
	  outGPIO1.setValue(LOW);
	  outGPIO2.setValue(LOW);
	  outGPIO3.setValue(LOW);
	  outGPIO4.setValue(LOW);
	  usleep(500000);
   }

	return 0;
}
