#include <stdio.h>
#include "doissomamx.h"
#include "binarysearch.h"
#include "buscacomhash.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "interpolationsearch.h"
#define NUM_DE_SOLUCOES 9
int main() {
    int *Entrada, *copia_Entrada, sz,x; clock_t tempo[NUM_DE_SOLUCOES]; int it = 0;
    scanf("%d %d",&sz, &x);
    Entrada = (int*) malloc (sz * sizeof(int));
    copia_Entrada = (int*) malloc (sz * sizeof(int));
    for(int i = 0; i < sz; i++) scanf("%d",Entrada + i);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("quickSort apenas\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,quickSort,dumbSearch);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("heapSort apenas\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,heapSort,dumbSearch);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("mergeSort apenas\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,mergeSort,dumbSearch);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("quickSort interpolation\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,quickSort,interpolation_search);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("heapSort interpolation\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,heapSort,interpolation_search);
    printf("mergeSort interpolation\n");
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,mergeSort,interpolation_search);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("quickSort binary\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,quickSort,binarySearch);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("heapSort binary\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,heapSort,binarySearch);
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    printf("mergeSort binary\n");
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,mergeSort,binarySearch);
    /*
    printf("Hash\n");
    for(int i = 0; i < sz; i++) copia_Entrada[i] = Entrada[i];
    doisSomamXComTimer(&copia_Entrada,sz,x,tempo + it++,NULL,criaHashEBusca);
    */
    
    
    for(int i = 0; i < NUM_DE_SOLUCOES; i++){
        printf("Caso %d\n",i+1);
        printf("\tTempo gasto: %lu\n",tempo[i]);
    }
    return 0;
}
