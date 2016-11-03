/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 6;     // the number of the pushbutton pin
const int button2Pin = 3;
const int ledPin =  13;      // the number of the LED pin
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int button2State = 0;
bool flag;

void setup() {
  //Serial.read();
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);     
  pinMode(button2Pin, INPUT_PULLUP);
  Mouse.begin();
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  button1();
  button2();
  Serial.println(buttonState);
  if(flag){        
      Keyboard.set_key1(KEY_ESC);
      Keyboard.send_now();
      flag = false;
    }
}

void button1(){
  buttonState = digitalRead(buttonPin);
  Serial.println(button2State);
   // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    Mouse.click();
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  
  delay(50);              // wait for a 1/20 second
}

void button2(){
  button2State = digitalRead(button2Pin);
   // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (button2State == LOW) {
    flag = true;
    //Serial.println("Button is pressed!");
  } 
  else {
   //Serial.println("Button is not pressed...");
  }
  
  delay(50);              // wait for a 1/20 second
}


