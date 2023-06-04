#ifndef XYZ_H
#define XYZ_H

#include <SharpIR.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


void oled_print(int);
void boot_logo(void);
void print_to_computer(void);


#define MODEL1 1080
#define MODEL2 1080
#define MODEL3 1080

#define WIDTH 128
#define HEIGHT 64
#define OLED_RESET -1

#define BOX_LENGTH 12
#define BOX_WIDTH 8
#define BOX_HEIGHT 0

#define LENGTH_SENSOR_PIN A0
#define WIDTH_SENSOR_PIN A1
#define HEIGHT_SENSOR_PIN A2

Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, OLED_RESET);



SharpIR length_sensor(SharpIR::GP2Y0A21YK0F, LENGTH_SENSOR_PIN);
SharpIR width_sensor(SharpIR::GP2Y0A21YK0F, WIDTH_SENSOR_PIN);
SharpIR height_sensor(SharpIR::GP2Y0A21YK0F, HEIGHT_SENSOR_PIN);

uint8_t button_state = 0;
int last_reading = 0;
int length_value = 0;
int width_value = 0;
int height_value = 0;
int volume = 0;


void print_to_computer(void){
    Serial.print("length: ");
    Serial.print(length_value);
    Serial.print("-CM, width: ");
    Serial.print(width_value);
    Serial.print("-CM, height: ");
    Serial.print(height_value);
    Serial.print("-CM, volume: ");
    Serial.print(volume);
    Serial.print("-CM^3");
    Serial.println();
    
}


void oled_print(int volume){
    /*
      show the volume value from the sensors on OLED;
    */

    display.clearDisplay();

    display.drawRect(0, 0, WIDTH, HEIGHT, WHITE);
    display.drawLine(90, 0, 90, HEIGHT, WHITE);



    display.setTextSize(2.3);
    display.setTextColor(WHITE);
    display.setCursor(10, 25);

    if (button_state){
        display.println(String(last_reading));
        display.setTextSize(1.7);
        display.setCursor(97, 15);
        display.println(F("CM^3"));
        display.setCursor(103, 45);
        display.println(F("OFF"));

        // FOR SEPERATE CM^3 AND ON/OFF;
        display.drawLine(90, 44, WIDTH, 27, WHITE);

    }

    else{
        display.println(String(volume));
        display.setTextSize(1.7);
        display.setCursor(97, 15);
        display.println(F("CM^3"));
        display.setCursor(103, 45);
        display.println(F("ON"));

        // FOR SEPERATE CM^3 AND ON/OFF;
        display.drawLine(90, 27, WIDTH, 44, WHITE);
    }
    // update the screen;
    display.display();


  }



  void boot_logo(void){
  /*
    simple animation start when we boot up the arduino;
  */

    display.clearDisplay();

    display.drawRect(0, 10, WIDTH, HEIGHT-18, WHITE);



    display.setTextSize(2.2);
    display.setTextColor(WHITE);

    String logo = "XYZ";

    for (int i=0; i<3;i++){
      display.setCursor(50 + (11*i), 25);
      display.print(logo[i]);
      display.display();
      delay(500);
    }

    delay(10);

  }


void stop_(void){
  for(;;);
}








#endif