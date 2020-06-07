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
#include "ADXL345.h"

#include "I2CDevice.h"
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

void testADXL()
{
	cout << "beginning ADXL Test" << endl;
	ADXL345 sensor(2,0x53);
	sensor.setResolution(ADXL345::NORMAL);
	sensor.setRange(ADXL345::PLUSMINUS_4_G);
//	sensor.readSensorState();
	sensor.displayPitchAndRoll();
	cout <<"end ADCXL test" << endl;
}

void testGPIOout()
{
	GPIO outGPIO1(60), outGPIO2(48), outGPIO3(49), outGPIO4(20);
   int analog0;
   cout << "GPIO Test Code" << endl;
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
	usleep(50);

   }

	  //cout << "Analog Output: " << analog0 << endl;

	cout << "End GPIO Test Code" << endl;

}



int main() {
	cout << "Test BeagleBone Black Capabilities" << endl;
	//testGPIOout();
	testADXL();
	cout << "End Test" << endl;
	return 0;
}
