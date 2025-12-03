#include <DHT.h>
DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  
  pinMode(5, OUTPUT); 
  pinMode(8, OUTPUT); 
}

void loop() {

  double sicaklik = dht.readTemperature();
  double nem = dht.readHumidity();


  if (isnan(sicaklik) || isnan(nem)) {
 
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    return; 
  }


  if (sicaklik > 25.0) {

    digitalWrite(5, HIGH);
    digitalWrite(8, LOW);
  } else {

    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
  }

  Serial.print("Sicaklik: ");
  Serial.print(sicaklik);
  Serial.print(" °C\tNem: ");
  Serial.print(nem);
  Serial.println(" %");


  delay(1000);
}

