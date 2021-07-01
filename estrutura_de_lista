#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define MAXSIZE 50000
 
typedef char TItem;
 
typedef struct Cel *Pointer;
 
typedef struct Cel {
  TItem Item;
  Pointer Next;
} Cel;
 
typedef struct {
  Pointer Last;
  int Size;
}List;
 
void List_Start(List *pList){
  pList->Last = (Pointer) malloc(sizeof(Cel));
  pList-> Last->Next = pList->Last;
  pList->Size = 0;
}
 
int List_Empty(List *pList){
  return  (pList->Last->Next == pList->Last);
}
 
int List_Size(List *pList){
  return (pList->Size);
}
 
int List_Insert (List *pList, Pointer p, TItem x){
  Pointer pPrevious, pNew;
  pPrevious = pList -> Last -> Next;
  while ((pPrevious != pList->Last) && (pPrevious->Next != p)){
    pPrevious = pPrevious->Next;
  }
  if (pPrevious->Next != p){
    return 0;
  }
  pNew = (Pointer) malloc(sizeof(Cel));
  pNew->Item = x;
  pNew->Next = pPrevious->Next;
  pPrevious->Next = pNew;
  if (pPrevious == pList->Last){
        pList->Last = pNew;
      }
    pList->Size++;
  return 1;
  }
 
int List_Remove (List *pList, Pointer p, TItem *pX){
  Pointer pPrevious, pAux;
  if (List_Empty(pList)){
    return 0;
  }
  pPrevious = pList->Last->Next;
  while ((pPrevious != pList->Last) && (pPrevious->Next != p)){
    pPrevious = pPrevious->Next;
  }
  if (pPrevious->Next != p){
    return 0;
  }
  pAux = pPrevious->Next;
  pPrevious->Next = pAux->Next;
  if (pAux == pList->Last){
    pList->Last = pPrevious;
  }
  *pX = pAux-> Item;
  free(pAux);
  pList->Size --;
  return 1;
}
 
Pointer List_Return(List *pList, int p){
  Pointer pPointer;
  int Pos=0;
  pPointer = pList->Last->Next->Next;
  while ((pPointer != pList->Last->Next) && (Pos != p)){
    pPointer = pPointer->Next;
    Pos ++;
  }
  return pPointer;
}
 
int main(){
  List List;
  List_Start(&List);
  int reference = 0, Pointer, i=0, Size=0;;
  char input[MAXSIZE], aux;
  scanf("%[^\n]%*c", input);
  Size = strlen(input);
  while (i<Size){
      switch (input[i]){
        case '[':
          reference = 0;
          break;
 
        case ']':
          reference = List.Size;
          break;
          
        case '-':
          if(reference>0){
            reference --;
            List_Remove(&List, List_Return(&List, reference), &aux);
          }
          break;
 
        case '<':
          if(reference > 0) {
          reference--;
        }
        break;
 
        case '>':
          if(reference < List.Size) {
            reference++;
          }
        break;
 
        default:
          List_Insert(&List, List_Return(&List,  reference), input[i]);
        reference++;
        break;
    }
    i++;
  } 
  while(List_Size(&List)>0) {
    List_Remove(&List, List_Return(&List, 0), &aux);
    printf("%c", aux);
  }
  printf("\n");
  return 0;
}
