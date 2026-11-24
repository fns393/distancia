#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 2;
const int echoPin = 3;

long duracao;
int distancia;
int old_distancia = -999;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  if (distancia != old_distancia) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Distancia:");

    lcd.setCursor(1, 1);
    lcd.print(String(distancia) + " cm");

    old_distancia = distancia;
  }

  Serial.println("Distancia: " + String(distancia) + " cm");

  delay(500);
}
