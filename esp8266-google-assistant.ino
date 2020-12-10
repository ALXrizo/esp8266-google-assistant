#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include "Config.h"

void setup() {
  
  Setup();
  
}

void loop() {
  //Esperar a recibir mensajes desde Adafruit IO
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(1000))) {
    //Comprobar si el mensaje es para el LED
    if (subscription == &led) {
      //Comprobar el mensaje
      if (strcmp((char *)led.lastread, "encender") == 0){
        digitalWrite(0, HIGH);        
      } else if (strcmp((char *)led.lastread, "apagar") == 0){
        digitalWrite(0, LOW);
      }
    }
  }
}
