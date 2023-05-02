/* Seabird_pC08_20220321, with row0 not connected. The row0 here is row1 on PCB */
/*
KEY(0, 0, KEY_RESERVED),
  KEY(0, 1, KEY_RESERVED),
  KEY(0, 2, KEY_RESERVED),
  KEY(0, 3, KEY_RIGHT),
  KEY(0, 4, KEY_RESERVED),
  KEY(0, 5, KEY_RESERVED),
  KEY(0, 6, KEY_RESERVED),
  KEY(0, 7, KEY_N),
  KEY(0, 8, KEY_B),
  KEY(0, 9, KEY_V),
  KEY(0, 10, KEY_D),
  KEY(0, 11, KEY_X),
  KEY(0, 12, KEY_Z),
  KEY(0, 13, KEY_RESERVED),
  KEY(0, 14, KEY_LEFTSHIFT),
  KEY(1, 0, KEY_RESERVED),
  KEY(1, 1, KEY_RESERVED),
  KEY(1, 2, KEY_RESERVED),
  KEY(1, 3, KEY_RESERVED),
  KEY(1, 4, KEY_DOWN),
  KEY(1, 5, KEY_RESERVED),
  KEY(1, 6, KEY_RESERVED),
  KEY(1, 7, KEY_H),
  KEY(1, 8, KEY_G),
  KEY(1, 9, KEY_F),
  KEY(1, 10, KEY_C),
  KEY(1, 11, KEY_RESERVED),
  KEY(1, 12, KEY_RESERVED),
  KEY(1, 13, KEY_END),
  KEY(1, 14, KEY_RESERVED),
  KEY(2, 0, KEY_LEFTCTRL),
  KEY(2, 1, KEY_LEFTALT),
  KEY(2, 2, KEY_RESERVED),
  KEY(2, 3, KEY_BACKSPACE),
  KEY(2, 4, KEY_BACKSLASH),
  KEY(2, 5, KEY_LEFT),
  KEY(2, 6, KEY_ENTER),
  KEY(2, 7, KEY_7),
  KEY(2, 8, KEY_T),
  KEY(2, 9, KEY_E),
  KEY(2, 10, KEY_R),
  KEY(2, 11, KEY_W),
  KEY(2, 12, KEY_Q),
  KEY(2, 13, KEY_RESERVED),
  KEY(2, 14, KEY_RESERVED),
  KEY(3, 0, KEY_RESERVED),
  KEY(3, 1, KEY_RESERVED),
  KEY(3, 2, KEY_RESERVED),
  KEY(3, 3, KEY_EQUAL),
  KEY(3, 4, KEY_0),
  KEY(3, 5, KEY_I),
  KEY(3, 6, KEY_UP),
  KEY(3, 7, KEY_Y),
  KEY(3, 8, KEY_6),
  KEY(3, 9, KEY_5),
  KEY(3, 10, KEY_4),
  KEY(3, 11, KEY_3),
  KEY(3, 12, KEY_CAPSLOCK),
  KEY(3, 13, KEY_S),
  KEY(3, 14, KEY_A),
  KEY(4, 0, KEY_RESERVED),
  KEY(4, 1, KEY_RESERVED),
  KEY(4, 2, KEY_HOME),
  KEY(4, 3, KEY_P),
  KEY(4, 4, KEY_O),
  KEY(4, 5, KEY_K),
  KEY(4, 6, KEY_U),
  KEY(4, 7, KEY_8),
  KEY(4, 8, KEY_RESERVED),
  KEY(4, 9, KEY_RESERVED),
  KEY(4, 10, KEY_RESERVED),
  KEY(4, 11, KEY_2),
  KEY(4, 12, KEY_1),
  KEY(4, 13, KEY_RESERVED),
  KEY(4, 14, KEY_RESERVED),
  KEY(5, 0, KEY_RESERVED),
  KEY(5, 1, KEY_RESERVED),
  KEY(5, 2, KEY_RESERVED),
  KEY(5, 3, KEY_SEMICOLON),
  KEY(5, 4, KEY_L),
  KEY(5, 5, KEY_9),
  KEY(5, 6, KEY_J),
  KEY(5, 7, KEY_GRAVE),
  KEY(5, 8, KEY_RESERVED),
  KEY(5, 9, KEY_RESERVED),
  KEY(5, 10, KEY_RESERVED),
  KEY(5, 11, KEY_RESERVED),
  KEY(5, 12, KEY_TAB),
  KEY(5, 13, KEY_RESERVED),
  KEY(5, 14, KEY_RIGHTSHIFT),
  KEY(6, 0, KEY_RESERVED),
  KEY(6, 1, KEY_RIGHTALT),
  KEY(6, 2, KEY_SPACE),
  KEY(6, 3, KEY_SLASH),
  KEY(6, 4, KEY_DOT),
  KEY(6, 5, KEY_COMMA),
  KEY(6, 6, KEY_M),
  KEY(6, 7, KEY_APOSTROPHE),
  KEY(6, 8, KEY_RESERVED),
  KEY(6, 9, KEY_RESERVED),
  KEY(6, 10, KEY_RESERVED),
  KEY(6, 11, KEY_RESERVED),
  KEY(6, 12, KEY_RESERVED),
  KEY(6, 13, KEY_RESERVED),
  KEY(6, 14, KEY_RESERVED),
};
*/

//cccc rrr e

#define KEYBS(ROW,COL)(ROW<<1 | COL<<4)          //keyboard "simple"
#define KEYB(ROW,COL,MOD) {KEYBS(ROW,COL),(MOD)} //keyboard with modifiers

#define NONE     0x00
#define SHIFT    0x01
#define ALT      0x02
#define CTRL     0x04
#define INVALID  0x80

#define SHIFT_KEY (KEYBS(0, 14))
#define ALT_KEY   (KEYBS(2,  1))
#define CTRL_KEY  (KEYBS(2,  0))
#define CTRL_KEY2  (KEYBS(2,  0))
#define ENTER_KEY (KEYBS(2,  6))

const uint8_t kbd[256][2] =
{
  KEYB(0,0,INVALID),     //0
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),     //8
  KEYB(0,0,INVALID),
  KEYB(2,6,INVALID),      //'\n' - enter
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),     //16
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //24
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(6,2,INVALID),   //32 -space
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //40
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(3,4,INVALID),   //48 0
  KEYB(4,12,INVALID),   //1
  KEYB(4,11,INVALID),   //2
  KEYB(3,11,INVALID),   //3
  KEYB(3,10,INVALID),   //4
  KEYB(3,9,INVALID),   //5
  KEYB(3,8,INVALID),   //6
  KEYB(2,7,INVALID),   //7

  KEYB(4,7,INVALID),   //56 8
  KEYB(5,5,INVALID),   //9
  KEYB(5,3,INVALID),   //: - semicolon
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),  

  KEYB(0,0,INVALID),   //64  @
  KEYB(3,14,SHIFT),    //-a
  KEYB(0, 8,SHIFT),    //b
  KEYB(1,10,SHIFT),    //c
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //72
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),   //80
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //88
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //96 - grave

  KEYB(3,14,NONE),    //-a
  KEYB(0,8,NONE),     //b
  KEYB(1,10,NONE),    //c
  KEYB(0,10,NONE),    //d
  KEYB(2,9,INVALID),  //e
  KEYB(1,9,INVALID),  //f
  KEYB(1,8,INVALID),  //g

  KEYB(0,0,INVALID),   //104 h
  KEYB(0,0,INVALID),   //i
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),   //112
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(4,6,NONE),    //u
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //120
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),  

  KEYB(0,0,INVALID),   //128
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),  

    KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID)
};



static uint8_t keybSession;
#define KB_DOWN 1
#define KB_UP 0   //I mean release

void Keyb_General(uint8_t kbdata,uint8_t event)
{
  uint8_t resp[2] = {0x00,0x00};
  resp[0] = kbdata | (event & 0x01);
  resp[1] = keybSession++; //its just a counter, not parsed by the dev btw
  GeneralTxMessage(0x51,resp,2);
}


void UnicodeTest()
{
  char buff[20];

  //Keyb_General(CTRL_KEY, KB_DOWN);
  Keyb_General(SHIFT_KEY,KB_DOWN);
  
  SendKeyboard_char_simple('u');

  sprintf(buff,"03b1\n");
  for(int i=0;i<20;i++)
  {
    if(buff[i] == 0)break;
    SendKeyboard_char_simple(buff[i]);
  }
  Keyb_General(SHIFT_KEY,KB_UP);
  //Keyb_General(CTRL_KEY, KB_UP);
  
}



void UnicodeTest2()
{
  char buff[20];

  Keyb_General(ALT_KEY,KB_DOWN);
  


  sprintf(buff,"u192");
  for(int i=0;i<20;i++)
  {
    if(buff[i] == 0)break;
    SendKeyboard_char_simple(buff[i]);
  }
  
   Keyb_General(ALT_KEY,KB_UP);
  
}






void SedKeyBoardTestAll()
{
  char buff[30];
  
  for(int i=30;i<128;i++)
  {
    sprintf(buff,"%02x ",i);
  
    for(int j=0;j<30;j++)
    {
      if(buff[j] == 0)break;
      SendKeyboard_char_simple(buff[j]);
    }  

    Keyb_General(ALT_KEY,KB_DOWN);
      Keyb_General((i<<1),KB_DOWN);
      Keyb_General((i<<1),KB_UP);
    Keyb_General(ALT_KEY,KB_UP);
    
    SendKeyboard_char(' ');
    SendKeyboard_char(' ');
    delay(20);
    
  }  
}



void SendKeyboard_char_simple(uint8_t data)
{
  if(!data)return;
  Keyb_General(kbd[data][0],KB_DOWN);
  Keyb_General(kbd[data][0],KB_UP);
}



void SendKeyboard_char(uint8_t data)
{
  if(!data)return;

  if(kbd[data][1] & SHIFT)   Keyb_General(SHIFT_KEY,KB_DOWN);
  if(kbd[data][1] & ALT)     Keyb_General(ALT_KEY,  KB_DOWN);
  if(kbd[data][1] & CTRL)    Keyb_General(CTRL_KEY, KB_DOWN);

  Keyb_General(kbd[data][0],KB_DOWN);
  Keyb_General(kbd[data][0],KB_UP);

  if(kbd[data][1] & SHIFT)   Keyb_General(SHIFT_KEY,KB_UP);
  if(kbd[data][1] & ALT)     Keyb_General(ALT_KEY,  KB_UP);
  if(kbd[data][1] & CTRL)    Keyb_General(CTRL_KEY, KB_UP);  
}
