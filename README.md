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

[pogo_-_page_12](https://user-images.githubusercontent.com/132338151/235611830-a67d9f11-b7cb-493c-ad19-2e62dee38e93.png)
