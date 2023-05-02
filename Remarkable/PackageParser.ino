#include "PackageParser.h"


#define DATA_KEY (0x3A) //':'

uint8_t buff[BUFF_LEN] = {0};

typedef enum ProcessState
{
  St_init = 0,
  St_key = 1,
  St_len_l,
  St_len_h,
  St_cmd,
  St_data,
  St_checksum
} ProcessState_t;



  static ProcessState_t state = St_init; //"state machine" state
  static uint16_t buff_i   = 0;   //buffer index
  static uint8_t  csum     = 0;     //checksum
  static uint16_t d_length = 0;     //dataLength
  static uint16_t d_cntr   = 0;

void ReStartStateMachine()
{
  state = St_init;
  
}

int ProcessPack_low(uint8_t data_in)
{


  switch(state)
  {
  //----------------------------------------
  case St_init:
  //----------------------------------------
    memset(buff,0,BUFF_LEN);
    buff_i   = 0;
    d_length = 0;
    csum     = 0;
    d_cntr   = 0;

    state    = St_key;

  //----------------------------------------
  case St_key:
  //----------------------------------------
    if(data_in == DATA_KEY)
    {
      state = St_len_l;
    }
    break;
  //----------------------------------------
  case St_len_l:
  //----------------------------------------
    d_length += ((uint16_t)data_in << 0);
    csum += data_in;
    buff[buff_i++] = data_in;
    state = St_len_h;
    break;
  //----------------------------------------
  case St_len_h:
  //----------------------------------------
    d_length += ((uint16_t)data_in << 8);
    csum += data_in;
    buff[buff_i++] = data_in;
    if(d_length > BUFF_LEN) {state = St_init;}
    else {state = St_cmd;}
    break;
  //----------------------------------------
  case St_cmd:
  //----------------------------------------
    csum += data_in;
    buff[buff_i++] = data_in;
    if(d_length > 0){state = St_data; d_cntr = 0;}
    else            {state = St_checksum;}
    break;
  //----------------------------------------
  case St_data:
  //----------------------------------------
    csum += data_in;
    buff[buff_i++] = data_in;

    if(++d_cntr >= d_length)
    {
      state = St_checksum;
    };

    break;
  //----------------------------------------
  case St_checksum:
  //----------------------------------------
    buff[buff_i] = data_in;

    csum ^= 0xff;
    csum++;

    state = St_init;

    if(csum == data_in) return 1;
    else return -1;
    break;
  }

  return 0;
}

void FirstTestResponse()
{
  Response_07();
}

uint8_t TxBuff[128] = {0};
void GeneralTxMessage(uint8_t cmd,uint8_t* buff,uint16_t len)
{
  uint8_t csum = 0;
  int i=0;
  
  TxBuff[0] = 0x2e;
  TxBuff[1] = (len >> 0) & 0xff;
  TxBuff[2] = (len >> 8) & 0xff;
  TxBuff[3] = cmd;

  csum = TxBuff[1]+TxBuff[2]+TxBuff[3];

  for(i=0;i<len;i++)
  {
    TxBuff[4+i] = buff[i];
    csum += buff[i];  
  }
  
  csum ^= 0xff;
  csum++;
  
  TxBuff[4+i] = csum;
  Serial1.write(TxBuff,i+5);     
}

//3A 08 00 20 
//02 11 04 06 10 07 05 12 
//8D

//nope!
void SuperResponsePack()
{
  Response_02();
  Response_11();
  Response_04();
  Response_06();
  Response_10();
  Response_07();
  Response_05();
  Response_12();
}

#define AUTH_KEY_STRING ("@O8eO77%o^4*1GE@oeodd#WMa%8Kr6v@")
void SendAuthKeyResponse()
{
  Serial.println("Auth Key");
  uint8_t resp[] = AUTH_KEY_STRING;

  GeneralTxMessage(0x09,resp,sizeof(resp));
}


void Keep_Alive()
{
  
  GeneralTxMessage(0x40,0,0);
}


void SendKeyboard1()
{
  uint8_t resp[2] = {0x01,0x00};
   GeneralTxMessage(0x51,resp,sizeof(resp));
  
}


void SendKeyboard2()
{
  uint8_t resp[2] = {0x00,0x01};
   GeneralTxMessage(0x51,resp,sizeof(resp));
}

extern const uint8_t kbd[256];

void SendKeyboard_char(uint8_t data)
{
//5 14
  
  uint8_t resp[2] = {0x00,0x01};
  uint8_t shift[2] = {((5<<1)|(14<<4)|(1)),0x01};
  uint8_t shiftup[2] = {((5<<1)|(14<<4)|(0)),0x01};

 
  if(!data)return;

  if(kbd[data] & 0x01)   GeneralTxMessage(0x51,shift,2);

  resp[0] = kbd[data] | 0x01;
  GeneralTxMessage(0x51,resp,sizeof(resp));
  resp[0] = kbd[data] & 0xfe;
  GeneralTxMessage(0x51,resp,sizeof(resp));

  if(kbd[data] & 0x01)   GeneralTxMessage(0x51,shiftup,2);
}



void SendAPPResponse()
{
  Serial.println("jump to APP");
  GeneralTxMessage(0x04,0,0);
}

void SuperResponsePack_v2()
{
  Serial.println("BigPack!");

  //02 11 04 06 10 07 05 12 
    uint8_t resp[] = { 
                     0x02,0x00,        //FW Version (uint8_t[2])
                     0x19,
                     0x02,0x01,
                     
                     0x11,0x00,        //Language (package_kb_language_t:8)
                     0x30,
                     0x01,       
                     
                     0x04,0x00,        //DeviceClass (uint32) BIT(31)
                     0x0b,
                     0x02,0x00,0x00,0x80, //0x80000000 (?)
                     
                     0x06,0x00,         // ImageStartAddress (uint32)
                     0x1b,
                     0x00,0x40,0x00,0x00, //what the hell? - some random number
                     
                     0x10,0x00,        //KeyboardLayout (uint8)
                     0x18,
                     0x01,
                     
                     0x07,0x00,        //DeviceName (...string),
                     0x42,0x0c,
                     0x72,0x4d,0x6b,0x65,0x79,0x62,0x6f,0x61,0x72,0x64,0x30,0x31, //The original one
                     
                     0x05,0x00,
                     0x48,//DeviceID uint32[4]
                     0x0b,
                     0x04,0x00,
                     0x40,0x10,0x01,0x03,
                     0x28,0xa5,0xae,0xaf,
                     0x17,0x05,0x16,0x14,
                     0x10,0x05,0x00,0xf5,

                     
                     
                     0x12,0x00,        //SerialNumber uint8_t[15]
                     0x42,0x0f,
                     0x52,0x4d,0x37,0x31,0x32,0x2d,
                     0x33,0x31,0x31,0x2d,
                     '1','1','2','1','2'//Some random ASCII numbers
                     };
  
  
    GeneralTxMessage(0x20,resp,sizeof(resp));
  
}











void Response_02()
{
  uint8_t resp[] = { 0x02,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}

void Response_11()
{
  uint8_t resp[] = { 0x11,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}


void Response_04()
{
  uint8_t resp[] = { 0x11,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}


void Response_06()
{
  uint8_t resp[] = { 0x06,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}


void Response_10()
{
  uint8_t resp[] = { 0x10,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}

void Response_07()
{
  uint8_t resp[] = { ATTRIBUTE_ID_DEVICE_NAME,
                     0x00,0x42,0x0c,0x72,0x4d,0x6b,0x65,0x79,0x62,0x6f,0x61,0x72,0x64,0x30,0x31 };
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}

void Response_05()
{
  uint8_t resp[] = { 0x05,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}

void Response_12()
{
  uint8_t resp[] = { 0x12,
                     0x11,0x22,0x33,0x44};
                      
  GeneralTxMessage(0x20,resp,sizeof(resp));
}
