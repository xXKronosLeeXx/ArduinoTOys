/*
独眼舵机随机转动±150度
每次运动后随机静止时间3-8秒
*/
#include <Servo.h>
int idle = 0;
int jiaodu = 0;
Servo myservo;

void setup() {
  myservo.attach(3);            //走3号口输出   attiny45 234支持类比输入
}

void loop() {
  myservo.write(jiaodu);                  // sets the servo position according to the scaled value
  jiaodu = random(15, 165);              //在15和165之间随机转动
  delay(idle=random(2000,8000));                           // waits for the servo to get there
}
