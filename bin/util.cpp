#include <iostream>
#include "util.h"

using namespace std;

/* Funcão que tem como propósito percorrer uma matriz de adjacência de ordem n
 * e setar todos os seus elementos com o valor zero.
 */
void createAdjMatrix(adjMatrix *matriz, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            matriz->v[i][j].type = '0';
            matriz->v[i][j].value = 0;
        }
    }
}
/*
 * Esta função adiciona um componente, ou seja, um elemento de circuito como já foi definido na modelagem do
 * problema, à matriz de adjacência.
 */
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2){
    matriz->v[n1][n2].type = type;
    matriz->v[n1][n2].value = value;
    //não faz sentido colacar um if para o caso de n1 == n2, pois não faz sentido ligar
    //um nó nele mesmo!
    matriz->v[n2][n1].type = type;
    matriz->v[n2][n1].value = value;
}
/*
 * Esta função percorre a matriz de adjacência e exibe todos os seus elementos.
 * Para o caso do grafo modelar um circuito, ela exibe o tipo do elemento e seu valor.
 */
void printMatrix(adjMatrix *matriz, int nodes){
    cout<<"Print Matriz de Adjacencia"<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(matriz->v[i][j].type == '0'){
                cout<<"  0  ";
                cout<<" ";
            }
            else{
                cout<<"["<<matriz->v[i][j].type<<","<<matriz->v[i][j].value<<"] ";
            }
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
}

void criar_lista(Lista *lista_adjacencia, int tamanho) {
    lista_adjacencia->tamanho = tamanho;

    for (int i=0; i<tamanho; i++) {
        lista_adjacencia->lista[i].type = '0';
        lista_adjacencia->lista[i].valor = 0.0;
        lista_adjacencia->lista[i].proximo_no = nullptr;
    }
}

void inserir_ligacao(Lista *lista_adjacencia, char type, int valor, int n1, int n2) {
    No* novo_no = new No();
    novo_no->indice = n2;
    novo_no->type = type;
    novo_no->valor = valor;
    novo_no->proximo_no = nullptr;

    novo_no->proximo_no = lista_adjacencia->lista[n1].proximo_no;
    lista_adjacencia->lista[n1].proximo_no = novo_no;
}

void print_lista(Lista *lista_adjacencia){
    cout<<"Print Lista de Adjacencia"<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<lista_adjacencia->tamanho; i++){
        cout<<"["<<lista_adjacencia->lista[i].type<<","<<lista_adjacencia->lista[i].valor<<"]";
        No *aux = new No();
        aux = &lista_adjacencia->lista[i];
        while(aux->proximo_no != nullptr){
            cout<<" -> ["<<aux->proximo_no->type<<","<<aux->proximo_no->valor<<"]";
            aux = aux->proximo_no;
        }
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
}
