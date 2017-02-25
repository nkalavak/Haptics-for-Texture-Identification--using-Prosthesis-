*********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************// Control the vibration of an ERM motor
// using PWM and a photoresistor. 

const int analogInPin = A0;  // Analog input pin that the sensor is attached to
const int analogOutPin = 3; // Analog output pin that the Haptic Motor Driver is attached to
const int vibsens = A1;

int sensorValue = 0;        // value read from the sensor
int outputValue = 0;        // value output to the PWM (analog out)


void setup() 
{
  Serial.begin(9600);
}
void loop() 
{

 // read the analog in value:
  sensorValue = analogRead(vibsens);
  //float piezoV = sensorValue / 1023.0 * 5.0;
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue+150);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
 }

