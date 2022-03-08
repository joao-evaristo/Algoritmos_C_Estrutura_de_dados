#include <stdio.h>
#include <stdlib.h>
//João Pedro Assumpção Evaristo RA147887
int itsCousin (int N){//Função que irá verificar se o número é primo. Em caso positivo, retorna 1, em caso negativo, 0.
  int i=1, count = 0;
  for (i=1; i<=N; i++){
    if (N%i==0){
      count +=1;
    }
  }
  if (count == 2){
    return 1;
  }
  else{
    return 0;
  }
}
int main(){
  int numbertests=0, i=0, arraynumbers[10];//variáveis comuns e um array que irá conter os números de teste, com tamanho máximo 10
  scanf("%d", &numbertests);
  for(i=0; i<numbertests; i++){//Loop para que seja recebido N entradas, que é definido na variável numbertests que foi inserida anteriormente
    scanf("%d", &arraynumbers[i]);// Os números lidos são armazenados na array
  }
  for (i=0;i<numbertests;i++){//O programa irá verificar N vezes se cada elemento da array é primo utilizando-se da função definida anteriormente, se for primo, é escrito um 1 na frente do número, se não, um 0
    if (itsCousin(arraynumbers[i]) == 1){
      printf("%d 1\n", arraynumbers[i]);
    }
    else{
      printf("%d 0\n", arraynumbers[i]);
    }
  }
}
