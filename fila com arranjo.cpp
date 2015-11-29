#include<iostream>
using namespace std;
template<class T>class Fila{
private:
    T*itens;
    int tam;
    T inicio,fim;
public:
    Fila(int tamanho){
        tam=tamanho;
        itens=new T[tam];
        inicio=0;
        fim=inicio;
    }
    bool vazia(){
        return inicio==fim;
    }
    void enfileira(T item){
        if((fim+1)%tam==inicio) cout<<"Fila cheia.";
        else{
            itens[fim]=item;
            fim=(fim+1)%tam;
        }
    }
    void desenfileira(){
        if(!vazia()){
            T temp=itens[inicio];
            inicio=(inicio+1)%tam;
            cout << temp;
        }
        else cout<< "Lista vazia.";
    }
};
int main(){
    int y;
    cout<<"tamanho: "; cin>>y;
    Fila<int>x(y+1);
    while(true){
        cout<<"0-sair\t1-inserir\t2-retirar: "; cin>>y;
        if(y==0) break;
        else if(y==1){
            cout<<"valor a enfileirar: "; cin>>y;
            x.enfileira(y);
        }
        else if(y==2) x.desenfileira();
        cout<<endl;
    }
}
