#include "vex.h"

double slewStep = 15;
double rightDtVel = 0;
double leftDtVel = 0;

int slew() {
  while(1) {
    if( rightDtVel < master.Axis2.value() ) {
      rightDtVel += slewStep;
      if( rightDtVel > master.Axis2.value()) {
        rightDtVel = master.Axis2.value();
      }
    }
    if( leftDtVel < master.Axis3.value() ) {
      leftDtVel += slewStep;
      if( leftDtVel > master.Axis3.value()) {
        leftDtVel = master.Axis3.value();
      }
    }
    if( rightDtVel > master.Axis2.value() ) {
      rightDtVel -= slewStep;
      if( rightDtVel < master.Axis2.value()) {
        rightDtVel = master.Axis2.value();
      }
    }
    if( leftDtVel > master.Axis3.value() ) {
      leftDtVel -= slewStep;
      if( leftDtVel < master.Axis3.value()) {
        leftDtVel = master.Axis3.value();
      }
    }
    this_thread::sleep_for(15);
  }
  return 1;
}