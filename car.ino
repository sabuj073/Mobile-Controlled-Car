int Motor_A_Enable = 9;
int Motor_B_Enable = 10;

int Motor_A_Reverse = 3;
int Motor_A_Forward = 4;


int Motor_B_Reverse = 5;
int Motor_B_Forward = 6;

int motor_a_speed = 70;
int motor_b_speed = 70;

int trigPin = A0;
int echoPin = A1;

long duration;
int distance;
int getDistance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);

  pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);
  
  if (Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());
    Serial.print(data);
    Serial.print("\n");

    switch (data)
    {
      case 'F': //FORWARD
       if (distance <= 25){
         analogWrite(Motor_A_Enable, 0);
         analogWrite(Motor_B_Enable, 0);
         Serial.println("Obstacle");
        
       }
       else{
        Serial.print("Forward\n");
        analogWrite(Motor_B_Enable, motor_a_speed);
        analogWrite(Motor_A_Enable, motor_b_speed);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward, HIGH);
       }
        break;
      case 'B': //REVERSE
        Serial.print("Reverse\n");
        analogWrite(Motor_B_Enable, motor_b_speed);
        analogWrite(Motor_A_Enable, motor_a_speed);
        digitalWrite(Motor_A_Forward, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_B_Reverse, HIGH);
        break;
      case 'L': //FORWARD LEFT
        Serial.print("LEFT\n");
        analogWrite(Motor_B_Enable, motor_b_speed);
        analogWrite(Motor_A_Enable, motor_a_speed);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_A_Forward, LOW);
        break;
      case 'R': //FORWARD RIGHT
        Serial.print("Right\n");
        analogWrite(Motor_A_Enable, motor_a_speed);
        analogWrite(Motor_B_Enable, motor_b_speed);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Reverse, HIGH);
        digitalWrite(Motor_B_Forward, LOW);
        break;
      case 'G': //REVERSE LEFT
        Serial.print("left\n");
        analogWrite(Motor_A_Enable, motor_a_speed);
        analogWrite(Motor_B_Enable, motor_b_speed);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_A_Forward, LOW);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
        break;
      case 'I': //REVERSE RIGHT
        Serial.print("Right\n");
        analogWrite(Motor_B_Enable, motor_b_speed);
        analogWrite(Motor_A_Enable, motor_a_speed);
        digitalWrite(Motor_B_Reverse, HIGH);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        break;

      case '1':
        motor_a_speed = 70;
        motor_b_speed = 70;
        break;

      case '2':
        motor_a_speed = 100;
        motor_b_speed = 100;
        break;


      case '3':
        motor_a_speed = 120;
        motor_b_speed = 120;
        break;

      case '4':
        motor_a_speed = 140;
        motor_b_speed = 140;
        break;

      case '5':
        motor_a_speed = 160;
        motor_b_speed = 160;
        break;

      case '6':
        motor_a_speed = 200;
        motor_b_speed = 200;
        break;

      case '7':
        motor_a_speed = 225;
        motor_b_speed = 225;
        break;


      default: //If bluetooth module receives any value not listed above, both motors turn off
        analogWrite(Motor_A_Enable, 0);
        analogWrite(Motor_B_Enable, 0);
    }
  }

}
