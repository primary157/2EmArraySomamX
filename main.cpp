#include <stdio.h>
#include "doissomamx.h"
#include "binarysearch.h"
#include "buscacomhash.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "interpolationsearch.h"
#define NUM_DE_SOLUCOES 6
int main() {
    int *Entrada, sz,x; unsigned long long tempo_de_usuario[NUM_DE_SOLUCOES], tempo_de_cpu[NUM_DE_SOLUCOES];
    scanf("%d %d",&sz, &x);
    Entrada = (int*) malloc (sz * sizeof(int));
    for(int i = 0; i < sz; i++) scanf("%d",Entrada + i);
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu,tempo_de_usuario,quickSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 1,tempo_de_usuario + 1,quickSort,interpolation_search);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 2,tempo_de_usuario + 2,heapSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 3,tempo_de_usuario + 3,heapSort,interpolation_search);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 4,tempo_de_usuario + 4,mergeSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 5,tempo_de_usuario + 5,mergeSort,interpolation_search);
    
    //doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 6,tempo_de_usuario + 6,NULL,criaHashEBusca);
    
    
    
    for(int i = 0; i < NUM_DE_SOLUCOES; i++){
        printf("Caso %d\n",i);
        printf("\tTempo de usuario: %llu\n",tempo_de_usuario[i]);
        printf("\tTempo de cpu: %llu\n",tempo_de_cpu[i]);
        printf("\tTempo total: %llu\n",tempo_de_cpu[i]+tempo_de_usuario[i]);
    }
    return 0;
}
