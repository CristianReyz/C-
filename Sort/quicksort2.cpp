#include<stdio.h> 

int print_array(int arr[], int n)
{
    int i;
    for(i=0; i < n; i++)
        printf("%d  ,", arr[i]);
    printf("\n Fin del ordenamiento");
}

void cambiar_posicion(int *n1, int *n2) //Funcion para cambiar la posicion de los elementos desordenados
{ 
    int temp =*n1;//Variable temporal que almacena un dato mientras hacemos el cambio
    *n1 = *n2;
    *n2 = temp;
} 
  
int particion (int arr[], int low, int high) //Funcion para particionar el array
{ 
    int i = (low - 1);  //Indice del elemento mas pequeño 
    int pivot = arr[high];    //Pivot 
    
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) //Si el elemento actual es menor o igual a pivote 
        { 
            i++;     
            cambiar_posicion(&arr[i], &arr[j]); 
        } 
    } 
    cambiar_posicion(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) //Funcion de ordenamiento
{ 
    if (low < high) 
    { 
        int pi = particion(arr, low, high); //pi es el indice de particionamiento
        quickSort(arr, low, pi - 1); //Organiza los elementos antes de la particion
        quickSort(arr, pi + 1, high); //Organiza los elementos de despues de la particion
    } 
} 
  
void printArray(int arr[], int n) //Funcion para imprimir el array
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n Fin del ordenamiento"); 
} 
  
int main(int argc, char const *argv[]) //Funcion principal
{ 
    int arr[] = {1992, 1990, 10, 5, 6, 100, 0, 1, -10};
    int n = sizeof(arr)/sizeof(arr[0]);  //sizeof es una funcion que da el tamaño de bites de lo que necesitemos
    quickSort(arr, 0, n-1); 
    printf("El array ordenado: \n"); 
    printArray(arr, n); 
    printf("\n");
    return 0; 
} 
