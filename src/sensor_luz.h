#ifndef SENSOR_LUZ_H
#define SENSOR_LUZ_H

#include <Arduino.h>
#include <sensor.h>
/* #include <Sensor/analog_sensor.h> */


class LIGHT: public Sensor<float> {
    public:
        LIGHT(uint8_t id, uint8_t pin):Sensor<float>(id, pin) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        float read();
};


float LIGHT::read() {
    float luz_voltaje = map(analogRead(this->pin),900, 640, 0, 255);
    return luz_voltaje;
}

#endif