#include <TinyGPS++.h>

TinyGPSPlus gps;

void setup()
{
  Serial.begin(115200);                    // For debugging
  Serial1.begin(9600, SERIAL_8N1, 16, 17); // For GPS module (TX=16, RX=17)
}

void loop()
{
  // Continuously read from the GPS module
  while (Serial1.available() > 0)
  {
    gps.encode(Serial1.read());

    // Check if valid location data is available
    if (gps.location.isValid())
    {
      Serial.println("GPS Data:");
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("Speed (km/h): ");
      Serial.println(gps.speed.kmph());
      Serial.print("Satellites: ");
      Serial.println(gps.satellites.value());
      Serial.print("Altitude (m): ");
      Serial.println(gps.altitude.meters());
    }
    else
    {
      Serial.println("No valid GPS data available.");
    }
  }
}