#include <ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
const int trigPin = D6;
const int echoPin = D5;
long duration;
int distanceCm;
const char* ssid = "GoVegan";
const char* password = "veganpower";
const int relayPin = D7                                                                                                                                 ;
int wifi = D0;
int per = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(wifi, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(wifi, HIGH);
  lcd.init();
  lcd.backlight();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CONNECTING TO");
    lcd.setCursor(0, 1);
    lcd.print("INTERNET");
    Serial.println("Connecting to WiFi");
    digitalWrite(wifi, LOW);
    delay(500);
    lcd.clear();
    digitalWrite(wifi, HIGH);
    delay(500);
  }
  digitalWrite(wifi, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CONNECTED TO");
  lcd.setCursor(0, 1);
  lcd.print("INTERNET");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PROJECT GUIDE");
  lcd.setCursor(0, 1);
  lcd.print("Dr.RASHMI JAIN");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAGAN BAGHEL");
  lcd.setCursor(0, 1);
  lcd.print("GROUP LEADER");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("JANHVI");
  lcd.setCursor(0, 1);
  lcd.print("KUMBHARKAR");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PRACHI");
  lcd.setCursor(0, 1);
  lcd.print("MUNDHARIKAR");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ANUSHKA");
  lcd.setCursor(0, 1);
  lcd.print("KSHIRSAGAR");
  delay(2000);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  Serial.println(distanceCm);
  per = map(distanceCm, 20, 3, 0, 100);
  if (per < 0)
  {
    per = 0;
  }
  else if (per > 100)
  {
    per = 100;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("~ WATER LEVEL ~");
  lcd.setCursor(0, 1);
  lcd.print(per);
  lcd.print(" %");
  delay(4000);
  if (per < 75 && per >= 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("~ PUMP STATUS ~");
    lcd.setCursor(0, 1);
    lcd.print("ON");
    digitalWrite(relayPin, HIGH);
    delay(2000);
  } else if (per >= 75 && per <= 100)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("~ PUMP STATUS ~");
    lcd.setCursor(0, 1);
    lcd.print("OFF");
    digitalWrite(relayPin, LOW);
    delay(2000);
  }
  Serial.println(per);
  HTTPClient http;
  http.begin("http://www.techvegan.in/neotank/level.php?level=" + (String)per);
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    String value = http.getString();
    Serial.println(value);
    delay(1000);
  }
  http.end();
  delay(2000);
}
