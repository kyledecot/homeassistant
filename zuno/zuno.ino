ZUNO_SETUP_CHANNELS(
    ZUNO_SENSOR_MULTILEVEL(
        ZUNO_SENSOR_MULTILEVEL_TYPE_DISTANCE,
        SENSOR_MULTILEVEL_SCALE_METER,
        SENSOR_MULTILEVEL_SIZE_TWO_BYTES,
        2, // two decimals after dot
        getter
    )
);

int readPin = 9;
int triggerPin = 16;
byte controlState = 0;
word lastValue;

void setup() {
  Serial.begin();
  
  pinMode(readPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  
  digitalWrite(triggerPin, LOW);
}

void loop() {
  int tmp;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // read pulse width
  tmp = pulseIn(readPin, HIGH, 100000);
  if (tmp != 0) {
    lastValue = tmp / 58; // convert to cm, see datasheet
    Serial.println(lastValue);

    zunoSendReport(1);
  }
}

word getter() {
  return lastValue;
}
