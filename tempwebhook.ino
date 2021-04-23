// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN 7     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = D7;  // The on-board LED

void setup() {
  pinMode(led, OUTPUT);
  	Serial.begin(9600); 
	Serial.println("DHTxx test!");

	dht.begin();
}

void loop() {
    	float f = dht.getTempFarenheit();
  digitalWrite(led, HIGH);   // Turn ON the LED

  String temp = String(f);
  Particle.publish("temp", temp, PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}