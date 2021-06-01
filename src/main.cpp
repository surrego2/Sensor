#include <Arduino.h>

#include <sensor.h>
#include <sensor_luz.h>
#include <settings.h>
#include <llp.h> 

LIGHT sensor = LIGHT(0x7E, A0);

void setup() {
   Serial.begin(115200);
   pinMode(SETTINGS::SENSOR_INPUT, INPUT);
}

void loop() {
      sensor.excecute();

    if (sensor.hasChanged()){      
      float raw_read = sensor.getValue();
      DataPack stored_value = DataPack();
      stored_value.addData(sensor.getId(), raw_read);
      stored_value.write(Serial);
      Serial.println(raw_read); 

    }
    delay(500);
}