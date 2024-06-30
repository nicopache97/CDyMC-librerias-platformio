// para el kit de arduino de la catedra "Circuitos Digitales y Microcontroladores"
// imprime "hola mundo" en la 1er fila del LCD, y numeros consecutivos del 0..9

#include <avr/io.h>
#include <util/delay.h>
#include "SerialPort.h"
#include "comand_interface.h"

char mensaje_recibido[buffer_leng];

int main(void) {
    	
    INIT_comand_interface();
	sei();								// Activo la mascara global de interrupciones (Bit I del SREG en 1)

    SerialPort_Send_String("conectado \r");

    while (1) {
        getComand(mensaje_recibido);
        if(*mensaje_recibido){// cuando un mensaje nuevo
            SerialPort_Send_String("\r nuevo mensaje recibido :\r ->   ");
            SerialPort_Send_String(mensaje_recibido);
            SerialPort_Wait_For_TX_Buffer_Free();
            SerialPort_Send_Data('\r');
        }

    }

    return 0;
}

