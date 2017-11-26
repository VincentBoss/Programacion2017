// vincent © 2017
#ifndef NIF_H
#define NIF_H

void NIF(int); //Prototipo

void NIF(int DNI){
char Letras[] = {'T','R','W','A','G','M',
                 'Y','F','P','D','X','B',
                 'N','J','Z','S','Q','V',
                 'H','L','C','K','E','O'};

    DNI = DNI - ((DNI / 23) * 23); //Operacion para determinar la letra del DNI

    printf("La letra correspondiente es: %c", Letras[DNI]); //imprime letra del DNI
}//Fin Funcion NIF

#endif //Fin NIF_H