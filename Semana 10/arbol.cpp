#include <iostream>
using namespace std;


//En este caso color sera establecido de la siguiente manera para nodo Negro = 0, Rojo = 1

class Node {
  public:
    int color;
    int info = -1;
    int posicion = -1;
    Node *parentNode;
    Node *childLeft;
    Node *childRight;
};

class arbolRojoNegro{
  
  public:
    Node *root;
    Node *tree;

  public: 
    arbolRojoNegro(){
      tree = new Node();
      tree->color = 0;
      tree->childRight = NULL;
      tree->childLeft = NULL;
      root = tree;
    }

    void insertar(int info, int posicion){
      Node *nodes = new Node();
      nodes->info = info;
      nodes->posicion = posicion;
      nodes->color = 1;
      nodes->childLeft = tree;
      nodes->childRight = tree;

      Node *parent = tree;
      Node *current = root;

      while(current != tree){
        parent = current;
        if(info < current->info){
          current = current->childLeft;
        }else{
          current = current->childRight;
        }
      }
      
      nodes->parentNode = parent;

      if(parent == tree){
        root = nodes;
      }else if(info < parent->info){
        parent->childLeft = nodes;
      }else{
        parent->childRight = nodes;
      }

      arreglarInsertar(nodes);
    }

    void arreglarInsertar(Node *node){
      while(node->parentNode->color == 1){
        if(node->parentNode == node->parentNode->parentNode->childLeft){
          Node *uncle = node->parentNode->parentNode->childRight;

          if(uncle->color == 1){
            node->parentNode->color = 0;
            uncle->color = 0;
            node->parentNode->parentNode->color = 1;
            node = node->parentNode->parentNode;
          }else{
            if(node == node->parentNode->childRight){
              node = node->parentNode;
              rotarizquierda(node);
            }

            node->parentNode->color = 0;
            node->parentNode->parentNode->color = 1;
            rotarderecha(node->parentNode->parentNode);
          }
        }else{
          Node *uncle = node->parentNode->parentNode->childLeft;

          if(uncle->color = 1){
            node->parentNode->color = 0;
            uncle->color = 0;
            node->parentNode->parentNode->color = 1;
            node = node->parentNode->parentNode;
          }else{
            if(node == node->parentNode->childLeft){
              node = node->parentNode;
              rotarderecha(node);
            }

            node->parentNode->color = 0;
            node->parentNode->parentNode->color = 1;
            rotarizquierda(node->parentNode->parentNode);
          }
        }
      }
      root->color = 0;
    }


    void rotarizquierda(Node *x){
      Node *y = x->childRight;
      x->childRight = y->childLeft;
      if(y->childLeft != tree){
        y->childLeft->parentNode = x;
      }

      y->parentNode = x->parentNode;

      if(x->parentNode == tree){
        root = y;
      }else if(x == x->parentNode->childLeft){
        x->parentNode->childLeft = y;
      }else{
        x->parentNode->childRight = y;
      }
      y->childLeft = x;
      x->parentNode = y;
    }

    void rotarderecha(Node *x){
      Node *y = x->childLeft;
      x->childLeft = y->childRight;
      if(y->childRight != tree){
        y->childRight->parentNode = x;
      }

      y->parentNode = x->parentNode;

      if(x->parentNode == tree){
        root = y;
      }else if(x == x->parentNode->childLeft){
        x->parentNode->childLeft = y;
      }else{
        x->parentNode->childRight = y;
      }

      y->childRight = x;
      x->parentNode = y;
    }

};

int main(){
  arbolRojoNegro tree;
  int n, q;

  cin >> n >> q;

  for(int i = 0; i < n; i++){
    int entrada;
    cin >> entrada;
    tree.insertar(entrada, i);
  }

  for(int i = 0; i < q; i++){
    int buscar;
    cin >> buscar;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *w = tree.root;
    int posicion = -1;
    while(w->info != -1){
      if(w->info == buscar){
        posicion = w->posicion;
        break;
      }
      
      if(w->info > buscar){
        w = w->childLeft;
      }else{
        w = w->childRight;
      }
    }

    cout<<posicion<<"\n";
  }

  return 0;
}