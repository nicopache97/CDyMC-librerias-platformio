
// mini biblioteca de procesamiento de comandos por protocolo serie

#ifndef COMAND_INTERFACE_H_
	#define COMAND_INTERFACE_H_ 	// usa libreria serial port, e interrupciones USART_RX_vect 

	#include "SerialPort.h"
	#define BR9600 (0x67)	// 0x67=103 configura BAUDRATE=9600@16MHz

	#define buffer_leng 30 // tamaño buffer de caracteres interno

	void INIT_comand_interface(); // interfaz serie standar 9600baudios
	void getComand(char*); //si hay comando lo escribe por referencia, sino guarda char*=0


#endif