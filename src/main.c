// para el kit de arduino de la catedra "Circuitos Digitales y Microcontroladores"
// imprime "hola mundo" en la 1er fila del LCD, y numeros consecutivos del 0..9
#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>

int main(void) {
    
    _delay_ms(1000);        // espera inicial para evitar errores colision de pines

    LCDinit();
    LCDclr();               // borra el display para iniciar
    _delay_ms(10);          // espera a que el display termine de borrar la pantalla

    LCDstring("hola mundo",10); // mensaje statico : hola mundo

    uint8_t num='0';
    while (1) {
        LCDGotoXY(15,0);    // posiciona el cursor al final primer linea
        LCDsendChar(num++); // envia numero
        if(num>'9')num='0'; // incrementa

        _delay_ms(500);     // bloqueo
    }

    return 0;
}