// vincent © 2017
#ifndef COMPROBACION_H
#define COMPROBACION_H

int comprobar(char * const);

int comprobar(char * const cadena){
int Numero = 0;
    Numero = atoi(cadena); /* Se transforma la cadena de tipo char a tipo int */

    if(Nuermo !=0 ) {/* Comprobamos que la cadena de entrada solo contenga numeros*/
            if (strlen(cadena) <= 4) { /* Menor de 4 cifras es un numero romano */
                if (Numero <= 3000) {  /* Numero válido, menor que 3000*/
                    return 1;
                } else { /* Error se despliega mensaje y se retorna valor 0 */
                    printf("\n\tLa cifra debe ser menor que 300 y mayor que 0, intentelo nuevamente\n");
                    return 0;
                }
            } else { /* Mayor de 4 cifras es un DNI*/
                if (Numero < 99999999) { /* Nuermo válido, menor que 99999999*/
                    return 1;
                } else { /* Error se despliega mensaje y se retorna valor 0 */
                    printf("\n\tEl numero debe ser menor que 99999999, intentelo nuevamente\n");
                    return 0;
                }
            }
    }else{ /* Error, la cadena de entrada contiene un caracter no válido */
        printf("\n\tNo se admiten ni signos de puntuacion ni letras, intentelo nuevamente\n");
        return 0;
    }
}

#endif //Fin COMPROBACION_H