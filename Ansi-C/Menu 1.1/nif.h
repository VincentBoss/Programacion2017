// vincent © 2017
#ifndef NIF_H
#define NIF_H

int NIF(char*); //Prototipo

int NIF(char* texto){
 int      DNI = atoi(texto); /* Se transforma el texto de entrada a numeros, previa validacion de comprobacion.h */
char Letras[] = {'T','R','W','A','G','M',
                 'Y','F','P','D','X','B',
                 'N','J','Z','S','Q','V',
                 'H','L','C','K','E','O'};

    DNI = DNI - ((DNI / 23) * 23); //Operacion para determinar la letra del DNI

    printf("\n\tLa letra correspondiente es: %c\n", Letras[DNI]); //imprime letra del DNI
return 0;
}//Fin Funcion NIF

#endif //Fin NIF_H
