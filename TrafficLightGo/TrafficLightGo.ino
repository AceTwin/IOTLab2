// the setup function runs once when you press reset or power the board

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//Setup WiFi stuff
const char* ssid = ""; //Enter Wifi ssid inbetween quotes
const char* password = ""; //Enter Wifi password inbetween quotes

int red = D4; //initialize LED connected to digital pin D4 -- Red
int yellow = D3; //Yellow
int green = D2; //Green

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
  pinMode(red, OUTPUT); //set digital pin as output
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //turn off all LEDS first
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
  //red
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // leave on for 1 sec
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);// leave off for 1 sec
  //yellow
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(yellow, LOW);
  delay(1000);
  //green
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(1000);
}

//Reference: https://www.arduino.cc/en/Tutorial-0007/BlinkingLED
//Wifi Reference: http://cyaninfinite.com/tutorials/getting-started-with-the-wemos-d1-esp8266-wifi-board/#Running-a-Simple-Web-Server
