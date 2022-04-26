//LEDs
int const redLED = 9;
int const greenLED = 10;
int const blueLED = 11;

//Potentiometers
int const redPot = A0; 
int const greenPot = A1; 
int const bluePot = A2;

//Potentiometer reading/conversion
int redValue = 0;
int redReading = 0;
int greenValue = 0;
int greenReading = 0;
int blueValue = 0;
int blueReading = 0;

void setup() {
  Serial.begin(9600);

  //setting the direction of the digital pins and setting up the serial port
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  //reading value of each potentiometer
  redReading = analogRead(redPot);
  greenReading = analogRead(greenPot);
  blueReading = analogRead(bluePot);

  //convert values of 0 - 1023 to values b/w 0 - 255
  redValue = redReading/4;
  greenValue = greenReading/4;
  blueValue = blueReading/4;
  
  //report the calculated LED light levels (test/debug only)
  Serial.print("Mapped Sensor Values \n Red: ");
  Serial.print(redValue);
  Serial.print(" \n Green:");
  Serial.print(greenValue);
  Serial.print(" \n Blue:");
  Serial.print(blueValue);
  
  //set LED light levels
  analogWrite(redLED, redValue);
  analogWrite(greenLED, greenValue);
  analogWrite(blueLED, blueValue);  
}
