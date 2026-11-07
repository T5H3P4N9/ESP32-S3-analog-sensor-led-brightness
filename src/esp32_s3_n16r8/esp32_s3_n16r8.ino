// ESP32-S3 N16R8 development board
const int analogPin = 7;
const int ledPin = 6;

const int inputSensorMinValue = 0;
const int inputSensorMaxValue = 4095;
const int outputSensorMinValue = 0;
const int outputSensorMaxValue = 255;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  const int sensorInput = analogRead(analogPin);
  const int output = map(sensorInput,
                         inputSensorMinValue, inputSensorMaxValue,
                         outputSensorMinValue, outputSensorMaxValue);

  analogWrite(ledPin, output);
  Serial.print(sensorInput);
  Serial.print(" maps to ");
  Serial.println(output);
  delay(100);
}
