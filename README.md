# Remarkable_TypeFolio_Pretender

## General:
  This is a simple proof of concept project, that mimics the communication of the "Type Folio" keyboard via the POGO pins of the device. It is written for the Arduino Leonardo (Pro micro 5v - clone?) board. But can easily adapt to any Arduino board. This project only translates some commands from the USB CDC UART to POGO Pin virtual keyboard command

## The communication with the RM2 on POGO pins:

-step0: The device pulls down the ID pin. 
~~(You can start with '.' character now - The USB Tx pulls down with some junk)~~
(You can start with PAUSE button (0x1A is being sent by Putty) now - but feel free to modify- The USB Tx pulls down with some junk)


-step1_a: The RM2 asks the name of the device.
-step1_b: The device responds

-Step2_a: The Rm2 ask some more info about the dev.
-Step2_b: The device responds with a single compound package

-Step3_a: The Rm2 asks the Auth.key
-Step3_b: The device responds (its a long string)

-Step4_a: The Rm2 asks the dev to enter "APP mode"
-Step4_b: The Dev confirms

-Step5: The device sends "keep alive" messages, and keyboard event messages!

## Hardware
The communication with the RM2 on POGO pins:
The circuit I used (just some transistors I found in my shelf):
![pogo_pinout_small](https://user-images.githubusercontent.com/132338151/235752679-8d9337df-3f65-466a-a5c2-9072b510fc36.jpg)


The pogo pin adapter I made (with resin printer):
![pogo_holder](https://user-images.githubusercontent.com/132338151/235751801-2565f187-1751-423a-bce9-8dee67da5865.png)

To be continued...

>Special thx to Pablo


## Usage
~~in this initial version,it only accepts 'a','b','c','A','B','C' and  '0'-'f' characters from the serial console. ...'Cause I was lazy to fill up all the fields of the lookup table.~~
Start the negotiation process by physically pulling down the ID pin for a moment - or press the "Pause" button in putty terminal (or somehow send 0x1A character). After the negotiation process finished, you can start typing into the console window.
Almost all alphanummeric characters added, but still a lot are missing.
The processPuttyTerminal() function parses the incoming characters for escape sequences (for accepting arrow key events, F1..F12 keys(not yet implemented) etc...)

The lookup table contains the "inverse" of the lookup table found in the RM2 code

## Some more info:
One Keypress byte looks like this:
ccccrrre (bits)
c:column bits
r:row bits
e:event (1:press 0:release)


## example:
character 'a' is the 97th element of the ascii table. The RM2 lookup table says its Col:14 and Row:3... so the 97th element of our lookup table is: 
((3<<1) | (14<<4)),   //97 - a
In my lookup table the lower bit means, there is a SHIFT key press necessary
In case of UPPER CASE letters the fw sends SHIFT DOWN / UP key events


