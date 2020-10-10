#include "vex.h"
#include "autonomous/alignCube.h"

bool trayRunningAuton = false;

void placeStack() {
  // alignCube();
  trayRunningAuton = true;
  while(angleAdj.rotation(rev) < 5.2) {
    angleAdj.spin(directionType::fwd, 100, pct);
    this_thread::sleep_for(15);
  }
  angleAdj.stop(hold);
  trayRunningAuton = false;
}