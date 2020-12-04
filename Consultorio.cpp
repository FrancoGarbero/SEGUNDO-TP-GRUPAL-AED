#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(bool &salir, bool &login);
void inicioSesion(bool &login,int copMatricula);
void listaEspera(int copMatricula);
void registrarEvolucion();
 

 
main()
{
	bool salir=false,login=false;

		
	printf("BIENVENIDO AL MODULO CONSULTORIO");
	printf("\n-----------------------------------");
	do
	{
		menu(salir,login);	
	}
	while(salir==false);
	
	printf("Adios popo");
	
}

void menu(bool &salir, bool &login)
{
	int seleccion;
	int copMatricula;//copia el numero de matrucula para comparar en turnos, asi no se tiene que recargar;
	do
	{
		printf("\n\n1.- Iniciar Sesion\n2.- Visualizar Lista de Espera de Turnos (informe)\n3.- Registrar Evolucion de la Mascota\n4.- Cerrar la aplicacion.\n\nIngrese una opcion: ");
		scanf("%d",&seleccion);
		
		switch(seleccion)
		{
			case 1:
				inicioSesion(login,copMatricula); 
				break;
				
			case 2:
				if (login==true)
				{
					listaEspera(copMatricula);	
				}
				else
				{
					printf("Error, necesita iniciar sesion para acceder a esta opcion\n");
					system("PAUSE");
				}
				break;
				
			case 3:
				if (login==true)
				{
					registrarEvolucion();	
				}
				else
				{
					printf("Error, necesita iniciar sesion para acceder a esta opcion\n");
					system("PAUSE");
				}
				break; 
				
			case 4:
				salir=true;
				break;
			
		}	
		system("CLS");		
	}
	while (salir==false);
	
}

void inicioSesion(bool &login,int copMatricula)
{
	char auxUsuario[20], auxContrasena[20];
	login=true; //borrar esto ma tarde	
	do{
		printf("\nUSUARIO: ");
		_flushall();
		gets(auxUsuario);
		_flushall();
	
		printf("\nCONTRASENA: ");
		gets(auxContrasena);
		_flushall();
		
		//comprobacion de usuario y contraseña que dara true o false en ingreso de sesion
		//
	}
	while(login==false);
	//aqui se realizara la copia de la matricula
	//se cierra
}

void listaEspera(int copMatricula)
{
	int contador=1; //para numerar turnos;
	printf("Aca van los turnos");
	//fopen ("turnos.dat","r");
	//fread espacio 1
	//while(!feof(mascotas.dat)
	{
		//if(MatriculadeVeterinario==copMatricula)
		{
			//printf("Turno %d\n=======",contador);
			//printf("Nombre
			//printf todos los datos\n
			//pasa al siguiente dato
				
		} 
		
				
	}
	//se carga el archivo y se muestra	
}

void registrarEvolucion()
{
	
	int auxDni;
	char auxEvolucion[380];
	//abre archivo de mascotas
	//leer
	//printf("DNI del dueño: ");//para identificar en que espacio del fichero se guardara la info, puedo usar dni o cualquier otro dato si es mas facil
	//scanf(auxDni)
	//while(!feof("turnos"))//seria turnos porque ahi se guardara la info de atencion segun el pdf
	{
		//if(auxDni==DniDelDueno)//comparara los datos si da dejara escribir en el archivo
		{
			//printear algo de info para confirmar de que mascota se trata
			
			printf("Evolucion de la mascota,(enter para finalizar");
			gets(auxEvolucion);
			//guardar en archivo
			
		}
		//fread pa pasar al siguiente dato
	}
	
	
}
