#include <POP32Accel.h>
#include <POP32.h>

POP32Accel accel;

void setup() {
    Serial.begin(115200);
    if (!accel.begin()) {
        Serial.println("Failed to initialize accelerometer.");
        while (1);
    }
}

void loop() {
    
    //X,Y,Z Axis count
    Serial.printf("Xa: %f\t", accel.XAxis());
    Serial.printf("Ya: %f\t", accel.YAxis());
    Serial.printf("Za: %f\t", accel.ZAxis());
}