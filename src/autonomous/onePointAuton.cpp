#include "vex.h"
#include "pre_auton.h"
#include "autonomous/autonFunctions.h"
#include "autonomous/deploy.h"
#include "autonomous/alignCube.h"
#include "autonomous/placeStack.h"

void onePointAuton() {
  iSensor.setRotation(270, rotationUnits::deg);
  runTask(0, 270);
  drivePDTask = vex::task(drivePD);
  enableDrivePD = true;
  resetDriveSensors = true;
  /////////////////////////
  /////////////////////////  
  runTask(-20);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(20);
  while(isRunning) {
    wait(10, msec);
  }

  deploy();
}