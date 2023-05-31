#ifndef XYZ_H
#define XYZ_H

#include <SharpIR.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define MODEL 1080
#define WIDTH 128
#define HEIGHT 64
#define OLED_RESET -1

#define BOX_LENGTH 0
#define BOX_WIDTH 0
#define BOX_HEIGHT 0


class XYZ{

  private:
    int *length_sensor_pin;
    int *width_sensor_pin;
    int *height_sensor_pin;

    int lp, wp, hp;

  

  public:

    XYZ(int length_pin=0, int width_pin=1, int height_pin=2){
      lp = length_pin;
      wp = width_pin;
      hp =  height_pin;

      length_sensor_pin = &lp;
      width_sensor_pin = &wp;
      height_sensor_pin = &hp;


    }

    ~XYZ(void){
      delete length_sensor_pin;
      delete width_sensor_pin;
      delete height_sensor_pin;

    }

    int get_length_in_cm(void){
      SharpIR length_ir(length_sensor_pin, MODEL);

      

      return length_ir.distance();

    }

    int get_width_in_cm(void){
      SharpIR width_ir(width_sensor_pin, MODEL);
    
      return width_ir.distance();
    }

    int get_height_in_cm(void){
      SharpIR height_ir(height_sensor_pin, MODEL);

      return height_ir.distance();
    }

    int get_area_in_cm(void){
      int area = 0;

      area = this->get_length_in_cm() * this->get_width_in_cm();

      return area;
    }

    int get_volume_in_cm(void){
      int volume = 0;

      volume = this->get_length_in_cm() * this->get_width_in_cm() * this->get_height_in_cm();

      return volume;
    }


};


#endif