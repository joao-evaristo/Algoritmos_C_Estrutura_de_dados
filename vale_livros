#include <stdio.h>
#include <stdlib.h>
//João Pedro Assumpção Evaristo RA147887
int trocasvales (int x, int v){//função recursiva que calcula a troca de vales por livros, somando 1 vale a mais a cada 2 gastos
  if (x>=v){
    return (trocasvales(x+1-v, v)+1);
  }
  else return (0);
}
int main(){
  int d=0,p=0,v=0, n=0, i=0, livros=0;
  scanf("%d", &n);
  int vet[n];
  for(i=0;i<n;i++){
    scanf("%d%d%d", &d, &p, &v);
    livros = d/p;
    livros += trocasvales(livros, v);
    vet[i] = livros;//vetor que armazena a quantidade de livro para cada entrada
  }
  for(i=0;i<n;i++){
    printf("%d\n", vet[i]);
  }
}
