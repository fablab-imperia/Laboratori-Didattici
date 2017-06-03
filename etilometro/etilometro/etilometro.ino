#include "LiquidCrystal_I2C.h"


#define ALCOHOL_SENSOR_PIN A0

#define ZERO_LEVEL 100
#define SOBER_LEVEL 170
#define ONE_BEER_LEVEL 250
#define TWO_BEERS_LEVEL 500
#define DRUNK_LEVEL 600

#define BAC_BEER_RATE 0.2


LiquidCrystal_I2C lcd(0x27,16,4);


void aggiorna_lcd(int valore_sensore)  
{
  lcd.setCursor(0,0);
  lcd.print("Sensore: ");
  lcd.setCursor(9,0);
  lcd.print(valore_sensore);
  lcd.setCursor(0,1);
  lcd.print("BAC: ");
  lcd.setCursor(5,1);

  float bac = (float(BAC_BEER_RATE) / ONE_BEER_LEVEL) * valore_sensore;
  
  lcd.print(bac);
  lcd.setCursor(10,1);
  lcd.print("%");

  lcd.setCursor(0,3);
     if (valore_sensore <= ZERO_LEVEL)
     {
      lcd.print("Nessun valore   ");

      }
    else if (valore_sensore > ZERO_LEVEL && valore_sensore < SOBER_LEVEL)
     {
      lcd.print ("Uhm...Astemmio??");
      }   
    else if (valore_sensore > SOBER_LEVEL && valore_sensore < ONE_BEER_LEVEL)
     {
      lcd.print ("Una birrozza?   ");
      }
      else if (valore_sensore > ONE_BEER_LEVEL && valore_sensore < TWO_BEERS_LEVEL)
     {
      lcd.print ("Sei al limite!! ");
      }
      else if (valore_sensore > TWO_BEERS_LEVEL && valore_sensore < DRUNK_LEVEL)
     {
      lcd.print ("Addio Patente!! ");
      }
      else if (valore_sensore > DRUNK_LEVEL)
     {
      lcd.print ("Ambulanzaaaa!!! ");
      }
     else 
     {
       lcd.print("Boh...Non Saprei"); 
     }
}


void setup() {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {

    Serial.print("ALCOHOL: ");
    int quantita_alcohol = analogRead(A0);

    Serial.println(quantita_alcohol);
    delay(2000);

    aggiorna_lcd(quantita_alcohol);


}


