/*

 Example guide: TBD
 */
#include "IRDevice.h"

// Set IR TX and RX pins
// check the board pin mapping for available IR pins
#define IR_RX_PIN       8
#define IR_TX_PIN       9

uint8_t adr = 0;
uint8_t cmd = 0;

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    IR.beginNEC(IR_RX_PIN, IR_TX_PIN, IR_MODE_TX); // configure for NEC IR protocol
}

void loop() {
    if (cmd++ >=255) {
        adr++;
    }

    IR.sendNEC(adr, cmd);
    Serial.print("Sent ");
    Serial.print(adr);
    Serial.print(cmd);
    Serial.println();
    //IR.end();   // Call this method to stop IR device and free up the pins for other uses
}
