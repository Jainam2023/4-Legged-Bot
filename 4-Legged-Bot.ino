
#include<IRremote.h>
#include<Servo.h>
Servo r_f, l_f, r_h, l_h,c,_e;
int rf = 87, rh = 80, lf = 87, lh = 90, i,e=20;
long key;
#define repeat 0xFFFFFFFF
IRrecv ir(8);
decode_results result;
#define power 0x1FE48B7
#define mute 0x1FE7887
#define one 0x1FE50AF
#define two 0x1FED827
#define three 0x1FEF807
#define four 0x1FE30CF
#define five 0x1FEB04F
#define six 0x1FE708F
#define seven 0x1FE00FF
#define eight 0x1FEF00F
#define nine 0x1FE9867
#define zero 0x1FEE01F
void setup() {
  ir.enableIRIn();
  r_f.attach(4);
  r_h.attach(5);
  l_f.attach(6);
  l_h.attach(7);
  c.attach(2);
  _e.attach(3);
  while(digitalRead(9)!=1);
  hp();
}

void loop() {
  if (ir.decode(&result))
  {
    if (result.value != repeat)
    {
      key = result.value;
    }
    if (key == one)
    {
      fwd();
    }
    if (key == power)
    {
      hp1();
    }
    if (key == two)
    {
      back();
    }
    if (key == three)
    {
      left();
    }
    if (key == four)
    {
      right();
    }
    if (key == five)
    {
      down();
    }
    if(key==six)
    {
      c.write(80);
    }
    if(key==seven)
    {
      c.write(110);
    }
    if(key==eight)
    {
      eup();
    }
    if(key==nine)
    {
      edown();
      
    }
    ir.resume();
  }
}
void hp()
{
  r_f.write(rf);
  r_h.write(rh);
  l_f.write(lf);
  l_h.write(lh);
  _e.write(e);
  delay(10);
}
void hp1()
{
   rf = 87, rh = 80, lf = 87, lh = 90;
   hp();
}
void back()
{
  rf = 87, rh = 80, lf = 87, lh = 90;
  for (i = 0; i <= 20; i++)
  {
    rf--;
    lh++;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rh++;
    lf--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf++;
    lh--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rh--;
    lf++;
    hp();
  }
}
void fwd()
{
  rf = 87, rh = 80, lf = 87, lh = 90;
  for (i = 0; i <= 20; i++)
  {
    rf++;
    lh--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rh--;
    lf++;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf--;
    lh++;

    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rh++;
    lf--;
    hp();
  }
}
void left()
{
  rf = 87, rh = 80, lf = 87, lh = 90;
  for (i = 0; i <= 20; i++)
  {
    lf++;
    lh++;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf++;
    rh++;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    lf--;
    lh--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf--;
    rh--;
    hp();
  }
}
void right()
{
  rf = 87, rh = 80, lf = 87, lh = 90;
  for (i = 0; i <= 20; i++)
  {
    lf--;
    lh--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf--;
    rh--;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    lf++;
    lh++;
    hp();
  }
  for (i = 0; i <= 20; i++)
  {
    rf++;
    rh++;
    hp();
  }
}
void down()
{
  for (i = 0; i <= 80; i++)
  {
    rf++;
    lf--;
    hp();
  }
}
void eup()
{
  e++;
  hp();
}
void edown()
{
  e--;
  hp();
}
