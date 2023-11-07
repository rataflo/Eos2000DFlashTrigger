/*
* Simple code to trigger flash sync when flash from camera is triggered and captured with photodiode.
* Run on attiny85.
* Flo Gales 2023: Do what the fuck you want license. Licence rien à branler.
*/

// Pins are switched from schematic.
#define DIODE_PIN A2
#define FLASH_PIN A1

void setup() {
  pinMode(DIODE_PIN, INPUT);
  pinMode(FLASH_PIN, OUTPUT);
  analogWrite(FLASH_PIN, 0);
}

void loop() {
  int value = analogRead(DIODE_PIN);
  if(value > 900){
    // Fire in the hall
    analogWrite(FLASH_PIN, 1024);
    delay(100);
    analogWrite(FLASH_PIN, 0);
  } 
}
