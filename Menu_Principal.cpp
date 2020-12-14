#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int menuPrincipal();

main()
{
	int opc=0;
		do{
		opc = menuPrincipal();
		switch(opc){
			case 1:
			{
				system("CLS");
				system("PAUSE");
				break;
			} 
			case 2:
			{
				system("CLS");
				system("PAUSE");
				break;
			}
			case 3:
			{
				system("CLS");
				system("PAUSE");
				break;
			}
			case 4:
			{
				system("CLS");
				system("PAUSE");
				break;
			}
				
				
			default:	
				system("PAUSE");
		}
	}while(opc != 5);
	
}

/*------------------------------------*/
int menuPrincipal(){
	int op;
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t|------------------------------------------------------|");
	printf("\n\n\t\t|          		V E T E R I N A R I A		           |");
	printf("\n\n\t\t|------------------------------------------------------|");
	printf("\n\n\t\t|     1 - Consultorio					               |");
	printf("\n\n\t\t|     2 - Recepcion									   |");
	printf("\n\n\t\t|     3 - Administracion						       |");
	printf("\n\n\t\t|     4 - Salir						                   |");
	printf("\n\n\t\t|------------------------------------------------------|");
	printf("\n\n\t\t     Seleccione una Opcion: "); 
	scanf("%d", &op);
	return op;
}
