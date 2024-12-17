#ifndef POP32ACCEL_H
#define POP32ACCEL_H

#include <MC34X9.h>
#include <math.h>

// Ensure MC34X9 object is defined externally
extern MC34X9 MC34X9_acc;

// POP32Accel class definition
class POP32Accel {
public:
    // Constructor
    POP32Accel();

    // Initialize the accelerometer
    // bool begin(bool isI2C, uint8_t addressOrChipSelect);
    bool begin();

    // Read raw acceleration data (counts)
    int16_t XAxis();
    int16_t YAxis();
    int16_t ZAxis();

    // Read acceleration data (G-forces)
    float XAxis_g();
    float YAxis_g();
    float ZAxis_g();

    // Calculate orientation
    float readPitch(); // Rotation about the X-axis
    float readRoll();  // Rotation about the Y-axis
};

#endif // POP32ACCEL_H
