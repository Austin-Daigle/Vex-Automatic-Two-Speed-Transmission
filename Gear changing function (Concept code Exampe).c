#pragma config(Sensor, dgtl1,  powerButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  gearShift,      sensorTouch)
#pragma config(Sensor, dgtl3,  gearoneSensor,  sensorTouch)
#pragma config(Sensor, dgtl4,  geartwoSensor,  sensorTouch)
#pragma config(Sensor, dgtl9,  gearvarFlash,   sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, gearIndicator,  sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, powervarFlash,  sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, powerIndicator, sensorLEDtoVCC)
#pragma config(Motor,  port2, mainMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3, gearshiftMotor, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
/*program is meant to demostate a shifting concept for a VEX gear shift, this is a experimental
and has missing features and/or bugs*/



//Gear Shift button Variables
int gearshiftStatus = 0;
int gearshiftDisable = 0;
int gear = 1;

void shiftgear()
{
while(gear == 1 && (SensorValue(gearoneSensor) == 0))
{
startMotor(mainMotor, 127);
startMotor(gearshiftMotor, 35);
wait(0.5);
stopMotor(mainMotor);

stopMotor(gearshiftMotor);
}
while(gear == 2 && (SensorValue(geartwoSensor) == 0))
{
startMotor(mainMotor, 127);
startMotor(gearshiftMotor, -35);
wait(0.5);
}
}


/*
void shiftgear()
{
if(gear == 1)
	{
if(SensorValue(gearoneSensor) == 0)
	{
startMotor(gearshiftMotor, 127);
startMotor(mainMotor, 127);
	}
if(gear == 2)
		{
if(SensorValue(geartwoSensor) == 0)
			{
			startMotor(gearshiftMotor, -127);
			startMotor(mainMotor, 127);
			}
}
}
stopMotor(mainMotor);
}
*/



void gearvarChange()
{
if(gear == 1)
	{
	gear = 2;
	}
else
	{
		if(gear == 2)
		{
		gear = 1;
		}
	}
shiftgear();
}

//Gear shift enable
void gearshiftClear()
{
if(SensorValue(gearShift) == 0)
{
gearshiftDisable = 0;
}
}
//Reset all LED's prior to program execution
void cleanLeds()
{
turnLEDOff(gearvarFlash);
turnLEDOff(gearIndicator);
turnLEDOff(powervarFlash);
turnLEDOff(powerIndicator);
}

//Activate the gear shift function
void gearshiftFunction()
{
if(SensorValue(gearShift) == 1 && gearshiftDisable == 0)
{
		gearshiftStatus = 1;
		}
if(gearshiftStatus > 0)
		{
		turnLEDOn(gearvarFlash);
		gearvarChange();
		wait1Msec(100);
		gearshiftStatus = 0;
		gearshiftDisable = 1;
		}
	else
		{
		stopMotor(gearshiftMotor);
		turnLEDOff(gearvarFlash);
		}
		gearshiftClear();
		}

task main()
{
cleanLeds();
while(true)
{
gearshiftFunction();

}
}
