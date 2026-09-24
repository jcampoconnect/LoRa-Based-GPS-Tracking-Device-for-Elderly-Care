// This sketch is for parsing the Latitude and Longitude of GPS Module connected to BLue Pill. 

#include <TinyGPS++.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = PB7, TXPin = PB6;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial GPS(RXPin, TXPin);

void setup(){
  Serial.begin(9600);
  GPS.begin(9600);
}

void loop(){
    

  // This sketch displays information every time a new sentence is correctly encoded.
  while (GPS.available() > 0){
    gps.encode(GPS.read());
    if (gps.location.isUpdated()){
      Serial.print("Lat= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Long= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }

}