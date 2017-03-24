#define LED_PIN 13
#define BUT_PIN A2
#include"event_driven.h"
int old = 0;
int interval = 0;
int buttonState = 1;
void button_listen(int pin){
  buttonState = digitalRead(pin);
}
void timer_set(int ms){
  interval = ms;
  old = millis();
}

void setup (){
 pinMode(LED_PIN, OUTPUT);
 pinMode(BUT_PIN, INPUT);
 init1();
 }
void loop(){
  /* detect new events*/
  int newButtonState = digitalRead(BUT_PIN);
  if(buttonState != newButtonState){
    buttonState = newButtonState;
    button_changed(BUT_PIN, buttonState);
  }
 // button_changed(...);
  if(millis() >= (old + interval))
    timer_expired();
}
