#include<iostream>
#include<conio.h>
#include<wchar.h>
#include<locale.h>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include <string.h>
#include <algorithm>
#include <cstring>

using namespace std;

//declaracion de funciones
int Factroial(int);
int MCD(int, int);
int Fibo(int);
int Pas(int, int);
void Ha(int, char, char, char);
void heapSort(int[], int);
void maxHeapify(int[], int, int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void shell(int[], int);
void Quicksort(int [],int,int);
void MuestraArreglo(int,int []);


void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

struct vertice {
       char nod;
       int marca;
       struct vertice *sig;
       struct arco *arc;
};

struct arco {
       struct vertice *ver;
       int marca;
       int suma;
       int clave;
       struct arco *sig;
};


struct vertice *pri, *nue, *aux, *ult, *aux2;
struct arco *nueArc, *auxArc, *arcMen, *auxArc2, *antArc;
char auxNod, auxNod2, ban2, let;
int ban, enlace, ban3, ban4, numVer;

void actualizarCampos();
void crearVertice();
void enlazarVertices();
void enlazar();
void listarAdyacencia();
void obtenerArcoMenor();
void listarAdyacenciaPrim ();
void sumaCaminos();

void crearVertice () {
     system ("cls");
     if (pri == NULL){
        pri = new vertice;
        cout << "El Grafo no tiene vertices\nDigite la letra del Primer Nodo: ";
        cin >> pri->nod;
        pri->marca = 0;
        pri->arc = NULL;
        pri->sig = NULL;
        ult = pri;
        cout << "\nNodo registrado correctamente.";
     }
     else {
          cout << "Digite la letra del vertice: ";
          cin >> let;
          do {
              aux = pri;
              ban = 0;
              while (aux != NULL){
                    if (aux->nod == let){
                          ban = 1;
                    }
                    aux = aux->sig;
              }
              if (ban == 1) {
                     cout << "\n ya utilizaste esto, igual que las siguientes:\n";
                     aux = pri;
                     while (aux != NULL) {
                           cout << aux->nod << " ";
                           aux = aux->sig;
                     }
                     cout << "\n Ingresa una letra diferente: ";
                     cin >> let;
              }
          }while (ban == 1);
          nue = new vertice;
          nue->nod = let;
          nue->marca = 0;
          nue->sig = NULL;
          nue->arc = NULL;
          ult->sig = nue;
          ult = nue;
          cout << "\n se ha registrado correctamente.";

     }

     getch();
}

void enlazarVertices () {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              cout << aux->nod << "\n";
              aux = aux->sig;
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar: ";
        cin >> auxNod;
        ban = 0;
        while (ban == 0){
              aux = pri;
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 cout << "\n este nodo no existe\n digite un nodo de los listados anteriormente: ";
                 cin >> auxNod;
              }
        }
        cout << "\nNodos que dispones para realizar tu enlace\n";
        aux = pri;
        aux2 = pri;
        while (aux2->nod != auxNod){
              aux2 = aux2->sig;
        }
        while (aux != NULL){
              if (aux->nod != auxNod){
                  auxArc = aux2->arc;
                  ban4 = 0;
                  while (auxArc != NULL && ban4 == 0){
                        if (aux->nod == auxArc->ver->nod){
                           ban4 = 1;
                        }
                        auxArc = auxArc->sig;
                  }
                  if (ban4 == 0){
                     cout << aux->nod << "\n";
                  }
              }

              aux = aux->sig;
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar el nodo elegido: ";
        cin >> auxNod2;
        ban = 0;
        while (ban == 0){
              aux = pri;
              while (auxNod2 == auxNod){
                    cout << "\nNo se puede hacer ese enlace\nDigite otro nodo disponible: ";
                    cin >> auxNod2;
              }
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod2){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod2;
              }
        }
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        auxArc = aux->arc;
        ban3 = 0;
        while (auxArc != NULL && ban3 == 0){
              if (auxArc->ver->nod == auxNod2){
                 ban3 = 1;
              }
              auxArc = auxArc->sig;
        }
        if (ban3 == 0){
           enlazar();
           cout << "\nEnlace creado correctamente.";
        }
        else {
             cout << "\nEse enlace ya existe. Compruebe el enlace la proxima vez.";
        }
     }
}

void enlazar (){
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        aux2 = pri;
        while (aux2->nod != auxNod2){
              aux2 = aux2->sig;
        }
        if (aux->arc == NULL){
           nueArc = new arco;
           nueArc->ver = aux2;
           cout << "\nIntroduce el peso de tu arista de enlace: ";
           cin >> enlace;
           while (nueArc->clave < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor: ";
                 cin >> enlace;
           }
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           aux->arc = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
        else {
           nueArc = new arco;
           nueArc->ver = aux2;
           cout << "\nIntroduce el peso de tu arista de enlace: ";
           cin >> enlace;
           while (enlace < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 cin >> enlace;
           }
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           auxArc = aux->arc;
           while (auxArc->sig != NULL){
                 auxArc = auxArc->sig;
           }
           auxArc->sig = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
}

void obtenerArcoMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->clave < arcMen->clave){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
}

void obtenerSumaMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->suma < arcMen->suma){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
     auxArc = arcMen->ver->arc;
     while (auxArc != NULL){
           auxArc->suma = arcMen->suma + auxArc->clave;
           auxArc = auxArc->sig;
     }
}

void paso2 (){
            obtenerArcoMenor();
            cout << "\nEl arco menor es: "<< arcMen->ver->nod << " vale: " << arcMen->clave;
            getch();
            aux = arcMen->ver;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  if (auxArc->ver->marca == 0){
                         aux2 = pri;
                         while (aux2 != NULL){
                               if (aux2 != aux && aux2->marca == 1){
                                     auxArc2 = aux2->arc;
                                     while (auxArc2 != NULL){
                                           if (auxArc->ver->nod == auxArc2->ver->nod){
                                                  if (auxArc->clave < auxArc2->clave){
                                                         auxArc2->marca = 2;
                                                         auxArc->marca = 1;
                                                  }
                                                  else {
                                                       auxArc->marca = 2;
                                                       auxArc2->marca = 1;
                                                  }
                                           }
                                           auxArc2 = auxArc2->sig;
                                     }
                               }
                               aux2 = aux2->sig;
                         }
                         if (auxArc->marca == 0){
                                auxArc->marca = 1;
                         }
                  }
                  else {
                       auxArc->marca = 2;
                  }
                  auxArc = auxArc->sig;
            }
}


void paso2Dijkstra () {
            obtenerSumaMenor();
            cout << "\nLo obtenido hasta la arista " << arcMen->ver->nod << " es: "<< arcMen->suma;
            getch();
            aux = arcMen->ver;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  if (auxArc->ver->marca == 0){
                         aux2 = pri;
                         while (aux2 != NULL){
                               if (aux2 != aux && aux2->marca == 1){
                                     auxArc2 = aux2->arc;
                                     while (auxArc2 != NULL){
                                           if (auxArc->ver->nod == auxArc2->ver->nod){
                                                  if (auxArc->suma  < auxArc2->suma){
                                                         auxArc2->marca = 2;
                                                         auxArc->marca = 1;
                                                  }
                                                  else {
                                                       auxArc->marca = 2;
                                                       auxArc2->marca = 1;
                                                  }
                                           }
                                           auxArc2 = auxArc2->sig;
                                     }
                               }
                               aux2 = aux2->sig;
                         }
                         if (auxArc->marca == 0){
                                auxArc->marca = 1;
                                auxArc->suma = arcMen->suma + auxArc->clave;
                         }
                  }
                  else {
                       auxArc->marca = 2;
                  }
                  auxArc = auxArc->sig;
            }
}

void algoritmoPrim () {
     system("cls");
     if (pri != NULL){
            actualizarCampos();
            cout << "Digite el vertice inicial: ";
            cin >> auxNod;
            ban = 0;
            while (ban == 0){
                  aux = pri;
                  while (aux != NULL){
                        if (aux->nod == auxNod){
                               ban = 1;
                        }
                        aux = aux->sig;
                  }
                  if (ban == 0){
                         cout << "\nNo existe un nodo con esa letra.";
                         aux = pri;
                         cout << "\n---Lista de Nodos---\n";
                         while (aux != NULL){
                               cout << aux->nod << " ";
                               aux = aux->sig;
                         }
                         cout << "\nDigite uno de los anteriores nodos: ";
                         cin >> auxNod;
                  }
            }
            aux = pri;
            while (aux->nod != auxNod){
                  aux = aux->sig;
            }
            aux->marca = 1;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  auxArc->marca = 1;
                  auxArc = auxArc->sig;
            }
            cout << "\nSe han marcado todos los arcos para el vertice elegido.";
            ban2 = 1;
            while (ban2 == 1){
                  paso2();
                  ban2 = 0;
                  aux = pri;
                  while (aux != NULL){
                        if (aux->marca == 0){
                               ban2 = 1;
                        }
                        aux = aux->sig;
                  }
            }
            listarAdyacenciaPrim ();
            sumaCaminos();
     }
     getch();
}

void listarAdyacencia () {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        cout << "Lista de Los Nodos Y Sus Aristas\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n\n" << aux->nod << "->";
              while (auxArc != NULL){
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
        getch();
     }
}

void sumaCaminos () {
     aux = pri;
     int suma = 0;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 if (auxArc->marca == 3){
                        suma = suma + auxArc->clave;
                 }
                 auxArc = auxArc->sig;
           }
           aux = aux->sig;
     }
     cout << "\nLa suma de los caminos es: " << suma;
}

void listarAdyacenciaPrim () {
     if (pri != NULL){
        aux = pri;
        cout << "\n---Lista de Adyacencia---\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n|\n" << aux->nod << "->";
              while (auxArc != NULL){
                    if (auxArc->marca == 3)
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
     }
}

void algoritmoDijkstra () {
     system("cls");
     if (pri != NULL){
            actualizarCampos ();
            cout << "Digite el vertice inicial: ";
            cin >> auxNod;
            ban = 0;
            while (ban == 0){
                  aux = pri;
                  while (aux != NULL){
                        if (aux->nod == auxNod){
                               ban = 1;
                        }
                        aux = aux->sig;
                  }
                  if (ban == 0){
                         cout << "\nNo existe un nodo con esa letra.";
                         aux = pri;
                         cout << "\n---Lista de Nodos---\n";
                         while (aux != NULL){
                               cout << aux->nod << " ";
                               aux = aux->sig;
                         }
                         cout << "\nDigite uno de los anteriores nodos: ";
                         cin >> auxNod;
                  }
            }
            aux = pri;
            while (aux->nod != auxNod){
                  aux = aux->sig;
            }
            aux->marca = 1;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  auxArc->marca = 1;
                  auxArc->suma = auxArc->clave;
                  auxArc = auxArc->sig;
            }
            cout << "\narcos trazados correctamente";
            ban2 = 1;
            while (ban2 == 1){
                  paso2Dijkstra();
                  ban2 = 0;
                  aux = pri;
                  while (aux != NULL){
                        if (aux->marca == 0){
                               ban2 = 1;
                        }
                        aux = aux->sig;
                  }
            }
            listarAdyacenciaPrim ();
     }
     system("pause");
}

void actualizarCampos () {
     aux = pri;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 auxArc->marca = 0;
                 auxArc->suma = 0;
                 auxArc = auxArc->sig;
           }
           aux->marca = 0;
           aux = aux->sig;
     }
}


int m[102][102]={-1};  
struct busqueda{
	char color[15];
	int d;
	int padre;
};
struct busqueda bus[100];
struct nodo{
    int nro;
    struct nodo *sgte;
};
struct cola{
    nodo *delante;
    nodo *atras  ;
};
void encolar( struct cola &q, int valor ){
     struct nodo *aux = new(struct nodo);  
     aux->nro = valor;
     aux->sgte = NULL;
     if( q.delante == NULL)
         q.delante = aux;  
     else
         (q.atras)->sgte = aux;
     q.atras = aux;       
}
int desencolar( struct cola &q ){
     int num ;
     struct nodo *aux ;
     aux = q.delante;      
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          
     return num;
}
void bfs(int s,int n){
	struct cola q;
    q.delante = NULL;
    q.atras   = NULL;
    int u,cont=0;
	char white[]="white",gray[]="gray",black[]="black";
	for(int i=1;i<=n; i++){
		strcpy(bus[i].color,white);
		bus[i].d=cont;
		bus[i].padre=0;		
	}
	strcpy(bus[s].color,gray);
	bus[s].d=cont;
	bus[s].padre=0;
	encolar(q,s);
	while(q.delante!=NULL){
		u=desencolar( q );
		for(int i=1;i<=n;i++){
			if(m[u][i]==1){
				if(strcmp(bus[i].color,white)==0){
					strcpy(bus[i].color,gray);
					bus[i].d=cont;
					bus[i].padre=u;
					encolar(q,i);
					cont++;
				}
			}
			strcpy(bus[u].color,black);
		}
	}
	
}
void imprimir(int n,int s){
	cout<<"\t\tLos datos son: \n";
	for(int i=1; i<=n; i++){
		cout<<"Color "<<i<<" es: "<<bus[i].color<<"\n";
		cout<<"Distancia "<<i<<" es: "<<bus[i].d<<"\n";
		cout<<"Padre "<<i<<" es: "<<bus[i].padre<<"\n";
		cout<<"------------------------------\n";
	}
	cout<<"\t\tBFS es:\n";
	int j=0;
	cout<<s<<"\n";
	while(j!=n){
		for(int k=1; k<=n; k++){
			if(bus[k].d==j && k!=s){
				cout<<k<<"\n";
			}
		}
		j++;	
	}
}
int padre[40];

void Inicializacion (int n){
    for( int i = 1 ; i <= n ; ++i )
	padre[i] = i;
}

int Encontrar_Raiz(int x){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Encontrar_Raiz( padre[ x ] );
}

void Union( int x , int y ){
    padre[ Encontrar_Raiz( x ) ] = Encontrar_Raiz( y );
}
bool sameComponent( int x , int y ){
    if( Encontrar_Raiz( x ) == Encontrar_Raiz( y ) ) return true;
    return false;
}


int V , E;

struct Grafo{
    int origen;
    int destino;
    int peso;
    Grafo (){}

    bool operator<( const Grafo &e ) const {
        return peso < e.peso;
    }
}arista[ 40 ];
Grafo MST[ 40 ];

void Kruskal(){
    int origen , destino , peso;
    int total = 0;
    int noAristas = 0;

    Inicializacion ( V );
    std::sort( arista , arista + E );

    for( int i = 0 ; i < E ; ++i ){
        origen = arista[ i ].origen;
        destino = arista[ i ].destino;
        peso = arista[ i ].peso;

        if( !sameComponent( origen , destino ) ){
            total += peso;
            MST[ noAristas++ ] = arista[ i ];
            Union( origen , destino );
        }
    }

    if( V - 1 != noAristas ){
        puts("No existe arbol de recubrimiento minimo");
        return;
    }
    puts( "El arbol de recubrimiento minimo tiene los siguientes caminos");
    for( int i = 0 ; i < noAristas ; ++i )
        printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso );

    printf( "El peso  minimo es: %d\n" , total );
}





int main()
{
    int n, N, i, j, fa, a, b, mcd, aux, r, fi[n];
    char A,B,C;
     int V1[]={10,17,2,1,12,5,8,13,9,3,15,14,18,15,4,6,11};
     int V2[]={1,12,5,8,13,9,3,2,15,14,18,17,15,4,6,10,11};
     int V3[]={9,10,17,2,1,12,5,8,13,3,15,14,18,15,4,6,11};
     int V4[]={12,11,17,2,1,5,8,13,9,3,15,14,18,15,4,6,11};
     int V5[]={13,7,17,2,1,12,5,8,13,9,3,14,18,15,4,6,11};
     char Fig=178;
    int op;
    do{
        printf("                                         *Proyecto Programacion Avanzada*\n");
        printf("                                          by: Michelle de Maria Gomez Alvarez\n");

        printf("1.PRIMER PARCIAL \n2.SEGUNDO PARCIAL\n3.Salir\n");
        printf("Dame Opcion\n");
        scanf("%d", &op);

    switch(op){
    case 1:
    do{
        printf("1.Menu De Programas Iterativos\n2.Menu De Programas Recursivos\n3.Metodos De Ordenamiento\n4.Salir.\n");
        printf("Dame Opcion \n");
        scanf("%d", &op);

switch(op){
case 1:

    do{
    printf("Menu _Programas Iterativos_\n\n");

    printf("1.Factorial\n2.MCD\n3.Fibonacci\n4.T.Pascal\n5.Torres De Hanoi\n6.Salir\n\n");
    printf("Dame Opcion\n");
        scanf("%d", &op);
    if(op>6 || op<1){
    	printf("opcion no valida, por favor elige una opcion valida\n");
	}else
    switch(op){
    case 1:
    printf("Dame un numero: \n");
        scanf("%d", &N);
            if(N<0){
            fa=0;
            }else if(N==0)
            fa=1;
            else{

            for(i=1; i<=N; i++){
                fa=fa*i;
              }
            }
    printf("El factorial de tu numero de forma iterativa es: %d \n", fa );
    break;
    case 2:
    printf("Dame a \n");
        scanf("%d", &a);

    printf("Dame b \n");
        scanf("%d", &b);

        while(a<0 && b<0);
           mcd=a;
           aux=b;
        do{
           r=mcd%aux;
           mcd=aux;
           aux=r;
       }while(r!=0);

     printf("El maximo comum divisor de a,b de form2a iterativa es :  %d \n", mcd);
    break;
    case 3:
     printf("Ingrese el elemento: \n");
        scanf("%d", &n);

     fi[0]=0;
     fi[1]=1;
    printf("Fibonacci [0]:%d \n", fi[0]);
    printf("Fibonacci [1]:%d \n", fi[1]);

        for(i=2; i<=n; i++){
           fi[i]=fi[i-1]+fi[i-2];
           cout<<"Fibonacci ["<<i<<"]:"<<fi[i]<<endl;
       }
    break;
    case 4:
    int j, k, pasc[1000];

    printf("Cuantos niveles desea desplegar? \n");
        scanf("%d",&n);
    k=0;

   for(i=1; i<=n; i++){
      for (j=k; j>=0; j--){
         if(j==k || j==0){
            pasc[j]=1;
         }else{
            pasc[j]=pasc[j]+pasc[j-1];
        }
    }
   k++;
   printf("\n");
      for(j=1; j<=(n-i); j++)
         printf("   ");
        for(j=0; j<k; j++){
             printf("%3d ", pasc[j]);
        }
    }
    printf("\n");
    break;
    case 5:
    printf( "Cuantos discos son? " );
       scanf( "%d", &n );
    printf( "\n\n" );

     for (i=1; i < (1 << n); i++)
      printf( "Mueve desde la torre %i a la torre %i.\n",
		 (i&i-1)%3, ((i|i-1)+1)%3 );
    break;
    case 6:
        int main();
    break;
    }

  }while(op!=6);

break;
case 2:

  do{
    printf("Menu _Programas Recursivos_\n\n");

    printf("1.Factorial\n2.MCD\n3.Fibonacci\n4.T.Pascal\n5.Torres De Hanoi\n6.Salir\n\n");
    printf("Dame Opcion\n");
        scanf("%d", &op);
    if(op>6 || op<1){
    	printf("opcion no valida, por favor elige una opcion valida\n");
	}else
    switch(op){
    case 1:
        printf("Dame un numero: \n");
        scanf("%d", &N);

    printf("El factorial de tu numero de forma recursiva es: %d \n", Factroial(N));
    break;
    case 2:
    printf("Dame a \n");
        scanf("%d", &a);

    printf("Dame b \n");
        scanf("%d", &b);

    printf("El MCD de tus numeros a,b de forma recursiva es: %d \n", MCD(a, b));

    break;
    case 3:
     printf("Ingrese el valor de n: \n");
        scanf("%d", &n);

    printf("la serie de Fibonacci de tu numero de forma recursiva es: %d \n", Fibo(n));
    break;
    case 4:
        int i, j;
    printf("Dame i:\n");
      scanf("%d", &i);
    printf("Dame j:\n");
      scanf("%d", &j);

    printf("el resultado es: %d \n", Pas(i, j));

    break;
    case 5:
    printf("Las torres son A, B, C \n");
    printf("Numero de discos: ");
        scanf("%d", &n);
     Ha(n,'A','C','B');
    break;
    case 6:
       int main();
    break;
    }

    }while(op!=6);

break;
case 3:

      printf("se ordena por medio de burbuja: \n");

       for(int i=0;i<17;i++){
          for(int j=i+1;j<17;j++){
              if(V1[j]<V1[i]){
                aux=V1[i];
                V1[i]=V1[j];
                V1[j]=aux;
        }
      }
    }

	for(int x=0;x<17;x++){
		for(int y=40;y>40-V1[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V1[x]);
	}

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("el vector de numeros 2: \n");

for(int x=0;x<17;x++){
		for(int y=60;y>60-V2[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V2[x]);
	}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("se ordena por medio de Heap Sort: \n");

 heapSort(V2, 17);

for(int x=0;x<17;x++){
		for(int y=80;y>80-V2[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V2[x]);
	}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("el vector de numeros 3: \n");

for(int x=0;x<17;x++){
		for(int y=100;y>100-V3[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V3[x]);
	}


	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("se ordena por medio de Merge Sort: \n");

mergeSort(V3, 0, 16);
	for(int x=0;x<17;x++){
		for(int y=120;y>120-V3[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V3[x]);
	}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("el vector de numeros 4: \n\n\n\n");

for(int x=0;x<17;x++){
		for(int y=140;y>140-V4[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V4[x]);
	}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("se ordena por medio de SellSort: \n");

shell(V4, 17);

for(int x=0;x<17;x++){
		for(int y=160;y>160-V4[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V4[x]);
	}

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("el vector de numeros 5: \n");

for(int x=0;x<17;x++){
		for(int y=180;y>180-V5[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V5[x]);
	}
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("se ordena por medio de QuickSort: \n");
   Quicksort(V5,0,16);
   cout<<endl<<"Elementos en orden ascendente: "<<endl;
   MuestraArreglo(17,V5);
printf("\n\n\n\n\n\n");
   for(int x=0;x<17;x++){
		for(int y=207;y>207-V5[x];y--){
			gotoxy((x+1)*3,y);cout<<Fig;
		}
     printf("%d", V5[x]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
break;
case 4:
       int main();
break;
}
}while(op!=4);
    break;
    case 2:
    int op;
    do{
        printf("Menu SEGUNDO PARCIAL\n");
        printf("1.Primero En Anchura\n2.Kruskal\n3.Prim\n4.Dijkstra\n5.Salir\n");
        printf("Dame Opcion\n");
        scanf("%d", &op);
    switch(op){
    case 1:
       int n,num,i,x,y,s;
    cout << "Ingresa el numero de nodos que tiene el grafo: ";
    cin >> n;
    cout << "Ahora el numero de aristas: ";
    cin >> num;
    for(i=1;i<=num;i++){
        cout << "la arista "<<i<<" que conecta con los nodos, separados por un espacio \n";
        cin >> x >> y;
        m[x][y]=1;
        m[y][x]=1;
    }
    cout << "El nodo inicial es:";
    cin >> s;
    bfs(s,n);
    imprimir(n,s);
    return 0;
    break;
    case 2:

          int mst;
          	printf("\nIngresa el numero de vertices\n");
            scanf("%d" , &V  );
         printf("\nIngresa el numero de aristas\n");
         scanf("%d" , &E  );
  
       for( int i = 0 ; i < E ; ++i ){
    	   printf("Ingresa vertice de origen (%d):\n", i+1);
        	scanf("%d" , &arista[ i ].origen );
    	   printf("Ingresa vertice destino (%d):\n", i+1);
         	scanf("%d" , &arista[ i ].destino );
    	   printf("Ingresa peso de la arista (%d):\n", i+1);
         	scanf("%d" , &arista[ i ].peso );

       }
        Kruskal();

    return 0;      




    break;
    case 3:
       int op;
    do{
       printf("1.insertar un verice\n");
       printf("2.adjuntar verices\n");
       printf("3.mostrar la lista de los verices\n");
       printf("4.Utilizar algoritmo Prim\n");
       printf("5.salir\n");
     
       printf("\n Ingresa una Opcion:\n");
      scanf("%d", &op);
       while (op>7){
             printf("Opcion no valida, digite un numero del 1 al 7: ");
             scanf("%d", &op);
       }
       switch(op){
                  case 1: crearVertice();
				  break;
                  case 2: enlazarVertices(); 
				  getch(); 
				  break;
                  case 3: listarAdyacencia(); 
				  break;
                  case 4: algoritmoPrim(); 
				  break;
                  case 5: 
				  exit (0);
				  break;
       }
    }while(op<6);

    break;
    case 4:
    	 
    do{
       printf("1.insertar un verice\n");
       printf("2.adjuntar verices\n");
       printf("3.mostrar la lista de los verices\n");
       printf("4.Utilizar algoritmo Dijkstra\n");
       printf("5.salir\n");
     
       printf("\n Ingresa una Opcion:\n");
      scanf("%d", &op);
       while (op>7){
             printf("Opcion no valida, digite un numero del 1 al 7: ");
             scanf("%d", &op);
       }
       switch(op){
                  case 1: crearVertice();
				  break;
                  case 2: enlazarVertices(); 
				  getch(); 
				  break;
                  case 3: listarAdyacencia(); 
				  break;
                  case 4: algoritmoDijkstra(); 
				  break;
                  case 5: 
				      int main();
				  break;
       }
    }while(op<6);
    
    break;
    case 5:
        int main();
    break;
    }
}while(op!=5);
        
        
        
        
        
        
    break;
    case 3:
        return 0;
    break;
    }
}while(op!=3);
}






//Funciones.
void maxHeapify(int V[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && V[l] > V[largest]){
        largest = l;
    }
    if (r < n && V[r] > V[largest]){
        largest = r;
    }
    if (largest != i)
    {
        swap(V[i], V[largest]);
        maxHeapify(V, n, largest);
    }
}

void heapSort(int V[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        maxHeapify(V, n, i);
    }
    for (int i=n-1; i>=0; i--)
    {
        swap(V[0], V[i]);
        maxHeapify(V, i, 0);
    }
}

void merge(int V[], int l, int x, int r){
    int i, j, k;
    int n1 = x - l + 1;
    int n2 =  r - x;
    int L[n1], R[n2];
  for (i = 0; i < n1; i++)
        L[i] = V[l + i];
    for (j = 0; j < n2; j++)
         R[j] = V[x + 1+ j];
    i = 0;
    j = 0;
    k = l;
   while (i < n1 && j < n2){
        if (L[i] <= R[j]){
             V[k] = L[i];
               i++;
        }else{
             V[k] = R[j];
               j++;
        }
        k++;
    }
    while (i < n1){
            V[k] = L[i];
             i++;
        k++;
    }
    while (j < n2){
        V[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int V[], int l, int r){
    if (l < r){
        int x = l+(r-l)/2;
        mergeSort(V, l, x);
        mergeSort(V, x+1, r);
		merge(V, l, x, r);
    }
}

void shell(int array[], int size){
	int i, j, intervalo, temp;

	intervalo = size/2;
		while (intervalo > 0) {
			for (i=intervalo; i < size; i++) {
				j = i;
				temp = array[i];
					while ((j >= intervalo) && (array[j - intervalo] > temp)) {
						array[j] = array[j - intervalo];
						j = j - intervalo;
					}
				array[j] = temp;
            }
        intervalo /= 2;
        }
}

void Quicksort(int arreglo[],int primero, int ultimo){
int i, j, aux, pivote;
 i=primero;
 j=ultimo;
 pivote=arreglo[(primero+ultimo)/2];
 do {
     while(pivote>arreglo[i])
     i++;
     while(pivote<arreglo[j])
     j--;
     if(i<=j)
     { aux=arreglo[i];
     arreglo[i]=arreglo[j];
     arreglo[j]=aux;
      i++;
      j--;
        }
     }while(i<=j);
     if(primero<j)
       Quicksort(arreglo,primero,j);
     if(ultimo>i)
       Quicksort(arreglo,i,ultimo);
  }

void MuestraArreglo(int n, int array[]){
int i;
 for(i=0; i<n; i++)
     cout<<"["<<array[i]<<"]  ";
}

int Factroial(int N){
   if(N<0){
    return 0;
   }else if(N>1)
    return N*Factroial(N-1);
    return 1;
}

int MCD(int a, int b){
   if (b==0){
       return a;
   }
else
    return MCD(b, a%b);
}

int Fibo(int n){
   if(n<=1){
    return n;
   }else
    return Fibo(n-1)+Fibo(n-2);
}

int M[100][100];
int Pas(int i, int j){
    if(i==j || j==1){
     M[i][j]=1;
 } if(M[i][j]==0){
     M[i][j]=Pas(i-1, j)+Pas(i-1, j-1);
 }
 return M[i][j];
 }

void Ha(int num,char A,char C,char B){
    if(num==1){
    printf("Mueva desde la torre %c, Hasta La Torre %c \n", A , C);
    }
    else{
        Ha(num-1,A,B,C);
        printf("Mueva desde la torre %c, Hasta La Torre %c \n", A , C);
        Ha(num-1,B,C,A);
    }
}

