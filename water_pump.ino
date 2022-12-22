const int relayEnable = 2;
const int sensorPin = A0;
const int thresholdMax = 800;
const int thresholdMin = 10;

void setup() {
  pinMode(relayEnable, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  Serial.println("Soil Moisture Level: ");
  delay(1000);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, thresholdMax, thresholdMin, 0, 100);
  Serial.print("Moisture: ");
  Serial.print("sensorValue");
  Serial.println("%");

  if (sensorValue < 0) {
    digitalWrite(relayEnable, LOW);
  } else {
    digitalWrite(relayEnable, HIGH);
    Serial.println("Relay OFF");
  }

  delay(1000);
}
