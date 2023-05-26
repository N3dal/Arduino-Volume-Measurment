#include "xyz.h"

XYZ reader(123, 553, 120);


void setup(void){
    Serial.begin(9600);

}


void loop(void){
    float volume = 0;
    
    volume = reader.get_volume_in_cm();

    Serial.println(volume, 20);


    delay(1000);


}