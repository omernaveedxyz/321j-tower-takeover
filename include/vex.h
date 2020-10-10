#include "v5.h"
#include "v5_vcs.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vex_imu.h>

#include "robot-config.h"

using namespace vex;
using namespace std;

extern competition Competition;

extern controller master;
extern controller secondary;

extern motor rightDtFront;
extern motor rightDtBack;
extern motor leftDtFront;
extern motor leftDtBack;

extern motor intakeRight;
extern motor intakeLeft;

extern motor angleAdj;
extern motor lift;

extern inertial iSensor;

extern line lineFollower;

extern motor_group rightDt;
extern motor_group leftDt;
extern motor_group dt;
extern motor_group intake;

extern task slewTask;
extern task drivePDTask;
extern task trayTask;
extern task intakeTask;
extern task liftTask;

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)