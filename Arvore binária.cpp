#include <iostream>
using namespace std;
template<class T>class No{
public:
    T item;
    No<T>*esq, *dir;
    No(T item1){
        item=item1;
        esq=NULL;
        dir=NULL;
    }
};
template<class T>class Celula{
public:
    No<T>*no;
    Celula<T>*prox;
    Celula(){
        prox=NULL;
    }
};
template<class T>class Fila{
public:
    Celula<T>*inicio,*fim;
    Fila(){
        inicio=new Celula<T>;
        fim=inicio;
    }
    void Enfileira(No<T>*no){
        fim->prox=new Celula<T>;
        fim=fim->prox;
        fim->no=no;
    }
    bool Vazia(){
        return inicio==fim;
    }
    No<T>*Desenfileira(){
        if(!Vazia()){
            No<T>*aux=inicio->prox->no;
            inicio=inicio->prox;
            return aux;
        }
    }
};
template<class T>class ArvoreBin{

public:
    No<T>*raiz;
    ArvoreBin(){
        raiz=NULL;
    }
   /* No<T>*getRaiz(){
        return *&raiz;
    } */
    void Inserir(No<T>*& no , T item){
        if(no==NULL){
            no=new No<T>(item);
        }
        else{
            if(no->item > item) Inserir(no->dir, item);
            else if(no->item < item) Inserir(no->esq, item);
        }
    }
    bool Vazia(){
        return raiz==NULL;
    }
    No<T>*Buscar(No<T>*no, T item){
        if(no!=NULL){
            if(no->item==item) return no;
            else if(no->item > item) Buscar(no->dir,item);
            else if(no->item < item) Buscar(no->esq,item);
            else return NULL;
        }
    }
    void Substituir(No<T>*no1,No<T>*no2){
        if(no2->dir!=NULL) Substituir(no1, no2->dir);
        else{
            no1->item=no2->item;
            no2=no2->esq;
        }
    }
    void Remover(No<T>*no, T item){
        if(no!=NULL){
            if(item < no->item) Remover(no->esq, item);
            else if(item > no->item) Remover(no->dir, item);
            else{
                if(no->esq==NULL && no->dir!=NULL){
                    no->item=no->dir->item;
                    delete no->dir;
                    no->dir=NULL;
                }
                else if(no->dir==NULL && no->esq!=NULL){
                    no->item=no->esq->item;
                    delete no->esq;
                    no->esq=NULL;
                }
                else if(no->dir!=NULL && no->esq!=NULL) Substituir(no, no->esq);
            }
        }
        else cout<<"nao encontrado\n";
    }
    void PercorrerOrdem(No<T>*no){
        if(no!=NULL){
            PercorrerOrdem(no->dir);
            cout<<no->item<<' ';
            PercorrerOrdem(no->esq);
        }
    }
    void PercorrerPre(No<T>*no){
        if(no!=NULL){
            cout<<no->item<<' ';
            PercorrerPre(no->dir);
            PercorrerPre(no->esq);
        }
    }
    void PercorrerPos(No<T>*no){
        if(no!=NULL){
            PercorrerPre(no->dir);
            PercorrerPre(no->esq);
            cout<<no->item<<' ';
        }
    }
    void PercorrerNivel(No<T>*no){
        if(no!=NULL){
            Fila<T>nos;
            nos.Enfileira(no);
            while(!nos.Vazia()){
                No<T>*aux=nos.Desenfileira();
                cout<<aux->item<<' ';
                if(aux->dir!=NULL) nos.Enfileira(aux->dir);
                if(aux->esq!=NULL) nos.Enfileira(aux->esq);
            }
        }
    }
};
int main(){
    ArvoreBin<int>x;
    int y;
    while(true){
        cout<<"Um valor ou 0: "; cin>>y;
        if(y==0) break;
        else x.Inserir(x.raiz, y);
    }
    x.PercorrerOrdem(x.raiz);
    while(!x.Vazia()){
        cout<<"\nvalor a excluir, ou 0: ";cin>>y;
        if(y==0) break;
        x.Remover(x.raiz, y);
        x.PercorrerNivel(x.raiz);
        cout<<endl;
    }
    cout<<"por ordem: "; x.PercorrerOrdem(x.raiz); cout<<endl;
    cout<<"por pos  : "; x.PercorrerPos(x.raiz); cout<<endl;
    cout<<"por pre  : "; x.PercorrerPre(x.raiz); cout<<endl;
    cout<<"por nivel: "; x.PercorrerNivel(x.raiz); cout<<endl;
}
