#include <Chrono.h>
#include <LightChrono.h>
#include <Servo.h>

/*
  独眼舵机随机转动±150度
  同时执行，转眼睛和眼睛亮灭同时进行
  眼睛转速快，一步到位
*/
Chrono eys;
Chrono roll;
Chrono light;
Servo myservo;
int jiaodu = 0;
int lighttime = 0;
int rolltime = 0;

void setup()
{
  myservo.attach(5);            //走3号口输出   attiny45 234支持类比输入
  pinMode(3, OUTPUT);           //2号口控制眼睛灯光 attiny45 234支持类比输入
}
void loop()
{
  rolltime = random(500, 5000);     //生成随机舵机停留时间
  jiaodu = random(30, 150);         //生成随机角度

  if (roll.hasPassed(250))          //设置计时器，250毫秒检测一次
  {
    roll.restart();
    if (rolltime > 0)
    {
      rolltime = rolltime - 250;
    }
    myservo.write(jiaodu);            //舵机旋转随机开始


    lighttime = random(1000, 5000);         //生成亮灯持续时间
    for (int i = 0; i < 255; i++)
    {
      analogWrite(3, i);
      if (lighttime > 0)
      {
        delay(8);
      }
    }
    for (int i = 255; i > 0; i--)
    {
      analogWrite(3, i);
      delay(8);
    }
  }
}
