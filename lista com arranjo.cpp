#include<iostream>
using namespace std;

template<class T>class Lista{
private:
    T *itens;
    int ultimo, tam;
public:
    Lista(int tam1){
        tam=tam1;
        itens=new T[tam1];
        ultimo=0;
    }
    bool vazia(){
        return ultimo==0;
    }
    bool cheia(){
        return ultimo==tam;
    }
    void imprime(){
        if(!vazia()){
            for(int i =0;i<ultimo;i++) cout<<itens[i]<<' ';
        }
        else cout<<"Lista vazia.";
    }
    void insere(T item){
        if(!cheia()){
            itens[ultimo]=item;
            ultimo++;
        }
        else cout<<"Lista cheia.\n";
    }
    void insere(T item, int pos){
        if(!cheia()){
            for(int i=ultimo-1;i>=pos;i--) itens[i+1]=itens[i];
            itens[pos]=item;
            ultimo++;
        }
        else cout<<"Lista cheia.\n";
    }
    int pesquisa(T item){
        for(int i=0;i<ultimo;i++){
            if(itens[i]==item) return i;
        }
        return -1;
    }
    T remover(int pos){
        if(pos<ultimo){
            T aux=itens[pos];
            for(int i=pos;i<ultimo;i++){
                itens[i]=itens[i+1];
            }
            ultimo--;
            return aux;
        }
        return 0;
    }
};
int main(){
    int y,z;
    cout<<"tamanho da lista: "; cin>>y;
    Lista<int>x(y);
    while(true){
        cout<<"0-sair\t 1-inserir\t 2-inserir em determinada posicao\t 3-pesquisar\t 4-remover em determinada posicao: ";cin>>y;
        if(y==0) break;
        else if(y==1){
            cout<<"item a inserir: "; cin>>y;
            x.insere(y);
        }
        else if(y==2){
            cout<<"Item a inserir: "; cin>>y;
            cout<<"Posicao a ser inserido: "; cin>>z;
            x.insere(y,z);
        }
        else if(y==3){
            cout<<"item a ser pesquisado: "; cin>>y;
            cout<<x.pesquisa(y)<<endl;
        }
        else if(y==4){
            cout<<"Posicao a ser removida: "; cin>>y;
            x.remover(y);
        }
    }
    x.imprime();
}
