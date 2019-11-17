#include <iostream>
#include "util.h"
#include "parser.h"

using namespace std;

int main()
{
    //int n = 8;
    adjMatrix *matriz = new adjMatrix();

    Parser leitor_dados(matriz);
    leitor_dados.tratamento("instrucoes-12n");
    int n = leitor_dados.getNodes();


    //ISSO AQUI NÃO VAI EXISTIR 3.34 3.46
//    createAdjMatrix(matriz, n);
//    addComponente(matriz, 'V',  10.0, 0, 1);
//    addComponente(matriz, 'W',  0.0, 1, 2);
//    addComponente(matriz, 'R',  3.0, 2, 3);
//    addComponente(matriz, 'W',  0.0, 3, 0);
//    addComponente(matriz, 'R',  4.0, 2, 4);
//    addComponente(matriz, 'W',  0.0, 3, 5);
//    addComponente(matriz, 'R',  6.0, 4, 5);
//    addComponente(matriz, 'W',  0.0, 4, 6);
//    addComponente(matriz, 'R',  2.0, 6, 7);
//    addComponente(matriz, 'W',  0.0, 7, 5);
    //ISSO AQUI NÃO VAI EXISTIR */


    adjMatrix *B = new adjMatrix();
    adjMatrix *C = new adjMatrix();

    adjMatrix D[n];
    createAdjMatrix(B, n);
    createAdjMatrix(C, n);
    int k=0;

    k=findFundamentalcycles(matriz, B, C, D, n);

    float matrizResistencia[MAX][MAX];
    float arrayVoltagem[MAX];
    montarMatrizCircuito(D, k, n, matrizResistencia, arrayVoltagem);

    float x[MAX] = {0};

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cout<<matrizResistencia[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int j=0; j<k; j++){
        cout<<arrayVoltagem[j]<<", ";
    }
    cout<<endl;


    resolverSistema(matrizResistencia, arrayVoltagem, k, x);

    cout<<endl<<"Vetor de resultados:"<<endl;
    for(int i=0; i<k; i++){
        cout<<"| I"<<i<<" ";
    }
    cout<<" |"<<endl;
    for(int i=0; i<k; i++){
        cout<<"| "<<x[i]<<" ";
    }
    cout<<" |";
    cout<<endl;
    cout<<endl;


    cout<<"MATRIZ A: "<<endl;
    printMatrix(matriz, n);
    cout<<"MATRIZ B: "<<endl;
    printMatrix(B, n);
    cout<<"MATRIZ C: "<<endl;
    printMatrix(C, n);

    for(int i=0; i<k; i++){
        cout<<"MATRIZ D["<<i<<"]: "<<endl;
        printMatrix(&D[i], n);
    }

    cout<<endl;
    cout<<endl;

//    adjMatrix *spanningTree = new adjMatrix();
//    findSpanningTree(matriz, spanningTree, n);
//    printMatrix(spanningTree, n);
//    cout<<endl;
//    n = 4;
//    Lista *listaajd = new Lista();
//    criar_lista(listaajd, n);
//    inserir_ligacao(listaajd, 'R', 2.0, 0, 1);
//    inserir_ligacao(listaajd, 'I', 1.0, 1, 3);
//    inserir_ligacao(listaajd, 'R', 1.0, 1, 2);
//    inserir_ligacao(listaajd, 'W', 0.0, 0, 2);
//    inserir_ligacao(listaajd, 'W', 0.0, 2, 3);
//    print_lista(listaajd);

    return 0;
}

