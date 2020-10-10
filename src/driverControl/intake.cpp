#include "vex.h"
#include "driverControl/driverFunction.h"

int intakes() {
  while(1) {
    if(master.ButtonL1.pressing()) {
      intakeRunning = false;
      liftRunning = false;
      intake.spin(fwd, 12, volt);
    }
    else if(master.ButtonL2.pressing()) {
      intakeRunning = false;
      liftRunning = false;
      intake.spin(directionType::rev, 12, volt);
    }
    else {
      if(!intakeRunning) {
        intake.stop(coast);
      }
    }
    this_thread::sleep_for(15);
  }
  return 1;
}