#include<iostream>
using namespace std;
template<class T>class Celula{
public:
    T item;
    Celula<T>*prox;
    Celula(){
        prox=NULL;
    }
};
template<class T>class Pilha{
private:
    Celula<T>*topo;
    int tam;
public:
    Pilha(){
        topo=NULL;
        tam=0;
    }
    void empilha(T item){
        Celula<T>*aux=topo;
        topo=new Celula<T>;
        topo->item=item;
        topo->prox=aux;
        tam++;
    }
    T desempilha(){
        if(!vazia()){
            Celula<T>*aux=topo;
            topo=topo->prox;
            return aux->item;
        }
        else cout<<"Pilha vazia.";
    }
    bool vazia(){
        return topo==NULL;
    }
};
int main(){
    Pilha<int>x;
    int y;
    while(true){
        cout<<"valor ou 0: "; cin>>y;
        if(y==0) break;
        x.empilha(y);
    }
    while(!x.vazia()){
        cout<<x.desempilha()<<endl;
    }
}
