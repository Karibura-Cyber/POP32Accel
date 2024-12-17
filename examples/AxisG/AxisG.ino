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
    //X,Y,Z Axis by gravity acceleration
    Serial.printf("Xg: %f\t", accel.XAxis_g());
    Serial.printf("Yg: %f\t", accel.YAxis_g());
    Serial.printf("Zg: %f\t", accel.ZAxis_g());
    delay(10);
}