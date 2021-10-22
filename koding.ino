#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
int trigPin = 11;
int echoPin = 12; 
int ledON = 2;
int ledOFF = 4;
long duration; 
int jarakCm;

void setup() {
  lcd.begin();
  pinMode(trigPin, OUTPUT); //trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); //echoPin sebagai INPUT
  pinMode(ledON, OUTPUT); //ledbiru sebagai OUTPUT
  pinMode(ledOFF, OUTPUT); //ledmerah sebagai OUTPUT
  servo.attach(10);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);//trigPin diberi sinyal LOW (di OFF kan)
  delayMicroseconds(2); //selama 1 microseconds
  digitalWrite(trigPin, HIGH); //trigPin diberi sinyal HIGH
  delayMicroseconds(5); // selama 1 microseconds
  digitalWrite(trigPin, LOW);//
  duration = pulseIn(echoPin, HIGH); //variabel echoPin menunggu sinyal pantul HIGH
  jarakCm = duration*0.034/2; // rumus jarak dalam cm
  Serial.print("Jarak ");
  Serial.print(jarakCm);
  Serial.println(" cm");
  if (jarakCm <= 15)
    {
    delay(1000);
    servo.write(170);
    digitalWrite(ledON,HIGH); //High 5 Volt
    digitalWrite(ledOFF,LOW); //Low 0.2 Volt
    lcd.setCursor(0,0);
    lcd.print("Luckman gantenk");
    lcd.setCursor(0,1);
    lcd.print(String("Jarak : ") + jarakCm + (" cm     "));
    }
    else
    {
    delay(1000);
    servo.write(0);
    digitalWrite(ledON,LOW); //Low 0.2 Volt
    digitalWrite(ledOFF,HIGH); //High 5 Volt
    lcd.setCursor(0,0);
    lcd.print("sampah-nothing ");
    lcd.setCursor(0,1);
    lcd.print(String("Jarak : ") + jarakCm + (" cm     "));
    }
}
