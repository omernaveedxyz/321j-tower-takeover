#include "vex.h"

bool trayRunning = false;
bool liftRunning = false;
bool intakeRunning = false;

void alignCubeDriver() {
  // intakeRunning = true;
  // while(lineFollower.value(pct) > 68 && intakeRunning) {
  //   intake.spin(directionType::rev, 6, volt);
  //   this_thread::sleep_for(15);
  // }
  // intake.stop(coast);
  // intakeRunning = false;
}

void highTowerDriver() {
  liftRunning = true;
  while(lift.rotation(rev) < 2.4 && liftRunning) {
    if(angleAdj.rotation(rev) < 1.2) {
      angleAdj.spin(fwd, 12, volt);
    }
    else {
      angleAdj.stop();
    }

    if(angleAdj.rotation(rev) > 0.3) {
      lift.spin(fwd, 12, volt);
    }
    else { 
      lift.stop();
    }
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  lift.stop();
  liftRunning = false;
}

void lowTowerDriver() {
  liftRunning = true;
  while(lift.rotation(rev) < 1.2 && liftRunning) {
    if(angleAdj.rotation(rev) < 1.2) {
      angleAdj.spin(fwd, 12, volt);
    }
    else {
      angleAdj.stop();
    }

    if(angleAdj.rotation(rev) > 0.3) {
      lift.spin(fwd, 12, volt);
    }
    else { 
      lift.stop(coast);
    }
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  lift.stop();
  liftRunning = false;
}

void placeStackDriver() {
  trayRunning = true;
  alignCubeDriver();
  while(angleAdj.rotation(rev) < 5.2 && trayRunning) {
    angleAdj.spin(fwd, 12, volt);
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  trayRunning = false;
}

void dropTrayDriver() {
  trayRunning = true;
  while(angleAdj.rotation(rev) > 0 && trayRunning) {
    angleAdj.spin(directionType::rev, 12, volt);
    this_thread::sleep_for(15);
  }
  angleAdj.stop();
  trayRunning = false;
}