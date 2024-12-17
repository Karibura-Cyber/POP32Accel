#include "POP32Accel.h"
#include <MC34X9.h>

MC34X9 MC34X9_acc = MC34X9();

// Constructor: Initializes the accelerometer
POP32Accel::POP32Accel() {}

bool POP32Accel::begin(){
    return MC34X9_acc.start(1, 0x6c);
}

// Read raw acceleration data in counts
int16_t POP32Accel::XAxis() {
    return MC34X9_acc.readRawAccel().XAxis;
}

int16_t POP32Accel::YAxis() {
    return MC34X9_acc.readRawAccel().YAxis;
}

int16_t POP32Accel::ZAxis() {
    return MC34X9_acc.readRawAccel().ZAxis;
}

// Read acceleration in G-forces
float POP32Accel::XAxis_g() {
    return MC34X9_acc.readRawAccel().XAxis_g;
}

float POP32Accel::YAxis_g() {
    return MC34X9_acc.readRawAccel().YAxis_g;
}

float POP32Accel::ZAxis_g() {
    return MC34X9_acc.readRawAccel().ZAxis_g;
}

// Calculate pitch (rotation about the X-axis)
float POP32Accel::readPitch() {
    auto accel = MC34X9_acc.readRawAccel();
    return atan2(accel.XAxis_g, sqrt(pow(accel.YAxis_g, 2) + pow(accel.ZAxis_g, 2))) * (-180.0 / M_PI);
}

// Calculate roll (rotation about the Y-axis)
float POP32Accel::readRoll() {
    auto accel = MC34X9_acc.readRawAccel();
    return atan2(accel.YAxis_g, sqrt(pow(accel.XAxis_g, 2) + pow(accel.ZAxis_g, 2))) * (-180.0 / M_PI);
}
