#include <DHT.h>


DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(5, OUTPUT); 
  pinMode(8, OUTPUT); 
}

void loop() {
  double nem = dht.readHumidity();
  double sicaklik = dht.readTemperature(); 

  
  Serial.print("Sicaklik: ");
  Serial.print(sicaklik);
  Serial.print(" C,  Nem: ");
  Serial.print(nem);
  Serial.println(" %");


  if (sicaklik > 25) {
    digitalWrite(5, HIGH);  
    digitalWrite(8, LOW);   
  } else {
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
  }

  delay(1000); 
}
