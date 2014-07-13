const int fadePinR = 7;    // The pretty blue LED
const int fadePinG = 8;    // The pretty blue LED
const int fadePinB = 9;    // The pretty blue LED
const int redPin = 10;    // Red LED
const int greenPin = 11;  // Green LED
const int fadeAmount = 5; // Increment to adjust brightness
 
int incomingByte;   // A variable to read incoming serial data into
int brightness = 0; // How bright the LED is
 
void setup()  {
  // Initialize serial communication:
  Serial.begin(9600);
 
  // Declare outputs:
  pinMode(fadePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
} 
 
void loop()  {
  // Indicate ready state
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
 
  if (Serial.available() > 0) {
    // Indicate change state
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
 
    // See if there's incoming serial data:
    incomingByte = Serial.read();
 
    if (incomingByte == 'H' && brightness < 255) {
      // Cycle the blue LED from dim to bright
      for (brightness = 0; brightness < 255; brightness += fadeAmount) {
        analogWrite(fadePin, brightness);
        delay(30);
      }
    } else if (incomingByte == 'L' && brightness > 0) {
      // Cycle the blue LED from bright to dim
      for (brightness = 255; brightness > 0; brightness -= fadeAmount) {
        analogWrite(fadePin, brightness);
        delay(30);
      }
    }
  }
}
