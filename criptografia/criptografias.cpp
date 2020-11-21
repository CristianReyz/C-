#include<conio.h>
#include<stdio.h>>
#include<iostream>
#include<string.h>
#include<windows.h>
#include<Math.h>

using namespace std;
char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void euclides_extendido(int a,int b, int *q1, int *q2, int *q3){
    int d,x,y,x1,x2,y1,y2,q,r;
    if(b==0){
        d=a;
        x=1;
        y=0;
        //return(d);
    }
    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while(b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}

int inverso(int n,int a){
	 int d,x,y,inver;
	 int *p1=&d;
	 int *p2=&x;
	 int *p3=&y;
     euclides_extendido(a,n,p1,p2,p3);
     if(d>1){
     	return 0;
     }
     else{
     	if(x<0){
     		inver=n+x;
     	}
     	else{
     		inver=x;
     	}
     }
     return(inver);
}

void cifrado_cesar(){
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=(j+3)%26;
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje cifrado es: "<<m<<endl<<endl;
}

void descifrado_cesar(){
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux;
					if((j-3)<0){
						aux=26+(j-3);
					}
					else{
						aux=(j-3)%26;
					}
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje descifrado es: "<<m<<endl<<endl;
}

void cifrado_afin(){
	cout<<"Cifrado afin C=a.P+b(mod n)"<<endl;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	int a,b;
	do{
	   cout<<"Ingrese el valor de a: ";
	   cin>>a;
   }while(a<0||inverso(26,a)==0);
	do{
      cout<<"Ingrese el valor de b: ";
      cin>>b;
   }while(b<0||b>25);
   
   	
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=((a*j)+b)%26;
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje cifrado es: "<<m<<endl<<endl;
}

void descifrado_afin(){
	cout<<"Descifrado afin P=a-1.(C-b)(mod n)"<<endl;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	int a,b;
	do{
		cout<<"Ingrese el valor de a: ";
		cin>>a;	
	}while(inverso(26,a)==0||a<0);
   do{	
      cout<<"Ingrese el valor de b: ";
	   cin>>b;
   }while(b<0||b>25);
	int inv_a=inverso(26,a);     
	cout<<"Inverso de a: "<<inv_a<<endl; 	
	b=26-((inv_a*b)%26); 
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=((inv_a*j)+b)%26;
					m[i]=alf[aux];
					break;
				}
			}	
		}		
	}
	cout<<"El mensaje descifrado es: "<<m<<endl<<endl;
}

void cifrado_vigenere (){
	int aux1,aux2,aux3;
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	//ci  = mi  + ki (mod 26), 0 = ci  = 25;
	int k=0;
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					 aux1=j;
				}
				if(clave[k%strlen(clave)]==alf[j]){
					 aux2=j;
				}
			}
			aux3=(aux1+aux2)%26;
			m[i]=alf[aux3];
			k++;	
		}				
	}
	cout<<"El mensaje cifrado es:"<<m<<endl<<endl;
}

void descifrado_vigenere(){
	int aux1,aux2,aux3;
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	//Usar mi  = ci  - ki (mod 26), 0 = mi  = 25;

	int k=0;
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					 aux1=j;
				}
				if(clave[k%strlen(clave)]==alf[j]){
					 aux2=j;
				}
			}
			if((aux1-aux2)<0){
				aux3=26+(aux1-aux2);
			}
			else{
				aux3=(aux1-aux2)%26;
			}
			m[i]=alf[aux3];
			k++;	
		}				
	}
	cout<<"El mensaje descifrado es:"<<m<<endl<<endl;
}

int esta_matriz (char letra,char matriz[5][5]){
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
            if(letra == matriz[i][j]){
                  return 1;
            }
       }
    }
    return -1;
}

void llenar_matriz(char clave[],char matriz[5][5]){
    int fila=0;
    int columna=0;
    int aux;
    for(int i=0;i<strlen(clave);i++){
         aux=esta_matriz(clave[i],matriz);
         if(aux==-1&&clave[i]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=clave[i];
		        columna++;
         }            
    }
    for(int j=0;j<strlen(alf);j++){
        aux=esta_matriz(alf[j],matriz); 
        if(aux==-1&&alf[j]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=alf[j];
		        columna++;
         }   
    } 
}

void acomodar_mensaje (char m2[],char m[]){
	int j=0;
	for(int i=0;i<strlen(m);i++){		
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';
	//cout<<m2<<endl;
		
	int i=0;
	j=1;
	while(j<=strlen(m2)){
		if(m2[i]==m2[j]){
			for(int k=strlen(m2)+1;k>j;k--){
				m2[k]=m2[k-1];
			}
			m2[j]='x';
		}
		i=i+2;
		j=j+2;
	}
	
	if(strlen(m2)%2!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';		
	}
	//cout<<m2<<endl;
	//cout<<strlen(m2)<<endl;
}


void cifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i=0;i<5;i++)
	 for(int j=0;j<5;j++)
	   matriz[i][j]='\0';
	
	llenar_matriz(clave,matriz);
	/*for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<matriz[i][j];
			if(j==4){
				cout<<endl;
			}
		}
	}*/
	
	fflush(stdin);
	char m2[100];
	acomodar_mensaje(m2,m);
		
	int i=0;
	int j=1;
	while(j<=strlen(m2)){	
		int fila1,fila2,columna1,columna2;
		if(m2[i]=='j'){
			m2[i]='i';
		}
		if(m2[j]=='j'){
			m2[j]='i';
		}
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				if(m2[i]==matriz[x][y]){
					fila1=x;
					columna1=y;
				}
				if(m2[j]==matriz[x][y]){
					fila2=x;
					columna2=y;
				}
			}
		}
		if(fila1==fila2){
			m2[i]=matriz[fila1][(columna1+1)%5];
			m2[j]=matriz[fila1][(columna2+1)%5];
		}
		else if(columna1==columna2){
			m2[i]=matriz[(fila1+1)%5][columna1];
			m2[j]=matriz[(fila2+1)%5][columna1];
		}
		else{
			m2[i]=matriz[fila1][columna2];
			m2[j]=matriz[fila2][columna1];
		}
		i=i+2;
		j=j+2;
	}
	cout<<"El mensaje cifrado es:";
	for(int i=0;i<strlen(m2);i++){
		cout<<m2[i];
		if(i%2!=0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;

}

void descifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i=0;i<5;i++)
	 for(int j=0;j<5;j++)
	   matriz[i][j]='\0';
	
	llenar_matriz(clave,matriz);
	
	fflush(stdin);
	char m2[100];
	
	int p=0;
	for(int q=0;q<strlen(m);q++){		
		if(m[q]!=32){
		   m2[p]=m[q];
		   p++;
		}
	}
	m2[p]='\0';
	
	int i=0;
	int j=1;
	while(j<=strlen(m2)){	
		int fila1,fila2,columna1,columna2;
		if(m2[i]=='j'){
			m2[i]='i';
		}
		if(m2[j]=='j'){
			m2[j]='i';
		}
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				if(m2[i]==matriz[x][y]){
					fila1=x;
					columna1=y;
				}
				if(m2[j]==matriz[x][y]){
					fila2=x;
					columna2=y;
				}
			}
		}
		if(fila1==fila2){
			if((columna1-1)<0){
				m2[i]=matriz[fila1][4];
			}
			else{
				m2[i]=matriz[fila1][columna1-1];
			}
			if((columna2-1)<0){
				m2[j]=matriz[fila1][4];
			}
			else{
				m2[j]=matriz[fila1][columna2-1];
			}		
		}
		else if(columna1==columna2){
			if((fila1-1)<0){
				m2[i]=matriz[4][columna1];
			}
			else{
				m2[i]=matriz[fila1-1][columna1];	
			}
			if((fila2-1)<0){
				m2[j]=matriz[4][columna2];
			}
			else{
				m2[j]=matriz[fila2-1][columna2];	
			}
		}
		else{
			m2[i]=matriz[fila1][columna2];
			m2[j]=matriz[fila2][columna1];
		}
		i=i+2;
		j=j+2;
	}
	cout<<"El mensaje descifrado es:";
	for(int i=0;i<strlen(m2);i++){
		cout<<m2[i];
		if(i%2!=0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
}

int calcular_determinante(int a[][26],int orden)
{
   int det=0;
	int aux1[26][26];
   int aux2[26][26];


	if(orden==1)
   	return a[0][0];

   for(int i=0;i<orden;i++)
     {
      if(i%2==0)
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux1[x][y]=a[x][y+1];
            else
               aux1[x][y]=a[x+1][y+1];

      	 det=det+a[i][0]*calcular_determinante(aux1,orden-1);
       }
      else
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux2[x][y]=a[x][y+1];
            else
               aux2[x][y]=a[x+1][y+1];

      	det=det-a[i][0]*calcular_determinante(aux2,orden-1);
       }
      }
   return det;
}

int es_invertible(int matriz[][26],int d){
	
	int det=calcular_determinante(matriz,d);
	cout<<"Determinante: "<<det<<endl;
	if(det<0){
		det=-1*det;
	}

	if(det%2==0 || det%13==0){
		return 0;
	}
	else{
		return 1;
	}
	
}

void quitar_espacios (char m2[],char m[], int d){
	int j=0;
	for(int i=0;i<strlen(m);i++){		
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';
	
	while(strlen(m2)%d!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';		
	}
}

void multiplica (int matriz[][26],int indices[],int d){
	int indices_aux[d];
	for(int i=0;i<d;i++){
		int aux=0;
		for(int j=0;j<d;j++){	
			aux=(matriz[i][j]*indices[j])+aux;
		}
		//cout<<aux;
		indices_aux[i]=aux%26;
		//cout<<indices_aux[i]<<endl;
	}
	for(int i=0;i<d;i++){
		indices[i]=indices_aux[i];
		//cout<<indices[i]<<endl;
	}
}

void cifrado_hill(){
	int d;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	
	fflush(stdin);
	char m2[100];
			
	do{
		cout<<"Ingrese un numero entero d:";
		cin>>d;	
	}while(d<0||d>25);
	quitar_espacios(m2,m,d);
	cout<<m2<<endl;
	
	int matriz[26][26];
	cout<<"Llenado de la matriz: "<<endl;
	do{
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				do{
					cout<<"Ingrese elemento ["<<i<<"]["<<j<<"]:";
					cin>>matriz[i][j];
				}while(matriz[i][j]<0||matriz[i][j]>25);
			}
		}
		
	}while(es_invertible(matriz,d)==0);
	
	int indices[100];
	int k=0;
	int l=0;
	
	for(int i=0; i<strlen(m2);i++){	
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
					 //cout<<indices[k]<<endl;
				}
			}
			k++;
			if(k%d==0){
				multiplica(matriz,indices,d);
				for(int i=0;i<d;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}				
	}
	cout<<"El mensaje cifrado es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){	
		cout<<m2[i];
		conta++;
		if(conta%d==0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
	/*
	cout<<endl;
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++)
			{
				cout<<matriz[i][j];
				if(j==d-1){
					cout<<endl;
				}
			}	*/	
}

double determinante(double matriz[][26], int d)
{
    double det;
    if(d==2)
    {
        det=(matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]);
        return det;
    }
    double suma=0;
    for(int i=0; i<d; i++){
    double nm[d-1][26];
        for(int j=0; j<d; j++){
            if(j!=i){
                for(int k=1; k<d; k++){
                int indice=-1;
                if(j<i)
                indice=j;
                else if(j>i)
                indice=j-1;
                nm[indice][k-1]=matriz[j][k];
                }
            }
        }
        if(i%2==0)
        suma+=matriz[i][0] * determinante(nm,(d-1));
        else
        suma-=matriz[i][0] * determinante(nm,(d-1));
    }
    return suma;
}

void matrizCofactores (double matriz[][26], int d ){
    double nm[d][d];
    for(int i=0;i<d;i++) {
        for(int j=0;j<d;j++) {
            double det[d-1][26];
            double detValor;
            for(int k=0;k<d;k++) {
                if(k!=i) {
                    for(int l=0;l<d;l++) {
                        if(l!=j) {
                        int indice1=k<i ? k : k-1 ;
                        int indice2=l<j ? l : l-1 ;
                        det[indice1][indice2]=matriz[k][l];
                        }
                    }
                }
            }
            detValor=determinante(det,d-1);
            nm[i][j]=detValor * (double)pow(-1, i+j+2);
        }
    }
    for(int i=0;i<d;i++) 
        for(int j=0;j<d;j++) 
   			 matriz[i][j]=nm[i][j];
}

void matrizTranspuesta(double matriz[][26], int d ){
    double nuevam[d][d];
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
            nuevam[i][j]=matriz[j][i];
    }
    for(int i=0;i<d;i++) 
        for(int j=0;j<d;j++) 
   			 matriz[i][j]=nuevam[i][j];
}

void matrizAdjunta(double  matriz[][26], int d){
    matrizCofactores(matriz, d);
    matrizTranspuesta(matriz, d);
    
}

void multiplicarMatriz(double n, double matriz[][26], int d) {
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            matriz[i][j]*=n;
}

void matrizInversa(double matriz[][26], int d){
	double det;
	det= 1/determinante(matriz,d);
	matrizAdjunta(matriz,d);
	//multiplicarMatriz(det,matriz,d);
}

void descifrado_hill(){
	int d;
	char m[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	
	fflush(stdin);
	char m2[100];
			
	do{
		cout<<"Ingrese un numero entero d:";
		cin>>d;	
	}while(d<0||d>25);
	quitar_espacios(m2,m,d);
	//cout<<m2<<endl;
	
	double matriz[26][26];
	cout<<"Llenado de la matriz: "<<endl;
	//do{
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				do{
					cout<<"Ingrese elemento ["<<i<<"]["<<j<<"]:";
					cin>>matriz[i][j];
				}while(matriz[i][j]<0||matriz[i][j]>25);
			}
		}
		
	//}while(es_invertible(matriz,d)==0);
	int matriz_aux[26][26];
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				matriz_aux[i][j]=(int)matriz[i][j];
			}
		}
	
	int deter =calcular_determinante(matriz_aux,d);
	deter=inverso(26,deter%26);
	//cout<<deter<<endl;
	matrizInversa(matriz,d);
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++){
			matriz[i][j]=matriz[i][j]*deter;
		}
	
	int matriz_aux2[26][26];
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				matriz_aux2[i][j]=(int)matriz[i][j];
			}
		}
	for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				if(matriz_aux2[i][j]<0){
					while(matriz_aux2[i][j]<0){
						matriz_aux2[i][j]=matriz_aux2[i][j]+26;
					}
				}
				else{
					matriz_aux2[i][j]=matriz_aux2[i][j]%26;
				}
			}
	}	
	cout<<endl;
	/*
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++)
			{
				cout<<matriz_aux2[i][j];
				if(j==d-1){
					cout<<endl;
				}
			}*/
	
	int indices[100];
	int k=0;
	int l=0;		
	for(int i=0; i<strlen(m2);i++){	
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
					 //cout<<indices[k]<<endl;
				}
			}
			k++;
			if(k%d==0){
				multiplica(matriz_aux2,indices,d);
				for(int i=0;i<d;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}				
	}
	cout<<"El mensaje descifrado es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){	
		cout<<m2[i];
		conta++;
		/*if(conta%3==0){
			cout<<" ";
		}*/
	}
	cout<<endl<<endl;	
	
}

bool validar(char palabra[], int n){
	int cont=0;
	cout<<palabra<<endl;
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		if(palabra[i]!=49 || palabra[i]!=48){
			return false;
		}
	}	
	return true;
}

void cifrado_vernam(){
	char texto_plano[100] ;
	char texto_cifrado[100] ;
	char clave[100] ;
	int tam1, tam2;
	bool band;
	//do{
		fflush(stdin);
		cout<<"Ingrese texto plano:";
		cin.getline(texto_plano,100);
		tam1=strlen(texto_plano);
		
	//}while(band!=true);
	
	//do{
		fflush(stdin);
		cout<<"Ingrese clave:";
		cin.getline(clave,100);
		tam2=strlen(clave);
	//}while(validar(clave,tam2)==0);
	
	for(int i=0;i<tam1;i++){
		if(texto_plano[i]==clave[i]){
			texto_cifrado[i]='0';
		}
		else{
			texto_cifrado[i]='1';
		}
	}
	texto_cifrado[tam1]='\0';
	cout<<"Texto Cifrado: "<<texto_cifrado<<endl;
		
}

void descifrado_vernam(){
	char texto_cifrado[100] ;
	char texto_descifrado[100] ;
	char clave[100] ;
	int tam1, tam2;
	bool band;
	//do{
		fflush(stdin);
		cout<<"Ingrese texto a descifrar:";
		cin.getline(texto_cifrado,100);
		tam1=strlen(texto_cifrado);
		
	//}while(band!=true);
	
	//do{
		fflush(stdin);
		cout<<"Ingrese clave:";
		cin.getline(clave,100);
		tam2=strlen(clave);
	//}while(validar(clave,tam2)==0);
	
	for(int i=0;i<tam1;i++){
		if(texto_cifrado[i]==clave[i]){
			texto_descifrado[i]='0';
		}
		else{
			texto_descifrado[i]='1';
		}
	}
	texto_descifrado[tam1]='\0';
	cout<<"Texto Cifrado: "<<texto_descifrado<<endl;
}

main(){
	int opc,opc2;
	do{
		cout<<"Menu:"<<endl;
		cout<<"1.- Cifrado del Cesar:"<<endl;
		cout<<"2.- Cifrado Afin"<<endl;
		cout<<"3.- Cifrado de Vigenere"<<endl;
		cout<<"4.- Cifrado de  Playfair"<<endl;
		cout<<"5.- Cifrado de Hill"<<endl;
		cout<<"6.- Cifrado de Vernam"<<endl;
		cout<<"7.- Salir"<<endl;
		cout<<"Ingrese Opcion:";
		cin>>opc;
		
		switch(opc){
			case 1: system("cls");
					do{
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: cifrado_cesar(); break;
							case 2: descifrado_cesar(); break;
						}
					}while(opc2!=3);
					system("cls");			
					break;
					
			case 2: system("cls");
					do{	
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: /*system("cls");*/ cifrado_afin(); break;
							case 2: /*system("cls");*/ descifrado_afin(); break;
						}
					}while(opc2!=3);
					system("cls");		
					break;
			
			case 3: system("cls");
					do{	
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: cifrado_vigenere(); break;
							case 2: descifrado_vigenere(); break;
						}
					}while(opc2!=3);
					system("cls");		
					break;
					
			case 4: system("cls");
					do{	
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1:  cifrado_playfair(); break;
							case 2:  descifrado_playfair(); break;
						}
					}while(opc2!=3);
					system("cls");		
					break;	
			
			case 5: system("cls");
					do{
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: cifrado_hill(); break;
							case 2: descifrado_hill(); break;
						}
					}while(opc2!=3);
					system("cls");			
					break;	
					
			case 6: system("cls");
					do{
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: cifrado_vernam(); break;
							case 2: descifrado_vernam(); break;
						}
					}while(opc2!=3);
					system("cls");			
					break;	
		}
	}while(opc!=7);
	getch();
}
