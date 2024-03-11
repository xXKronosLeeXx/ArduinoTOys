/*
  独眼红色呼吸灯效果

*/

void setup() {
  pinMode(5, OUTPUT); //2号口控制眼睛灯光 attiny45 234支持类比输入
  pinMode(3, OUTPUT); //2号口控制眼睛灯光 attiny45 234支持类比输入

}

void loop()
{ // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++)
  {
    analogWrite(5, i);
    delay(4);
  }
  for (int i = 255; i > 0; i--)
  {
    analogWrite(5, i);
    delay(4);
  }
  //以下是闪灯
  for (int i = 0; i < 5; i++)
  {
    
      digitalWrite(3, HIGH);
         delay(30);
      digitalWrite(3, LOW);
         delay(30);
    }
  }
