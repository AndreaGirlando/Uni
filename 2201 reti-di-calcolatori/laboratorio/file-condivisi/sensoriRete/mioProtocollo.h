#include <stdint.h>

#define TYPE_READ 1
#define TYPE_UNLOCK 2


#pragma pack(push,1)

typedef struct{

uint16_t seonsorID; //2
uint8_t isBlocked;  //1

//letture sensore:
int temperature;  //4
int humidity;     //4
uint8_t ceRiccobene;    //1

//posizione sensore
char citta[32]; //32
}sensor_read_t; //quanto pesa? //44 bytes


typedef struct{

uint16_t sensorID; //2
uint8_t isBlocked;  //1

}sensor_unlock_t;   //3 bytes


typedef struct{
    uint8_t type;   //1
    uint8_t payload[63];    //44

}protocol_message_t;    //64 bytes -> è il peso totale del mio protocollo

#pragma pack(pop)