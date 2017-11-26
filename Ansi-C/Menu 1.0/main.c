// vincent © 2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comprobacion.h"
#include "romanos.h"
#include "nif.h"

int main() {
    char Texto[7], Opcion[3];
    int Numero = 0;

    printf("\n\tBienvenido al menu de aplicaciones \n"); /* Mensaje de bienvenida, solo visible 1 vez */
    do{
        /* Se listan las opciones del menu */
        printf("\n\t <----Menu 1.0---->\n"
               "\t 1 para traducir numeros decimales a romanos\n\t"
                 " 2 para Calcular la letra del DNI\n\t"
                 "-1 para salir\n\t"
                 "Elija una opcion: ");
        scanf("%s", Opcion);
        Numero = atoi(Opcion); /* Se transforma la cadena de entrada del tipo char al tipo int*/
                            if (Numero != 0) {
                                if (Numero == 1) {
                                    printf("\t<----Romanos---->\n");
                                    printf("\tEscriba el numero: ");
                                    scanf("%s", Texto);
                                            if(comprobar(Texto) == 1) {
                                                printf("\n\t");
                                                Romanos(Texto);
                                                printf("\n");}

                                } else if (Numero == 2) {
                                    printf("\t<----Letra DNI---->\n");
                                    printf("\tEscriba el DNI: ");
                                    scanf("%s", Texto);
                                            if(comprobar(Texto) == 1) {
                                                Numero = atoi(Texto);
                                                printf("\n\t");
                                                NIF(Numero);
                                                printf("\n");}
                                } else if (Numero == -1) {
                                        printf("Adios cowboy...\n");
                                } else {/* Error, la Opcion elejida por el usuario es desconocida pero con formato valido*/
                                        printf("\n\nDisculpa mi ignorancia, pero no se lo que significa %s :(\n\n\t", Opcion);
                                }
                            } else { /* Error, Formato de opcion no valida */
                                  printf("\n\tOpcion no valida\n\t");
                            }
       }while(Numero != -1);

  return 0;
}//Fin main
