 #include "HX711.h"
#include <SoftwareSerial.h>
#include <Wire.h>



// HX711 接線設定
const int DT_PIN = 3;
const int SCK_PIN = 2;
const int scale_factor = -226;  
HX711 scale;
char LEDstatus;
SoftwareSerial BT(12,13);
int f = 5;
int i = 255;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  BT.begin(38400); // 設定和 HC-05 通訊的速度 (預設 38400)
  Serial.println("Initializing the scale");
  scale.begin(DT_PIN, SCK_PIN);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale.get_units(5), 0);  //未設定比例參數前的數值

  scale.set_scale(scale_factor);       // 設定比例參數
  scale.tare();               // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
  
}

void loop() {
  float weight = scale.get_units(10);
  if(weight<=2){
    weight = 0;
  }
  Serial.println(weight, 0); 
  if (BT.available()){
    LEDstatus=BT.read();
    Serial.println(LEDstatus);  
  }
  switch (LEDstatus){ 
        case 'a':
        if (i<=255){
          while (i>60){
            i-=f;
          }
        }
        else if (i>=0){
          while (i<60){
            i+=f;
          }
        }
        break;
        case 'b':
        i=100;
        break;
        case 'c':
        i=175;
        break;
        case 'd':
        i=255;
        break;
        case 'e':
        i=0;
        break;
        case 'g':
        Serial.println(LEDstatus);
        for(int j=0;j<=10;j+=1){
          for(i=0;i<=255;i=i+=f){
            analogWrite(5,i);
            analogWrite(6,i);
            delay(50);
            Serial.println(i,0);
          }
          for(i=255;i>=0;i-=f){
            analogWrite(5,i);
            analogWrite(6,i);
            delay(50);
            Serial.println(i,0);
          }
        }
    }
  if (10 * scale.get_units(5) < 5000){
       analogWrite(5,0);
       analogWrite(6,0);
  }
  else if (10 * scale.get_units(5) < 15000){
    analogWrite(5, i);
    analogWrite(6, 0);
  }
  else {
    analogWrite(5,i);
    analogWrite(6,i);
  }
    
  
  
}
