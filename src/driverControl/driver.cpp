#include "vex.h"
#include "driverControl/tray.h"
#include "driverControl/slew.h"
#include "driverControl/intake.h"
#include "driverControl/tower.h"
#include "autonomous/deploy.h"

double driveSpeedFront = 6;
double driveSpeedBack = 2;

/*
Button Functions
A: Forward
B: Back (slow)
X: HighTower
Y: LowTower
Up: Tray fwd
Down: Tray rev
Right: PlaceStack
Left: DropTray
*/
void driver() {
  lift.resetRotation();
  angleAdj.resetRotation();
  drivePDTask.stop();
  trayTask = task(tray);
  liftTask = task(tower);
  intakeTask = task(intakes);
  slewTask = task(slew);

  while(1) {
    //RightDt
    if( abs(master.Axis2.value()) > 0.1 ) {
      // rightDt.spin(vex::directionType::fwd, ( pow( rightDtVel,3) / 10000 ) * 0.01 * 12, voltageUnits::volt);
      rightDt.spin(vex::directionType::fwd, ( pow( master.Axis2.value(),3) / 10000 ) * 0.01 * 12, voltageUnits::volt);
    }
    else {
      rightDt.stop(coast);
    }

    //LeftDt
    if( abs(master.Axis3.value()) > 0.1 ) {
      // leftDt.spin(vex::directionType::fwd, ( pow( leftDtVel,3) / 10000 ) * 0.01 * 12, voltageUnits::volt); 
      leftDt.spin(vex::directionType::fwd, ( pow( master.Axis3.value(),3) / 10000 ) * 0.01 * 12, voltageUnits::volt); 
    }
    else {
      leftDt.stop(coast);
    }

    //Buttons
    if(master.ButtonA.pressing()){
      dt.spin(vex::directionType::fwd, driveSpeedFront, voltageUnits::volt);
    }

    if(master.ButtonB.pressing()){
      dt.spin(vex::directionType::rev, driveSpeedBack, voltageUnits::volt);
    }

    this_thread::sleep_for(15);    
  }
}

void driverSkills() {
  driveSpeedFront = 8.5;
  deploy();
  driver();
}