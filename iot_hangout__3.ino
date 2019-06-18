/*DHT11 LIBRARY*/
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

/*DS18B20 LIBRARY*/
DHT dht(DHTPIN, DHTTYPE);

int water_sensor_value;
int temp_celsius_sol;
int apa_senzor = 0;

void setup(void) {
  Serial.begin(115200);
  dht.begin();
}

void loop(void) {
  water_sensor_value = analogRead(A0);
  apa_senzor = digitalRead(D3);

  /*Senzor de umiditate si temperatura din exterior*/
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Exterior Temperature (C) = ");
  Serial.println(t, 2);
  Serial.print("Exterior Humidity = ");
  Serial.println(h, 2);
  delay(10000);
  /*//timp de asteptare intre afisarile valorilor//*/
  /*notificare si cu asta*/


  /*!!WATER LEVEL SENSOR!!*/
  Serial.println("Umiditatea solului este:");
  Serial.println(water_sensor_value);
  //adaugare timp de refresh pt informatie

  Water_sensor();
  delay(10000);

  Serial.println("Nivelul apei este:");
  Serial.println(apa_senzor);
  delay(10000);

}

void Water_sensor() {
  if ((water_sensor_value < 1023) && (water_sensor_value > 700)) {
    Serial.println("Sol uscat!");
    //se trimite notificare
    //se actioneaza pompa din apasarea butonului corespunzator
  }
  else
  {
    if ((water_sensor_value < 600) && (water_sensor_value > 250)) {
      Serial.println("Am nevoie de apa!");
      //se trimite notificare
      //se actioneaza pompa din apasarea butonului corespunzator

    }
    else {
      if (water_sensor_value < 200) {
        Serial.println("Umiditate optima!");
        //Achievement unlocked!!
      }
    }
  }
}
