#include <SoftwareSerial.h> 
char inchar; // Will hold the incoming character from the GSM shield
SoftwareSerial SIM900(7, 8);
 
int BULB1 = 7;
int BULB2 = 8;
int BULB3 = 12;
int BULB4 = 13;
 
void setup()
{
  Serial.begin(19200);
  // set up the digital pins to control
  pinMode(BULB1, OUTPUT);
  pinMode(BULB2, OUTPUT);
  pinMode(BULB3, OUTPUT);
  pinMode(BULB4, OUTPUT);
  digitalWrite(BULB1, LOW);
  digitalWrite(BULB2, LOW);
  digitalWrite(BULB3, LOW);
  digitalWrite(BULB4, LOW);
 
  // wake up the GSM shield
  SIM900power(); 
  SIM900.begin(19200);
  delay(20000);  // give time to log on to network.
  SIM900.print("AT+CMGF=1\r");  // set SMS mode to text
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
  delay(100);
  Serial.println("Ready...");
}
 
void SIM900power()
// software equivalent of pressing the GSM shield "power" button
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(7000);
}
 
void loop() 
{
  //If a character comes in from the cellular module...
  if(SIM900.available() >0)
  {
    inchar=SIM900.read(); 
    if (inchar=='#')
    {
      delay(10);
 
      inchar=SIM900.read(); 
      if (inchar=='O')
      {
        delay(10);
        inchar=SIM900.read();
        if (inchar=='N')
        
        {delay(10);
        inchar=SIM900.read();
        if (inchar=='1')
         { digitalWrite(BULB1, HIGH);
        } 
        else if (inchar=='2')
        {
          digitalWrite(BULB2, HIGH);
        }
        else if (inchar=='3')
        { digitalWrite(BULB3,HIGH);
        }
        else if(inchar=='4')
        { digitalWrite(BULB4,HIGH);
        }
        }
        else if(inchar=='F')
        {
        delay(20);
        inchar=SIM900.read(); 
        if (inchar=='1')
        { digitalWrite(BULB1,LOW);
        }
        else if (inchar=='2')
          {
            digitalWrite(BULB2, LOW);
          } 
          else if (inchar=='3')
          {
            digitalWrite(BULB3, LOW);
          }
          else if (inchar=='4')
          { digitalWrite(BULB4,LOW);
          }
        }
      }
              delay(10);
            }
          }
          SIM900.println("AT+CMGD=1,4"); // delete all SMS
        }

    
  

