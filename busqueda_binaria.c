/*
David Barrios  davidbarrios@usal.es
Estructuras de datos
Algoritmo de busqueda binaria (**Para vectores ordenados**)


PSEUDOCODIGO

    MÓDULO busqueda_binaria
    DATOS
        PARÁMETROS
            Recibe V() de tipo T
            Recibe N entera
            Recibe X de tipo T
        VARIABLES
            I, IZQ, DER, CEN enteras
    INICIO
    IZQ ← 1
    DER ← N
    CEN ← (N+1)\2         ** división entera
        Mientras ( (V(CEN) ≠ X)   y   (IZQ < DER) ) hacer
            Si ( V(CEN) > X ) entonces
                DER ← CEN-1
            sino
                 IZQ ← CEN+1
            fin-si
            CEN ← (IZQ+DER)\2
        fin-mientras
        Si ( V(CEN) = X ) entonces
             Escribir "encontrado en la posición", CEN
        sino
            Escribir "no existe el valor buscado"
        fin-si
FIN

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// funcion que aplica la busqueda binaria a un array de enteros 
// Parametros: v -> es el vector ordenado x
void busqueda_binaria(int v[], int x, int n)
{	
    // Variables de la funcion
	int izq,der,centro;
	
    // Asignaciones de la funcion
	izq = 0;    // La mitad de la izq empieza en la posicion 0
	der = n-1;  // El extremo derecho esta en el valor N-1
	centro = (der+izq)/2;   // El centro del vector esta en la posicion n/2, al ser tipo entero no hay problema si el vector es de un numero impar

	// Mientras el valor no sea el valor buscado se repetira este bucle while 
	while(v[centro] != x && izq < der){
        //Si el valor es mayor que el buscado entonces reducimos el vector a la mitad N/2
		if(v[centro] > x){
			der = centro-1;
        }
		//si es menor que el buscado, el vector se reduce a la mitad derecha
		else{ 
			izq = centro+1;
        }
        //Al cambiar el vector debemos calcular de nuevo el centro del vector.
		centro = (izq+der)/2;
	}
	
	if(v[centro] == x){
        printf("\n EXITO!");
		printf("\n Encontrado el numero %d en la posicion %d.\n",x, centro);
    }
    else{
        printf("\n ERROR!");
		printf("\n No existe el valor %d.\n", x);
    }
}

void presentacion (){
    // Funcion para presentar el programa.
    printf("\n\t-------------------------------------------");
    printf("\n\t           BUSQUEDA BINARIA");
    printf("\n\tDavid Barrios  davidbarrios@usal.es");
    printf("\n\t-------------------------------------------\n\n\n");


}

void main()
{
    // Declaracion de las variables:
	int x, i, modo; // x:Variable que almacenara el numero a buscar
	


    presentacion();
    printf("\nEjecutar el programa en modo automatico? (Si=1 / No=0) \n");
    scanf("%d", &modo);

    if(modo==0){    // Ejecutamos el programa en modo manual, el usuario introduce los datos.
        int v[100]; // Array de enteros
        printf(" Introduzca el valor a buscar:   ");	//Pedimos que introduzca el valor a buscar
        scanf("%d", &x);	// lo guardamos en x
        
        getchar(); // Interceptamos el salto de linea. Si no hacemos esto dara fallo porque cogera el salto de linea y el vector introducido es de 0 elementos

	    char str[200];
	    printf(" Inserte el array de enteros ordendos separados por espacios: ");	
	    fgets(str, 200, stdin); // Con esto leemos los primeros 200 caracteres. Es decir 100 numeros ya que por cada numero hay un espacio como minimo.
	    char * pch;
        pch = strtok (str," ,"); // divide el char[] (str) si encuentra un espacio o una coma. retorna un puntero a la primera direccion
				 
        // Tratamos los datos.
	    int n_datos = 0;
	    for (n_datos = 0; pch != NULL; n_datos++){
	        v[n_datos] = atoi(pch);
	        pch = strtok (NULL, " ,");
	    }


        // Mostramos el vector
        printf("\n El vector introducido es:\n   ");
        for(i=0;i<n_datos;i++){
            printf("%d ", v[i]);
        }
        printf("\n");

	    /// Llamamos a la funcion de busqueda binaria con los datos introducidos.
	    busqueda_binaria(v, x, n_datos);
    }
if(modo==1){    // En este modo se cargan datos de forma automatica para evitar que el usuario lo haga de forma manual.
    int v[]={1,2,3,4,5,6,7,8,9,10};
    x=5;
    // Tratamos los datos.
	int n_datos = 10;
    // printf("\n ///   %ld",(sizeof(v)/4));

    // hacemos todo lo que nos pide el enunciado

    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    // Mostramos el vector
    // Esto podriamos hacerlo en una funcion para llamarla tambien desde el modo manual.
        printf("\n El vector introducido es:\n   ");
        for(i=0;i<n_datos;i++){
            printf("%d ", v[i]);
        }
        printf("\n");

    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");  // usamos esto para separar visulamente.
	printf("\n\n\n Buscamos el primero valor almacenado en el vector \n");
    x=1;    // cambiamos solo el valor y usamos el mismo vector. Podriamos tambien cambiar el vector y llamar a la funcion de mostrar vector.
    busqueda_binaria(v, x, n_datos);    // Llamamos a la funcion

    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\n\n Buscamos el ultimo valor almacenado en el vector \n");
    x=10;   // Cambiamos dato
    busqueda_binaria(v, x, n_datos);    // llamamos a la funcion
    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    printf("\n\n\n Buscamos un valor que forme parte del vector y sea distinto de los anteriores \n");
    x=4;    // cambiamos dato
    busqueda_binaria(v, x, n_datos);    // llamamos a la funcion
    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    printf("\n\n\n Buscamos un valor que no forma parte del vector \n");
    x=30;   // cambiamos dato por uno no valido
    busqueda_binaria(v, x, n_datos);    //llamamos a la funcion
    printf("\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

}
}


