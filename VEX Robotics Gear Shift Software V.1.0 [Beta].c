#pragma config(Sensor, dgtl1,  powerButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  gearShift,      sensorTouch)
#pragma config(Sensor, dgtl3,  gearoneSensor,  sensorTouch)
#pragma config(Sensor, dgtl4,  geartwoSensor,  sensorTouch)
#pragma config(Motor,  port2,           mainMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           gearshiftMotor, tmotorVex393_MC29, openLoop)
/*VEX ROBOTICS 2 SPEED GEAR SHIFT SOFTWARE version 1.0 [Testing Copy]

DEVELOPER: Austin A. Daigle
DATE WRITTEN AND TESTED: 3-12-2017

NOTES: This program does not have the any analytics features for diagnosing, repairing, or reporting problems
via a LED function. The program assumes that the gear is alway set to gear one upon start up, thus care should
always be taken to set the gear before the microcontroller is initialed or restarted. */

//Global Variables
int powerbuttonStatus = 0;
int powerbuttonDisable = 0;
int powertoggle = 0;
int previousmainmotorState = 0;
int gearshiftStatus = 0;
int gearshiftDisable = 0;
int gear = 1;

//Reset to prior motor state Function
void returnmotorpriorState()
{
	if(previousmainmotorState == 0)
	{
		stopMotor(mainMotor);
	}
	else
	{
		startMotor(mainMotor, 127);
	}
}

//Gear changing Function
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
	returnmotorpriorState();
}

//Gear variable button changer
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

//Gear shift button variable enable
void gearshiftClear()
{
	if(SensorValue(gearShift) == 0)
	{
		gearshiftDisable = 0;
	}
}

//Power button enable
void powerbuttonClear()
{
	if(SensorValue(powerButton) == 0)
	{
		powerbuttonDisable = 0;
	}
}

//Power toggle Variable reset
void powerstat()
{
	if(powertoggle > 1)
	{
		powertoggle = 0;
	}
}

//Activate the gear shift (button) function
void gearshiftFunction()
{
	if(SensorValue(gearShift) == 1 && gearshiftDisable == 0)
	{
		gearshiftStatus = 1;
	}
	if(gearshiftStatus > 0)
	{
		gearvarChange();
		wait1Msec(100);
		gearshiftStatus = 0;
		gearshiftDisable = 1;
	}
	else
	{
		stopMotor(gearshiftMotor);
	}
	gearshiftClear();
}

//Activate the power button function
void powerbuttonFunction()
{
	if(SensorValue(powerButton) == 1 && powerbuttonDisable == 0)
	{
		powerbuttonStatus = 1;
	}
	if(powerbuttonStatus > 0)
	{
		wait1Msec(250);
		powertoggle = powertoggle + 1;
		powerstat();
		powerbuttonStatus = 0;
		powerbuttonDisable = 1;
		if(powertoggle == 0)
		{
			previousmainmotorState = 0;
			stopMotor(mainMotor);
		}
		else
		{
			previousmainmotorState = 1;
			startMotor(mainMotor,127);
		}
	}
	powerbuttonClear();
}

//Core Execution Script
task main()
{
	powerstat();
	while(true)
	{
		powerbuttonFunction();
		gearshiftFunction();
	}
}
