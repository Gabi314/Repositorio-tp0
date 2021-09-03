#include "scanner.h"


int estado_vigente = 0;
char c;

const bool estados[5] =
{false,
false,
true,
true,
true};


int tabla_transicion[5][4] = 
{
    {0,   3,  4,  1},
    {2,   2,  2,  1},
    {99, 99, 99, 99},
    {99, 99, 99, 99},
    {99, 99, 99, 99},
  
};

bool salida()
{
    return estados[estado_vigente];
}


int cambiar_estado()
{
    if(isspace(c))
        return tabla_transicion[estado_vigente][ESPACIO];
    else if(c == ',')
        return tabla_transicion[estado_vigente][COMA];
    else if(c == EOF)
        return tabla_transicion[estado_vigente][FIN];
    	else
    	return tabla_transicion[estado_vigente][OTROS];
}

TOKEN identificar_token()
{

    switch(estado_vigente)
    {
    case 2: 
        ungetc(c,stdin); 
        return CAD;
    case 3:
        return SEP;
    case 4:
        return FDT;
    }
    return 0;
}

TOKEN get_token(int *puntero)
{
    TOKEN tk;

    while(!salida())
    {
        c = getchar();
        estado_vigente = cambiar_estado();
        if(estado_vigente!=0)
        (*puntero)++;
    }
    tk = identificar_token(); 
    estado_vigente = 0;
    return tk;
}

int cantidadRegistros( FILE * f){
char r;
fseek(f, 0, SEEK_END); 
return ftell(f)/sizeof(r);
}
