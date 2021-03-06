#include <Arduino.h>

extern void sendStatus();
extern strDateTime DateTime;

class relay
{
    byte state=0;
    int pin;
    String name;
    long offTime;
    long onTime;    
public:
    relay(int Pin, String Name);
    void setState(byte State); 
    void toggle();
    byte getState() {return state;};
    String getName() {return name;};
    long getoffTime() {return offTime;};
    long getonTime() {return onTime;};
    void setoffTime(long off) {offTime = off;};
    void setonTime(long on) {onTime = on;};
    void tick();
};

relay::relay(int Pin,String Name)
{
  pin=Pin;
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  name = Name;
  offTime = 0;
  onTime = 0;
}

void relay::setState(byte State)
{
  byte oldstate = state;
  state = State;
  if(state==1)
  {
    digitalWrite(pin,HIGH);
  }
  else
  {
      digitalWrite(pin,LOW);
  }
  if(state != oldstate)
    sendStatus();
}

void relay::toggle()
{
  if(state==1)
    setState(0);
  else
    setState(1);
}

void relay::tick()
{
  if(offTime > 0)
  {
    offTime--;
    if(offTime==0)
      setState(0);
  }
  if(onTime > 0)
  {
    onTime--;
    if(onTime==0)
      setState(1);
  }
}
