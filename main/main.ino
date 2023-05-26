#include "xyz.h"
#define LENGTH_SENSOR_PIN A0
#define WIDTH_SENSOR_PIN A1
#define HEIGHT_SENSOR_PIN A2

float length_voltage_readings = 0;
float width_voltage_readings = 0;
float height_voltage_readings = 0;


void setup(void){
    Serial.begin(9600);

}


void loop(void){

    length_voltage_readings = analogRead(LENGTH_SENSOR_PIN) * (5 / 1024);
    width_voltage_readings = analogRead(WIDTH_SENSOR_PIN) * (5 / 1024);
    height_voltage_readings = analogRead(HEIGHT_SENSOR_PIN) * (5 / 1024);


}