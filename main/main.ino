#include "xyz.h"

void oled_print(int);
void boot_logo(void);


XYZ reader(0, 1, 2);

Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, OLED_RESET);


void setup(void){
    Serial.begin(9600);

    // now setup the oled screen;

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
      Serial.println("SSD1306 FAILED!!!");
      for(;;);
    }

    boot_logo();

}


void loop(void){
    int length = 0;
    int width = 0;
    int height = 0;
    int volume = 0;
    
    length = reader.get_length_in_cm() + BOX_LENGTH;
    width = reader.get_width_in_cm() + BOX_WIDTH;
    height = reader.get_height_in_cm() + BOX_HEIGHT;

    volume = length * width * height;

    if (volume < 0){
      volume = 0;
    }

    // print on the oled;
    oled_print(volume);

    // Serial.println(volume, 20);
    Serial.print("length: ");
    Serial.print(length);
    Serial.print("-CM, width: ");
    Serial.print(width);
    Serial.print("-CM, height: ");
    Serial.print(height);
    Serial.print("-CM, volume: ");
    Serial.print(volume, 3);
    Serial.print("-CM^3");
    Serial.println();

    delay(500);


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
    display.println(String(volume));

    if (false){
        display.setTextSize(1.7);
        display.setCursor(103, 30);
        display.println(F("M^3"));
    }

    else{
        display.setTextSize(1.7);
        display.setCursor(97, 30);
        display.println(F("CM^3"));
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

    delay(1000);

  }






