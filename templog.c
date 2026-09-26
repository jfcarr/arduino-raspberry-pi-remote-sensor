/* This is the pin getting the stream of temperature data. */
#define sensorPin 0

float Celsius, Fahrenheit;
int sensorValue;

void setup()
{
	Serial.begin(9600);  /* Initialize the Serial communications */
}

void loop()
{

	GetTemp();

	Serial.println(Fahrenheit);  /* You can easily change this to print Celsius if you want. */

	delay(2000);  /* Wait 2 seconds before getting the temperature again. */
}

void GetTemp()
{
	sensorValue = analogRead(sensorPin);  /* Get the current temperature from the sensor. */

	/*
	 * The data from the sensor is in mV (millivolts), where 10mV = 1 degree Celsius.
	 * So if, for example, you receive a value of 220 from the sensor, this indicates
	 * a temperature of 22 degrees Celsius.
	 */

	Celsius = sensorValue / 10;         /* Convert the sensor value to Celsius */
	Fahrenheit = (Celsius * 1.8) + 32;  /* Convert the Celsius value to Fahrenheit */
}
