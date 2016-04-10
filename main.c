/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kryshedz
 *
 * Created on 9 de abril de 2016, 19:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
// prototipo funciones
void vaciarBuffer();
void limpiarPantalla();
int validar(char cadena[3]);
void menu();
void ingresoPlabra();
void ingresoClave();
void cifrar();
void decifrar();
// variables globales
char palabra[50];
char clave[50];


void vaciarBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
void limpiarPantalla(){
    printf("\n Presione 'Enter' para continuar... ");
    while ( getchar() != '\n');
	system("clear");
}
int validar(char cadena[3]){
	int a,numCadena,cont=0;
	for(a=0;a<strlen(cadena);a++){
		numCadena=cadena[a];
		if(numCadena>=48 && numCadena<=57){
			cont+=1;
		}
	}
	if(cont==strlen(cadena)){
		return 0;
	}
	else{
		return 1;
	}
}
void menu(){
    setlocale(LC_CTYPE, "Spanish");
    printf("              Cifrado de Vigenére\n");
    printf("1.- Cifrar palabra\n");
    printf("2.- Decifrar palabra\n");
    printf("3.- Salir\n");
    printf("Ingrese una opción ");
    
}
void ingresoPlabra(){
    fgets(palabra,50,stdin);
    if ( palabra[strlen(palabra)-1]=='\n' )
        palabra[strlen(palabra)-1]='\0';
    else
        vaciarBuffer();

}
void ingresoClave(){
    fgets(clave,50,stdin);
    if ( clave[strlen(clave)-1]=='\n' )
        clave[strlen(clave)-1]='\0';
    else
        vaciarBuffer();
}

void cifrar(){
    int index;
    int tamanioClave=0;
    int numLetraCifrada;
    for (index = 0; index < strlen(palabra); index++) {
        if(tamanioClave==strlen(clave)){
            tamanioClave=0;
        }
        numLetraCifrada=clave[tamanioClave] - palabra[index];
        if(numLetraCifrada<0){
            numLetraCifrada=(clave[tamanioClave]-97)+(122-palabra[index])+1;
        }
        
        if(numLetraCifrada==0){
            numLetraCifrada=26;
        }
        tamanioClave++;
        
        if(numLetraCifrada>9){
            printf("%d",numLetraCifrada);  
        }else{
            printf("0%d",numLetraCifrada);
        }
    }
}
void decifrar(){
    int index;
    int indexCifrado=0;
    int indexClave=0;
    char letraDecifrada;
    
    for (index = 0; index < strlen(palabra)/2; index++) {
        char letra[2];
        letra[0]=palabra[indexCifrado];indexCifrado++;
        letra[1]=palabra[indexCifrado];indexCifrado++;
        if(indexClave==strlen(clave)){
            indexClave=0;
        }
        int numLetra=clave[indexClave]-atoi(letra);
        if(numLetra<97){
            letraDecifrada=122 - ( (atoi(letra)- (clave[indexClave]-96) ) );
        }else{
            letraDecifrada=numLetra;
        }
        indexClave++;
        printf("%c",letraDecifrada);       
    }
}
int main() {
    char opcionChar[3];
    int validacion=0;
    int opcion;
    
    while(validacion!=1){
        menu();
        scanf("%s",opcionChar);
        vaciarBuffer();
        switch(validar(opcionChar)){
            case 0:
                opcion=atoi(opcionChar);
                if(opcion==1){
                    printf("Ingrese su palabra: ");
                    ingresoPlabra();
                    printf("Ingrese su clave: ");
                    ingresoClave();
                    printf("\n\n      mensaje cifrado: ");cifrar();printf("\n\n");
                    limpiarPantalla();
                }if(opcion==2){
                    printf("Ingrese el codigo cifrado: ");
                    ingresoPlabra();   
                    printf("Ingrese su clave: ");
                    ingresoClave();
                    printf("\n\n      mensaje cifrado: ");decifrar();printf("\n\n");
                    limpiarPantalla();
                }if(opcion==3){
                    validacion=1;
                }if(opcion>3 || opcion<1){
                    printf("ingrese una opción valida");
                    limpiarPantalla();
                }
                break;
            default:
                printf("usted a ingresado letras en opción\n");
                limpiarPantalla();
                break;
        }    
    }
    return (0);
}