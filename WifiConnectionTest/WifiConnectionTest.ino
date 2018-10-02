// the setup function runs once when you press reset or power the board

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//Setup WiFi stuff
const char* ssid = ""; //Enter Wifi ssid inbetween quotes
const char* password = ""; //Enter Wifi password inbetween quotes

int ledPin = D4; //initialize LED connected to digital pin D4 -- Red
int led1 = D3; //Yellow
int led2 = D2; //Green

void setup() {
  //Wifi stuff
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT); //set digital pin as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //turn off all LEDS first
  digitalWrite(ledPin, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(1000);
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // leave on for 1 sec
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // leave off for 1 sec
}

//Reference: https://www.arduino.cc/en/Tutorial-0007/BlinkingLED
//Wifi Reference: http://cyaninfinite.com/tutorials/getting-started-with-the-wemos-d1-esp8266-wifi-board/#Running-a-Simple-Web-Server
