/*
  独眼舵机随机转动±150度
  不适用Servo而直接驱动analog，以便达成看起来幻速旋转的效果。要用到模拟信号位
*/

int jiaoduend = 0;
int jiaodu = 90;
int lighttime = 0;
int rolltime = 0;

void setup()
{
  pinMode(5, OUTPUT);           //这是舵机
}
void loop()
{
  jiaoduend = random(30, 150);         //生成随机角度
  Serial.begin(9600);
  delay(1000);

  Serial.println("");
  Serial.print("角度生成");
  Serial.println(jiaoduend);
  analogWrite(5, jiaodu);                //把舵机初始位置写在安全范围
  for (; jiaoduend < jiaodu; jiaodu--)   //比较新生成的位置与初始位置关系，并进行加减运算，逐级运动。这里是减运算
  {
    analogWrite(5, jiaodu);
    Serial.print(jiaodu);
    Serial.print("  ");
    delay(8);
  }
  for (; jiaoduend > jiaodu; jiaodu++) //这里是加运算
  {
    analogWrite(5, jiaodu);
    delay(8);
  }
  delay(800);     //眼睛移动到位后，统一执行停留0.8秒的动作
}
