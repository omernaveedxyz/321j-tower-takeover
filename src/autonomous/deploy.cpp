#include "vex.h"

void deploy() {
  intake.rotateFor(5, rotationUnits::rev, 100, velocityUnits::pct, false);
  this_thread::sleep_for(100);
  angleAdj.rotateFor(0.5, rotationUnits::rev, 100, velocityUnits::pct, false);
  lift.rotateFor(0.4, rotationUnits::rev, 100, velocityUnits::pct, true);
  lift.rotateFor(-0.5, rotationUnits::rev, 100, velocityUnits::pct, false);
  angleAdj.rotateFor(-0.5, rotationUnits::rev, 100, velocityUnits::pct, false);
  intake.stop();
}