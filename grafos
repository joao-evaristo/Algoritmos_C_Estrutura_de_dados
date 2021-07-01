#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef int TPackages;
typedef int TRelations;
typedef char TItem;
 
typedef struct {
  int indexRelations;
  TRelations Relation;
}TAdjacency;

typedef struct {
  TAdjacency Adj[100][10000];
  int NPackages;
  int NRelaions;
}TFork;

int TFork_Start(TFork *pFork, int NPackages){ 
  TPackages u, v;
  if (NPackages > 100)
    return 0;
  pFork->NPackages = NPackages;
  pFork->NRelaions = 0;
  for (u = 0; u < pFork->NPackages; u++){
    for (v = 0; v < pFork->NPackages; v++){
      pFork->Adj[u][v].indexRelations = 0;
    }
  }
  return 1;
}

int TFork_existRelation(TFork *pFork, TPackages u, TPackages v){
  return pFork->Adj[u][v].indexRelations;
}

int TFork_insertPackage(TFork *pFork, TPackages u, TPackages v){
  pFork->Adj[u][v].indexRelations = 1;
  pFork->NRelaions++;
  return 1;
}

int TFork_NPackages(TFork *pFork){
  return (pFork->NPackages);
}

int TFork_NRelations(TFork *pFork){
  return (pFork->NPackages);
}

int main(){
  TFork *pFork = (TFork*)malloc(sizeof(TFork));
  int Packages=0, Relations = 0, i = 0, u, v, j=0, k = 0, dependent = 0, dependency = 0;
  scanf("%d%d", &Packages, &Relations);
  TFork_Start(pFork, Packages);
  for (i=0; i < Relations;i++){
    scanf("%d%d", &u, &v);
    TFork_insertPackage(pFork, u - 1, v - 1);
  }
   for (k=0; k<Packages; k++){
     for (j=0; j<Packages; j++){
       if (TFork_existRelation(pFork, k, j) == 1){
         dependency ++;
       }
       if(TFork_existRelation(pFork, j, k)){
         dependent ++;
       }
     }
     printf("%d %d %d", k+1,dependent, dependency);
     dependency = 0;
     dependent = 0;
      for (j=0; j<Packages; j++){
       if (TFork_existRelation(pFork, k, j) == 1){
        printf(" %d", j+1);
        }
      }
     printf("\n");
    }
  return 0;
}
