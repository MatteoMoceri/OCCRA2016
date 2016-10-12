#pragma config(Sensor, in1,    armPot,         sensorPotentiometer)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           frontRightMotor, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           backLeftMotor, tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           backRightMotor, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           liftMotor,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

	//Potentiometer Constants
	//int armAngle = SensorValue[armPot];


	//Deadzone contants
	int thresholdpos = 20;
	int chan1 = vexRT(Ch1);
	int chan2 = vexRT(Ch2);
	int chan3 = vexRT(Ch3);
	int chan4  = vexRT(Ch4);

	//Ch1 deadzone
	if(abs(vexRT[Ch1]) > thresholdpos)
		chan1 = vexRT(Ch1);
	else
		chan1 = 0;

	//Ch2 deadzone
	if(abs(vexRT[Ch2])> thresholdpos)
		chan2 = vexRT(Ch2);
	else
		chan2 = 0;


	//Ch3 deadzone
	if(abs(vexRT[Ch3])> thresholdpos)
		chan3 = vexRT(Ch3);
	else
		chan3 = 0;


	//Ch4 deadzone
	if(abs(vexRT[Ch4])> thresholdpos)
		chan4 = vexRT(Ch4);
	else
		chan4 = 0;

	//Basic and Crab Drive


	while (true){
		//Robot movement
		motor[frontRightMotor] = vexRT[Ch4] - vexRT[Ch1] - vexRT[Ch3];
		motor[backRightMotor] =  vexRT[Ch4] + vexRT[Ch1] + vexRT[Ch3];
		motor[frontLeftMotor] = vexRT[Ch4] - vexRT[Ch1] + vexRT[Ch3];
		motor[backLeftMotor] =  vexRT[Ch4] + vexRT[Ch1] - vexRT[Ch3];

		//Arm lifter
		motor[liftMotor] = vexRT[Ch2Xmtr2];

	}
/**
	// Arm Potentiometer Control
	while(true){
		if(armAngle >= 0)
			motor[liftMotor] = 0;
	}

	if(Btn8UXmtr2)
		motor[liftMotor] = 63.5;
	repeatUntil(armAngle >= 0)

	if(Btn8DXmtr2)
		motor[liftMotor] = -63.5;
	repeatUntil(armAngle >= 0);
}
**/
}
