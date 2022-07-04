#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int IR1 = A1, IR2 = A2;
const int redled = 13, greenled = 10, buzzer = 9;
int s_val_1 = 0, s_val_2 = 0, count = 0;

void setup()
{
  lcd.begin(16, 2);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  s_val_1 = digitalRead(IR1);
  s_val_2 = digitalRead(IR2);
  Serial.print(s_val_1);
  Serial.println("=IR1\n");
  printf("/n");
  printf("/n");
  Serial.print(s_val_2);
  Serial.println("=IR2\n");


  if (s_val_1 == 0)
  {

    delay(10);
    count++;
    delay(500);
    digitalWrite(greenled, 1);
    digitalWrite(buzzer, 1);
    lcd.setCursor(0, 0);
    lcd.print(count);
    lcd.setCursor(2, 0);
    lcd.print(": Students");
    lcd.setCursor(0, 1);
    lcd.print(" Are Visted ");
    delay(1000);
    lcd.clear();
    tone(buzzer, 4000, 500);
  }
  else if (s_val_2 == 0)
  {
    if (count != 0)
      count--;
    delay(500);
    digitalWrite(redled, 1);
    digitalWrite(buzzer, 1);
    lcd.setCursor(0, 0);
    lcd.print(count);
    lcd.setCursor(2, 0);
    lcd.print(": Students");
    lcd.setCursor(0, 1);
    lcd.print("Are In");
    delay(1000);
    lcd.clear();
    tone(buzzer, 4000, 500);

  }
  else
  {
    digitalWrite(redled, 0);
    digitalWrite(greenled, 0);
    digitalWrite(buzzer, 0);
    lcd.setCursor(0, 0);
    lcd.print("No Student");
    lcd.setCursor(0, 1);
    lcd.print("Entered Class");
    delay(1000);
    lcd.clear();
  }
}
