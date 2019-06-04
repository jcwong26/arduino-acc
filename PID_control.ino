int trig = 10;
int echo = 9;
int led = 11;
int pot = 0;
int motor = 6; 
int set_spd = 0;
int min_dist = 10;
double error[2] = {0};
double deriv = 0;
double inte = 0;
double pid = 0;
int m_speed = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor, OUTPUT);
  set_spd = analogRead(pot);  
}

void loop() {
  // put your main code here, to run repeatedly:

  //ultrasonic set up
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  

 // analogWrite(motor, set_spd/4);
  
  long duration = pulseIn(echo, HIGH);
  long distance_cm = duration/2/29.1;

  error[0] = min_dist - distance_cm;
  deriv = (error[1]-error[0])/500;
  inte = error[1]*100;

  pid = error[0]*1 + deriv*5 + inte*3;
  m_speed =analogRead(motor);
  analogWrite(motor,pid);
  
  error[1] = error[0];

  Serial.println(error[0]);
  Serial.println(pid);
  Serial.println(m_speed);
  delay(500);
}
