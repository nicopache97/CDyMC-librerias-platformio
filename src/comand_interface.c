

#include "comand_interface.h"

	// variable interna para guardado parcial de mensaje

	volatile uint8_t mensaje[buffer_leng]; // vector global de caracteres para pantalla
	volatile uint8_t indice_mensaje=0;
	volatile uint8_t flag_New_MSJ=0; // vandera de nuevo mensaje recibido

void INIT_comand_interface(){
    SerialPort_Init(BR9600); 		// Inicializo formato 8N1 y BAUDRATE = 9600bps
	SerialPort_TX_Enable();			// Activo el Transmisor del Puerto Serie
	SerialPort_RX_Enable();			// Activo el Receptor del Puerto Serie
	SerialPort_RX_Interrupt_Enable();	// Activo Interrupción de recepcion.
}

void getComand(char* str){
    if(flag_New_MSJ){
        for(uint8_t i=0 ; indice_mensaje>i ; i++){ // copia el mensaje caracter a caracer
            str[i]=mensaje[i];
        }
        indice_mensaje=0;	// reseteo la longitud del string acumulativo
        flag_New_MSJ=0;
    }else{
        *str =0; // avisa que no hay mensaje
    }

}

// Rutina de Servicio de Interrupción de Byte Recibido
ISR(USART_RX_vect){
	uint8_t keyPress=UDR0;      // guardo el caracter
    SerialPort_Send_Data(keyPress);	// hago el echo del caracter leido
    if (keyPress!=8){	// si no es el caracter DELETE
        mensaje[indice_mensaje] = keyPress;	// guardo el nuevo caracter
        if(mensaje[indice_mensaje]=='\r'){	//si el caracter que recibo es final de cadena
            flag_New_MSJ=1;				// marco como nuevo mensaje recibido
            mensaje[indice_mensaje]='\0';	// remplazo el \r con el fin de cadena

        }else{
            if(buffer_leng > (indice_mensaje+1) ){ // si hay espacio en el buffer
                indice_mensaje++;// incremento a la siguiente posicion
            }
        }
    }else{
        if(indice_mensaje){
            indice_mensaje--; // si el largo es mayor a cero, y el caracter es DELETE, se decrementa el caracter anterior
        }
    }
}