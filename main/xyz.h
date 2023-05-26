#ifndef XYZ_H
#define XYZ_H

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

    float get_length_in_cm(void){
      float volt_reading = analogRead(*length_sensor_pin);
      float distance = 13 * pow(volt_reading, -1);
      // Serial.println(distance);

      return distance;

    }

    float get_width_in_cm(void){
      float volt_reading = analogRead(*width_sensor_pin);
      float distance = 13 * pow(volt_reading, -1);
      // Serial.println(distance);

      return distance;
    }

    float get_height_in_cm(void){
      float volt_reading = analogRead(*height_sensor_pin);
      float distance = 13 * pow(volt_reading, -1);
      // Serial.println(distance);

      return distance;
    }

    double get_area_in_cm(void){
      double area = 0;

      area = this->get_length_in_cm() * this->get_width_in_cm();

      return area;
    }

    double get_volume_in_cm(void){
      double volume = 0;

      volume = this->get_length_in_cm() * this->get_width_in_cm() * this->get_height_in_cm();

      return volume;
    }
};


#endif