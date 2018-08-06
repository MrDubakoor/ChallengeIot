
#include <SPI.h>
#include <ESP8266WiFi.h>
char ssid[] = "";           // SSID of your WiFi
char pass[] = "";            // password of your WiFi
IPAddress server(,,,);       // the fix IP address of the server
WiFiClient client;
void setup() {
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  Serial.println(".");
  client.println("Hello server!?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  delay(2000);                  // client will trigger the communication after two seconds
}
