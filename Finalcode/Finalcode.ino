int ledPin = 13;           // LED connected to digital pin 13
int lightSensorPin = A0;   // Photoresistor connected to analog pin A0
int btnPin = 2;            // Button connected to digital pin 2
int threshold = 400;       // Light level threshold (adjust based on your sensor and environment)

int ledState = LOW;        // Current state of the LED
bool lastButtonState = HIGH; // Previous state of the button
unsigned long lastDebounceTime = 0;  // Last time the button state changed
unsigned long debounceDelay = 50;    // Debounce delay in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);       // Set the LED pin as an output
  pinMode(btnPin, INPUT_PULLUP); // Set the button pin as input with an internal pull-up resistor
}

void loop() {
  // Read the light sensor value
  int lightLevel = analogRead(lightSensorPin);

  // Control LED based on light sensor only if the button is not pressed
  if (digitalRead(btnPin) == HIGH) {  // Button not pressed
    if (lightLevel < threshold) {
      digitalWrite(ledPin, HIGH);   // Turn on the LED if light level is below the threshold
    } else {
      digitalWrite(ledPin, LOW);  // Turn off the LED if light level is above the threshold
    }
  }

  // Check for button press with debounce
  int buttonState = digitalRead(btnPin);
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (buttonState != ledState) {
      ledState = buttonState;
      digitalWrite(ledPin, ledState);
    }
  }

  // Update lastButtonState to the current state
  lastButtonState = buttonState;
}