#include "competition/opcontrol.h"
#include "vex.h"
#include "robot-config.h"


/**
 * Main entrypoint for the driver control period
 */
void opcontrol()
{

    con.ButtonUp.pressed([]()
                         { fw.spin_rpm(1000); });
    con.ButtonLeft.pressed([]()
                           { fw.spin_rpm(500); });
    con.ButtonRight.pressed([]()
                            { fw.spin_rpm(750); });
    con.ButtonDown.pressed([]()
                           { fw.spin_rpm(0); });

    while (imu.isCalibrating())
    {
        vexDelay(20);
    }

    // ================ INIT ================
    while (true)
    {
        double l = con.Axis3.position() / 100.0;
        double r = con.Axis2.position() / 100.0;
        drive_sys.drive_tank(l, r, 1, TankDrive::BrakeType::TimedHold);
        vexDelay(10);
    }

    // ================ PERIODIC ================
}