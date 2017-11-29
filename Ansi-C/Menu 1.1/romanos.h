// vincent © 2017
#ifndef ROMANOS_H
#define ROMANOS_H

int Romanos(char*); //Prototipo

int Romanos(char * Entrada){
    /*****************************************************************************
     * Romanos[], es el array mas importante del programa, usado para poder      *
     * escribir de forma correcta las cifras, haciendo operaciones solo con la   * 
     * clave de los valores del array.                                           * 
     * la variable tmp es una variable temporal usada para almacenar solo        *
     * un digito de de la variable Entrada que posteriormente será transformado, *
     * Entrada el numero que el usuario quiere tranasformar                      *
     *****************************************************************************/
     const char  Romanos[] = "MDCLXVI";
     char tmp, *Msg;  Msg = (char*) malloc(13 * sizeof(char));

    /******************************************************************************************************
     * variables de iteración, junto con una variable temporal (Numero) para el digito a transformar.     *
     * La variable Indice2 es utiliza para almacenar los caracteres en Msg, Indice es usada por           *
     * las variables "fix" para determinar el digito Romano correspondiente al numero indicado en la      *
     * iteracion activa, la variable Contador, se usa en el bucle más externo al contrario que            *
     * ContadorDos, que es usada solo en los bucles internos y al salir de ellos es de nuevo igualada a 0 *
     ******************************************************************************************************/
     int  Contador , ContadorDos , Numero , Indice , Indice2 , Longitud , prefix , fix , sufix;
          Contador = ContadorDos = Numero = Indice = Indice2 = Longitud = prefix = fix = sufix = 0;

    Numero = atoi(Entrada);
    Longitud = strlen(Entrada); /* Longitud del numero ingresado por el usuario */

    if((Numero <= 3000) && (Numero != 0) ){
        
   /*****************************************************************************************************
    * Aquí comienza el recorrido cifra por cifra del numero que ingreso el usuario                      *
    * Esta operacion es escencial para calcular correctamente digito dentro del array Romanos           *
    * tmp es un digito unico que posterior mente es transformado por atoi para se almacenado en Numero  *
    *****************************************************************************************************/
          while(Contador < Longitud){
              
              /********************************************************************************************************************
              * 4 es la longitud máxima de un numero menor que 3000, la siguiente operacion, (4 - (Longitud - Contador)) * 2      *
              * determina a partir de que letra del array Romanos se comienzan a hacer las operaciones Longitud - Contador        *
              * determina el orden de un numero es decir multiplo de 10^n dentro del array Romanos[], en el caso de que sea 0     *
              * sería 1, para 2 el orden es 100 de este modo 421, el numero 2 corresponde a la iteracion 1 y 3 que es la longitud * 
              * del numero podemos sustituir (4 - (3 - 1)) * 2 = 4, Romanos[4] = X                                                *
              *********************************************************************************************************************/
              Indice = (4 - (Longitud - Contador)) * 2;
              tmp = Entrada[Contador];
              Numero = atoi(&tmp);
                      if(Numero < 5){
                          fix = Indice;
                          
                              if( Indice > 0)prefix = Indice - 1;
                                    if(Numero != 4){ /* Aquí se escriben los digitos diferentes de la forma 4x10^n, 3 = III  */
                                            while (ContadorDos < Numero){
                                                    Msg[Indice2] = Romanos[fix]; Indice2 +=1; /* Se repite I en el mensaje final */
                                                ++ContadorDos;                                /* solo se repite un maximo de 3 veces */
                                              }ContadorDos = 0 ;
                                    }else{/* Aquí se escriben los digitos de la forma 4x10^n, 4 = IV */
                                        Msg[Indice2] = Romanos[fix];     Indice2 +=1; /* Se almacena I en el mensaje final */
                                        Msg[Indice2] = Romanos[prefix];  Indice2 +=1; /* Se almacena V en el mensaje final */
                                    }/* Fin IF */
                          
                      }else{
                        prefix = Indice;
                           fix = Indice - 1;
                         sufix = Indice - 2;
                          
                                    if(Numero == 5){ /* Aquí se escriben los digitos de la forma 5x10^n  */
                                          Msg[Indice2] = Romanos[fix]; Indice2 +=1;

                                    }else if(Numero == 9){ /* Aquí se escriben los digitos de la forma 9x10^n, 9 = IX */
                                          Msg[Indice2] = Romanos[prefix]; Indice2 +=1; /* Se almacena I en el mensaje final */
                                          Msg[Indice2] = Romanos[sufix];  Indice2 +=1; /* Se almacena X en el mensaje final */

                                    }else{ /*Numeros entre los tipos 5x10^n y 9x10^n, correspondientes a la iteracion, 7 = VII*/
                                          Msg[Indice2] = Romanos[fix]; Indice2 +=1; /* Se almacena V en el mensaje final */
                                              while ( ContadorDos < (Numero - 5) ){ /* Se repite I en el mensaje final */
                                                      Msg[Indice2] = Romanos[prefix]; Indice2 += 1;
                                                  ++ContadorDos;
                                                }ContadorDos = 0;
                                    }/* Fin IF */
                          
                      }/* Fin IF */
              
                ++Contador; /*Con Contador recorremos la cadena Romanos*/
          }/* Fin WHILE */
        
        Msg[Indice2] = '\0';
        printf("\n\tEn Romano es: %s\n", Msg);
    }else{ 
        printf("El numero debe ser mayor que uno y menos que tres mill\n"); 
    }/* Fin IF */
return 0;
}//Fin Romanos

#endif //Fin ROMANOS_H
