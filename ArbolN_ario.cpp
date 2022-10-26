#include<iostream>
#include <stack>        
#include <vector>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
  vector<Node*> hij;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
      hij = {};
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
      hij = {};
  }
  
  int getData(){
      return data;
  }
  
  Node* getIzq(){
      return izq;
  }
  
  Node* getDer(){
      return der;
  }
  
  vector<Node*> getHij(){
      return hij;
  }
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  void setHij(Node* h){
      hij.push_back(h);
  }  
  
  bool isHoja(){
      if(hij.empty())
        return true;
        
      return false;
  }
    
};

class Tree{
  Node* root;

public:
  Tree(){
      root = NULL;
  }
  
  void add(int d){
      Node* n = new Node(d);
      if(root == NULL){
          root = n;
      }else{
          Node* t = root;
          bool found = false;
          while(!found){
              if(t->getData() < n->getData()){
                if(t->isHoja()){
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }   
              }else{
                if(t->isHoja()){
                    t =  t->getIzq();
                }else{
                    t->setIzq(n);
                    found=true;
                } 
              }
          }
      }
  }

  void preorder(){
      preorder(root);
  }

  void preorder(Node* r){
      if(r != NULL){
          cout<<r->getData()<<"\t";
          preorder(r->getIzq());
          preorder(r->getDer());
      }
  }
    
  void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
        }
    }

    
    
};

int main()
{
    
    Tree t;

    return 0;
}


