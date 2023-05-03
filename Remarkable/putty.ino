//putty processor
//some special sh*t:
//UP:     1B 5B 41
//DOWN:   1B 5B 42
//RIGHT:  1B 5B 43
//LEFT:   1B 5B 44

//PGUP    1B 5b 35 7e
//PGDWN   1B 5B 36 7e
//HOME    1B 5B 31 7e
//END     1B 5B 34 7e


//ESC       1B
//Enter     0d - /r instead of /n
//Backspace 7f

enum EscapeStates
{
  esc_check = 0,
  esc_2,
  esc_3,
  esc_4 
};


int processPuttyTerminal(uint8_t ch)
{
 static enum EscapeStates escState=esc_check;
  
  switch(escState)
  {
   case esc_check:
    if(ch == 0x1b){ escState=esc_2;return 0;}
    break;
   case esc_2:
    if(ch == 0x5b){ escState=esc_3;return 0;}
    else{escState=esc_check;} //not found
      break;
   case esc_3:
           if(ch == 0x41){escState=esc_check;kbd_up();    return 0;} //UP
      else if(ch == 0x42){escState=esc_check;kbd_dwn();   return 0;} //Down
      else if(ch == 0x44){escState=esc_check;kbd_left();  return 0;} //left
      else if(ch == 0x43){escState=esc_check;kbd_right(); return 0;} //right
      else if(ch == 0x35){escState=esc_check;return 0;}   //pgUP
      else if(ch == 0x36){escState=esc_check;return 0;}   //pgDown
      else if(ch == 0x31){escState=esc_check;kbd_home();  return 0;} //Home
      else if(ch == 0x34){escState=esc_check;kbd_end();   return 0;} //end
      
      escState=esc_check;
      break;
   case esc_4:
      //rather not bother
      escState=esc_check;
    
    break; 
  }

  SendKeyboard_char(ch);
  return 1;
  
}

void kbd_up()
{
  Keyb_General(UP_KEY,KB_DOWN);  
  Keyb_General(UP_KEY,KB_UP);
  Serial.println("UP");
}

void kbd_dwn()
{
  Keyb_General(DOWN_KEY,KB_DOWN);  
  Keyb_General(DOWN_KEY,KB_UP);  
}

void kbd_left()
{
  Keyb_General(LEFT_KEY,KB_DOWN);  
  Keyb_General(LEFT_KEY,KB_UP);  
}

void kbd_right()
{
  Keyb_General(RIGHT_KEY,KB_DOWN);  
  Keyb_General(RIGHT_KEY,KB_UP);  
}

void kbd_home()
{
  Keyb_General(HOME_KEY,KB_DOWN);  
  Keyb_General(HOME_KEY,KB_UP);  
  
}

void kbd_end()
{
  Serial.println("END key");
  Keyb_General(END_KEY,KB_DOWN);  
  Keyb_General(END_KEY,KB_UP);    
}
