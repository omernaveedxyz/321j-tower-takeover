#include "vex.h"
#include "pre_auton.h"
#include "autonomous/autonFunctions.h"
#include "autonomous/deploy.h"
#include "autonomous/alignCube.h"
#include "autonomous/placeStack.h"

void skillsAuton2() {
  iSensor.setRotation(270, rotationUnits::deg);
  runTask(0, 270);
  drivePDTask = vex::task(drivePD);
  enableDrivePD = true;
  resetDriveSensors = true;
  /////////////////////////
  /////////////////////////
  // deploy();
  // wait(2000, msec);

  // intake.rotateFor(5, rotationUnits::rev, 100, velocityUnits::pct, false);
  // runTask(30);
  // while(isRunning) {
  //   wait(10, msec);
  // }

  // intake.stop();
  // alignCube();
  // lowTower();
  // intake.rotateFor(-3, rotationUnits::rev, 100, velocityUnits::pct, true);

  // dropTower();
  // runTask(-30, 220, 6, 0.5, 1);
  // while(isRunning) {
  //   wait(10, msec);
  // }


  iSensor.setRotation(270, rotationUnits::deg); //270
  intake.rotateFor(100, rotationUnits::rev, 80, velocityUnits::pct, false);
  runTask(55);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();

  runTask(0, 270);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(100, rotationUnits::rev, 80, velocityUnits::pct, false);
  runTask(50, 270, 5);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();

  runTask(0, 317);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(16.5);
  while(isRunning) {
    wait(10, msec);
  }

  drivePDTask.stop();
  dt.stop();
  placeStack();
  while(trayRunningAuton) {
    wait(10, msec);
  }
  intake.rotateFor(-1, rotationUnits::rev, 100, velocityUnits::pct, true);
  drivePDTask = vex::task(drivePD);
  intake.rotateFor(-5, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(-15, 317, 2);
  while(isRunning) {
    wait(10, msec);
  }

  angleAdj.rotateFor(-5.2, rotationUnits::rev, 100, velocityUnits::pct, true);
  runTask(0, 179);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(20, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(30, 179, 4);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(-5);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();
  alignCube();
  highTower();

  runTask(7);
  while(isRunning) {
    wait(10, msec);
  }
  intake.rotateFor(-2, rotationUnits::rev, 60, velocityUnits::pct, true);

  // angleAdj.rotateFor(0.7, rotationUnits::rev, 100, velocityUnits::pct, true);
  iSensor.setRotation(179, rotationUnits::deg); //179
  runTask(-15, 90);
  while(isRunning) {
    wait(10, msec);
  }
  dropTower();

  intake.rotateFor(80, rotationUnits::rev, 80, velocityUnits::pct, false);
  runTask(50, 90, 8);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(10, 100);
  while(isRunning) {
    wait(10, msec);
  }
  // wait(1000, msec);

  runTask(40, 90, 4);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();

  // runTask(-20, 90, 10);
  // while(isRunning) {
  //   wait(10, msec);
  // }

  runTask(0, 35);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(36.5);
  while(isRunning) {
    wait(10, msec);
  }

  drivePDTask.stop();
  dt.stop();
  alignCube();
  placeStack();
  while(trayRunningAuton) {
    wait(10, msec);
  }
  intake.rotateFor(-1, rotationUnits::rev, 100, velocityUnits::pct, true);
  drivePDTask = vex::task(drivePD);
  intake.rotateFor(-5, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(-17, 37, 2);
  while(isRunning) {
    wait(10, msec);
  }

  // iSensor.setRotation(35, rotationUnits::deg); //270
  // runTask(0, 35);

  angleAdj.rotateFor(-5.2, rotationUnits::rev, 100, velocityUnits::pct, true);
  runTask(0, 179);
  while(isRunning) {
    wait(10, msec);
  }

  intake.rotateFor(20, rotationUnits::rev, 100, velocityUnits::pct, false);
  runTask(27, 179, 8);
  while(isRunning) {
    wait(10, msec);
  }

  runTask(-8);
  while(isRunning) {
    wait(10, msec);
  }
  intake.stop();
  alignCube();
  highTower();

  runTask(7);
  while(isRunning) {
    wait(10, msec);
  }
  intake.rotateFor(-3, rotationUnits::rev, 60, velocityUnits::pct, true);
}