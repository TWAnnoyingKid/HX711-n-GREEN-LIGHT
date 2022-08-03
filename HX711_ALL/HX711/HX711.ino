#include "HX711.h"

// HX711 接線設定
const int DT_PIN = 3;
const int SCK_PIN = 2;
const int scale_factor =121;  

HX711 scale;

void setup() {
  Serial.begin(9600);
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
  float weight = scale.get_units(20);
  if (weight <=2){
    weight = 0;
  }
  int a = weight;
  a= weight/4;
  if (weight>0){
    Serial.print("WEIGHT : "); 
    Serial.print(weight, 0); 
    Serial.print("  //  "); 
    Serial.print("AMMO : "); 
    Serial.println(a); 
  }
  else{
    Serial.println("nothing on it"); 
  }
  
}
