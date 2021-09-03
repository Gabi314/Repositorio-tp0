#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdbool.h> 
#include <stdio.h>
#include <ctype.h>


//ACA VAN LAS DECLARACIONES


typedef enum {CAD,SEP,FDT} TOKEN; 
typedef enum{ESPACIO,COMA,FIN,OTROS}CARACTER; 

// Uno es para TT y el otro para caracteres individuales

bool salida();
int cambiar_estado(); 
TOKEN identificar_token();
TOKEN get_token(int *puntero);


#endif
