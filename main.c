#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int length){
    for(int i = length - 1; i > 0; i--){
        for (int j = 0; j < i; j++) {
            if(array[j] > array[j+1]){
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void insertionSort(int array[], int length){
    int temp, j;

    for(int i = 1; i < length; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && temp < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void merge(int array[], int length){
    int mid, i, j, k;
    int *temp;

    temp = (int*) malloc(length * sizeof(int));
    if(temp == NULL)
        exit(1);

    mid = length/2;
    i = 0;
    j = mid;
    k = 0;
    while(i < mid && j < length){
        if(array[i] < array[j]){
            temp[k] = array[i];
            ++i;
        }
        else{
            temp[k] = array[j];
            ++j;
        }
        ++k;
    }
    if(i == mid){
        while(j < length){
            temp[k] = array[j];
            ++j;
            ++k;
        }
    }
    else{
        while(i < mid){
            temp[k] = array[i];
            ++i;
            ++k;
        }
    }
    for(i = 0; i < length; i++)
        array[i] = temp[i];
    free(temp);
}

void mergeSort(int array[], int length){
    int mid;

    if(length > 1){
        mid = length/2;
        mergeSort(array, mid);
        mergeSort(array + mid, length - mid);
        merge(array, length);
    }
}

void randomInteger(int vet[], int n)
{
    //Preenchendo o vetor com numeros aleatórios
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 10000;
    }
}

void vetorCrescente(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
}

void vetorDecrescente(int vet[], int n){
    for(int i = n; i > 0; i--){
        vet[i] = i;
    }
}

int main() {
    int n = 100000;
    int vet[100000];

    //randomInteger(vet, n);
    //vetorCrescente(vet, n);
    vetorDecrescente(vet, n);

    //Imprimir na ordem gerada
    /*for(int i = 0; i < n; i++) {
        printf("%d", vet[i]);
        if (i < n-1)
            printf(", ");
    }*/
    printf("\n\n");
    printf("\n\n");

    clock_t begin = clock(); //Tempo inicial

    //bubbleSort(vet, n);
    //insertionSort(vet, n);
    mergeSort(vet, n);

    clock_t end = clock(); //Tempo final
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;  //Calcula o tempo de execução


    //Imprimir ordenada
    for(int i = 0; i < n; i++){
        printf("%d", vet[i]);
        if (i < n-1)
            printf(", ");
    }

    printf("\n\nTempo de execucao do algoritmo de ordenacao: %lf", time_spent);
    //system("pause");
    return 0;
}