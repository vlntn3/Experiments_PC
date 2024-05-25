int LIGHT_SENSOR_PIN = A0;
int LED_PIN = 3;
int ANALOG_THRESHOLD = 500;
int analogValue;

void setup() {
pinMode(LED_PIN, OUTPUT);
}

void loop() {
analogValue = analogRead(LIGHT_SENSOR_PIN);
if(analogValue < ANALOG_THRESHOLD)
digitalWrite(LED_PIN, HIGH);
else
digitalWrite(LED_PIN, LOW);
}