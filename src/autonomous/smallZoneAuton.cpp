#include "vex.h"
#include "pre_auton.h"
#include "autonomous/autonFunctions.h"
#include "autonomous/deploy.h"
#include "autonomous/alignCube.h"
#include "autonomous/placeStack.h"

void smallZoneAuton() {  
  iSensor.setRotation(270, rotationUnits::deg);
  runTask(0, 270);
  drivePDTask = vex::task(drivePD);
  enableDrivePD = true;
  resetDriveSensors = true;
  /////////////////////////
  /////////////////////////
  runTask(2, 270, 12);
  deploy();
  wait(2000, msec);

  intake.rotateFor(12, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(43, 270, 5);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();

  runTask(-4, 270 + colorConst*30, 10);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(4, rotationUnits::rev, 60, velocityUnits::pct, false);
  runTask(12, 270 + colorConst*30, 10, 0.5, 1);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(-12, 270, 10, 0.5, 1);
  while(isRunning) {
    wait(10, msec);
  }

  if(colorConst == 1) {
    runTask(0, 90 + colorConst*38);
  }
  else {
    iSensor.setRotation(0, rotationUnits::deg);
    runTask(0, 128);
  }
  while(isRunning) {
    wait(10, msec);
  }
  
  intake.rotateFor(-0.2, rotationUnits::rev, 60, velocityUnits::pct, false);
  angleAdj.rotateFor(3, rotationUnits::rev, 100, velocityUnits::pct, false);
  if(colorConst == 1) {
    runTask(32.5, 90 + colorConst*38, 6);
  }
  else {
    runTask(32.5, 128, 6);
  }
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
  if(colorConst == 1) {
    runTask(-5, 90 + colorConst*38, 2);
  }
  else {
    runTask(-5, 128, 2);
  }
}