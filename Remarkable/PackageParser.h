/*
 * PacketParser.h
 *
 *  Created on: 2023. ápr. 27.
 *      Author: A.Cserna "Dudlushka"
 */

#ifndef INC_PACKETPARSER_H_
#define INC_PACKETPARSER_H_


//------------------------------------------------
//from remarkable code: pogo_attribute_storage.h
//------------------------------------------------
typedef enum _attributes_ids {
  /* Read only attributes */
  ATTRIBUTE_ID_PROTOCOL_VERSION = 0x01,
  ATTRIBUTE_ID_FW_VERSION,
  ATTRIBUTE_ID_HW_VERSION,
  ATTRIBUTE_ID_DEVICE_CLASS,
  ATTRIBUTE_ID_DEVICE_ID,
  ATTRIBUTE_ID_IMAGE_START_ADDRESS,
  ATTRIBUTE_ID_DEVICE_NAME,

  /* Read/Write attributes */
  ATTRIBUTE_ID_KEY_LAYOUT = 0x10,
  ATTRIBUTE_ID_LANGUAGE,
  ATTRIBUTE_ID_RM_SERIAL_NUMBER,

  /* Production and test attributes */
  ATTRIBUTE_ID_MFG_LOG = 0x20,
  ATTRIBUTE_ID_AUTO_KEYBOARD_TEST_MODE,
  ATTRIBUTE_ID_COMMUNICATION_TEST_KEYS_DELAY_MS,
  ATTRIBUTE_ID_COMMUNICATION_TEST_PRESS_RELEASE_DELAY_MS,

  /* Communication delays */
  ATTRIBUTE_ID_ALIVE_MESSAGE_TIMEOUT_MS = 0x30,
  ATTRIBUTE_ID_POGO_PIN_RX_TX_SWITCH_DELAY_US,
  ATTRIBUTE_ID_MATRIX_SCAN_DELAY_US,
  ATTRIBUTE_ID_LPD_INITIAL_WAIT_US,
  ATTRIBUTE_ID_LPD_REQUEST_VBUS_PULSE_US,
  ATTRIBUTE_ID_SUSPEND_WAIT_FOR_VBUS_LOSS_US,
  ATTRIBUTE_ID_UNKNOWN,
} attributes_ids_t;


typedef enum _package_kb_language
{
    DE = 1,
    ES = 2,
    FR = 3,
    IT = 4,
    NO = 5,
    PT = 6,
    UK = 7,
    US = 8
} package_kb_language_t;



#define BUFF_LEN 128
extern uint8_t buff[BUFF_LEN];

int ProcessPack_low(uint8_t data_in);
void FirstNameResponse();
void ReStartStateMachine();

void SuperResponsePack_v2();
void SendAuthKeyResponse();

#endif /* INC_PACKETPARSER_H_ */
