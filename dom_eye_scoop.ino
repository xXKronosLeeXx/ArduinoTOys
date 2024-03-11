#include "SCoop.h"
int sp1 = 9; //定义下舵机接口数字接口9
int sp2 = 10; //定义上舵机接口数字接口10
int pulsewidth; //定义脉宽变量
int val;
int val1 = 90; //l和ll要分清，别自己挖坑坑自己
int myangle1;
int led = 11; //LED信号脚位，信号线11

void servopulse(int sp1, int val1) //定义一个脉冲函数
{
  myangle1 = map(val1, 0, 180, 500, 2480);
  digitalWrite(sp1, HIGH); //将舵机接口电平至高
  delayMicroseconds(myangle1);//延时脉宽值的微秒数
  digitalWrite(sp1, LOW); //将舵机接口电平至低
  delay(20 - val1 / 1000);
}
//servopulse函数部分到此结束

defineTask(Task1);
void Task1::setup()
{
  pinMode(sp1, OUTPUT); //设定舵机接口为输出接口
  pinMode(sp2, OUTPUT); //设定舵机接口为输出接口
  pinMode(led, OUTPUT);
  pinMode(led, INPUT);
}
void Task1::loop()//呼吸灯
{
  for (int i = 0; i <= 255; i += 1)
  {
    analogWrite(led, i);
    delay(30);
  }//呼吸灯点亮

  for (int i = 255; i >= 0; i -= 1)
  {
    analogWrite(led, i);
    delay(30);
  }//呼吸灯熄灭
}
//快速定义
defineTaskLoop(Task2)//可动眼
{

  //————开始横向舵机逻辑————
  for (int a = 0; a <= 3 ; a += 1)
  { //随机动眼的次数，默认为3
    val = random(65, 115); // 随机角度函数    随机在安全范围角度内
    {
      val1 = val - '0'; //将特征量转化为数值变量
      servopulse(sp1, val1); //引用脉冲函数
      delay(1000);//展示1秒，叉会腰
    }
  }
  servopulse(sp1, 90);//强制归位到90度
  delay(1000);//展示1秒，叉会腰
  
  //————开始纵向舵机逻辑————
  for (int a = 0; a <= 3; a += 1)
  { //随机动眼的次数，默认为3
    val = random(90, 110); // 随机角度函数    随机在安全范围角度内
    {
      val1 = val - '0'; //将特征量转化为数值变量
      servopulse(sp2, val1); //引用脉冲函数
      delay(1000);//展示1秒，叉会腰
    }
    servopulse(sp2, 90);//强制归位到90度
    delay(1000);//展示1秒，叉会腰
  }


}
void setup()
{
  mySCoop.start();
  pinMode(3, OUTPUT);
}
void loop()
{
  yield();
}
