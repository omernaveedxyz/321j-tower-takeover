#include "vex.h"
#include "pre_auton.h"
#include "autonomous/smallZoneAuton.h"
#include "autonomous/largeZoneAuton.h"
#include "autonomous/onePointAuton.h"
#include "autonomous/skillsAuton.h"

void auton() {
  if(autonomousMode == 0 || autonomousMode == 1) {
    smallZoneAuton();
  }
  else if(autonomousMode == 2 || autonomousMode == 3) {
    largeZoneAuton();
  }
  else if(autonomousMode == 4) {
    onePointAuton();
  }
  else if(autonomousMode == 5) {
    skillsAuton2();
  }
}