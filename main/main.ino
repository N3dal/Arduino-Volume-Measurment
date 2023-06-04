#include "xyz.h"




void setup(void){
    Serial.begin(9600);

    pinMode(13, INPUT_PULLUP);


    // now setup the oled screen;

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
      Serial.println("SSD1306 FAILED!!!");
      stop_();
    }

    boot_logo();

}


void loop(void){
    int button_read = digitalRead(13);

    if (button_state != 1){

      length_value = length_sensor.getDistance() + BOX_LENGTH;
      width_value = width_sensor.getDistance() + BOX_WIDTH;
      height_value = height_sensor.getDistance() + BOX_HEIGHT;

      volume = length_value * width_value * height_value;

      if (volume < 0){
        volume = 0;
      }

      last_reading = volume;
    }

    if (button_read){
      button_state = button_state ? 0: 1;
    }

    // print on the oled;
    oled_print(volume);

    print_to_computer();

    delay(150);


}


