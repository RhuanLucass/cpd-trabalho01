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

void selectionSort (int array[], int length){
    int min, temp;
    for(int i = 0; i < length; i++){
        min = i;
        for (int j = i + 1; j < length; j++){
            if (array[j] < array[min]){
                min = j;
            } 
        }
        if (array[i] != array[min]){
            temp = array[i];
            array[i] = array[min];
            array [min] = temp;
        }        
    }  

}

void quickSort (int values[], int began, int end){
    int i, j, pivo, temp;
    i = began;
    j = end - 1;
    pivo = values[began];
    while (i <= j){
        while (values[i] < pivo && i < end)
            i++;
        while (values[j] > pivo && j > began)
            j--;
        
        if (i<=j){
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    
    }
    if (j > began){
        quickSort (values, began, j+1);
    }
    if (i < end){
        quickSort (values, i, end);
    }
}

void troca (int a, int b){
    int t = a;
    a = b;
    b = t;
}

void constroiHeap (int array[], int length){
    for (int k = 1; k < length; k++){
        int f = k + 1;
        while (f > 1 && array[f/2] < array[f]){
            troca (array[f/2], array[f]);
            f /= 2;
        }
    }
}

void peneira (int array[], int length){
    int p = 1, f = 2, x = array[1];
    while (f <= length){
        if(f < length && array[f] < array[f+1])
            ++f;
        if(x >= array[f])
        break;
        array[p] = array[f];
        p = f, f = 2*p;
    }
    array[p] = x;
}

void heapSort(int array[], int length){
    constroiHeap(array, length);
    for (int m = length; m >= 2; --m){
        troca (array[1], array[m]);
        peneira(array, m-1);
    }
}

void randomInteger(int vet[], int n)
{
    //Preenchendo o vetor com numeros aleatórios
    for(int i = 0 ; i < n; i++){
        vet[i] = rand() % 10000;
    }
}

void vetorCrescente(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
}

void vetorDecrescente(int vet[], int n){
    int j = 0;
    for(int i = n; i > 0; i--){
        vet[j] = i;
        j++;
    }
}

int main() {
    int opc, opc2 = 1, n = 30000;
    int vet[30000];
    int vet2[30000];
    int vet3[30000];

    printf("   ORDENACAO DE VETORES\n");
    printf("Qual a ordem do vetor? (1-Aleatorio, 2-Crescente, 3-Decrescente)\n");
    scanf("%d", &opc);
    switch(opc){
        case 1:
            randomInteger(vet, n);
            randomInteger(vet2, n);
            randomInteger(vet3, n);
            break;

        case 2:
            vetorCrescente(vet, n);
            vetorCrescente(vet2, n);
            vetorCrescente(vet3, n);
            break;

        case 3:
            vetorDecrescente(vet, n);
            vetorDecrescente(vet2, n);
            vetorDecrescente(vet3, n);
            break;

        default:
            printf("Valor invalido!!");
    }


    //Imprimir na ordem gerada
    for(int i = 0; i < n; i++) {
        printf("%d", vet[i]);
        if (i < n-1)
            printf(", ");
    }
    printf("\n\n");
    for(int i = 0; i < n; i++) {
        printf("%d", vet2[i]);
        if (i < n-1)
            printf(", ");
    }
    printf("\n\n");
    for(int i = 0; i < n; i++) {
        printf("%d", vet3[i]);
        if (i < n-1)
            printf(", ");
    }
    printf("\n\n");
    printf("\n\n");

    while(opc2 !=0) {
        printf("Qual algoritmo de ordenacao usar? (1-Bubble, 2-Selection, 3-Insertion, 4-Quick, 5-Merge, 6-Heap, 0-Sair)\n");
        scanf("%d", &opc2);
        if(opc2 == 0)
            break;
        clock_t begin = clock(); //Tempo inicial

        switch (opc2) {
            case 1:
                bubbleSort(vet, n);
                bubbleSort(vet2, n);
                bubbleSort(vet3, n);
                break;

            case 2:
                selectionSort(vet, n);
                selectionSort(vet2, n);
                selectionSort(vet3, n);
                break;

            case 3:
                insertionSort(vet, n);
                insertionSort(vet2, n);
                insertionSort(vet3, n);
                break;

            case 4:
                quickSort(vet, 0, n);
                quickSort(vet2, 0, n);
                quickSort(vet3, 0, n);
                break;

            case 5:
                mergeSort(vet, n);
                mergeSort(vet2, n);
                mergeSort(vet3, n);
                break;
            
            case 6:
                heapSort(vet, n);
                heapSort(vet2, n);
                heapSort(vet3, n);
                break;

            default:
                printf("Valor invalido!!");
        }

        clock_t end = clock(); //Tempo final
        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;  //Calcula o tempo de execução


        //Imprimir ordenada
        for (int i = 0; i < n; i++) {
            printf("%d", vet[i]);
            if (i < n - 1)
                printf(", ");
        }
        printf("\n\n");
        for (int i = 0; i < n; i++) {
            printf("%d", vet2[i]);
            if (i < n - 1)
                printf(", ");
        }
        printf("\n\n");
        for (int i = 0; i < n; i++) {
            printf("%d", vet3[i]);
            if (i < n - 1)
                printf(", ");
        }

        printf("\n\nTempo de execucao do algoritmo de ordenacao: %lf\n\n", time_spent);
    }
    //system("pause");
    return 0;
}
