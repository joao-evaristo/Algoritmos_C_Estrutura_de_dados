#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define true 1
#define false 0

typedef int bool;
typedef  int TKey;

typedef struct aux {
  TKey Key;
  struct aux *left, *right;
}Node;

typedef Node* Pont;

Pont Tree_Start(){
  return NULL;
}

Pont Create_Node(TKey x){
  Pont newNode = (Pont)malloc(sizeof(Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->Key = x;
  return (newNode);
}

Pont Insert_Node(Pont Root, Pont node){
  if (Root == NULL)
    return (node);
  else if (node->Key <Root->Key)
    Root->left = Insert_Node(Root->left, node);
  else  
    Root->right = Insert_Node(Root->right, node);
  return (Root);
}

Pont Search_Node(TKey x, Pont root){
  if (root == NULL)
    return  (NULL);
  else if (root->Key == x)
    return(root);
  else if (root->Key > x)
    return (Search_Node(x, root->left));
  return(Search_Node(x, root->right));
}

Pont Search_Nodefather(Pont root, TKey x, Pont *father){
  Pont current = root;
  *father = NULL;
  while (current){
    if (current->Key == x)
      return (current);
    *father = current;
    if (x < current->Key)
      current = current->left;
    else
      current = current->right;
  }
  return (NULL);
}

Pont Remove_Node (Pont root, TKey x){
  Pont father, node, p, q;
  node = Search_Nodefather(root, x, &father);
  if (node==NULL)
    return (root);
  if (!node->left || !node->right){
    if (!node->left)
      q = node->right;
    else  
      q = node->left;
  }
  else {
    p = node;
    q = node->left;
    while (q->right){
      p = q;
      q = q->right;
    }
    if (p != node){
      p->right = q->left;
      q->left = node->left;
    }
    q->right = node->right;
  }
  if (!father){
    free (node);
    return (q);
  }
  if (x < father->Key)
    father->left = q;
  else
    father ->right = q;
    free(node);
  return(root);
}
void Display_Tree(Pont root){
  if (root != NULL){
    printf("(C%i", root->Key);
    Display_Tree(root->left);
    Display_Tree(root->right);
    printf(")");
  }
  else {
    printf("()");
  }
}

int main(){
  Pont root = Tree_Start();
  int n=0, i=0, aux, removenode;
  Pont node, nodeifinsert;
  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%d", &aux);
    node = Create_Node(aux);
    root = Insert_Node(root, node);
  }
  scanf("%d", &removenode);
  if (Search_Node(removenode, root) == NULL){
    nodeifinsert = Create_Node(removenode);
    Insert_Node(root, nodeifinsert);
  }
   else{
    Remove_Node(root, removenode);
   }
  Display_Tree(root);
}
