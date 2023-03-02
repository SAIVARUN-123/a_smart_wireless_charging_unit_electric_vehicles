   
 
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
#define SS_PIN 10
#define RST_PIN 9
int RED=3;
int Green=2;
int L6=4;
int BUZZER=4; 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  pinMode(RED,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(7,1);
  pinMode(6,1);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  lcd.init();
  lcd.backlight();
  

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "A3 6A 11 0A") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Name: VARUN");
    Serial.println("Vehicle.No: TN31AS5552");
    Serial.println("-----------------------------");
    Serial.println("");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Name: VARUN");
    lcd.setCursor(0,1);
    lcd.print("V.No:TN31AS5552");
    digitalWrite(Green,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(L6,HIGH);
    digitalWrite(BUZZER,LOW);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(1000);
  }
  else if (content.substring(1) == "34 FF DF 0B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Name: NISHANTH");
    Serial.println("Vehicle.No: TN07DB-8289");
    Serial.println("-----------------------------");
    Serial.println("");
    lcd.clear();
    lcd.print("Name:NISHANTH");
    lcd.setCursor(0,1);
    lcd.print("V.No:TN07DB8289");
    digitalWrite(RED,LOW);
    digitalWrite(Green,HIGH);
    digitalWrite(L6,HIGH);
    digitalWrite(BUZZER,LOW);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(6,1);
    delay(200);
    digitalWrite(6,0);
    delay(1000);
  }
  else 
  { 
    Serial.println(" Access Denied");
    Serial.println();
    lcd.clear();
    lcd.print("ACCESS DENIED");
    Serial.println("-----------------------------");
    Serial.println("");
    digitalWrite(RED,HIGH);
    digitalWrite(Green,LOW);
    digitalWrite(L6,LOW);
    digitalWrite(BUZZER,HIGH);
    digitalWrite(7,1);
    delay(200);
    digitalWrite(7,0);
    delay(200);
    digitalWrite(7,1);
    delay(200);
    digitalWrite(7,0);
    delay(200);
    digitalWrite(7,1);
    delay(200);
    digitalWrite(7,0);
    delay(1000);
  }
 
 
} 
