#include "HX711.h"
#include <SoftwareSerial.h>
#include <Wire.h>

// HX711 接線設定
const int DT_PIN = 3;
const int SCK_PIN = 2;
const int scale_factor =104;  //矯正數

HX711 scale;
char LEDstatus;
SoftwareSerial BT(12,13);//接TX RX

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  BT.begin(38400);
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
  float weight = scale.get_units(1);
  
  if(weight<=2){
    weight = 0;
  }
  if (BT.available()){
    LEDstatus=BT.read();
    Serial.println(LEDstatus);  
  }
  
  Serial.println(weight, 0); 
  if (10 * scale.get_units(5) < 7900) {
    analogWrite(4,0);
    analogWrite(5,0);
    analogWrite(11,0);
    analogWrite(7,0);
    analogWrite(8,0);
    analogWrite(9,0);
    analogWrite(10,0);
  } 
  else if (10 * scale.get_units(5) < 17500) {
    analogWrite(4,255);
    analogWrite(5,0);
    analogWrite(11,0);
    analogWrite(7,0);
    analogWrite(8,0);
    analogWrite(9,0);
    analogWrite(10,0);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        break;
        case 'b':
        analogWrite(4,100);
        break;
        case 'c':
        analogWrite(4,175);
        break;
        case 'd':
        analogWrite(4,255);
        break;
        case 'e':
        analogWrite(4,0);
        break;
    }
  } 
  else if (10 * scale.get_units(5) < 29000) {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(11,0);
    analogWrite(7,0);
    analogWrite(8,0);
    analogWrite(9,0);
    analogWrite(10,0);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        break;
    }
  } 
  else if (10 * scale.get_units(5) < 42000) {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(11,0);
    analogWrite(7,255);
    analogWrite(8,0);
    analogWrite(9,0);
    analogWrite(10,0);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        analogWrite(7,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        analogWrite(7,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        analogWrite(71,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        analogWrite(7,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        analogWrite(7,0);
        break;
    }
  } 
  else if (10 * scale.get_units(5) < 57000) {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(11,0);
    analogWrite(7,255);
    analogWrite(8,255);
    analogWrite(9,0);
    analogWrite(10,0);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        analogWrite(8,60);
        analogWrite(7,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        analogWrite(8,100);
        analogWrite(7,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        analogWrite(8,175);
        analogWrite(7,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        analogWrite(8,255);
        analogWrite(7,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        analogWrite(8,0);
        analogWrite(7,0);
        break;
    }
  } 
  else if (10 * scale.get_units(5) < 70000) {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(11,0);
    analogWrite(7,255);
    analogWrite(8,255);
    analogWrite(9,255);
    analogWrite(10,0);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        analogWrite(9,60);
        analogWrite(7,60);
        analogWrite(8,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        analogWrite(9,100);
        analogWrite(7,100);
        analogWrite(8,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        analogWrite(9,175);
        analogWrite(7,175);
        analogWrite(8,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        analogWrite(9,255);
        analogWrite(7,255);
        analogWrite(8,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        analogWrite(9,0);
        analogWrite(7,0);
        analogWrite(8,0);
        break;
    }
  }
  else if (10 * scale.get_units(5) < 79000) {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(11,0);
    analogWrite(7,255);
    analogWrite(8,255);
    analogWrite(9,255);
    analogWrite(10,255);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        analogWrite(10,60);
        analogWrite(7,60);
        analogWrite(8,60);
        analogWrite(9,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        analogWrite(10,100);
        analogWrite(7,100);
        analogWrite(8,100);
        analogWrite(9,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        analogWrite(10,175);
        analogWrite(7,175);
        analogWrite(8,175);
        analogWrite(9,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        analogWrite(10,255);
        analogWrite(7,255);
        analogWrite(8,255);
        analogWrite(9,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        analogWrite(10,0);
        analogWrite(7,0);
        analogWrite(8,0);
        analogWrite(9,0);
        break;
    }
  }
  else {
    analogWrite(4,255);
    analogWrite(5,255);
    analogWrite(7,255);
    analogWrite(8,255);
    analogWrite(9,255);
    analogWrite(10,255);
    analogWrite(11,255);
    switch (LEDstatus){ 
        case 'a':
        analogWrite(4,60);
        analogWrite(5,60);
        analogWrite(11,60);
        analogWrite(7,60);
        analogWrite(8,60);
        analogWrite(9,60);
        analogWrite(10,60);
        break;
        case 'b':
        analogWrite(4,100);
        analogWrite(5,100);
        analogWrite(11,100);
        analogWrite(7,100);
        analogWrite(8,100);
        analogWrite(9,100);
        analogWrite(10,100);
        break;
        case 'c':
        analogWrite(4,175);
        analogWrite(5,175);
        analogWrite(11,175);
        analogWrite(7,175);
        analogWrite(8,175);
        analogWrite(9,175);
        analogWrite(10,175);
        break;
        case 'd':
        analogWrite(4,255);
        analogWrite(5,255);
        analogWrite(11,255);
        analogWrite(7,255);
        analogWrite(8,255);
        analogWrite(9,255);
        analogWrite(10,255);
        break;
        case 'e':
        analogWrite(4,0);
        analogWrite(5,0);
        analogWrite(11,0);
        analogWrite(7,0);
        analogWrite(8,0);
        analogWrite(9,0);
        analogWrite(10,0);
        break;
    }
  }
  
}
