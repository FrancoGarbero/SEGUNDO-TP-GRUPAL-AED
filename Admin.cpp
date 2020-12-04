#include <stdio.h>
#include <stdlib.h>

int menuPrincipal();
void registroVet();
void registroAsist();
int atenciones();
int ranking();

main()
{
	int opc=0;
	
	do{
		opc= menuPrincipal();
		switch(opc){
			case 1:
				
				break;
			case 2:
			{
			
				break;
			}
			case 3:
			{
			
				break;
			}	
			case 4:
			{
	
				break;
			}
			
			default:
				system("PAUSE");	
		}
	}while(opc != 5);
	
}

int menuPrincipal()
{
	int op;
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t            Modulo  Administracion                    ");
	printf("\n\n\t\t======================================================");
	printf("\n\n\t\t     1. - Registrar Veterinario                       ");
	printf("\n\n\t\t     2. - Registrar Ususario Asistente                ");
	printf("\n\n\t\t     3. - Atenciones por Veterinarios                 ");
	printf("\n\n\t\t     4. - Ranking de Veterinarios por Atenciones      ");
	printf("\n\n");
	printf("\n\n\t\t     5. - Cerrar la aplicacion                        ");
	printf("\n\n\t\t     Ingrese una opcion: "); 
	scanf("%d", &op);
	return op;
}

void registroVet()
{
	
}

void registroAsist()
{
	
}

int atenciones()
{
	
}

int ranking()
{
	
}
