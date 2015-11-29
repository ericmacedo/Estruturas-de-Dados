#include<iostream>
using namespace std;
class Celula{
public:
    int item;
    Celula*prox,*ante;
    Celula(){
        prox=NULL;
        ante=NULL;
    }
};
class Lista{
public:
    Celula*inicio, *fim;
    Lista(){
        inicio=new Celula;
        fim=inicio;
    }
    void inserir(int item){
        if(!pesquisar(item)){
            fim->prox=new Celula;
            fim->prox->item=item;
            fim->prox->ante=fim;
            fim=fim->prox;
        }
    }
    bool vazia(){
        return fim==inicio;
    }
    void remover(int item){
        if(!vazia()){
            Celula*aux=inicio->prox;
            while(aux!=NULL){
                if(aux->item!=item){
                    aux=aux->prox;
                }
                else{
                    aux->ante->prox=aux->prox;
                    if(aux->prox!=NULL) aux->prox->ante=aux->ante;
                    delete aux;
                    break;
                }
            }
        }
        if(inicio->prox==NULL) fim=inicio;
    }
    bool pesquisar(int item){
        if(!vazia()){
            Celula*aux=inicio->prox;
            while(aux!=NULL){
                if(aux->item!=item){
                    aux=aux->prox;
                }
                else return true;
            }
        }
        return false;
    }
    void imprimir(){
        cout<<"< ";
        if(!vazia()){
            Celula*aux=inicio->prox;
            while(aux!=NULL){
                cout<<aux->item<<' ';
                aux=aux->prox;
            }
        }
        cout<<">";
    }
};
class Fila{
public:
    int*fila;
    int inicio,fim,tamanho;
    Fila(int num){
        fila=new int[num];
        inicio=0;
        fim=0;
        tamanho=num;
    }
    bool vazia(){
        return inicio==fim;
    }
    void enfileirar(int x){
        fila[fim]=x;
        fim=fim;
        fim=(fim+1)%tamanho;
    }
    int desenfileirar(){
        int aux;
        aux=fila[inicio];
        inicio=(inicio+1)%tamanho;
        return aux;
    }
};
class Grafo{
private:
    int numVertices;
    Lista*lista_adj;
public:
    Grafo(int num){
        numVertices=num;
        lista_adj=new Lista[num];
        for(int i=0;i<num;i++){
            lista_adj[i]=Lista();
        }
    }
    void inserirAresta(int v1, int v2){
        lista_adj[v1].inserir(v2);
        lista_adj[v2].inserir(v1);
    }
    void removerAresta(int v1, int v2){
        lista_adj[v1].remover(v2);
        lista_adj[v2].remover(v1);
    }
    bool existeAresta(int v1, int v2){
        return lista_adj[v1].pesquisar(v2);
    }
    void imprime(){ //IMPRIME AS LISTAS DE ADJACENCIA
        for(int i=0;i<numVertices;i++){
            lista_adj[i].imprimir();
            cout<<endl;
        }
    }

    void buscaLargura(int x){
        int estado[numVertices];
        int distancia[numVertices];
        for(int i=0;i<numVertices;i++){
            estado[i]=0;
            distancia[i]=0; // A DISTANCIA ZERO E PADRAO, ENTAO SE UM VERTICE FOR INCALCANSAVEL, ELE TERA DISTANCIA ZERO
        }
        Fila fila(numVertices);
        fila.enfileirar(x);
        estado[x]=1;
        int pos;
        while(!fila.vazia()){
            pos=fila.desenfileirar();
            Celula*aux=(lista_adj[pos]).inicio;
            aux=aux->prox;
            while(aux!=NULL){
                if(estado[aux->item]==0){
                    estado[aux->item]=1;
                    distancia[aux->item]=distancia[pos]+1;
                    fila.enfileirar(aux->item);
                }
                aux=aux->prox;
            }
        }
        for(int i=0;i<numVertices;i++){
            cout<<"Distancia do vertice "<<x<<" ao vertice "<<i<<": "<<distancia[i]<<endl;
        }
    }

};
