// the setup function runs once when you press reset or power the board
int ledRed = D1; //initialize LED connected to digital pin D4 -- Red
int ledYellow = D3; //Yellow
int ledGreen = D2; //Green

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledRed, OUTPUT); //set digital pin as output
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //turn off all LEDS first
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  delay(1000);
  digitalWrite(ledRed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // leave on for 1 sec
  digitalWrite(ledYellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // leave on for 1 sec
  digitalWrite(ledGreen, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // leave on for 1 sec
}

//Reference: https://www.arduino.cc/en/Tutorial-0007/BlinkingLED
