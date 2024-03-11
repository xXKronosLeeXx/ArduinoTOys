int sp1 = 2; //定义舵机接口数字接口10(attniy上是2）
int pulsewidth; //定义脉宽变量
int val=90;
int val1=90; //l和ll要分清，别自己挖坑坑自己
int myangle1;
int eye;//灯亮变量，这里偷懒了，灯口是3号，后面直接写死

void servopulse(int sp1, int val1) //定义一个脉冲函数
{
  myangle1 = map(val1, 0, 180, 500, 2480);
  digitalWrite(sp1, HIGH); //将舵机接口电平至高
  delayMicroseconds(myangle1);//延时脉宽值的微秒数
  digitalWrite(sp1, LOW); //将舵机接口电平至低
  delay(20 - val1 / 1000);
}
//servopulse函数部分到此结束
void setup()
{
  pinMode(sp1, OUTPUT); //设定舵机接口为输出接口
}

void loop()//开始正式搞事
{
  //————眼睛呼吸灯控制第一部分，亮灯————
  for (eye = 0; eye < 255; eye += 1) // 从灭到亮
  {
    analogWrite(1, eye); //3号是灯口(attniy上是1）
    delay(5); // 等待亮度变化
  }

  //————从这里开始往下是控制转动模块————
  val = random(15, 165); // 随机角度  随机在安全范围角度内
  { 
    val1 = val - '0'; //将特征量转化为数值变量
    servopulse(sp1, val1); //引用脉冲函数，你丫给我转。这里千万不要用递减或递增，舵机会跳，而且会莫名360转
    delay(1000); // 休息1秒
  }
  //————眼睛呼吸灯控制第二部分，关灯————
  for (eye = 255; eye > 1; eye = eye - 1) // 从亮到灭
  {
    analogWrite(1, eye); //3号是灯口(attniy上是1）
    delay(5); // 等待亮度变化
  }
}
