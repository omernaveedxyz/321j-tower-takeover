#include "vex.h"
#include "pre_auton.h"
#include "driverControl/driver.h"
#include "autonomous/auton.h"

competition Competition;

vex::controller master(vex::controllerType::primary);
vex::controller secondary(vex::controllerType::partner);

//Broken Ports: 16
vex::motor rightDtFront(vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::motor rightDtBack(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor leftDtFront(vex::PORT13, vex::gearSetting::ratio18_1, false);
vex::motor leftDtBack(vex::PORT1, vex::gearSetting::ratio18_1, false);

vex::motor intakeRight(vex::PORT19, vex::gearSetting::ratio18_1, true);
vex::motor intakeLeft(vex::PORT14, vex::gearSetting::ratio18_1, false);

vex::motor angleAdj(vex::PORT9, vex::gearSetting::ratio36_1, true);
vex::motor lift(vex::PORT17, vex::gearSetting::ratio36_1, true);

vex::inertial iSensor(vex::PORT3);

vex::triport myThreeWirePort(PORT22);
vex::line lineFollower(myThreeWirePort.A);

//Motor Groups
motor_group rightDt(rightDtFront, rightDtBack);
motor_group leftDt(leftDtFront, leftDtBack);
motor_group intake(intakeRight, intakeLeft);
motor_group dt(rightDtFront, rightDtBack, leftDtFront, leftDtBack);

//TASKS
task slewTask;
task drivePDTask;
task trayTask;
task intakeTask;
task liftTask;

// Main
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(10, msec);
  }
}
