#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int menuPrincipal();
void gotoxy(int x,int y);
void cuadro(int x1, int y1, int x2, int y2);

main()
{
	system("color B0");
	
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
	
	cuadro(1,1,77,3);
	gotoxy (30,2);
	printf("V E T E R I N A R I A\n\n");
	printf("\n\n\t\t|     1 - Consultorio");
	printf("\n\n\t\t|     2 - Recepcion");
	printf("\n\n\t\t|     3 - Administracion");
	printf("\n\n\t\t|     4 - Salir");

	printf("\n\n\t\t     Seleccione una Opcion: "); 
	scanf("%d", &op);
	return op;
}

/*------------------------------------*/
void gotoxy(int x,int y)
{  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

/*------------------------------------*/
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
    for (i=x1;i<x2;i++)
	{	
		gotoxy(i,y1);printf("Ä") ; //linea horizontal superior 
		gotoxy(i,y2);printf("Ä") ; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++)
	{	
		gotoxy(x1,i);printf("³") ; //linea vertical izquierda
		gotoxy(x2,i);printf("³") ; //linea vertical derecha
    }
    
    gotoxy(x1,y1); printf("Ú"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("À");
    gotoxy(x2,y1); printf("¿");
    gotoxy(x2,y2); printf("Ù");
}
