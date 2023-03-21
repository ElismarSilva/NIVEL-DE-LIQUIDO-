#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pinLed 7

//Estado dos botões
int estadoPin1 = 0;
int estadoPin2 = 0;
int estadoPin3 = 0;
int estadoPin4 = 0;
int estadoPin5 = 0;

//Variaveis auxiliares
bool auxPin1 = false;
bool auxPin2 = false;
bool auxPin3 = false;
bool auxPin4 = false;


void setup() {

  Serial.begin(9600);
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("<OLAMUNDO.IO");
  lcd.setCursor(0, 1);
  lcd.print("NIVEL = ");
  lcd.setCursor(8, 1);
  lcd.print("00%");
  digitalWrite(pinLed, HIGH);
}

void loop() {
  estadoPin1 = digitalRead(pin1);
  estadoPin2 = digitalRead(pin2);
  estadoPin3 = digitalRead(pin3);
  estadoPin4 = digitalRead(pin4);
  estadoPin5 = digitalRead(pin5);

  if (estadoPin1 == LOW && auxPin1 == false) {
    digitalWrite(pinLed, LOW);
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("20");
    lcd.setCursor(10, 1);
    lcd.print("%");
    auxPin1 = true;
   
  }

  else if (estadoPin2 == LOW && auxPin2 == false ) {
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("40");
    lcd.setCursor(10, 1);
    lcd.print("%");
    auxPin2 = true;
  }
  else if (estadoPin3 == LOW && auxPin3 == false ) {
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("60");
    lcd.setCursor(10, 1);
    lcd.print("%");
    auxPin3 = true;
  }
  else if (estadoPin4 == LOW && auxPin4 == false ) {
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("80");
    lcd.setCursor(10, 1);
    lcd.print("%");
    auxPin4 = true;
  }
  else if (estadoPin5 == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("100");
    lcd.setCursor(11, 1);
    lcd.print("%");
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("NIVEL = ");
    lcd.setCursor(8, 1);
    lcd.print("");

  }

}
