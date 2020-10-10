#include "vex.h"
#include "autonomous/drivePD.h"

double inToRev(double inches) {
  return (inches / (M_PI * 4) );
}

void runTask(double driveDist, double turnDist, double maxSpeed, double lateralConst, double turnConst) {
  if(driveDist != 0) {
    cL = lateralConst;
    cT = turnConst;
    maxSpeedDrive = maxSpeed;
    resetDriveSensors = true;
    desiredTarget = inToRev(driveDist);
  }
  desiredTurnValue = turnDist;
  count = 0;
  isRunning = true;
}

void lowTower() {
  while(lift.rotation(rev) < 1.2) {
    if(angleAdj.rotation(rev) < 2) {
      angleAdj.spin(fwd, 12, volt);
    }
    else {
      angleAdj.stop();
    }

    if(angleAdj.rotation(rev) > 0.5) {
      lift.spin(fwd, 12, volt);
    }
    else { 
      lift.stop();
    }
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  lift.stop();
}

void highTower() {
  while(lift.rotation(rev) < 1.8) {
    if(angleAdj.rotation(rev) < 1.7) {
      angleAdj.spin(fwd, 12, volt);
    }
    else {
      angleAdj.stop();
    }

    if(angleAdj.rotation(rev) > 0.2) {
      lift.spin(fwd, 8, volt);
    }
    else { 
      lift.stop();
    }
    cout << angleAdj.rotation(rev) << " " << lift.rotation(rev) << endl;
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  lift.stop();
}

void dropTower() {
  while(lift.rotation(rev) > 0) {
    angleAdj.spin(directionType::rev, 12, volt);
    lift.spin(directionType::rev, 10, volt);
  }
  lift.stop();
  angleAdj.stop();
}