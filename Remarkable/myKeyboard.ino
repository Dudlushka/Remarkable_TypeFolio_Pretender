/* Seabird_pC08_20220321, with row0 not connected. The row0 here is row1 on PCB */
/*
KEY(0, 3, KEY_RIGHT),
  KEY(1, 4, KEY_DOWN),
  KEY(2, 5, KEY_LEFT),
  KEY(3, 6, KEY_UP),

  KEY(0, 14, KEY_LEFTSHIFT),
  KEY(5, 14, KEY_RIGHTSHIFT),
  KEY(2, 0, KEY_LEFTCTRL),
  KEY(2, 1, KEY_LEFTALT),
  KEY(6, 1, KEY_RIGHTALT),

  KEY(6, 2,  KEY_SPACE),
  KEY(2, 3,  KEY_BACKSPACE),
  KEY(2, 6,  KEY_ENTER),
  KEY(3, 12, KEY_CAPSLOCK),

  KEY(5, 12, KEY_TAB),

  KEY(4, 2, KEY_HOME),
  KEY(1, 13, KEY_END),

  KEY(6, 3, KEY_SLASH),
  KEY(2, 4, KEY_BACKSLASH),
  KEY(3, 3, KEY_EQUAL),
  KEY(6, 7, KEY_APOSTROPHE),
  KEY(5, 3, KEY_SEMICOLON),
  KEY(5, 7, KEY_GRAVE),
  KEY(6, 5, KEY_COMMA),
  KEY(6, 4, KEY_DOT),
  
  KEY(4, 12, KEY_1),
  KEY(4, 11, KEY_2),
  KEY(3, 11, KEY_3),
  KEY(3, 10, KEY_4),
  KEY(3, 9,  KEY_5),
  KEY(3, 8, KEY_6),
  KEY(2, 7, KEY_7),  
  KEY(4, 7, KEY_8),
  KEY(5, 5, KEY_9),
  KEY(3, 4, KEY_0),
 
  KEY(3, 14, KEY_A),
  KEY(0, 8, KEY_B),
  KEY(1, 10, KEY_C),
  KEY(0, 10, KEY_D),
  KEY(2, 9, KEY_E),
  KEY(1, 9, KEY_F),
  KEY(1, 8, KEY_G),
  KEY(1, 7, KEY_H),
  KEY(3, 5, KEY_I),
  KEY(5, 6, KEY_J),
  KEY(4, 5, KEY_K),
  KEY(5, 4, KEY_L),
  KEY(6, 6, KEY_M),
  KEY(0, 7, KEY_N),
  KEY(4, 4, KEY_O),
  KEY(4, 3, KEY_P),
  KEY(2, 12, KEY_Q),
  KEY(2, 10, KEY_R),
  KEY(3, 13, KEY_S),
  KEY(2, 8, KEY_T),
  KEY(4, 6, KEY_U),
  KEY(0, 9, KEY_V),
  KEY(2, 11, KEY_W),
  KEY(0, 11, KEY_X),
  KEY(3, 7, KEY_Y),
  KEY(0, 12, KEY_Z),

*/

//cccc rrr e

#define KEYBS(ROW,COL)(ROW<<1 | COL<<4)          //KEYBS = keyboard "simple"
#define KEYB(ROW,COL,MOD) {KEYBS(ROW,COL),(MOD)} //keyboard with modifiers

#define NONE     0x00
#define SHIFT    0x01
#define ALT      0x02
#define CTRL     0x04
#define INVALID  0x80

#define SHIFT_KEY (KEYBS(0, 14))
#define ALT_KEY    (KEYBS(2,  1))
#define ALT2_KEY   (KEYBS(6,  1))
#define CTRL_KEY  (KEYBS(2,  0))
#define CTRL_KEY2  (KEYBS(2,  0))
#define ENTER_KEY (KEYBS(2,  6))

#define UP_KEY    (KEYBS(3,  6))
#define DOWN_KEY  (KEYBS(1,  4))
#define LEFT_KEY  (KEYBS(2,  5))
#define RIGHT_KEY (KEYBS(0,  3))

#define HOME_KEY  (KEYBS(4,  2))
#define END_KEY   (KEYBS(1,  13))


//NOT finished yet!!!!!! - some characters missing!

const uint8_t kbd[256][2] =
{
  KEYB(0,0,INVALID),     //0 -null
  KEYB(0,0,INVALID),     //SOH
  KEYB(0,0,INVALID),     //
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(2,3, NONE),       //8 -backspace  
  KEYB(5,12,NONE),       //9 hor tab
  KEYB(2,6, NONE),       //'\n' - enter
  KEYB(0,0,INVALID),     //ver.tab - X
  KEYB(0,0,INVALID),     //new page - X
  KEYB(2,6, NONE),       //carriage return (ENTER!) //remove this if you want
  KEYB(0,0,INVALID),     //shift out
  KEYB(0,0,INVALID),     //shift in
  
  KEYB(0,0,INVALID),     //16 - data link escape
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
  KEYB(0,0,INVALID),   // ESCAPE
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(6,2,NONE),      //32 -space
  KEYB(0,0,INVALID),   //!
  KEYB(0,0,INVALID),   //"
  KEYB(0,0,INVALID),   //#
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
  KEYB(4,12,INVALID),  //1
  KEYB(4,11,INVALID),  //2
  KEYB(3,11,INVALID),  //3
  KEYB(3,10,INVALID),  //4
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
  KEYB(3,14,SHIFT),     //-a
  KEYB(0,8, SHIFT),      //b
  KEYB(1,10,SHIFT),     //c
  KEYB(0,10,SHIFT),     //d
  KEYB(2,9,SHIFT),      //e
  KEYB(1,9,SHIFT),      //f
  KEYB(1,8,SHIFT),      //g

  KEYB(1,7,SHIFT),      //104 h
  KEYB(3,5,SHIFT),   //i
  KEYB(5,6,SHIFT),   //j 
  KEYB(4,5,SHIFT),   //k
  KEYB(5,4,SHIFT),   //l
  KEYB(6,6,SHIFT),   //m
  KEYB(0,7,SHIFT),   //n
  KEYB(4,4,SHIFT),   //o
  
  KEYB(4,3,SHIFT),   //112 p
  KEYB(2,12,SHIFT),   //q
  KEYB(2,10,SHIFT),   //r
  KEYB(3,13,SHIFT),   //s
  KEYB(2,8,SHIFT),   //t
  KEYB(4,6,SHIFT),      //u
  KEYB(0,9,SHIFT),   //v
  KEYB(2,11,SHIFT),   //w

  KEYB(0,11,SHIFT),   //120 x
  KEYB(3,7,SHIFT),   //y
  KEYB(0,12,SHIFT),   //z
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),

  KEYB(0,0,INVALID),   //96 - grave

  KEYB(3,14,NONE),     //-a
  KEYB(0,8,NONE),      //b
  KEYB(1,10,NONE),     //c
  KEYB(0,10,NONE),     //d
  KEYB(2,9,NONE),      //e
  KEYB(1,9,NONE),      //f
  KEYB(1,8,NONE),      //g

  KEYB(1,7,NONE),      //104 h
  KEYB(3,5,NONE),   //i
  KEYB(5,6,NONE),   //j 
  KEYB(4,5,NONE),   //k
  KEYB(5,4,NONE),   //l
  KEYB(6,6,NONE),   //m
  KEYB(0,7,NONE),   //n
  KEYB(4,4,NONE),   //o
  
  KEYB(4,3,NONE),   //112 p
  KEYB(2,12,NONE),   //q
  KEYB(2,10,NONE),   //r
  KEYB(3,13,NONE),   //s
  KEYB(2,8,NONE),   //t
  KEYB(4,6,NONE),      //u
  KEYB(0,9,NONE),   //v
  KEYB(2,11,NONE),   //w

  KEYB(0,11,NONE),   //120 x
  KEYB(3,7,NONE),   //y
  KEYB(0,12,NONE),   //z
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(0,0,INVALID),
  KEYB(2,3,NONE),    //bakspace in putty,  

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






//----------------------------------------------------------------------------------


static uint8_t keybSession; //session counter-not really used by the RM2, just prints to the debug console
#define KB_DOWN 1  //Keyboard press event
#define KB_UP 0    //...release event

void Keyb_General(uint8_t kbdata,uint8_t event)
{
  uint8_t resp[2] = {0x00,0x00};
  resp[0] = kbdata | (event & 0x01);
  resp[1] = keybSession++; //its just a counter, not parsed by the dev btw
  GeneralTxMessage(0x51,resp,2);
}


//----------------------------------------------------------------------------------
//Some helper functions
//----------------------------------------------------------------------------------

//A simple keyboard character without modifiers
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

  SendKeyboard_char_simple(data);

  if(kbd[data][1] & SHIFT)   Keyb_General(SHIFT_KEY,KB_UP);
  if(kbd[data][1] & ALT)     Keyb_General(ALT_KEY,  KB_UP);
  if(kbd[data][1] & CTRL)    Keyb_General(CTRL_KEY, KB_UP);  
}
