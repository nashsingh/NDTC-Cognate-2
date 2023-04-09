///////FOR Ultrasonic///////
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;
//////////////////////////

//// For l298n//////
int in1 = 9;
int in2 = 8;
int in3 = 5;
int in4 = 4;

//////////////////
void setup() {
/////////Ultrasonic//////////
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
/////////////////////////////

//////l298n//////
 pinMode (in1, OUTPUT);
   pinMode (in2, OUTPUT);
    pinMode (in3, OUTPUT);
     pinMode (in4, OUTPUT);
      speedControl();
  delay(1000);
     /////////////

     

}

void ultrasonic(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  }

  void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //delay(500);
  }
 
void forward(){
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //delay(500);

}
 void backward(){
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(500);
 
 }
 void right (){
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(500);
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(500);
  }

  void left(){
      digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   delay(500);
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   delay(500);
  }
void loop() {

  ultrasonic();


  
if(distance < 15){
   backward();
}
else{
   forward();
}


  if (distance =80; distance < 150 ){
    right();
    
  }
  else {
    left();
  }


 
}

