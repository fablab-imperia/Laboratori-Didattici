#define ALCOHOL_SENSOR_PIN A0

#define ZERO_LEVEL 100
#define SOBER_LEVEL 170
#define ONE_BEER_LEVEL 250
#define TWO_BEERS_LEVEL 500
#define DRUNK_LEVEL 600




void setup() {

  Serial.begin(9600);
}

void loop() {

    Serial.print("ALCOHOL: ");
    int quantita_alcohol = analogRead(A0);

    Serial.println(quantita_alcohol);
    delay(2000);

    if (quantita_alcohol <= ZERO_LEVEL)
     {
      Serial.println ("Quantità alcool quasi nulla");
      }
    else if (quantita_alcohol > SOBER_LEVEL && quantita_alcohol < ONE_BEER_LEVEL)
     {
      Serial.println ("Quantità alcool almeno una birrozza");
      }
      else if (quantita_alcohol > ONE_BEER_LEVEL && quantita_alcohol < TWO_BEERS_LEVEL)
     {
      Serial.println ("Quantità alcool al limite della soglia");
      }
      else if (quantita_alcohol > TWO_BEERS_LEVEL && quantita_alcohol < DRUNK_LEVEL)
     {
      Serial.println ("Quantità dei punti della patente inferiore al tuo tasso alcolico");
      }
      else if (quantita_alcohol > DRUNK_LEVEL)
     {
      Serial.println ("AAA cercasi Ambulanza");
      }
}


