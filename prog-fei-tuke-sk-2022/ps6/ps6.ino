#include <avr/wdt.h>
#include <Wire.h>
#include "lcd_wrapper.h"
#include "mastermind.h"

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(A0, INPUT);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
//  wdt_enable(WDTO_8S);
  lcd_init();
  lcd_print("   Mastermind   ");
  char* code = generate_code(0, 4);
  lcd_print_at(1, 1, "Enter a number");
  turn_off_leds();
  Serial.println(code);
  play_game(code);
}
void loop() {
//  wdt_reset();
}
