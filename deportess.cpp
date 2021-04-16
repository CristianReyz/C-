//Reyes Albarrán Cristian Deusdedit
//Michelle Gomez Alvarez

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

using namespace std;
int const arrayNombre = 30;
int const arrayDomicilio = 50;
int const arrayCodigo = 7;
int const arrayCategoria = 20;
int const arrayRango = 10;
int const arrayOpcion = 1;
int const arrayEdad = 2;
int cantidad = 0;
const int edadMinima = 13;
const int edadMaxima = 35;
const int tamanioCodigoDeporte = 6;
struct Deporte{
	int clave;
	char nombre[arrayNombre];
	char categoria[arrayCategoria];
	char rango[arrayRango];
};

struct Alumno{
	char codigo [arrayCodigo];
	char nombre[arrayNombre];
	int edad;
	float estatura;
	float peso;
	char domicilio[arrayDomicilio];
	int deporte;
};

//funciones para ordenar
void cambiar(Alumno *alumno, int i, int j);

Alumno z;

//vector donde se guardará el código fragmentado de la clave de deporte para analizarlo y validarlo
int sliceSportCode[3];	

	//FUNCIONES PARA ORDENAR REGISTROS POR CÓDIGO Y ALMACENARLOS EN UN NUEVO ARCHIVO ORDENADO
//contar registros del archivo para ordenar
int contarRegistros(FILE *archivo){
	int i=0;
	archivo = fopen("deportes.bin", "rb");
	if(archivo == NULL){
		cout<<"Error al abrir el archivo...";
	}else{
		while(!feof(archivo)){
			fread(&z, sizeof(z), 1, archivo);
			i++;
		}
	}
	fclose(archivo);
	return (i-1);
}

//burbuja
void bubbleSort(Alumno *vectorAlumno, int tamanio, int z){

	for(int i=0; i<tamanio; i++){
		for(int j=0; j<tamanio-1; j++){
			if(z==0){
				if(strcmp(vectorAlumno[j].codigo, vectorAlumno[j+1].codigo)>0){
					cambiar(vectorAlumno, i, j);
				}
			}else{
				if((strcmp(vectorAlumno[j].codigo, vectorAlumno[j+1].codigo)>0)&&(vectorAlumno[j].codigo==vectorAlumno[j+1].codigo)){
					cambiar(vectorAlumno, i, j);
				}
			}	
		}
	}
}

//swap de todos los elementos del registro
void cambiar(Alumno *alumno, int i, int j){
	Alumno auxiliar;
	strcpy(auxiliar.codigo, alumno[j].codigo);
	strcpy(auxiliar.nombre, alumno[j].nombre);
	auxiliar.edad = alumno[j].edad;
	auxiliar.estatura = alumno[j].estatura;
	auxiliar.peso = alumno[j].peso;
	strcpy(auxiliar.domicilio,alumno[j].domicilio);
	auxiliar.deporte = alumno[j].deporte;
	
	strcpy(alumno[j].codigo, alumno[j+1].codigo);
	strcpy(alumno[j].nombre, alumno[j+1].nombre);
	alumno[j].edad = alumno[j+1].edad;
	alumno[j].estatura = alumno[j+1].estatura;
	alumno[j].peso = alumno[j+1].peso;
	strcpy(alumno[j].domicilio, alumno[j+1].domicilio);
	alumno[j].deporte = alumno[j+1].deporte;
	
	strcpy(alumno[j+1].codigo, auxiliar.codigo);
	strcpy(alumno[j+1].nombre, auxiliar.nombre);
	alumno[j+1].edad = auxiliar.edad;
	alumno[j+1].estatura = auxiliar.estatura;
	alumno[j+1].peso = auxiliar.peso;
	strcpy(alumno[j+1].domicilio, auxiliar.domicilio);
	alumno[j+1].deporte = auxiliar.deporte;
}

//preparando vector de registros
void ordenarRegistros(FILE *a, int n){
	Alumno vector[n];
	a = fopen("deportes.bin", "rb");
	if(a == NULL){
		perror("ERROR");
	}else{
		int i=0;
		fread(&z, sizeof(z), 1, a);
		while(!feof(a)){
			//colocando los registros en el vector de objetos
			strcpy(vector[i].codigo, z.codigo);
			strcpy(vector[i].nombre, z.nombre);
			vector[i].edad = z.edad;
			vector[i].estatura = z.estatura;
			vector[i].peso = z.peso;
			strcpy(vector[i].domicilio, z.domicilio);
			vector[i].deporte = z.deporte;
			fread(&z, sizeof(z), 1, a);
			i++;
		}
	}
	fclose(a);
	bubbleSort(vector, n, 0);
	bubbleSort(vector, n, 1);
	FILE *b =fopen("nuevo.bin", "wb");
	if(b==NULL){
		cout<<"ERROR AL CREAR EL ARCHIVO...";
	}else{
		for(int i=0; i<n; i++){
			//con este simple condicional se eliminan los espacios vacíos físicamente al no escribirlos en el nuevo archivo
			if(strlen(vector[i].codigo)>1){
				fwrite(&vector[i], sizeof(vector[i]), 1, b);	
			}
		}
	}
	fclose(b);
}

//preparar todo para ordenar
void ordenarArchivo(){
	FILE *archivo;
	int size = contarRegistros(archivo);
	ordenarRegistros(archivo,size);
}

									
									
												//FUNCIONES PARA VALIDAR REGISTROS DE ALUMNOS

//Validar opción del menú principal
int validarOpcion(char opcionSinValidar[arrayOpcion]){
	if(strlen(opcionSinValidar)!= arrayOpcion){
    	cout<<"error, la opcion debe tener una longitud de "<<arrayOpcion<<endl; getch();
    	return -1;
	}
	if(isdigit(opcionSinValidar[0]) == 0){
		cout<<"Opcion invalida, debes ingresar digitos."<<endl; getch();
		return -1;
	}
	return atoi(opcionSinValidar);
	
	
}


//todas las validaciones para el código de alumno estan aqui
int validarCodigoAlumno(char codigoAlumno[arrayCodigo]){
	if(isdigit(codigoAlumno[0]) != 0){
		cout<<"El primer caracter del codigo debe ser una letra"<<endl; getch();
		return -1;
	}else if(isdigit(codigoAlumno[1])!= 0){
		cout<<"El segundo caracter del codigo debe ser una letra"<<endl; getch();
		return -1;	
	}else if(isdigit(codigoAlumno[2]) == 0){
		cout<<"Error, el tercer caracter debe ser un digito"<<endl;	 getch();
		return -1;
	}else if(isdigit(codigoAlumno[3]) == 0){
		cout<<"Error, el cuarto caracter debe ser un digito"<<endl;	 getch();
		return -1;
	}else if(isdigit(codigoAlumno[4]) == 0){
		cout<<"Error, el quinto caracter debe ser un digito"<<endl;	 getch();
		return -1;
	}else if(isdigit(codigoAlumno[5]) != 0){
		cout<<"El sexto caracter del codigo debe ser una letra"<<endl; getch();
		return -1;
	}//else if(codigoAlumno[5] != 'M' || codigoAlumno[5] != 'F'){
	//	cout<<"Error, ingresa el genero del alumno en la ultima posicion "<<codigoAlumno[5]<<endl;
	//	return -1;
	//}
	else{
		return 1;
		
	}
}


//validar el rango de edad en cada categoria (falta optimizar o armar para rango o categoria, está solamente de forma general)
int validarEdad(char edad[arrayEdad]){
	if(isdigit(edad[0]) == 0 || isdigit(edad[1] == 0)){
		cout<<"La edad debe ser entero positivo"<<endl;
		return -1;
	}else if(atoi(edad) < edadMinima){
		cout<<"Solo se pueden inscribir a partir de los "<<edadMinima<<" años"<<endl;
		return -1;
	}else if(atoi(edad) > edadMaxima){
		cout<<"Solo se pueden inscribir hasta los "<<edadMaxima<<" años"<<endl;
		return -1;
	}else{
		return atoi(edad);
	}
}

								
								
								
								
												//FUNCIONES PARA DESPLEGAR REGISTROS DE UNA FORMA MAS ESTÉTICA
//Funcion para escribir en una posicion especifica
void coordenadas(int x, int y)
{
	 HANDLE hcon;
	 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD dwPos;
	 dwPos.X = x;
	 dwPos.Y = y;
	 SetConsoleCursorPosition(hcon,dwPos);
}

//Funcion para pintar Lineas y separar los registros al mostrarlos
void pintar(int a){
	int i=1;
	switch(a){
		case 1:
			printf("\n%c", 204);
		break;
		case 0:
			printf("%c", 201);
		break;
		default:
			printf("%c", 200);
		break;	
	}
	while(i<150){
		if(i%15==0){
			if(a == 1){
				printf("%c", 206);
			}else if(a==0){
				printf("%c", 203);
			}else{
				printf("%c", 202);
			}
		}else{
			printf("%c", 205);
		}
		i++;
	}
	if(a == 1){
		printf("%c\n", 185);
	}else if(a==0){
		printf("%c\n", 187);
	}else{
		printf("%c\n", 188);
	}
}

//Funcion que pinta la descripcion de los campos del registro
void pintarCampos(){
	pintar(0);
	printf("%cCODIGO\t       %cNOMBRE\t      %cEDAD\t     %cESTATURA\t    %cPESO\t   %cDOMICILIO     %cDEPORTE ID\t %cDEPORTE\t%cCATEGORIA     %cRANGO         %c", 186, 186, 186, 186, 186, 186, 186,186,186, 186, 186);
	pintar(1);
	fflush(stdin);
}

//Funcion que escribe un registro del archivo en Consola 
void escribirRegistros(Alumno alumno, int r){
	fflush(stdin);
	coordenadas(0, r);
    printf("%c", 186);
	coordenadas(1, r);
    printf("%s", alumno.codigo);
    coordenadas(15, r);
    printf("%c", 186);
    coordenadas(16, r);
    printf("%s", alumno.nombre);
    coordenadas(30,r);
    printf("%c", 186);
    coordenadas(31, r);
    printf("%i", alumno.edad);
    coordenadas(45, r);
    printf("%c", 186);
    coordenadas(46, r);
    printf("%.2f", alumno.estatura);
    coordenadas(60, r);
    printf("%c", 186);
    coordenadas(61, r);
    printf("%.2f", alumno.peso);
    coordenadas(75, r);
    printf("%c", 186);
    coordenadas(76, r);
   	printf("%s", alumno.domicilio);
    coordenadas(90, r);
    printf("%c", 186);
    coordenadas(91, r);
    printf("%i", alumno.deporte);
    coordenadas(105, r);
    printf("%c", 186);
    pintar(1);
}

//continuar con getch
void continuar(){
    printf("Presione una tecla para continuar\n\n");
    getch();
}




					//FUNCIONES PARA OPERAR ARCHIVO SECUENCIAL DESORDENADO

//crear archivo secuencial desordenado
void crear(){
    FILE *archivo;
    archivo=fopen("deportes.bin","wb");
    if (archivo==NULL)
        exit(1);
    fclose(archivo);
    continuar();
}


//insertar en archivo secuencial desordenado
void insertar(){
    FILE *archivo;
    char codigoSinValidar[arrayCodigo];
    int banderaError = 0;
	char edadSinValidar[arrayEdad];
    archivo=fopen("deportes.bin","ab");
    if (archivo==NULL)
        exit(1);
    Alumno nuevoAlumno;
    do{
    	fflush(stdin);
		cout<<"CLAVE: "; 	
		//se convierte de una vez a mayusculas el código sin validar para reducir el número de comparaciones sea como fuere que el usuario ingrese los datos
		cin.getline(codigoSinValidar,arrayCodigo);	fflush(stdin);	strupr(codigoSinValidar);
		//validando que de primera el codigo sin validar tenga la longitud correcta, de no ser así, se sale del ciclo y regresa sin guardar	
		if(strlen(codigoSinValidar) != arrayCodigo-1){
			cout<<"la longitud del codigo debe ser de "<<arrayCodigo-1<<endl;  getch();  fflush(stdin); system("cls"); banderaError = 1; break;
		//validando la opcion en cada una de sus posiciones en la función que valída 	
		}else if(validarCodigoAlumno(codigoSinValidar) == -1){
			cout<<"Error de validacion"<<endl; banderaError = 1; break;
		//en caso de pasar todas las pruebas se guarda	
		}else{
			fflush(stdin);	
			strcpy(nuevoAlumno.codigo,codigoSinValidar);
		}		
		fflush(stdin);
		cout<<"NOMBRE: ";	cin.getline(nuevoAlumno.nombre,arrayNombre);	fflush(stdin);		strupr(nuevoAlumno.nombre);
		fflush(stdin);
		cout<<"EDAD: ";		scanf("%s", &edadSinValidar); 
		if(strlen(edadSinValidar) < arrayEdad){
			cout<<"Edad invalida"<<endl; banderaError = 1; break;
		}else if(validarEdad(edadSinValidar) == -1){
			banderaError  = 1; break;	
		}else{
			nuevoAlumno.edad = validarEdad(edadSinValidar);
		}
		cout<<"ESTATURA: ";	scanf("%f",&nuevoAlumno.estatura);
		cout<<"PESO: ";		scanf("%f",&nuevoAlumno.peso);
		fflush(stdin);
		cout<<"DOMICILIO: ";	cin.getline(nuevoAlumno.domicilio,arrayDomicilio); fflush(stdin);		strupr(nuevoAlumno.domicilio);
		fflush(stdin);
		//break porque si no se repite infinitamente jaja
		cout<<"ID DEPORTE: ";	scanf("%i",&nuevoAlumno.deporte);	break;
		fflush(stdin);
	}while(banderaError != 1);
	//en caso de que no se haya pasado alguna prueba, no se guarda el registro en el archivo
	//sin esta validación el registro se guarda con espacios vacíos
	if(banderaError != 1){
	    fwrite(&nuevoAlumno, sizeof(nuevoAlumno), 1, archivo);
    	fclose(archivo);	
	}
    continuar();
}


//consulta general de archivo secuencial desordenado
void consultaGeneral(){
    FILE *archivo;
    archivo=fopen("deportes.bin","rb");
    if (archivo==NULL)
        exit(1);
	int r = 3;
    Alumno alumno;
    fread(&alumno, sizeof(alumno), 1, archivo);
    pintarCampos();
    while(!feof(archivo))
    {
    	escribirRegistros(alumno,r);
    	r+=2;
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    	coordenadas(0, r-1);
		pintar(2);
    fclose(archivo);
    continuar();
}

//consultar por codigo en archivo secuencial desordenado
void consultarID(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportes.bin","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a consultar:");
    char codigo[arrayCodigo];
    fflush(stdin);
    cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
            pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}

//modificar por codigo en archivo secuencial desordenado
void modificar(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportes.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    char codigo[arrayCodigo]; fflush(stdin);	cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
        	pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
          	cout<<"Ingresa nuevo nombre: "<<endl; fflush(stdin); cin.getline(alumno.nombre,arrayNombre); fflush(stdin); strupr(alumno.nombre);
          	fflush(stdin);
          	cout<<"Ingresa nueva edad: "<<endl; fflush(stdin); cin>>alumno.edad;
          	cout<<"Ingresa nueva estatura: "<<endl; fflush(stdin); cin>>alumno.estatura;
          	cout<<"Ingresa nuevo peso: "<<endl; fflush(stdin); cin>>alumno.peso;
          	fflush(stdin);
          	cout<<"Ingresa nuevo domicilio: "<<endl; fflush(stdin); cin.getline(alumno.domicilio,arrayDomicilio); fflush(stdin); strupr(alumno.domicilio);
          	fflush(stdin);
          	cout<<"Ingresa nuevo id del deporte: "<<endl; fflush(stdin); cin>>alumno.deporte;
        	int posicion=ftell(archivo)-sizeof(alumno);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&alumno, sizeof(alumno), 1, archivo);
           	printf("Se modifico el nombre del alumno.\n");
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}

void eliminar(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportes.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    char codigo[arrayCodigo]; fflush(stdin);	cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
        	int opcion;
        	pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
	    	cout<<"eliminando alumno..."<<endl;
	    	getch();	    	
			strcpy(alumno.codigo,"");
           	strcpy(alumno.nombre,"");
           	alumno.edad = 0;
           	alumno.estatura = 0.0;
           	alumno.peso = 0.0;
           	strcpy(alumno.domicilio,"");
           	alumno.deporte = 0;
           	
           	int posicion=ftell(archivo)-sizeof(alumno);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&alumno, sizeof(alumno), 1, archivo);
           	printf("Se elimino el alumno.\n");
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}



					//FUNCIONES PARA OPERACIONES DEL ARCHIVO DE DEPORTES
//Funcion para descomponer clave de deporte								
void descomponerSportCode(int numero){
        sliceSportCode[0] = numero%10;  //último dígito(femenil(1), varonil(2)
        numero /=10;
		sliceSportCode[1] = numero%10000; //segundo digito (rango de edad)
		numero /=10000;
		sliceSportCode[2] = numero; //primer digito (idDeporte)
}					
			
//validando que el tamaño sea el correcto					
int validarCodigoDeporte(int codigoDeporte){
	
 	if(codigoDeporte/100000 < 1 || codigoDeporte/100000 > 9){ 	//validando que el int sea de 6 dígitos, esto jugando con divisiones como son 6 digitos al dividirlos entre cienmil el resultado debe estar entre el
		cout<<"El codigo del deporte debe tener 6 digitos"<<endl; //1-9 (checa en la calculadora chavo jaja) 
		cout<<"SINTAXIS: ID_DEPORTE(1-9)-RANGO(JUVENTIL [1317], PROFESIONAL [1835])-CATEGORIA(FEMENIL[1],VARONIL[2]) "<<endl;
		return -1;
	}else{
		return 1;
	}
}	
			
//Funcion para pintar Lineas y separar los registros al mostrarlos
void pintarTablaDeporte(int a){
	int i=1;
	switch(a){
		case 1:
			printf("\n%c", 204);
		break;
		case 0:
			printf("%c", 201);
		break;
		default:
			//printf("%c", 200);
		break;	
	}
	while(i<60){
		if(i%15==0){
			if(a == 1){
				printf("%c", 206);
			}else if(a==0){
				printf("%c", 203);
			}else{
				printf("%c", 202);
			}
		}else{
			printf("%c", 205);
		}
		i++;
	}
	if(a == 1){
		printf("%c\n", 185);
	}else if(a==0){
		printf("%c\n", 187);
	}else{
		printf("%c\n", 188);
	}
}


//Funcion que pinta la descripcion de los campos del registro
void pintarCamposDeporte(){
	pintarTablaDeporte(0);
	printf("%cCLAVE\t       %cNOMBRE\t      %cCATEGORIA     %cRANGO\t    %c",186, 186, 186, 186,186);
	pintarTablaDeporte(1);
	fflush(stdin);
}


//Funcion que escribe un registro del archivo en Consola 
void escribirRegistrosDeporte(Deporte deporte, int r){
	fflush(stdin);
	coordenadas(0, r);
    printf("%c", 186);
	coordenadas(1, r);
    printf("%i", deporte.clave);
    coordenadas(15, r);
    printf("%c", 186);
    coordenadas(16, r);
    printf("%s", deporte.nombre);
    coordenadas(30,r);
    printf("%c", 186);
    coordenadas(31, r);
    printf("%s", deporte.categoria);
    coordenadas(45, r);
    printf("%c", 186);
    coordenadas(46, r);
    printf("%s", deporte.rango);
    coordenadas(60, r);
    printf("%c", 186);
    coordenadas(61, r);
    pintarTablaDeporte(1);
}


void crearDeporte(){
    FILE *archivo;
    archivo=fopen("deportesRegistros.bin","wb");
    if (archivo==NULL)
        exit(1);
    fclose(archivo);
    continuar();
}

void insertarDeporte()
{
    FILE *archivo;
    int banderaError = 0;
    int claveSinValidar;
    archivo=fopen("deportesRegistros.bin","ab");
    if (archivo==NULL)
        exit(1);
	Deporte nuevoDeporte;    
    do{
    	fflush(stdin);
		cout<<"CLAVE: /t  SINTAXIS [ID,RANGO_EDAD(13-17 JUVENIL, 18-35 PROFESIONAL),CATEGORIA(1 FEMENIL, 2 VARONIL)]"<<endl; 	
		cin>>claveSinValidar; descomponerSportCode(claveSinValidar);
		if(validarCodigoDeporte(claveSinValidar) == -1){
			system("cls");	banderaError = 1; break;
		}else {
			if(sliceSportCode[0] == 1){
				    	fflush(stdin);
				strcpy(nuevoDeporte.categoria,"FEMENIL");
				cout<<"CATEGORIA: FEMENIL"<<endl;
				if(sliceSportCode[1] == 1317){
					    	fflush(stdin);
					strcpy(nuevoDeporte.rango,"JUVENIL");
					cout<<"RANGO: JUVENIL"<<endl;
				}else if(sliceSportCode[1] == 1835){
					    	fflush(stdin);
					strcpy(nuevoDeporte.rango,"PROFESIONAL");
					cout<<"RANGO: PROFESIONAL"<<endl;
				}else{
					banderaError = 1;
					cout<<"Error en la asignacion del rango de edad, revisa la sintaxis"<<endl; break;
				}
			}else if(sliceSportCode[0] == 2){
				    	fflush(stdin);
				strcpy(nuevoDeporte.categoria,"VARONIL");
				cout<<"categoria: VARONIL"<<endl;
				if(sliceSportCode[1] == 1317){
					    	fflush(stdin);
					strcpy(nuevoDeporte.rango,"JUVENIL");
					cout<<"RANGO: JUVENIL"<<endl;
				}else if(sliceSportCode[1] == 1835){
					    	fflush(stdin);
					strcpy(nuevoDeporte.rango,"PROFESIONAL");
					cout<<"RANGO: PROFESIONAL"<<endl;
				}else{
					banderaError = 1;
					cout<<"Error en la asignacion del rango de edad, revisa la sintaxis"<<endl; break;
				}
			}else{
				banderaError = 1;
				cout<<"Error en la asignacion del ultimo digito, revisa la sintaxis"<<endl; break;
			}
			nuevoDeporte.clave = claveSinValidar;
		}
		fflush(stdin);
		cout<<"NOMBRE: ";	cin.getline(nuevoDeporte.nombre,arrayNombre);	fflush(stdin);		strupr(nuevoDeporte.nombre);
		fflush(stdin);
		//break porque si no se repite infinitamente jaja
		break;
		fflush(stdin);
	}while(banderaError != 1);
	//en caso de que no se haya pasado alguna prueba, no se guarda el registro en el archivo
	//sin esta validación el registro se guarda con espacios vacíos
	if(banderaError != 1){
	    fwrite(&nuevoDeporte, sizeof(nuevoDeporte), 1, archivo);
    	fclose(archivo);	
	}
    continuar(); 
}

void consultaGeneralDeporte()
{
    FILE *archivo;
    archivo=fopen("deportesRegistros.bin","rb");
    if (archivo==NULL)
        exit(1);
	int r = 3;
    Deporte deporte;
    fread(&deporte, sizeof(deporte), 1, archivo);
    pintarCamposDeporte();
    while(!feof(archivo))
    {
    	escribirRegistrosDeporte(deporte,r);
    	r+=2;
        fread(&deporte, sizeof(deporte), 1, archivo);
    }
    coordenadas(0, r-1);
	pintar(2);
    fclose(archivo);
    continuar();
}

void consultarIDDeporte(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportesRegistros.bin","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo de deporte a consultar:");
    int codigo;
    fflush(stdin);
    cin>>codigo;
    system("cls");
    Deporte deporte;
    int existe=0;
    fread(&deporte, sizeof(deporte), 1, archivo);
    while(!feof(archivo))
    {
        if (codigo == deporte.clave)
        {
            pintarCamposDeporte();
            escribirRegistrosDeporte(deporte,r);
    		r+=2;
           	existe=1;
           	break;
        }
        fread(&deporte, sizeof(deporte), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un deporte con dicho codigo\n");
    fclose(archivo);
    continuar();
}

void modificarDeporte(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportesRegistros.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    int codigo; cin>>codigo;
    system("cls");
    Deporte deporte;
    int existe=0;
    fread(&deporte, sizeof(deporte), 1, archivo);
    while(!feof(archivo))
    {
        if (codigo==deporte.clave)
        {
        	pintarCamposDeporte();
            escribirRegistrosDeporte(deporte,r);
    		r+=2;
          	cout<<"Ingresa nuevo nombre: "<<endl; fflush(stdin); cin.getline(deporte.nombre,arrayNombre); fflush(stdin); strupr(deporte.nombre);
        	int posicion=ftell(archivo)-sizeof(deporte);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&deporte, sizeof(deporte), 1, archivo);
           	printf("Se modifico el nombre del deporte.\n");
           	existe=1;
           	break;
        }
        fread(&deporte, sizeof(deporte), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un deporte con dicho codigo\n");
    fclose(archivo);
    continuar();
}


void menuDeportes(){
    int opcion;
    do {
    	system("cls");
        printf("1 - Crear un archivo binario llamado \"deportesRegistrados.bin\"\n");
        printf("2 - Insertar nuevo deporte\n");
        printf("3 - Consulta general.\n");
        printf("4 - Consulta de un deporte por su codigo.\n");
        printf("5 - Modificar el nombre de un deporte. \n");
        printf("6 - Regresar\n\n");
        printf("Ingrese su opcion:");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:crearDeporte();
                   break;
            case 2:system("cls");insertarDeporte();
                   break;
            case 3:system("cls");consultaGeneralDeporte();
                   break;
            case 4:system("cls");consultarIDDeporte();
                   break;
            case 5:system("cls");modificarDeporte();
                   break;
       
			case 6:system("cls");
					break;			
        }
    } while (opcion!=7);
}





												//OPERACIONES ARCHIVO ORDENADO


//insertar en archivo secuencial desordenado
void insertarAlumnoEnOrdenado(){
    FILE *archivo;
    char codigoSinValidar[arrayCodigo];
    int banderaError = 0;
	char edadSinValidar[arrayEdad];
    archivo=fopen("nuevo.bin","ab");
    if (archivo==NULL)
        exit(1);
    Alumno nuevoAlumno;
    do{
    	fflush(stdin);
		cout<<"CLAVE: "; 	
		//se convierte de una vez a mayusculas el código sin validar para reducir el número de comparaciones sea como fuere que el usuario ingrese los datos
		cin.getline(codigoSinValidar,arrayCodigo);	fflush(stdin);	strupr(codigoSinValidar);
		//validando que de primera el codigo sin validar tenga la longitud correcta, de no ser así, se sale del ciclo y regresa sin guardar	
		if(strlen(codigoSinValidar) != arrayCodigo-1){
			cout<<"la longitud del codigo debe ser de "<<arrayCodigo-1<<endl;  getch();  fflush(stdin); system("cls"); banderaError = 1; break;
		//validando la opcion en cada una de sus posiciones en la función que valída 	
		}else if(validarCodigoAlumno(codigoSinValidar) == -1){
			cout<<"Error de validacion"<<endl; banderaError = 1; break;
		//en caso de pasar todas las pruebas se guarda	
		}else{
			fflush(stdin);	
			strcpy(nuevoAlumno.codigo,codigoSinValidar);
		}		
		fflush(stdin);
		cout<<"NOMBRE: ";	cin.getline(nuevoAlumno.nombre,arrayNombre);	fflush(stdin);		strupr(nuevoAlumno.nombre);
		fflush(stdin);
		cout<<"EDAD: ";		scanf("%s", &edadSinValidar); 
		if(strlen(edadSinValidar) < arrayEdad){
			cout<<"Edad invalida"<<endl; banderaError = 1; break;
		}else if(validarEdad(edadSinValidar) == -1){
			banderaError  = 1; break;	
		}else{
			nuevoAlumno.edad = validarEdad(edadSinValidar);
		}
		cout<<"ESTATURA: ";	scanf("%f",&nuevoAlumno.estatura);
		cout<<"PESO: ";		scanf("%f",&nuevoAlumno.peso);
		fflush(stdin);
		cout<<"DOMICILIO: ";	cin.getline(nuevoAlumno.domicilio,arrayDomicilio); fflush(stdin);		strupr(nuevoAlumno.domicilio);
		fflush(stdin);
		//break porque si no se repite infinitamente jaja
		cout<<"ID DEPORTE: ";	scanf("%i",&nuevoAlumno.deporte);	break;
		fflush(stdin);
	}while(banderaError != 1);
	//en caso de que no se haya pasado alguna prueba, no se guarda el registro en el archivo
	//sin esta validación el registro se guarda con espacios vacíos
	if(banderaError != 1){
	    fwrite(&nuevoAlumno, sizeof(nuevoAlumno), 1, archivo);
    	fclose(archivo);	
	}
    continuar();
}


//consulta general de archivo secuencial desordenado
void consultaGeneralEnOrdenado(){
    FILE *archivo;
    archivo=fopen("nuevo.bin","rb");
    if (archivo==NULL)
        exit(1);
	int r = 3;
    Alumno alumno;
    fread(&alumno, sizeof(alumno), 1, archivo);
    pintarCampos();
    while(!feof(archivo))
    {
    	escribirRegistros(alumno,r);
    	r+=2;
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    	coordenadas(0, r-1);
		pintar(2);
    fclose(archivo);
    continuar();
}

//consultar por codigo en archivo secuencial desordenado
void consultarIDEnOrdenado(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("nuevo.bin","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a consultar:");
    char codigo[arrayCodigo];
    fflush(stdin);
    cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
            pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}

//modificar por codigo en archivo secuencial desordenado
void modificarEnOrdenado(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("nuevo.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    char codigo[arrayCodigo]; fflush(stdin);	cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
        	pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
          	cout<<"Ingresa nuevo nombre: "<<endl; fflush(stdin); cin.getline(alumno.nombre,arrayNombre); fflush(stdin); strupr(alumno.nombre);
          	fflush(stdin);
          	cout<<"Ingresa nueva edad: "<<endl; fflush(stdin); cin>>alumno.edad;
          	cout<<"Ingresa nueva estatura: "<<endl; fflush(stdin); cin>>alumno.estatura;
          	cout<<"Ingresa nuevo peso: "<<endl; fflush(stdin); cin>>alumno.peso;
          	fflush(stdin);
          	cout<<"Ingresa nuevo domicilio: "<<endl; fflush(stdin); cin.getline(alumno.domicilio,arrayDomicilio); fflush(stdin); strupr(alumno.domicilio);
          	fflush(stdin);
          	cout<<"Ingresa nuevo id del deporte: "<<endl; fflush(stdin); cin>>alumno.deporte;
        	int posicion=ftell(archivo)-sizeof(alumno);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&alumno, sizeof(alumno), 1, archivo);
           	printf("Se modifico el nombre del alumno.\n");
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
}

void menuOrdenacion(){
	int opcion;
    do {
    	system("cls");
    	printf("-----------ARCHIVO ORDENADO-------------\n");
        printf("1 - Ordenar (Se creara nuevo archivo)\n");
        printf("2 - Insertar nuevo alumno\n");
        printf("3 - Consulta general.\n");
        printf("4 - Consulta de un alumno por su codigo.\n");
        printf("5 - Modificar el nombre de un alumno. \n");
        printf("6 - Regresar\n\n");
        printf("Ingrese su opcion:");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:ordenarArchivo();	
                   break;
            case 2:system("cls");insertarAlumnoEnOrdenado();
                   break;
            case 3:system("cls");consultaGeneralEnOrdenado();
                   break;
            case 4:system("cls");consultarIDEnOrdenado();
                   break;
            case 5:system("cls");modificarEnOrdenado();
                   break;
			case 6:system("cls");
					break;			
        }
    } while (opcion!=6);
}
	









	//FUNCIONES PARA OPERAR ARCHIVO DIRECTO

//crear archivo directo
void crearDirecto(){
    FILE *archivo;
    archivo=fopen("deportesDirecto.bin","wb");
    if (archivo==NULL)
        exit(1);
    fclose(archivo);
    continuar();
}


//insertar en archivo secuencial desordenado
void insertarDirecto(){
    FILE *archivo;
    char codigoSinValidar[arrayCodigo];
    int banderaError = 0;
	char edadSinValidar[arrayEdad];
    archivo=fopen("deportesDirecto.bin","ab");
    if (archivo==NULL)
        exit(1);
    Alumno nuevoAlumno;
    do{
    	fflush(stdin);
		cout<<"CLAVE: "; 	
		//se convierte de una vez a mayusculas el código sin validar para reducir el número de comparaciones sea como fuere que el usuario ingrese los datos
		cin.getline(codigoSinValidar,arrayCodigo);	fflush(stdin);	strupr(codigoSinValidar);
		//validando que de primera el codigo sin validar tenga la longitud correcta, de no ser así, se sale del ciclo y regresa sin guardar	
		if(strlen(codigoSinValidar) != arrayCodigo-1){
			cout<<"la longitud del codigo debe ser de "<<arrayCodigo-1<<endl;  getch();  fflush(stdin); system("cls"); banderaError = 1; break;
		//validando la opcion en cada una de sus posiciones en la función que valída 	
		}else if(validarCodigoAlumno(codigoSinValidar) == -1){
			cout<<"Error de validacion"<<endl; banderaError = 1; break;
		//en caso de pasar todas las pruebas se guarda	
		}else{
			fflush(stdin);	
			strcpy(nuevoAlumno.codigo,codigoSinValidar);
		}		
		fflush(stdin);
		cout<<"NOMBRE: ";	cin.getline(nuevoAlumno.nombre,arrayNombre);	fflush(stdin);		strupr(nuevoAlumno.nombre);
		fflush(stdin);
		cout<<"EDAD: ";		scanf("%s", &edadSinValidar); 
		if(strlen(edadSinValidar) < arrayEdad){
			cout<<"Edad invalida"<<endl; banderaError = 1; break;
		}else if(validarEdad(edadSinValidar) == -1){
			banderaError  = 1; break;	
		}else{
			nuevoAlumno.edad = validarEdad(edadSinValidar);
		}
		cout<<"ESTATURA: ";	scanf("%f",&nuevoAlumno.estatura);
		cout<<"PESO: ";		scanf("%f",&nuevoAlumno.peso);
		fflush(stdin);
		cout<<"DOMICILIO: ";	cin.getline(nuevoAlumno.domicilio,arrayDomicilio); fflush(stdin);		strupr(nuevoAlumno.domicilio);
		fflush(stdin);
		//break porque si no se repite infinitamente jaja
		cout<<"ID DEPORTE: ";	scanf("%i",&nuevoAlumno.deporte);	break;
		fflush(stdin);
	}while(banderaError != 1);
	//en caso de que no se haya pasado alguna prueba, no se guarda el registro en el archivo
	//sin esta validación el registro se guarda con espacios vacíos
	if(banderaError != 1){
	    fwrite(&nuevoAlumno, sizeof(nuevoAlumno), 1, archivo);
    	fclose(archivo);	
	}
    continuar();
}


//consulta general de archivo secuencial desordenado
void consultaGeneralDirecto(){
    FILE *archivo;
    archivo=fopen("deportesDirecto.bin","rb");
    if (archivo==NULL)
        exit(1);
	int r = 3;
    Alumno alumno;
    fread(&alumno, sizeof(alumno), 1, archivo);
    pintarCampos();
    while(!feof(archivo))
    {
    	escribirRegistros(alumno,r);
    	r+=2;
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    	coordenadas(0, r-1);
		pintar(2);
    fclose(archivo);
    continuar();
}

//consultar por codigo en archivo secuencial desordenado
void consultarIDDirecto(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportesDirecto.bin","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a consultar:");
    char codigo[arrayCodigo];
    fflush(stdin);
    cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
            pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}

//modificar por codigo en archivo secuencial desordenado
void modificarDirecto(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportesDirecto.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    char codigo[arrayCodigo]; fflush(stdin);	cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
        	pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
          	cout<<"Ingresa nuevo nombre: "<<endl; fflush(stdin); cin.getline(alumno.nombre,arrayNombre); fflush(stdin); strupr(alumno.nombre);
          	fflush(stdin);
          	cout<<"Ingresa nueva edad: "<<endl; fflush(stdin); cin>>alumno.edad;
          	cout<<"Ingresa nueva estatura: "<<endl; fflush(stdin); cin>>alumno.estatura;
          	cout<<"Ingresa nuevo peso: "<<endl; fflush(stdin); cin>>alumno.peso;
          	fflush(stdin);
          	cout<<"Ingresa nuevo domicilio: "<<endl; fflush(stdin); cin.getline(alumno.domicilio,arrayDomicilio); fflush(stdin); strupr(alumno.domicilio);
          	fflush(stdin);
          	cout<<"Ingresa nuevo id del deporte: "<<endl; fflush(stdin); cin>>alumno.deporte;
        	int posicion=ftell(archivo)-sizeof(alumno);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&alumno, sizeof(alumno), 1, archivo);
           	printf("Se modifico el nombre del alumno.\n");
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}

void eliminarDirecto(){
	int r = 3;
    FILE *archivo;
    archivo=fopen("deportesDirecto.bin","r+b");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el codigo del alumno a modificar:");
    char codigo[arrayCodigo]; fflush(stdin);	cin.getline(codigo,arrayCodigo); fflush(stdin); strupr(codigo);
    system("cls");
    Alumno alumno;
    int existe=0;
    fread(&alumno, sizeof(alumno), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(codigo,alumno.codigo)==0)
        {
        	int opcion;
        	pintarCampos();
            escribirRegistros(alumno,r);
    		r+=2;
	    	cout<<"eliminando alumno..."<<endl;
	    	getch();	    	
			strcpy(alumno.codigo,"");
           	strcpy(alumno.nombre,"");
           	alumno.edad = 0;
           	alumno.estatura = 0.0;
           	alumno.peso = 0.0;
           	strcpy(alumno.domicilio,"");
           	alumno.deporte = 0;
           	
           	int posicion=ftell(archivo)-sizeof(alumno);
           	fseek(archivo,posicion,SEEK_SET);
           	fwrite(&alumno, sizeof(alumno), 1, archivo);
           	printf("Se elimino el alumno.\n");
           	existe=1;
           	break;
        }
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
    if(existe == 1){
    	coordenadas(0, r-1);
		pintar(2);	
	}
    if (existe==0)
        printf("No existe un alumno con dicho codigo\n");
    fclose(archivo);
    continuar();
}



void menuDirecto(){
	int opcionValidada;
    char opcionSinValidar[arrayOpcion];
    do {
    	system("cls");
    	cout<<" \t \t \t MENU DE ARCHIVO DIRECTO"<<endl;
        printf("1 - Crear un archivo binario llamado \"deportesDirecto.bin\"\n");
        printf("2 - Insertar nuevo alumno\n");
        printf("3 - Consulta general.\n");
        printf("4 - Consulta de un alumno por su codigo.\n");
        printf("5 - Modificar el nombre de un alumno. \n");
        printf("6 - Eliminar logicamente alumno por codigo. \n");
        printf("7 - Ordenar \n");
        printf("8 - Administrar deportes\n");
        printf("9 - Salir \n\n");
        printf("Ingrese su opcion:");
        scanf("%s",&opcionSinValidar);
        //validando opcion
        opcionValidada = validarOpcion(opcionSinValidar);
        //según valor de la opción ya validada, hacer:
        switch (opcionValidada) {
            case 1:crearDirecto();
                   break;
            case 2:system("cls");insertarDirecto();
                   break;
            case 3:system("cls");consultaGeneralDirecto();
                   break;
            case 4:system("cls");consultarIDDirecto();
                   break;
            case 5:system("cls");modificarDirecto();
                   break;
            case 6:system("cls");eliminarDirecto();
					break;       		
			case 7:system("cls"); menuOrdenacionDirecto();
					break;
			case 8:system("cls"); menuDeportes();
					break;	
			case 9:system("cls"); continuar();
					break;			
			case -1: cout<<"error de validacion"<<endl;	
					break;	
			default: cout<<"ingresa una opcion valida"<<endl;
					break;	
        }
    } while (opcionValidada!=9 && opcionValidada!=-1);
}



void menuArchivoDesordenado(){
	 int opcionValidada;
    char opcionSinValidar[arrayOpcion];
    do {
    	system("cls");
        printf("1 - Crear un archivo binario llamado \"deportes.bin\"\n");
        printf("2 - Insertar nuevo alumno\n");
        printf("3 - Consulta general.\n");
        printf("4 - Consulta de un alumno por su codigo.\n");
        printf("5 - Modificar el nombre de un alumno. \n");
        printf("6 - Eliminar logicamente alumno por codigo. \n");
        printf("7 - Ordenar \n");
        printf("8 - Administrar deportes\n");
        printf("9 - Salir \n\n");
        printf("Ingrese su opcion:");
        scanf("%s",&opcionSinValidar);
        //validando opcion
        opcionValidada = validarOpcion(opcionSinValidar);
        //según valor de la opción ya validada, hacer:
        switch (opcionValidada) {
            case 1:crear();
                   break;
            case 2:system("cls");insertar();
                   break;
            case 3:system("cls");consultaGeneral();
                   break;
            case 4:system("cls");consultarID();
                   break;
            case 5:system("cls");modificar();
                   break;
            case 6:system("cls");eliminar();
					break;       		
			case 7:system("cls"); menuOrdenacion();
					break;
			case 8:system("cls"); menuDeportes();
					break;	
			case 9:system("cls"); continuar();
					break;			
			case -1: cout<<"error de validacion"<<endl;	
					break;	
			default: cout<<"ingresa una opcion valida"<<endl;
					break;	
        }
    } while (opcionValidada!=9 && opcionValidada!=-1);
}






void menuPrincipal(){
	int opcion;
	do{
		cout<<"1.- Menu de archivo secuencial-ordenado"<<endl;
		cout<<"2.- Menu de archivo directo"<<endl;
		switch(opcion){
			case 1:
				menuArchivoDesordenado();
				break;
			case 2:
				menuDirecto();
				break;
			case 3:
				break;
			default: cout<<"Ingresa una opcion valida"<<endl; break;			
		}
	}while(opcion != 3);
}										
										
												//MAIN
int main()
{
	menuPrincipal();
    return 0;
}


