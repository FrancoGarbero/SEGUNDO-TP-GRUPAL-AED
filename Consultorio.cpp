#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(bool &salir, bool &login);
void inicioSesion(bool &login,int &copMatricula);
void listaEspera(int copMatricula);
void registrarEvolucion();
bool comprobacion(int auxUsuario,char auxContrasena[20]);
typedef char palabra[60];


struct fecha //FECHA, CON UNA SOLA BASTA :)
{
	int dia;
	int mes;
	int anio;
};

struct veterinario{ //INFO DE LOS VETERINARIOS
	char apynom[60];
	int matricula;
	int dni;
	int telefono;
	char contra[10];
};

struct registro1//STRUCT PARA TURNOS
{
	int Matricula;
	fecha fech;
	int dni;
	char Atencion[380];
};

struct registro//DATOS DE MASCOTA
{
	palabra ApeYNom;
	palabra Domicilio;
	int DNI;
	palabra Localidad;
	float Peso;
	int Telefono;
	fecha fec;
};


 
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
	int copMatricula=0;//copia el numero de matrucula para comparar en turnos, asi no se tiene que recargar;
	do
	{
		printf("\n\n1.- Iniciar Sesion\n2.- Visualizar Lista de Espera de Turnos (informe)\n3.- Registrar Evolucion de la Mascota\n4.- Cerrar la aplicacion.\n\nIngrese una opcion: ");
		scanf("%d",&seleccion);
		
		switch(seleccion)
		{
			case 1:
				system("CLS");
				inicioSesion(login,copMatricula); 
				break;
				
			case 2:
				if (login==true)
				{
					system("CLS");
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
					system("CLS");
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

void inicioSesion(bool &login,int &copMatricula)
{
	char auxContrasena[20];
	int auxUsuario; 
	login=false; //borrar esto ma tarde	
	do{
		printf("\nMATRICULA: ");
		_flushall();
		scanf("%d",&auxUsuario);
		_flushall();
	
		printf("\nCONTRASENA: ");
		gets(auxContrasena);
		_flushall();
		
		if(comprobacion(auxUsuario,auxContrasena)==true)
		{
			login=true;
			copMatricula=auxUsuario;//aqui se realizara la copia de la matricula
			break;
		}
		
		//comprobacion de usuario y contraseña que dara true o false en ingreso de sesion
		//
	}
	while(login==false);
	
	//se cierra
}

void listaEspera(int copMatricula)
{
	registro1 turno;
	registro mascota;
	int edad=0;
	
	FILE *T ,*M;//T por turno, M por mascota
	T=fopen("Turnos.dat","r");
	M=fopen("Mascotas.dat","r");

	int contador=1; //para numerar turnos, Puramente visual
	fread(&turno, sizeof(registro1), 1, T);
	fread(&mascota, sizeof(registro), 1, M);

	while(!feof(T))
	{
		if(turno.Matricula==copMatricula)
		{
			printf("Turno %d\n=========",contador);
			printf("\nFecha: %d|%d|%d", turno.fech.dia,turno.fech.mes,turno.fech.anio);
			printf("\nDNI: %d",turno.dni);
			if(turno.Atencion!=NULL)
			{
				printf("\nNotas anteriores: ");
				puts(turno.Atencion);	
			}
			else
			{
				printf("\nNo esxiten notas anteriores");	
			}
			while(!feof(M))
			{
				if(mascota.DNI==turno.dni)
				{
					edad=turno.fech.anio-mascota.fec.anio;
					if(turno.fech.mes>mascota.fec.mes)
					{
						edad=edad-1;
					}
					else if(turno.fech.mes==mascota.fec.mes)
					{
						if(turno.fech.dia>mascota.fec.dia)
						{
							edad=edad-1;
						}
					}
					
					printf("\nNombre de mascota: ");
					puts(mascota.ApeYNom);
					printf("Domicilio:");
					puts(mascota.Domicilio);
					printf("Localidad:");
					puts(mascota.Localidad);
					printf("Edad:%d",edad);
					printf("\nPeso: %.2f Kg",mascota.Peso);
					printf("\nTelefono: %d",mascota.Telefono);
					
					printf("\n\n");		
					system("PAUSE");	
				}
				fread(&mascota, sizeof(registro), 1, M);
			}
			
			rewind(M);
			//SI TENGO QUE MOSTRAR INFO DE LA MASCOTA AQUI, ABRO LA OTRA; COMPARO DNI; REWINDEO LA INFO DE MASCOTA DESPUES DE IMPRIMIRLA RE ABRO LA OTRA;
			
		} 
		
		fread(&turno, sizeof(registro1), 1, T);
		contador++;
					
	}
	fclose(M);
	fclose(T);
	system("PAUSE");
	//se carga el archivo y se muestra	
}

void registrarEvolucion()
{
	bool hit=false;//Se fija si encrontro la mascota, informa si no lo hizo;
	int auxDni;
	char auxEvolucion[380],auxNombre[60];
	registro mascota;
	registro1 turnos;
	FILE *M,*T;
	M=fopen("Mascotas.dat","r+b");
	T=fopen("Turnos.dat","r+b");
	

	printf("Buscar mascota: Nombre y apellido: ");
	_flushall();
	gets(auxNombre);
	
	rewind(M);
	rewind(T);
	
	fread(&mascota,sizeof (registro),1,M);
	fread(&turnos,sizeof (registro1),1,T);
	
	while(!feof(M) && hit==false)
	{
		if(strcmp(auxNombre,mascota.ApeYNom)==0)
		{
			while(!feof(T))
			{
				
				if(turnos.dni==mascota.DNI)
				{
					hit=true;
					printf("Evolucion de la mascota,(enter para finalizar): ");
					gets(auxEvolucion);
					strcpy(turnos.Atencion,auxEvolucion);
					printf("\nDiagnostico actualizado: ");
					puts(turnos.Atencion);
					fwrite(&turnos,sizeof (registro1),1,T);
					break;
				}
				fread(&turnos,sizeof (registro1),1,T);	
			}			
		}
		fread(&mascota,sizeof (registro),1,M);
	}
	/*if(hit==false);
	{
		printf("No se encrontro la mascotas");
		system("PAUSE");
	}*/
	system("PAUSE");
}

bool comprobacion(int auxUsuario,char auxContrasena[20])
{
	FILE *vet;
	bool inicio=false;
	veterinario regVet;
	vet=fopen("Veterinarios.dat","r+b");
	
	rewind(vet);
	fread(&regVet, sizeof(veterinario), 1, vet);

	if (vet==NULL)
	{
   		perror("No se puede abrir o no se registro ningun veterinario");
   		return -1;
	}
	while(!feof(vet))
	{
		
		printf("Matricula: %d", regVet.matricula);
		if(auxUsuario==regVet.matricula)
		{
			printf("\nEl usuario existe");
			//a continuacion se compararia la contrasena IMPORTANTEEEEE
			inicio=true;
			break;
		}
		fread(&regVet, sizeof(veterinario), 1, vet);	
	}
	
	if(inicio==true)
	{
		printf("\nSe inicio sesion correctamente, bienvenido: ");
		puts(regVet.apynom);
		fclose(vet);
		system("PAUSE");
		return(true);
	}
	else
	{
		printf("No se pudo iniciar sesion, pruebe nuevamente\n");
		fclose(vet);
		system("PAUSE");
		return(false);
	}
	
	system("PAUSE");
	//hace falta una forma de mantener registrado el veterinario, con el aux que guarda la matricula registrada o un bool login
}
