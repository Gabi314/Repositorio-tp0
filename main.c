#include "scanner.c"
#include <stdlib.h>

int main(void)
{
	
	FILE * f=fopen("Entrada.txt","rb");
	int reg=cantidadRegistros(f);
	int desde,hasta;
	fseek(f, 0, SEEK_SET);
	char cadena[reg];
	fread(cadena,sizeof(cadena),1,f);
	fseek(f, 0, SEEK_SET);
	int puntero=0;
	
	
    TOKEN tipo_token;
    printf("-------------------\n");
    do
    {  
    	desde=puntero;
        tipo_token = get_token(&puntero);
		hasta=puntero;              
        switch(tipo_token)
        {
            case CAD:
            printf("Cadena: ");  
			while(desde<hasta){
			printf("%c",cadena[desde]);
			desde++;
			}
			printf("\n"); 
            break;
            
            case SEP:
            printf("Separador: \n");
            while(desde<hasta){
			printf("%c",cadena[desde]);
			desde++;
			}	
			printf("\n"); 
            break;
            
            case FDT:
            printf("Fin De Texto: \n");
            while(desde<hasta){
			printf("%c", cadena[desde]);
			desde++;
			}
			printf("\n"); 
            break;
            
            }
    } while(tipo_token != FDT);
 
 
 return 0;   
}
    
