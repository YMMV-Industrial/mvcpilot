#include <avr/io.h>
int algd ; // analog data variable

int lp[4] = {2,1,0,4}; //LED Pin D1-red, yellow, red, D4-yellow

void setup() {
  //ADMUX |= (1 << REFS1); // internal ref voltage of 1.1v
  //ADMUX |= (1 << MUX0);
  //ADMUX |= (1 << MUX1); // set ADC3 as input 0011
  // change read order for ADCH & ADCL registers
  //ADMUX |= (1 << ADLAR);
  // forcing byte value ref v 1.1 volts,  ADC3, left adjust
  ADMUX = 0b10100011;
  // enable ADC Control & status register A
  // ADEN|ADSC|ADATE|ADIF|ADIE|ADPS2|ADPS1|ADPS0 <- ADCSRA
  //ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 
  // forcing byte value  to divide chip clock speed by 128, 8mhz ? 128 == 62 khz (between 50 & 200)
  ADCSRA = 0b10000111;

  // Initiate pins as output and set leds to off
  for (int i = 0 ; i < 4; i++) {
    pinMode(lp[i], OUTPUT);
    digitalWrite(lp[i], LOW);
  } 
}

void blinknotice(int pin, int bdur, int cyc){
  for (int i = 0 ; i <= cyc; i++){
    digitalWrite(lp[pin], HIGH);
    delay(bdur);
    digitalWrite(lp[pin], LOW);
    delay(bdur);
  }
  delay(500);
}

void motor1on(int pdur){
  digitalWrite(lp[3], HIGH);
  delay(m1dur);
  digitalWrite(lp[3], LOW);
}

void motor2on(int vdur) {
  digitalWrite(lp[0], HIGH);
  delay(m2dur);
  digitalWrite(lp[0], LOW);
}


// To Do, use an ADC input to temporarily disable either motor from operating.

// control loop
void loop() {
  ADCSRA |= (1 << ADSC);
//  algd = ADCH ; 
  delay(50); // possibly shrinkable?  expectiong 208 microsecond delay for reading pin 3
  blinknotice(2,500,2);
  motor1on(15000);
  delay(2000);
  blinknotice(1,500,2);
  motor2on(15000);

}
