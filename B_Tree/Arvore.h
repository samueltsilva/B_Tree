#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include "NoArvoreB.h"

using namespace std;

//Classe da �rvore
class Arvore_B {
private:
    No_Arvore_B* raiz;
    int t;

public:
    Arvore_B(int _k);
    void percorrer();
    No_Arvore_B* procurar(int k);
    void inserir(int k);
    void remover(int k);

};

Arvore_B::Arvore_B(int _t) {
    raiz = NULL;
    t = _t;

}

void Arvore_B::percorrer() {
    if (raiz != NULL)
        raiz->percorrer();
}

No_Arvore_B* Arvore_B::procurar(int k) {
    return (raiz == NULL) ? NULL : raiz->procurar(k);
}

//Fun��o prim�ria de inser��o. Ela que chama os m�todos auxiliares em NoArvoreB.h para inserir
//um valor e tratar a �rvore
void Arvore_B::inserir(int k) {
    if (raiz == NULL) { //se a raiz estiver vazia, crie uma e insere.
        raiz = new No_Arvore_B(t, true);
        raiz->setChaves(0, k);
        raiz->setN(1);
    }
    else {
        if (raiz->getN() == (2 * t) - 1) { //se a raiz estiver cheia, divide, seta os filhos e insere
            No_Arvore_B* s = new No_Arvore_B(t, false);
            s->setC(0, raiz);
            s->split_child(0, raiz);
            int i = 0;
            if (s->getChaves(i) < k)
                i++;

            s->setC2(s, i, k);
            raiz = s;

        }
        else
            raiz->insert_non_full(k); //Se a raiz n�o est� vazia nem cheia, somente insira o valor

    }
}

//Fun��o prim�ria de remo��o. Recebe a chave que precisa ser removida e acessa as m�todos em NoArvoreB.h
//para remover e tratar a �rvore
void Arvore_B::remover(int k) {
    if (!raiz) { //se n�o existe raiz, a �rvore est� vazia e n�o h� nada a ser removido
        cout << "N�o � poss�vel remover pois a �rvore est� vazia\n";
        return;
    }

    raiz->remover(k); //in�cio da recurs�o para remover a chave

    if (raiz->getN() == 0) { //se o n�mero de chaves da raiz for 0
        No_Arvore_B* aux = raiz;
        if (raiz->getFolha())
            raiz = NULL;
        else
            raiz->setC(0, raiz);

        delete aux;

    }
    return;

}

#endif // ARVORE_H_INCLUDED