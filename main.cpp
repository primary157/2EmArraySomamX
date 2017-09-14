#include <stdio.h>
#include "doissomamx.h"
#include "binarysearch.h"
#include "buscacomhash.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"

int main(int argc, char **argv) {
    int *Entrada, sz,x; unsigned long long tempo_de_usuario[4], tempo_de_cpu[4];
    scanf("%d %d",&sz, &x);
    Entrada = (int*) malloc (sz * sizeof(int));
    for(int i = 0; i < sz; i++) scanf("%d",Entrada + i);
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu,tempo_de_usuario,quickSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 1,tempo_de_usuario + 1,heapSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 2,tempo_de_usuario + 2,mergeSort,binarySearch);
    
    doisSomamXComTimer(&Entrada,sz,x,tempo_de_cpu + 3,tempo_de_usuario + 3,NULL,criaHashEBusca);
    
    for(int i = 0; i < 4; i++){
        printf("Caso %d\n",i);
        printf("\tTempo de usuario: %llu\n",tempo_de_usuario[i]);
        printf("\tTempo de cpu: %llu\n",tempo_de_cpu[i]);
        printf("\tTempo total: %llu\n",tempo_de_cpu[i]+tempo_de_usuario[i]);
    
    }
    
    return 0;
}
