#include<iostream>
using namespace std;
template<class T>class Celula{
public:
    Celula<T>*prox;
    T item;
    Celula(){
        prox=NULL;
    }
};
template<class T>class Fila{
private:
    Celula<T>*inicio,*fim;
    int tam;
public:
    Fila(){
        inicio=new Celula<T>;
        fim=inicio;
    }
    bool vazia(){
        return inicio==fim;
    }
    void enfileira(T item){
        fim->prox = new Celula<T>;
        fim = fim->prox;
        fim->item = item;
        tam++;
    }
    void desenfileira(){
        if(!vazia()){
            Celula<T>*aux=inicio->prox;
            inicio=aux;
            cout<<aux->item;
            delete aux;
            tam--;
        }
        else cout<< "Lista vazia.";
    }
};
int main(){
    Fila<int>x;
    int y;
    while(true){
        cout<<"0-sair\t 1-inserir\t 2-retirar: "; cin>>y;
        if(y==0) break;
        else if(y==1){
            cout<<"valor a enfileirar: "; cin>>y;
            x.enfileira(y);
        }
        else if(y==2) x.desenfileira();
        cout<<endl;
    }
}
