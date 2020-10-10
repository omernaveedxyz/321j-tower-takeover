#include "vex.h"
#include "pre_auton.h"
#include "autonomous/autonFunctions.h"
#include "autonomous/deploy.h"
#include "autonomous/alignCube.h"
#include "autonomous/placeStack.h"

void largeZoneAuton() {
  iSensor.setRotation(270, rotationUnits::deg);
  runTask(0, 270);
  drivePDTask = vex::task(drivePD);
  enableDrivePD = true;
  resetDriveSensors = true;
  /////////////////////////
  /////////////////////////
  deploy();
  wait(2000, msec);

  runTask(18);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();

  runTask(0, 270 + colorConst*-95);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(6, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(15);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(-15);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(0, 270 + colorConst*59);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(15, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(25);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(0, 90 + colorConst*-45);
  while(isRunning) {
    wait(10, msec);
  }

  angleAdj.rotateFor(3, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(15);
  while(isRunning) {
    wait(10, msec);
  }
 
  drivePDTask.stop();
  dt.stop();
  placeStack();
  while(trayRunningAuton) {
    wait(10, msec);
  }
  drivePDTask = vex::task(drivePD);
  intake.rotateFor(-5, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(-5, 90 + colorConst*-45, 2);
}