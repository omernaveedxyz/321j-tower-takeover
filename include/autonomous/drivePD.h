#include "vex.h"

extern bool enableDrivePD;
extern bool resetDriveSensors;
extern bool isRunning;

extern double cL;
extern double cT;

extern double desiredTarget;
extern double desiredTurnValue;
extern double maxSpeedDrive;
extern int count;

int drivePD();