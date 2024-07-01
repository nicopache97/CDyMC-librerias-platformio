# Ejemplo de proyecto PlatformIO
 platformio es un IDE que se utiliza integrado a VS-code o otros editeres de texto, que se propone utilizar en la catedra de "Circuitos Digitales y Microcontroladores" de la UNLP, para compilar programas en C para microcontroladores. Espesificamente bajo la arquitectura AVR, para el microcontrolador ATmega328p.


### Descripción de las Carpetas y Archivos

- **lib/**: Contiene las bibliotecas `/lcd` y `/SerialPort` en sus respectivas subcarpetas.
Cada biblioteca contiene los subdirectorios :
  - `/src` con su programa **'.c'** y cabeceras **'.h'**. 
  - `/examples` con programas de ejemplo.
  - `/docs` con la documentacion minima para usar correctamente esa biblioteca
- **simulacion/**: contiene los archivos de simulacion de proteus
- **src/**: Contiene el código fuente del proyecto.
  - **main.c**: Programa principal.
  - **comand_interface.c**: funciones modulares espesificas del tratamiento de comandos por protocolo serie.
  - **comand_interface.h**: cabecera de libreria externa
- **platformio.ini**: Archivo de configuración de PlatformIO.
- **README.md**: Este archivo con información del proyecto.

## Requisitos
- [PlatformIO](https://platformio.org/) instalado.


## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Ver el archivo [LICENSE](LICENSE) para más detalles.
