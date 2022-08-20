
void setup() {
  pinMode(2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(3, OUTPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() 
{
  // put your main code here, to run repeatedly:
  lampubos();
}

void lampubos()
{
  if(Serial.available() > 0)
  {
    int c = Serial.read();
    //lampu depan nih bang
    if(c == '1')
    {
      digitalWrite(2, HIGH);
    }
    if (c == '0')
    {
      digitalWrite(2, LOW);
    }
    //lampu belakang nih bang
    if(c == '5')
    {
      digitalWrite(3, HIGH);
    }
    if (c == '6')
    {
      digitalWrite(3, LOW);
    }
  }
}
