// vincent © 2017
#ifndef ROMANOS_H
#define ROMANOS_H

int Romanos(char*); //Prototipo

int Romanos(char * Entrada){
    /**************************************************************************
     * Creamos las variables como puntero y reservamos memoria                *
     * no me pregunten porque C, no queria usar cadenas                       *
     * la variable tmp es una variable tambien temporal usada                 *
     * para almacenar solo un digito que posteriormente será transformado     *
     * Entrada[4] es una variable cadena (Aqui si me dejo) para almacenar     *
     * el numero que el usuario quiere usuario quiere tranasformar            *
     **************************************************************************/
     const char  Romanos[] = "MDCLXVI";
     char *Msg;  Msg = (char*) malloc(13 * sizeof(char));
     char  tmp;

    /******************************************************************************************************
     * variables de iteración, junto con una variable temporal para el digito a transformar               *
     * Con la variable Indice2 utiliza para almacenar los caracteres en Msg, Indice es usada por          *
     * las variables "fix" para determinar el digito Romano correspondiente al numero indicado en la      *
     * iteracion actual, la variable Contador, se usa en el bucle más externo al contrario que            *
     * ContadorDos, que es usada solo en los bucles internos y al salir de ellos es de nuevo igualada a 0 *
     ******************************************************************************************************/
     int  Contador , ContadorDos , Numero , Indice , Indice2 , Longitud , prefix , fix , sufix;
          Contador = ContadorDos = Numero = Indice = Indice2 = Longitud = prefix = fix = sufix = 0;

    Numero = atoi(Entrada);
    Longitud = strlen(Entrada);

    if((Numero <= 3000) && (Numero != 0) ){
   /*****************************************************************************************************
    * Aquí comienza el recorrido cifra por cifra del numero que ingreso el usuario                      *
    * Esta operacion es escencial para calcular correctamente digito dentro del array Romanos           *
    * tmp es un digito unico que posterior mente es transformado por atoi para se almacenado en Numero  *
    *****************************************************************************************************/
          while(Contador < Longitud){
              Indice = (4 - (Longitud - Contador)) * 2;
              tmp = Entrada[Contador];
              Numero = atoi(&tmp);
                      if(Numero < 5){
                          fix = Indice;
                          if( Indice > 0)prefix = Indice - 1;
                                if(Numero != 4){ /* Aquí se escriben los digitos diferentes de la forma 4x10^n  */
                                        while (ContadorDos < Numero){
                                                Msg[Indice2] = Romanos[fix]; ++Indice2;
                                            ++ContadorDos;
                                          }ContadorDos = 0 ;
                                }else{/* Aquí se escriben los digitos de la forma 4x10^n  */
                                    Msg[Indice2] = Romanos[fix];     Indice2 +=1;
                                    Msg[Indice2] = Romanos[prefix];  Indice2 +=1;
                                }/* Fin IF */
                      }else{
                        prefix = Indice;
                           fix = Indice - 1;
                         sufix = Indice - 2;
                                if(Numero == 5){ /* Aquí se escriben los digitos de la forma 5x10^n  */
                                      Msg[Indice2] = Romanos[fix]; Indice2 +=1;
                                }else if(Numero == 9){ /* Aquí se escriben los digitos de la forma 9x10^n  */
                                      Msg[Indice2] = Romanos[prefix]; Indice2 +=1;
                                      Msg[Indice2] = Romanos[sufix];  Indice2 +=1;
                                }else{ /*Numeros entre los tipos 5x10^n y 9x10^n, correspondientes a la iteracion*/
                                      Msg[Indice2] = Romanos[fix]; Indice2 +=1;
                                          while ( ContadorDos < (Numero - 5) ){
                                                  Msg[Indice2] = Romanos[prefix]; Indice2 += 1;
                                              ++ContadorDos;
                                            }ContadorDos = 0;
                                }/* Fin IF */
                      }/* Fin IF */
                ++Contador; /*Con Contador recorremos la cadena Romanos*/
                ContadorDos = 0;
          }//Fin while
        Msg[Indice2] = '\0';
    printf("\n\tEn Romano es: %s\n", Msg);
    }else{ printf("El numero debe ser mayor que uno y menos que tres mill\n"); }/* Fin IF */
return 0;
}//Fin Romanos

#endif //Fin ROMANOS_H
