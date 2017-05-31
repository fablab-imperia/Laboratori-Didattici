int luce=0 ;
int buzzerpin=7 ;


void setup() {
  pinMode(A0,INPUT) ;
  Serial.begin(9600);
  pinMode(buzzerpin,OUTPUT);
  digitalWrite(buzzerpin,HIGH);
 
}



void loop() {
  luce=analogRead(A0);
  Serial.print("valore luce") ;
  Serial.println(luce);

  tone(buzzerpin,440);
  
  if(luce < 25)
  { 

    Serial.println("NO TONE");
    noTone(buzzerpin);
    digitalWrite(buzzerpin,HIGH);
    
  }
  else
  {
    
   int freq=map(luce,25,100,20,20000);
   Serial.print("VALORE FREQUENZA: ");
   Serial.println(freq);
   tone(buzzerpin,freq);
  }
  //tone(buzzerpin,440);
   delay (100);

}

