#include "vex.h"

bool enableDrivePD = false;
bool resetDriveSensors = false;
bool isRunning = true;
double kP = 80;
double kD = 250;

double turnkP = 0.16;
double turnkD = 0.15;

double cL = 1.00;
double cT = 1.00;
int count = 0;
int countDeriv = 0;

double error;
double prevError = 0;
double derivative;

double turnError;
double turnPrevError = 0;
double turnDerivative;

double desiredTarget = 0;
double desiredTurnValue = 270;
double maxSpeedDrive = 6;
double maxSpeedTurn = 9;

int drivePD() {
  while(1) {
    while(enableDrivePD) {
      if(resetDriveSensors) {
        rightDt.resetRotation();
        leftDt.resetRotation();
        resetDriveSensors = false;
      }

      double leftMotorRotation = leftDtBack.rotation(rev);
      double rightMotorRotation = rightDtBack.rotation(rev);
      double averageRotation = (leftMotorRotation + rightMotorRotation) / 2;

      error = desiredTarget - averageRotation;
      derivative = error - prevError;

      double lateralMotorPower = (kP*error) + (kD*derivative);
      ///////////////////////
      ///////////////////////
      turnError = desiredTurnValue - iSensor.rotation(deg);
      turnDerivative = turnError - turnPrevError;

      double turnMotorPower = (turnkP*turnError) + (turnkD*turnDerivative);
      ///////////////////////
      ///////////////////////
      // cout << "averageRotation: " << averageRotation << endl;
      // cout << "error: " << error << endl;
      // cout << "derivative: " << derivative << endl;
      // cout << "motorPower: " << lateralMotorPower << endl;
      // cout << "iSensor: " << iSensor.rotation(deg) << endl;
      // cout << "turnError: " << turnError << endl;
      // cout << "turnDerivative: " << turnDerivative << endl;
      // cout << "turnPower: " << turnMotorPower << endl;
      // cout << "////" << endl;
      ///////////////////////
      ///////////////////////
      if(lateralMotorPower > maxSpeedDrive) {
        lateralMotorPower = maxSpeedDrive;
      } else if(lateralMotorPower < -maxSpeedDrive) {
        lateralMotorPower = -maxSpeedDrive;
      }

      if(turnMotorPower > maxSpeedTurn) {
        turnMotorPower = maxSpeedTurn;
      } else if (turnMotorPower < -maxSpeedTurn) {
        turnMotorPower = -maxSpeedTurn;
      }

      leftDt.spin(fwd, cL*lateralMotorPower + cT*turnMotorPower, volt);
      rightDt.spin(fwd, cL*lateralMotorPower - cT*turnMotorPower, volt);

      if(fabs(error) < 0.01 && fabs(turnDerivative) < 0.1) {
        count++;
      } 
      else {
        count = 0;
      }

      if(fabs(derivative) < 0.005) {
        countDeriv++;
      }
      else {
        countDeriv = 0;
      }

      if(count >= 5 || countDeriv >= 35) {
        isRunning = false;
      }

      prevError = error;
      turnPrevError = turnError;
      this_thread::sleep_for(15);
    }
    this_thread::sleep_for(15);
  }
  return 1;
}