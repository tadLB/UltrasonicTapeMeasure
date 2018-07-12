// make easy to remember names for the Ultrasonic pins
int triggerPin = A2;
int echoPin = A3;


void setup() {
  // set up our Ultrasonic pins
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // establish a connection to the computer
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(readUltrasonic());
  Serial.println("inches away");
  delay(1000);
}


// a function that measures the distance using the Ultrasonic sensor in inches
int readUltrasonic()
{
  // make sure it's not already sending sound
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // send a pulse
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  // measure how long the sound took to return in microseconds
  int pingTime = pulseIn(echoPin, HIGH);

  // convert to distance using the speed of sound through air (13503.9inches/second)
  int distance = (pingTime * 13503.9 / 1000000) / 2;

  return distance;
}
