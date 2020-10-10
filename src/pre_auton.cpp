#include "vex.h"

bool selectingAuton = true;
int autonomousMode = 0;
int colorConst = 1;

void drawButtons() {
  Brain.Screen.setPenColor( vex::color(0x000000) );
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0, 0, 160, 90);
  Brain.Screen.printAt(5, 55, true, "blue small zone");

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 90, 160, 90);
  Brain.Screen.printAt(5, 145, true, "red small zone");

  Brain.Screen.setFillColor(white);
  Brain.Screen.drawRectangle(160, 0, 160, 90);
  Brain.Screen.printAt(165, 55, true, "blue large zone");

  Brain.Screen.setFillColor(orange);
  Brain.Screen.drawRectangle(160, 90, 160, 90);
  Brain.Screen.printAt(165, 145, true, "red large zone");

  Brain.Screen.setFillColor(green);
  Brain.Screen.drawRectangle(320, 0, 160, 90);
  Brain.Screen.printAt(325, 55, true, "one point auton");

  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawRectangle(320, 90, 160, 90);
  Brain.Screen.printAt(325, 145, true, "skills auton");
}

void userTouchCallbackPressed() {
  if(selectingAuton) {
    int xpos = Brain.Screen.xPosition();
    int ypos = Brain.Screen.yPosition();
    
    if(xpos > 0 && xpos < 160) {
      if(ypos > 0 && ypos < 90) {
        cout << "blue" << endl;
        autonomousMode = 0;
        colorConst = 1;
      }
      else if(ypos > 90 && ypos < 180) {
        cout << "red" << endl;
        autonomousMode = 1;
        colorConst = -1;
      } 
    }
    else if(xpos > 160 && xpos < 320) {
      if(ypos > 0 && ypos < 90) {
        cout << "white" << endl;
        autonomousMode = 2;
        colorConst = 1;
      }
      else if(ypos > 90 && ypos < 180) {
        cout << "orange" << endl;
        autonomousMode = 3;
        colorConst = -1;
      } 
    }
    else if(xpos > 320 && xpos < 480) {
      if(ypos > 0 && ypos < 90) {
        cout << "green" << endl;
        autonomousMode = 4;
        colorConst = 1;
      }
      else if(ypos > 90 && ypos < 180) {
        cout << "yellow" << endl;
        autonomousMode = 5;
        colorConst = 1;
      } 
    }
  }
}

void userTouchCallbackReleased() {
  Brain.Screen.drawRectangle(0, 0, 480, 272);
  selectingAuton = false;
}

void pre_auton() {
  vexcodeInit();

  Brain.Screen.pressed( userTouchCallbackPressed );
  Brain.Screen.released( userTouchCallbackReleased );
  drawButtons();
  while(selectingAuton) {
    wait(10, msec);
  }

  iSensor.calibrate(2000);
  this_thread::sleep_for(2000);
  cout << "done calibrating imu" << endl;

  angleAdj.resetRotation();
  lift.resetRotation();
  rightDtFront.resetRotation();
  rightDtBack.resetRotation();
  leftDtFront.resetRotation();
  leftDtBack.resetRotation();
  intake.resetRotation();

  angleAdj.setBrake(hold);
  lift.setBrake(hold);
  rightDtFront.setBrake(coast);
  rightDtBack.setBrake(coast);
  leftDtFront.setBrake(coast);
  leftDtBack.setBrake(coast);
  intakeLeft.setBrake(coast);
  intakeRight.setBrake(coast);
}