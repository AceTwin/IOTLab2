// the setup function runs once when you press reset or power the board

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

IPAddress server(192, 168, 1, 21); //IP of webserver


//Setup WiFi stuff
const char* ssid = ""; //Enter Wifi ssid inbetween quotes
const char* password = ""; //Enter Wifi password inbetween quotes

int red = D5; //initialize LED connected to digital pin D4 -- Red
int yellow = D3; //Yellow
int green = D2; //Green

void setup() {
  //Wifi stuff
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); //5 second wait
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // initialize digital pins as output
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  //Turn off all LEDs initially
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

// the loop function runs over and over again forever
void loop() {
  delay(500);

  Serial.print("connecting to host");
  //Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 5000;
  if (!client.connect(server, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/state";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
//  while(1==1){
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: 192.168.1.21" + "\r\n\r\n"+
               //"Host: " + host + "\r\n" +  
               "Connection: close\r\n\r\n");
  int timeout = millis() + 2000;
  while (client.available() == 0) {
    Serial.print(".");
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  int len;
  String led;
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){ //while there is a connection
    String line = client.readStringUntil('\r');
    Serial.print(line);
    len = line.length(); //Getting the length of the line
    led = &line[len - 1]; //Read the position, find the state
  }
  Serial.println();
  Serial.println("This is the led:" + led);
  dostuff(led); //Call the light function
//  if (led == "1")
//  {
//    Serial.println("Red");
//  } else {Serial.println("Not Red");}
  Serial.println("<-- Headers complete -->");
  Serial.println();
  Serial.println("closing connection");
}

void dostuff(String state){
  //state is red
  if (state == "1")
  {
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  }                       
  
  //state is yellow
  if (state == "2")
  {
  digitalWrite(yellow, HIGH);
  }
   
  //state is green
  if (state == "3")
  {
  digitalWrite(green,HIGH);
  }

  //state is off
  if (state == "0")
  {
  //// turn the LEDs off by making the voltage LOW
  digitalWrite(red, LOW);    
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  }

  if (state =="4")
  {
    //loop traffic lights
//    while(state=="4")
//   {
      digitalWrite(red, HIGH);     // red on
      delay(1000);                //wait
      digitalWrite(red, LOW);     //red off  
      
      digitalWrite(yellow, HIGH); //yellow on
      delay(1000);     
      digitalWrite(yellow, LOW);  //yellow off
  
      digitalWrite(green,HIGH);   //green on
      delay(1000);  
      digitalWrite(green, LOW);
//    }
  }

  Serial.print("Works");
}


//Reference: https://www.arduino.cc/en/Tutorial-0007/BlinkingLED
//Wifi Reference: http://cyaninfinite.com/tutorials/getting-started-with-the-wemos-d1-esp8266-wifi-board/#Running-a-Simple-Web-Server
//Read HTTP:  https://www.esp8266.com/viewtopic.php?f=32&t=6463
//https://techtutorialsx.com/2016/07/17/esp8266-http-get-requests/
