#define LED_PIN 13
#define BUT_PIN A2
#include"sketch.h"
void button_changed(int pin, int v){
  digitalWrite(13, v);
  button_listen(BUT_PIN);
}
void timer_expired(){
  int val = digitalRead(LED_PIN);
  digitalWrite(LED_PIN, !val);
  timer_set(1000);
}
void init1(){
  timer_set(1000);
  button_listen(BUT_PIN);
}
