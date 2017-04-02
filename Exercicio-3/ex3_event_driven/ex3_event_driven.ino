#include"event_driven.h"
int old = 0;
int interval = 0;
int buttonState = 1;
int interesseTimer = 0;
int vecInt[3] = {0,0,0};
void button_listen(int pin){
  buttonState = digitalRead(pin);
  vecInt[pin-1] = 1;
}
void timer_set(int ms){
  interval = ms;
  old = millis();
  interesseTimer = 1;
}

void setup (){
 pinMode(LED_PIN, OUTPUT);
 pinMode(BUT_PIN, INPUT);
 pinMode(BUT_PIN1, INPUT);
 pinMode(BUT_PIN2, INPUT);
 init1();
}
void loop(){
  
  /* detect new events*/
  //int newButtonState = digitalRead(BUT_PIN);
  if(buttonState != newButtonState){
    buttonState = newButtonState;
    button_changed(BUT_PIN, buttonState);
  }
  
 // button_changed(...);
  if(interesseTimer && millis() >= (old + interval)){
   // Serial.println(old);
    interesseTimer = 0;
    timer_expired();
  }
}
