int redPin=11;
int bluePin=10;
int greenPin=9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
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
  if(temperature>25) {
    digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  } else if(temperature<18) {
    digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
  } else {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
  }
  Serial.println(temperature);  
  delay(10);
}
