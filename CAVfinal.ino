int trig = 10;
int echo = 9;
int led = 11;
int pot = 0;
int motor = 6; 
int set_spd = 0;
int min_dist = 10;
double curr_spd = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //ultrasonic set up
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  set_spd = analogRead(pot);
 // analogWrite(motor, set_spd/4);
  
  long duration = pulseIn(echo, HIGH);
  long distance_cm = duration/2/29.1;

  curr_spd = analogRead(motor);
  if (distance_cm < min_dist){
    analogWrite(motor, (curr_spd)/(0.5/distance_cm));
    digitalWrite(led, HIGH);
  }
  else{
    analogWrite(motor, set_spd/4);
    digitalWrite(led, LOW);
  }
  delay(100);
}
