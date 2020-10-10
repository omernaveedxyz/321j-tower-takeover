#include "vex.h"

void alignCube() {
  while(lineFollower.value(pct) > 68) {
    cout << lineFollower.value(pct) << endl;
    intake.spin(directionType::rev, 60, pct);
    this_thread::sleep_for(15);
  }
  intake.stop();
}