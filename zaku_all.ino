#include <Servo.h>

/*
  独眼舵机随机转动±150度
  按顺序执行，转眼睛和眼睛亮灭排序进行
  眼睛旋转缓速转动
*/

int jiaoduend = 90;
int light = 0;
int jiaodu = 90;

void setup()
{
  pinMode(5, OUTPUT);       //舵机从5号口输出   attiny45 234支持类比输入
  pinMode(3, OUTPUT);       //3号口控制眼睛灯光 attiny45 234支持类比输入
}

void loop()
{
  for (int i = 0; i < 255; i++)     //开始头部呼吸灯亮起，固定启动时间
  {
    analogWrite(3, i);
    delay(2);
  }

  jiaoduend = random(30, 150);         //生成随机角度
    analogWrite(5, jiaodu);                //把舵机初始位置写在安全范围
  for (; jiaoduend <= jiaodu; jiaodu--)   //比较新生成的位置与初始位置关系，并进行加减运算，逐级运动。这里是减运算
  {
    analogWrite(5, jiaodu);
      delay(8);
  }
  for (;jiaoduend>jiaodu; jiaodu++)   //这里是加运算
  {
    analogWrite(5, jiaodu);
    delay(8);
  }
    delay(800);     //眼睛移动到位后，统一执行停留0.8秒的动作

  light = random(2000, 5000);         //生成持续时间
  delay(light);                      // 每次眼睛转动完毕头灯持续时间

  for (int i = 255; i > 0; i--)
  {
    analogWrite(3, i);
    delay(8);
  }
}
