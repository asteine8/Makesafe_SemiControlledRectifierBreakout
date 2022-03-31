/**
 * Arduino Pulse Generator
 * This program creates positive pulses on an output pin
 * of a duration specified via serial. Duration is in milli-seconds.
 * 
 * To use connect ground to pcb ground and OUTPUT_PIN to where
 * the pulse needs to go. Then connect the arduino via usb and
 * enter how many milliseconds you want to pulse for into the
 * serial moniter. Pulse occures immediatly after command is sent.
 * LED_BUILTIN corresponds to output to give visal feedback.
 * Duration is in integer milliseconds
 * 
 * Alexandra Steiner - March 30, 2022
 * v1.0
 */


#define OUTPUT_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(OUTPUT_PIN, LOW);
  
//  attachInterrupt(digitalPinToInterrupt(INPUT_PIN), startDelay, FALLING);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    int inputInt = Serial.parseInt();

    if (inputInt > 0) {
      // say what you got:
      Serial.print("Creating Pulse with Duration: ");
      Serial.println(inputInt);

      // Generate a positive pulse with the specified duration
      pulse(inputInt);
    } 
  }
  
}

void pulse(int ms) {
  digitalWrite(OUTPUT_PIN, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(ms);

  digitalWrite(OUTPUT_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}
