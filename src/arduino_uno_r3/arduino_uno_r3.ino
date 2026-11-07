// Arduino Uno R3
const int analogPin = A1;
const int ledPin = 6;

const int inputSensorMinValue = 0;
const int inputSensorMaxValue = 466; // Calibrate this for your sensor; Uno ADC maximum is 1023.
const int outputSensorMinValue = 0;
const int outputSensorMaxValue = 255;

void setup() {
  Serial.begin(9600);
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
