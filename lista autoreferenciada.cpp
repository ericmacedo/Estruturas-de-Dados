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
template<class T>class Lista{
private:
    Celula<T>*primeiro,*ultimo;
public:
    Lista(){
        primeiro=new Celula<T>;
        ultimo=primeiro;
    }
    bool vazia(){
        return primeiro==ultimo;
    }
    void insere(T item){
        ultimo->prox=new Celula<T>;
        ultimo=ultimo->prox;
        ultimo->item=item;
    }
    void insere(T item, int pos){
        Celula<T>*aux=primeiro->prox;
        for(int i=0;i<pos;i++) aux=aux->prox;
        Celula<T>*aux1=new Celula<T>;
        aux1->item=item;
        aux1->prox=aux->prox;
        aux->prox=aux1;
    }
    T pesquisa(T item){
        Celula<T>*aux=primeiro->prox;
        while(aux!=NULL){
            if(aux->item==item) return aux->item;
            else aux=aux->prox;
        }
    }
    void imprime(){
        if(!vazia()){
            Celula<T>*aux=primeiro->prox;
            cout<<endl;
            while(aux!=NULL){
                cout<<aux->item<<' ';
                aux=aux->prox;
            }
        }
        else cout<<"Lista vazia.\n";
    }
    T remover(int pos){
        T item1;
        if(!vazia()){
            Celula<T>*aux=primeiro;
            for(int i=0;i<pos;i++){
                if(aux==NULL){cout<<"fora do alcance."; return -1;}
                aux=aux->prox;
            }
            Celula<T>*aux1=aux->prox;
            item1=aux1->item;
            aux->prox=aux1->prox;
            delete aux1;
        }
        return item1;
    }
};
int main(){
    int y,z;
    Lista<int>x;
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
            cout<<"item removido: "<<x.remover(y);
        }
        cout<<endl;
    }
    x.imprime();
}
