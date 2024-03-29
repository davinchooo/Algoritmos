// ************************************** PUNTO 1 (Otro arbol) *************************************************

#include<iostream>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
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
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
  }
  
  bool isHoja(){
      if(izq == NULL && der == NULL)
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
  
  Node* getRT(){
      return root;
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
                if(t->hasDer()){
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }   
              }else{
                if(t->hasIzq()){
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

  void addre(int d){
      if(root != NULL)
        addre(d, root, root);
      else
        root =  new Node(d);
    }

    void addre(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d > pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d > t->getData()){
                addre(d, t->getIzq(), t);
            }else{
                addre(d, t->getDer(), t);
            }
        }
    }    
    
    void preorder2(Node* r, Tree* t){
      if(r != NULL){
          t->addre(r->getData());
          preorder2(r->getIzq(), t);
          preorder2(r->getDer(), t);
      }
    }
    
};

Tree* espejo(Tree t){
    Tree* t_c = new Tree();
    t.preorder2(t.getRT(),t_c);
    return t_c;
}




int main()
{
    
    Tree t;
    Tree* t_c;
    t.addr(4);
    t.addr(2);
    t.addr(5);
    t.addr(1);
    t.addr(3);
    
    t.preorder();
    cout << endl;
    t_c = espejo(t);
    t_c->preorder();
    
    return 0;
}


//****************************************** Punto 1 (mismo arbol) ******************************************************

#include<iostream>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
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
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
  }
  
  bool isHoja(){
      if(izq == NULL && der == NULL)
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
  
  Node* getRT(){
      return root;
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
                if(t->hasDer()){
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }   
              }else{
                if(t->hasIzq()){
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

  void addre(int d){
      if(root != NULL)
        addre(d, root, root);
      else
        root =  new Node(d);
    }

    void addre(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d > pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d > t->getData()){
                addre(d, t->getIzq(), t);
            }else{
                addre(d, t->getDer(), t);
            }
        }
    }    
    
    void preorder2(Node* r, Tree* t){
      if(r != NULL){
          t->addre(r->getData());
          preorder2(r->getIzq(), t);
          preorder2(r->getDer(), t);
      }
    }

    void mirror(Node* n){
        if (n == NULL)
            return;
        else {
            Node* temp = new Node();
     
            /* do the subtrees */
            mirror(n->getIzq());
            mirror(n->getDer());
     
            /* swap the pointers in this node */
            temp = n->getIzq();
            n->setIzq(n->getDer());
            n->setDer(temp);
        }
    }

};

Tree espejo(Tree t){
    t.mirror(t.getRT());
    return t;
    
}




int main()
{
    
    Tree t;
    Tree t_c;
    t.addr(4);
    t.addr(2);
    t.addr(5);
    t.addr(1);
    t.addr(3);
    
    t.preorder();
    cout << endl;
    t_c = espejo(t);
    t_c.preorder();
    
    return 0;
}


// **************************************** Punto2.a **********************************************************************

#include<iostream>

using namespace std;

class Grafos{
    int** mat;
    int tam;
public:

    Grafos(){
        mat = new int*[0];
        tam = 0;
    }
    
    Grafos(int p){
        mat = new int*[p];
        tam = p;
    }
    
    int** getMat(){
      return mat;
    }
    
    int getTam(){
      return tam;
    }
    
    void setMat(int** mt){
      mat =  mt;
    }
    
    void setTam(int tm){
      tam =  tm;
    }    
    
    void initMat(int p){
        for(int i = 0; i < p; ++i){
            mat[i] = new int[p];   
        } 
        
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
               mat[i][j] = 0;
            }
        }
    }
    
    void printMat(int p){
        int i = 1; 
        cout << "\t";
        while(i <= p){
            cout << i << "\t";
            i++;
        }
        i = 1;
        cout << endl << endl << i << "\t";
        for(int i = 0; i<p; i++){
            for(int j = 0; j<p; j++){
                cout<<mat[i][j]<<"\t";
            }
            if (i+2 <= p){
                cout<<"\n" << i+2 <<"\t";
            }
        }
        cout << endl;
    }    
    
    void addEnlace(int i, int f, int p){
        mat[i-1][f-1] = p;
    }
    
    void addNodo(){
        int** mat_copy = new int*[tam+1];
        for(int i = 0; i < tam+1; ++i){
            mat_copy[i] = new int[tam+1];   
        } 
        
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                mat_copy[i][j] = mat[i][j];
            }
        }
        
        for(int i=0;i<tam;i++)
            delete[] mat[i];
        
        delete[] mat;
        tam++;
        
        mat = new int*[tam];

        for(int i = 0; i < tam; ++i){
            mat[i] = new int[tam];   
        } 

        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                mat[i][j] = mat_copy[i][j];
            }
        }        
    }
    

    bool is_bidireccional(){
        
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                if (mat[i][j] != 0){
                    if (mat[i][j] != mat[j][i]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
};



int main()
{
    int p;
    cout << "Cuantos nodos son: ";
    cin>>p;
    Grafos g = Grafos(p);
    g.initMat(p);
    g.printMat(p);
    g.addEnlace(3,2,15);
    g.addEnlace(2,3,15);
    g.addEnlace(4,5,2);
    cout<< endl << endl;
    g.printMat(p);
    cout << endl << g.is_bidireccional();
    return 0;
}


//*********************************************** Punto 2.b *************************************************

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Grafo{
    int **matriz;
    int nodos;
   
public:
    Grafo(int Nodos_){
        nodos = Nodos_;
        matriz = new int*[nodos];          
        for(int i = 0; i < nodos; i++){
            matriz[i] = new int[nodos];
        }
           
        for(int i = 0;i < nodos;i++){
            for(int j = 0;j < nodos;j++){
                matriz[i][j] = 0;
            }
        }
    }
       
    int getPeso(int n1, int n2){
        return matriz[n1][n2];
    }
    
    int** getMt(){
        return matriz;
    }
   
    void addEnlace(int i, int f, int p){
        matriz[i-1][f-1] = p;
    }
   
    void addNodo(){
        int **n_matriz;
        int old_nodos = nodos;
        nodos +=1;
        n_matriz = new int*[nodos];          
            for(int i = 0; i < nodos; i++){
                n_matriz[i] = new int[nodos];
            }
           
        for(int i = 0;i < nodos;i++){
            for(int j = 0;j < nodos;j++){
                if(i >= old_nodos || j >= old_nodos){
                    *(*(n_matriz+i)+j) = 0;
                }else{
                *(*(n_matriz+i)+j) = *(*(matriz+i)+j);
                }
            }
        }
       
        for(int i = 0;i < old_nodos;i++){  
            delete[] matriz[i];
        }
       
        matriz = n_matriz;
    }
   
    bool es_bidireccional(){
        for(int i = 0;i < nodos;i++){
            for(int j = 0;j < nodos;j++){
                if(matriz[i][j] != matriz[j][i]){
                    return false;
                }
            }
        }    
        return true;
    }
   
    int get_min(vector<int> &arr){
        int min = arr[0];
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<min)
                min = arr[i];
        }
        return min;
    }
    bool found(int a, vector<int> arr){
        for(int i = 0; i <arr.size(); i++){
            if(arr[i] == a)
                return true;
        }
        return false;
    }
   
    int saltos(int a, int b, vector<int> rev){
        vector<int> conexiones;
        if(a == b)
            return 0;
        else{
            rev.push_back(a);
            for(int i = 0; i < nodos; i++){
                if(matriz[a-1][i]!=0 && !found(i+1, rev)){
                    conexiones.push_back(saltos(i+1, b, rev));
                }
            }
        }
        if(conexiones.size() == 0)
            return 235233256;
        else
            return get_min(conexiones)+1;
    }
   
    void print(int p){
        int i = 1; 
        cout << "\t";
        while(i <= p){
            cout << i << "\t";
            i++;
        }
        i = 1;
        cout << endl << endl << i << "\t";
        for(int i = 0; i<p; i++){
            for(int j = 0; j<p; j++){
                cout<<matriz[i][j]<<"\t";
            }
            if (i+2 <= p){
                cout<<"\n" << i+2 <<"\t";
            }
        }
        cout << endl;
    } 
};

bool saltosk(Grafo g,int a, int b, int k){
    vector<int> v;
    if (g.saltos(a, b, v) <= k){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    Grafo g = Grafo(6);
    vector<int> v;
    g.addEnlace(1, 2, 3);
    g.addEnlace(1, 3, 2);
    g.addEnlace(1, 5, 3);
    g.addEnlace(3, 4, 2);
    g.addEnlace(4, 6, 2);
    g.addEnlace(5, 6, 5);
    g.addEnlace(2, 6, 5);
    g.addEnlace(6, 2, 5);    
    g.addEnlace(2, 4, 5);
    g.addEnlace(4, 2, 5);
   
    g.print(6);
    cout<<endl<<"el num de saltos es: "<<g.saltos(5, 4, v)<<endl;
    cout<<endl<<saltosk(g, 5, 4, 2);
    return 0;
}

