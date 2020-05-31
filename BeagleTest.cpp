//============================================================================
// Name        : BeagleTest.cpp
// Author      : eric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<sstream>
#include<unistd.h> //for usleep

#include "GPIO.h"
using namespace std;
using namespace exploringBB;


#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

int readAnalog(int number){
   stringstream ss;
   ss << LDR_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int main() {
	cout << "GPIO Test Code" << endl;


   GPIO outGPIO1(60), outGPIO2(48), outGPIO3(49), outGPIO4(20);
   int analog0;
   // Basic Output - Flash the LED 10 times, once per second
   outGPIO1.setDirection(OUTPUT);
   outGPIO2.setDirection(OUTPUT);
   outGPIO3.setDirection(OUTPUT);
   outGPIO4.setDirection(OUTPUT);
   for (int i=0; i<100000; i++){
	   analog0 = readAnalog(0);
	  outGPIO1.setValue(LOW);
	  outGPIO2.setValue(LOW);
	  outGPIO3.setValue(LOW);
	  outGPIO4.setValue(LOW);

	  if(analog0 < 1000)
	  {
		  outGPIO1.setValue(HIGH);
	  }
	  else if(analog0 < 2000)
	  {
		  outGPIO2.setValue(HIGH);
	  }
	  else if(analog0 < 3000)
	  {
		  outGPIO3.setValue(HIGH);
	  }
	  else
	  {
		  outGPIO4.setValue(HIGH);
	  }



	  //cout << "Analog Output: " << analog0 << endl;

	  usleep(50);

   }

   cout << "End GPIO Test Code" << endl;

	return 0;
}
