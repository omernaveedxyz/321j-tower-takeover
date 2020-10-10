#pragma once
#include "vex.h"
#include "drivePD.h"

extern bool isRunning;
extern bool enableDrivePD;
extern bool resetDriveSensors;
extern double desiredTurnValue;

double inToRev();
int drivePD();
void runTask(double driveDist, double turnDist = desiredTurnValue, double maxSpeed = 6, double lateralConst = 1, double turnConst = 1);

void lowTower();
void highTower();
void dropTower();
