#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <FastLED.h>
//----------------------------
String wybor="rainbow";//ustawienia domyślne programu
String tmp="rainbow";//ustawienia domyślne programu
int r=0;
int g=0;
int b=0;
int t=0;
ESP8266WiFiMulti WiFiMulti;
#define LED_PIN     5
#define NUM_LEDS    54
#define MIC         A0
CRGB leds[NUM_LEDS];
#define main_url "http://ADRES_IP_SERVERA/ARDUINOPROJECT/LED/start.php"//adres pliku start.php
//w miejscu ADRES_IP_SERWERA umieść swój adres
//----------------------------
void setAll(byte red, byte green, byte blue);
//----------------------------
void setup() {
  pinMode(MIC,INPUT);
 FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("SSID", "PASSWORD");// Tutaj wpisz dane logowania do swojego wifi

}
//----------------------------------------
String option(String url)
{
   String payload;
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

   // Serial.print("[HTTP] begin...\n");
    if (http.begin(client, url )) {  // HTTP


      //Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
      //  Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
         payload = http.getString();
          Serial.println(payload);
        }
      } else {
        return "error";
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

return payload;
}
//----------------------------------------
void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
//----------------------------------------
void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue);
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(SpeedDelay);
  }
 
  delay(ReturnDelay);
}

//-----------------------------------------

void breath_random(){

  int r=random(255), g=random(255),b=random(255);
  int red,gre,blu;
    Serial.println("--------------");
  Serial.println(r);
    Serial.println(g);
      Serial.println(b);
    // Fade IN
    for(int k = 0; k < 256; k++) {
      if(k<=r)
      red=k;
        if(k<=r) 
       gre=k;
        if(k<=b)
        blu=k;
       setAll(red,gre,blu);
      
      showStrip();
      delay(3);
    }
    // Fade OUT
     for(int k = 255; k >= 0; k--) {
     if(red>0)
      red--;
        if(gre>0) 
       gre--;
        if(blu>0)
        blu--;
       setAll(red,gre,blu);
      
      showStrip();
      delay(3);
    }
  
}
void breath_one(int r, int g, int b){
  int red=0,gre=0,blu=0;
    // Fade IN
    for(int k = 0; k < 256; k++) {
      if(k<=r)
      red=k;
        if(k<=g) 
       gre=k;
        if(k<=b)
        blu=k;
       setAll(red,gre,blu);
      
      showStrip();
      delay(3);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) {
     if(red>0)
      red--;
        if(gre>0) 
       gre--;
        if(blu>0)
        blu--;
       setAll(red,gre,blu);
      
      showStrip();
      delay(3);
    }
  
}
//------------------------------------------


void RGBLoop(){
  for(int j = 0; j < 3; j++ ) {
    // Fade IN
    for(int k = 0; k < 256; k++) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      showStrip();
      delay(3);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) {
      switch(j) {
        case 0: setAll(k,0,0); break;
        case 1: setAll(0,k,0); break;
        case 2: setAll(0,0,k); break;
      }
      showStrip();
      delay(3);
    }
  }
}

//------------------------------------
void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}
void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}
//----------------------------------------------
void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for (j = 0; j < 256; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < NUM_LEDS; i++) {
      c = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c + 1), *(c + 2));
    }
    showStrip();
    delay(SpeedDelay);
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];

  if (WheelPos < 85) {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
 
  for(int j=0; j<NUM_LEDS*2; j++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<NUM_LEDS; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
     
      showStrip();
      delay(WaveDelay);
  }
}
//--------------------------------------
void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for(uint16_t i=0; i<NUM_LEDS; i++) {
      setPixel(i, red, green, blue);
      showStrip();
      delay(SpeedDelay);
  }
}//-------------------------------------

void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
  setAll(0,0,0);
 
  for(int i = 0; i < NUM_LEDS+NUM_LEDS; i++) {
   
   
    // fade brightness all LEDs one step
    for(int j=0; j<NUM_LEDS; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
   
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <NUM_LEDS) && (i-j>=0) ) {
        setPixel(i-j, red, green, blue);
      }
    }
   
    showStrip();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
   
    oldColor = strip.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
   
    strip.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
//--------------------------------------
void music(int red, int green, int blue)
{
double maxim=50;
  int t=time_s();
  int k=15000/t;
  for(int i=0;i<500;i++)
  {
    double k = analogRead(MIC);
    Serial.println(k);
    if(k>maxim)
    maxim=k;
   
  delay(30);
  
  k/=maxim;
  int r=(int)round(red*k);
  int g=(int)round(green*k);
  int b=(int)round(blue*k);
   setAll(r ,g,b);
   showStrip();
  }  
  
  
  
  //for (j = 0; j < round((k / 30) * 256); j++) { // 5 cycles of all colors on wheel
   // for (i = 0; i < NUM_LEDS; i++) {
   //   c = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
     // setPixel(i, *c, *(c + 1), *(c + 2));
   // }
    //showStrip();
    // delay(SpeedDelay);
  //}
}

//---------------------------------------
int red()
{
  tmp=option("http://ADRES_IP_SERVERA/ARDUINOPROJECT/LED/red.php");
  //w miejscu ADRES_IP_SERWERA umieść swój adres
  
 
  if(tmp=="error")
  {
    tmp=r;
  }
 
  return tmp.toInt();
}
int blue()
{

  tmp=option("http://ADRES_IP_SERVERA/ARDUINOPROJECT/LED/blue.php");
  //w miejscu ADRES_IP_SERWERA umieść swój adres
  if(tmp=="error")
  {
    tmp=b;
  }
 
  return tmp.toInt();
}
int green()
{

  tmp=option("http://ADRES_IP_SERVERA/ARDUINOPROJECT/LED/green.php");
  //w miejscu ADRES_IP_SERWERA umieść swój adres
  if(tmp=="error")
  {
    tmp=g;
  }
 
  return tmp.toInt();
}
int time_s()
{

  String w=option("http://ADRES_IP_SERVERA/ARDUINOPROJECT/LED/time.php");
  //w miejscu ADRES_IP_SERWERA umieść swój adres
  return w.toInt();
}


//---------------------------------------
void loop() {
  tmp=option(main_url);
  //String wybor="music";
 
  if(tmp!="error")
  {
    wybor=tmp;
  }
  
  if(wybor=="rainbow")
  {
    rainbowCycle(10);
  }
  else if(wybor=="rgbloop")
  {
    RGBLoop();
  }
  else if(wybor=="runniglight")
  {
    r=red();
  g=green();
  b=blue();
  t=50;
   RunningLights(r,g,b,t);
  }
  else if(wybor=="knightrider")
  {
    CylonBounce(0xff, 0, 0, 4, 10, 50);
  }
  else if(wybor=="cyclonbounce")
  {r=red();
  g=green();
  b=blue();
 
    CylonBounce(r,g,b, 4, 10, 50);
  }
  else if(wybor=="setall")
  {r=red();
  g=green();
  b=blue();

    setAll(r,g,b);
  }  
  else if(wybor=="colorwipe")
  {r=red();
  g=green();
  b=blue();
  t=50;
     colorWipe(r,g,b, t);
     colorWipe(0x00,0x00,0x00, t);
  }else if(wybor=="meteor")
  {
    r=red();
  g=green();
  b=blue();
  t=50;
     meteorRain(r,g,b,10, 64, true, t);
  }
  else if(wybor=="music")
  {r=red();
  g=green();
  b=blue();
  
    music(r,g,b);
  } else if(wybor=="breath_one")
  {
    r=red();
  g=green();
  b=blue();
 
     breath_one(r,g,b);
    
  } else if(wybor=="breath_random")
  {
    
     breath_random();
  }
  else if(wybor=="off")
  {
    setAll(0,0,0);
    delay(1000);
  }
   
}
