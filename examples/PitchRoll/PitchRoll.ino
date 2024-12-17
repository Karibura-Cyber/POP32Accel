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
    //Pitch and Roll in degree
    Serial.printf("Pitch: %d\t", (int)accel.readPitch());
    Serial.printf("Roll: %d\t", (int)accel.readRoll());
    delay(10);
}