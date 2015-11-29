#include<iostream>
using namespace std;
template<class T>class Pilha{
private:
    T *itens;
    int tam, topo;
public:
    Pilha(int tam1){
        topo=0;
        tam=tam1;
        itens=new T[tam];
    }
    void empilha(T item){
        if(topo==tam) cout<<"pilha cheia.";
        else{
            itens[topo]=item;
            topo++;
        }
    }
    T desempilha(){
        if(!vazia()){
            T temp=itens[--topo];
            return temp;
        }
        else cout<<"Pilha vazia.";
    }
    bool vazia(){
        return topo==0;
    }
    bool cheia(){
        return topo==tam;
    }
};
int main(){
    int tamanho;
    cout<<"tamanho da pilha: "; cin>>tamanho;
    Pilha<int>x(tamanho);
    int y;
    while(!x.cheia()){
        cout<<"valor: "; cin>>y;
        x.empilha(y);
    }
    while(!x.vazia()){
        cout<<x.desempilha()<<endl;
    }
}
