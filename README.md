# Remarkable_TypeFolio_Pretender


This is a simple proof of concept project, that mimics the communication of the "Type Folio" keyboard
via the POGO pins of the device.

It is written for the Arduino Leonardo (Pro micro 5v - clone?) board. But can easily adapt to any Arduino board.

This project only translates some commands from the USB CDC UART to POGO Pin virtual keyboard command

The communication with the RM2 on POGO pins:

step0: The device pulls down the ID pin. (You can start with '.' character now - The USB Tx pulls down with some junk)

step1_a: The RM2 asks the name of the device.
step1_b: The device responds

Step2_a: The Rm2 ask some more info about the dev.
Step2_b: The device responds with a single compound package

Step3_a: The Rm2 asks the Auth.key
Step3_b: The device responds (its a long string)

Step4_a: The Rm2 asks the dev to enter "APP mode"
Step4_b: The Dev confirms

Step5: The device sends "keep alive" messages, and keyboard event messages!


The circuit I used (just some transistors I found in my shelf):
[pogo_-_page_12](https://user-images.githubusercontent.com/132338151/235611830-a67d9f11-b7cb-493c-ad19-2e62dee38e93.png)

To be continued...


========================================
Special thx to Pablo
========================================


in this initial version,
it only accepts 'a','b','c','A','B','C' and  ('d' = enter) characters from the serial console. ...'Cause I was lazy to fill up all the fields of the lookup table.
The lookup table contains the "inverse" of the lookup table found in the RM2 code

One Keypress byte looks like this:
ccccrrre
c:column bits
r:row bits
e:event (1:press 0:release)

------------------------------
example:
character 'a' is the 97th element of the ascii table. The RM2 lookup table says its Col:14 and Row:3... so the 97th element of our lookup table is: 
((3<<1) | (14<<4)),   //97 - a
In my lookup table the lower bit means, there is a SHIFT key press necessary
------------------------------

In case of UPPER CASE letters the fw sends SHIFT DOWN / UP key events


