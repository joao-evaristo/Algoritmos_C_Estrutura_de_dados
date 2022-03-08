#include <stdio.h>
#include <stdlib.h>
//João Pedro Assumpção Evaristo RA: 147887
int merge(int lista[], int inicio, int metade, int fim, int K, int Count){//Função Merge
    int i=0, j=0, k=0, count=0;
    int tamanho1 = metade - inicio + 1;
    int tamanho2 = fim - metade;
    int vesquerda[tamanho1], vdireita[tamanho2];
    for (i = 0; i < tamanho1; i++){
        vesquerda[i] = lista[inicio + i];
    }
    for (j = 0; j < tamanho2; j++){
        vdireita[j] = lista[metade + 1 + j];
    }
    i = 0; 
    j = 0;
    k = inicio;
    while (i < tamanho1 && j < tamanho2) {
      if (vesquerda[i] <= K*vdireita[j]) {//Comparação do elemento a esquerda com K* o da direita
        lista[k] = vesquerda[i];
        i++;
      }
      else {
          lista[k] = vdireita[j];
          j++;
          Count += tamanho1-i;// Contador para acumular o número de vezes que dupla poderia ser feita
      }
    }
    i = 0; 
    j = 0;
    k = inicio;
    while (i < tamanho1 && j < tamanho2) {//ordenação por merge
      if (vesquerda[i] <= vdireita[j]) {
        lista[k] = vesquerda[i];
        i++;
      }
      else {
          lista[k] = vdireita[j];
          j++;
      }
        k++;
    }
    
    while (i < tamanho1) {
        lista[k] = vesquerda[i];
        i++;
        k++;
    }
    while (j < tamanho2) {
        lista[k] = vdireita[j];
        j++;
        k++;
    }
    return Count;
}
int mergeSort(int lista[], int inicio, int fim, int K, int Count){// Função mergesort
  if (inicio >= fim) {
    return 0;
  }
  else {
    int metade = (inicio + fim)/ 2;
    Count = mergeSort(lista, inicio, metade, K, Count) + mergeSort(lista, metade +1, fim, K, Count) + merge(lista, inicio, metade, fim, K, Count);
    return Count;
  }
}
int main(void) {
  int N=0, i=0, numbers;
  scanf("%d", &N);
  int v[N];
  int K = 0;
  scanf("%d", &K);
  for (i=0; i<N; i++){
    scanf("%d", &numbers); 
    v[i] = numbers;
  }
  printf("%d", mergeSort(v, 0, N-1, K, 0));
  return 0;
}
