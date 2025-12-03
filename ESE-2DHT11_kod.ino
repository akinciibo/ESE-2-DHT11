#include <DHT.h>
DHT dht(2, DHT11);
long sonYazma = 0;     
long yazmaraligi = 1000;  

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
    Serial.println("okunmadı:)");
    return;
  }

  if (sicaklik < 25) {
    digitalWrite(5, LOW);   
    digitalWrite(8, HIGH);   
  } else {
    digitalWrite(5, HIGH);   
    digitalWrite(8, LOW);   
  }

  long suan = millis(); 
  if (suan -  sonYazma >= yazmaraligi) {
     sonYazma = suan; 

    Serial.print("Sicaklik: ");
    Serial.print(sicaklik);
    Serial.print(" C, Nem: ");
    Serial.print(nem);
    Serial.println(" %");
  }
}
