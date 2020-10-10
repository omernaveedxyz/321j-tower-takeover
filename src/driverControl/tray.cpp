#include "vex.h"
#include "driverControl/driverFunction.h"

int tray() {
  while(1) {
    master.ButtonRight.pressed(placeStackDriver);
    master.ButtonLeft.pressed(dropTrayDriver);
    if(master.ButtonUp.pressing()) {
      trayRunning = false;
      liftRunning = false;
      angleAdj.spin(fwd, 12, volt);
    }
    else if(master.ButtonDown.pressing()) {
      trayRunning = false;
      liftRunning = false;
      angleAdj.spin(directionType::rev, 12, volt);
    }
    else {
      if(!trayRunning && !liftRunning) {
        angleAdj.stop();
      }
    }
    this_thread::sleep_for(15);
  }
  return 1;
}