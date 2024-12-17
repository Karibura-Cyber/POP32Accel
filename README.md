
# POP32Accel Library README

## Overview

The **POP32Accel** library is designed to interface with the MC34X9 accelerometer. It allows users to easily retrieve raw acceleration data as well as acceleration in G-forces, and calculate orientation angles such as pitch and roll based on the accelerometer readings.

This library is ideal for applications requiring 3D motion sensing, such as robotics, wearable devices, or any project where tracking orientation or movement is necessary.

## Dependencies

- **MC34X9**: This library handles the communication with the MC34X9 accelerometer module.
- **POP32Accel.h**: The header file for the POP32Accel class.

## Features

- **Initialization**: The library allows you to initialize the accelerometer and configure it to start reading.
- **Raw Data**: Access raw acceleration data on the X, Y, and Z axes.
- **Acceleration in G-forces**: Convert raw data into acceleration measurements in terms of gravitational units (G).
- **Pitch and Roll Calculation**: Calculate the pitch and roll angles based on the accelerometer data, which gives you the orientation of the device in space.

## Functions

### `POP32Accel::begin()`

This function initializes the accelerometer and starts communication with it.

**Returns**:  
- `true` if the initialization is successful.  
- `false` if initialization fails.

### `POP32Accel::XAxis()`

Returns the raw X-axis acceleration data.

**Returns**:  
- `int16_t`: Raw acceleration data in counts for the X-axis.

### `POP32Accel::YAxis()`

Returns the raw Y-axis acceleration data.

**Returns**:  
- `int16_t`: Raw acceleration data in counts for the Y-axis.

### `POP32Accel::ZAxis()`

Returns the raw Z-axis acceleration data.

**Returns**:  
- `int16_t`: Raw acceleration data in counts for the Z-axis.

### `POP32Accel::XAxis_g()`

Returns the X-axis acceleration data in G-forces.

**Returns**:  
- `float`: Acceleration in G on the X-axis.

### `POP32Accel::YAxis_g()`

Returns the Y-axis acceleration data in G-forces.

**Returns**:  
- `float`: Acceleration in G on the Y-axis.

### `POP32Accel::ZAxis_g()`

Returns the Z-axis acceleration data in G-forces.

**Returns**:  
- `float`: Acceleration in G on the Z-axis.

### `POP32Accel::readPitch()`

Calculates and returns the pitch angle (rotation around the X-axis) in degrees. 

**Returns**:  
- `float`: Pitch angle in degrees, ranging from -90° to 90°.

### `POP32Accel::readRoll()`

Calculates and returns the roll angle (rotation around the Y-axis) in degrees. 

**Returns**:  
- `float`: Roll angle in degrees, ranging from -180° to 180°.

## Usage Example

```cpp
#include "POP32Accel.h"

POP32Accel accel;

void setup() {
  Serial.begin(9600);
  if (accel.begin()) {
    Serial.println("Accelerometer initialized successfully.");
  } else {
    Serial.println("Failed to initialize accelerometer.");
  }
}

void loop() {
  Serial.print("X Accel (raw): ");
  Serial.println(accel.XAxis());
  
  Serial.print("X Accel (g): ");
  Serial.println(accel.XAxis_g());
  
  Serial.print("Pitch (degrees): ");
  Serial.println(accel.readPitch());
  
  delay(1000);
}
```

## License

This library is open source and is available for free use under the MIT License. Please refer to the LICENSE file for more details.
