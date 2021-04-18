#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include "NoArvoreB.h"


using namespace std;

//Classe da árvore
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

//Função primária de inserção. Ela que chama os métodos auxiliares em NoArvoreB.h para inserir
//um valor e tratar a árvore
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
            raiz->insert_non_full(k); //Se a raiz não está vazia nem cheia, somente insira o valor

    }




}


//Função primária de remoção. Recebe a chave que precisa ser removida e acessa as métodos em NoArvoreB.h
//para remover e tratar a árvore
void Arvore_B::remover(int k) {
    if (!raiz) { //se não existe raiz, a árvore está vazia e não há nada a ser removido
        cout << "Não é possível remover pois a árvore está vazia\n";
        return;
    }

    raiz->remover(k); //início da recursão para remover a chave

    if (raiz->getN() == 0) { //se o número de chaves da raiz for 0
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
