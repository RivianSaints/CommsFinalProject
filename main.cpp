#include "mbed.h"
#include "USBSerial.h"
//test program to recieve serial communication
//this will recieve comm from teraterm, but should work for windows too
// arduino-upload.bat COM9 BUILD/ARDUINO_NANO33BLE_SENSE/ARMC6\JLawrence_FinalProject_Comm.bin
// main() runs in its own thread in the OS

USBSerial ConnectionSerial(true);
char *StoredMessage[30];


int main(){  
    
    char spoon[] = "I am focused, Iron Focus\n\r"; // echo back
    ConnectionSerial.write(spoon, sizeof(spoon));
    char buff[1];
    while (true) {
        int i = 0;
       for(i=0 ;i<31;i++){
            ConnectionSerial.read(buff, sizeof(buff));
            if(buff == ";"){
                break;
            }
            StoredMessage[i] = buff;
            //ConnectionSerial.printf("%s\n\r", buff);
            ConnectionSerial.write(buff, sizeof(buff));
            thread_sleep_for(50);
        }
        ConnectionSerial.printf("Completed Message: \n\r");
        for(int i1= 0; i1<i; i1++){
            ConnectionSerial.printf("%s",StoredMessage[i1]);
        }
        thread_sleep_for(100);
    }
}

