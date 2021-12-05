#include <Servo.h>

int RW = 3;
int LW = 11; 

#define motor1 5 //오른쪽 모터 
#define motor2 6
#define motor3 9 //왼쪽 모터
#define motor4 10

//센서부
#define LLS1  A0// 맨 왼쪽 LED
#define LLS2  A1// 왼쪽 LED
#define CLS A2// 중간 LED
#define RLS2 A3// 오른쪽 LED
#define RLS1 A4// 맨 오른쪽 LED

#define FLS A5 // 전면 LED
#define SS 13
int analog_value = 0;

int LLS1_state;
int LLS2_state;
int CLS_state;
int RLS2_state;
int RLS1_state;
int SS_state;
Servo servo;
int servoPin = 2; //서보모터
int angle = 0;
 
int SV = 400;
int speed = 225 ;

void setup() {
Serial.begin(9600);

servo.attach(servoPin);

  // 아두이노와 적외선센서가 연결되는 핀들 선언
  pinMode(LLS1,INPUT);
  pinMode(LLS2,INPUT);
  pinMode(CLS,INPUT);
  pinMode(RLS1,INPUT);
  pinMode(RLS2,INPUT);
  pinMode(FLS, INPUT);
  //핀을 초기화합니다.
  //L298 모터드라이버의 핀들을 출력으로 변경합니다.
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  
  pinMode(RW, OUTPUT);
  pinMode(LW, OUTPUT);

  pinMode(servoPin, OUTPUT);
  digitalWrite(servoPin, LOW);
}

void loop() {
LLS1_state = analogRead(LLS1);
LLS2_state = analogRead(LLS2);
CLS_state = analogRead(CLS); 
RLS2_state = analogRead(RLS2);
RLS1_state = analogRead(RLS1);
SS_state = digitalRead(SS);

if ((SS_state==0))// ☆☆★☆☆
{
 Serial.println(SS_state);

  digitalWrite (motor1,LOW);
  digitalWrite (motor2,HIGH);
  digitalWrite (motor3,HIGH);
  digitalWrite (motor4,LOW);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(100);
}


if (!(LLS1_state > SV) && !(LLS2_state > SV) && (CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV))// ☆☆★☆☆
{
  Serial.println("CL");

  digitalWrite (motor1,LOW);
  digitalWrite (motor2,HIGH);
  digitalWrite (motor3,HIGH);
  digitalWrite (motor4,LOW);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(100);
}
// 좌회전
else if (!(LLS1_state > SV) && !(LLS2_state > SV) && !(CLS_state > SV) && (RLS2_state > SV) && !(RLS1_state > SV))// ☆☆☆★☆
{
  Serial.println("TR2");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed-100);
  analogWrite (LW, speed-30);
  delay(100);
  }
else if (!(LLS1_state > SV) && !(LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && !(RLS1_state > SV)) // ☆☆★★☆ 
{
  Serial.println("TR2+C");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed-70);
  analogWrite (LW, speed-20);
  delay(100);
  }

else if (!(LLS1_state > SV) && !(LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV)) // ☆☆★★★
{
  Serial.println("TR2+TR1+C");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed-30);
  analogWrite (LW, speed-10);
  delay(600);
  }
else if (!(LLS1_state > SV) && !(LLS2_state > SV) && !(CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV))// ☆☆☆★★
{
  Serial.println("TR2+TR1");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed-10);
  analogWrite (LW, speed);
  delay(100);
  }
else if (!(LLS1_state > SV) && !(LLS2_state > SV) && !(CLS_state > SV) && !(RLS2_state > SV) && (RLS1_state > SV)) // ☆☆☆☆★
{
  Serial.println("TR1");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed-40);
  analogWrite (LW, speed-10);
  delay(100);
}
  
//우회전
else if (!(LLS1_state > SV) && (LLS2_state > SV) && !(CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV)) // ☆★☆☆☆
{
  Serial.println("TL2");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed-30);
  analogWrite (LW, speed-100);
  delay(100);
  }    

else if (!(LLS1_state > SV) && (LLS2_state > SV) && (CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV)) // ☆★★☆☆
{
  Serial.println("TL2+C");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed-20);
  analogWrite (LW, speed-70);
  delay(100);
  }    
else if ((LLS1_state > SV) && (LLS2_state > SV) && (CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV)) // ★★★☆☆
{
  Serial.println("TL2+TL1+C");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed-10);
  analogWrite (LW, speed-30);
  delay(600);
  }
else if ((LLS1_state > SV) && (LLS2_state > SV) && !(CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV)) // ★★☆☆☆
{
  Serial.println("TL2+TL1");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed-20);
  analogWrite (LW, speed-40);
  delay(100);
  }    
else if ((LLS1_state > SV) && !(LLS2_state > SV) && !(CLS_state > SV) && !(RLS2_state > SV) && !(RLS1_state > SV)) // ★☆☆☆☆
{
  Serial.println("TL1");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed-10);
  analogWrite (LW, speed);
  delay(100);
  }  
//급커브
else if (!(LLS1_state > SV) && (LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV))// ☆★★★★
{
  Serial.println("급커브");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(1000);
  }
else if (!(LLS1_state > SV) && (LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && !(RLS1_state > SV))// ★★★★☆
{
  Serial.println("급커브1");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(1000);
  }

else if ((LLS1_state > SV) && !(LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV))// ☆☆★☆★
{
  Serial.println("CL+TR1");

  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);                       
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(1000);
  }
else if ((LLS1_state > SV) && !(LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV))// ★☆★☆☆
{
  Serial.println("CL+TR1");

  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);                       
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(1000);
  }
else if ((LLS1_state > SV) && (LLS2_state > SV) && (CLS_state > SV) && (RLS2_state > SV) && (RLS1_state > SV))// ★★★★★
{
  Serial.println("FW");

  digitalWrite (motor1,LOW);
  digitalWrite (motor2,HIGH);
  digitalWrite (motor3,HIGH);
  digitalWrite (motor4,LOW);

  analogWrite (RW, speed);
  analogWrite (LW, speed);
  delay(1000);
}  
if (digitalRead(FLS)==LOW){     
   analogWrite (RW, 0);
  digitalWrite (motor1, LOW);
   digitalWrite (motor2, LOW);
  analogWrite (LW, 0);
  digitalWrite (motor3, LOW);
 digitalWrite (motor4, LOW);

 {
  
 
for(int angle = 0; angle<170; angle++){
 servo.write(angle);
 delay(20);
 }
 
  for(int angle = 170; angle>0; angle--){
  servo.write(angle);
  delay(20);
  }
  }
}
}
