//------------------------------------------------------------------
//  Remarkable Type-Folio pretender
// (for POGO Pin connection)
//  By: Dudlushka (dudlushka@gmail.com)
// tested on: Arduino Leonardo (pro micro 5v variant)
//------------------------------------------------------------------
#include "PackageParser.h"


//--------------------------------------------------------

void setup() 
{
  Serial. begin(115200);   //USB
  Serial1.begin(115200);   //HW    
}

//--------------------------------------------------------

uint8_t rec = 0;
uint32_t us;
uint32_t p_us = 0;
uint32_t diff;

uint8_t in_app = 0;

#define REQ_FIRST_NAME        0x01
#define REQ_NEGOTIATION_PACK  0x02
#define REQ_AUTH_KEY          0x03
#define REQ_JUMP_APP          0x04

//--------------------------------------------------------

void loop() 
{
   if (Serial.available()) // USB to POGO
   {      
       //Serial1.write(Serial.read()); 
       char ch = Serial.read();
       
       if(ch == '.')        //reset the device - start pulldown
       {
         Serial1.print(0xff); //pulls down ID
         ReStartStateMachine();
         p_us = micros();
         in_app = 0;
       }
       else
       {
        SendKeyboard_char((uint8_t)ch);
       }

       
   }

   if (Serial1.available()) //HW to USB
   {     
      uint8_t aaa = Serial1.read();
      if(aaa == ':')Serial.println("");
      if(aaa<0x10)Serial.print("0");
      
      Serial.print(aaa,HEX);
      Serial.print(" ");   
       
      if(ProcessPack_low(aaa)) // Valid Packet Found!
      { 
        us = micros();
        diff = us-p_us;
        p_us = us;
        
          Serial.println("");
          Serial.println("Valid Packet received!");
          Serial.print("@time[us]");
          Serial.print(us);
          Serial.print(" time_diff:");
          Serial.print(diff);
          Serial.println(" us");


        if(buff[3] == 0x07){rec = REQ_FIRST_NAME;}
        if(buff[3] == 0x02){rec = REQ_NEGOTIATION_PACK;}
        if(buff[2] == 0x09){rec = REQ_AUTH_KEY;}
        if(buff[2] == 0x04){rec = REQ_JUMP_APP;}

      }
   }

    if(in_app)
    {
      us = micros();
      if(us - p_us > 400000)
      {
        Keep_Alive();
        p_us = us;
      }
    }

   
   //------------------------------------
   if(rec == REQ_FIRST_NAME)
   {   
    rec = 0;
    FirstTestResponse();
   }
  
   if(rec == REQ_NEGOTIATION_PACK)
   {
    rec = 0;
    SuperResponsePack_v2(); 
   }

   if(rec == REQ_AUTH_KEY)
   {
    rec = 0;
    SendAuthKeyResponse(); 
   }

   if(rec == REQ_JUMP_APP)
   {
    rec = 0;
    SendAPPResponse();
    in_app = 1;
   }
}

//--------------------------------------------------------
