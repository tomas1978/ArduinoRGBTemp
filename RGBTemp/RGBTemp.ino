int redPin=11;
int bluePin=10;
int greenPin=9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
}

float sensorToTemp(int analogPort) {
    int rawAnalogValue = analogRead(analogPort);
    float volt = (float)rawAnalogValue * 5.0 / 1023.0;
    float degC = (volt-0.5) * 100.0;
    return degC;
}

void loop()
{
    float temperature=sensorToTemp(0);
    Serial.println(temperature);
}
