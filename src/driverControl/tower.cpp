#include "vex.h"
#include "driverControl/driverFunction.h"

int tower() {
  while(1) {
    master.ButtonX.pressed(highTowerDriver);
    master.ButtonY.pressed(lowTowerDriver);
    if(master.ButtonR1.pressing()) {
      liftRunning = false;
      lift.spin(fwd, 12, volt);
    }
    else if(master.ButtonR2.pressing()) {
      liftRunning = false;
      lift.spin(directionType::rev, 12, volt);
    }
    else {
      if(!liftRunning) {
        lift.stop();
      }
    }
    this_thread::sleep_for(15);
  }
  return 1;
}