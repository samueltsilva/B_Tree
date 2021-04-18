#include <iostream>
#include "NoArvoreB.h"
#include "Arvore.h"
#include <Locale.h>

using namespace std;

int main()
{
    int t;
    int aux2;
    int k;

    cout << "Enter the minimum degree of the tree: " << endl;
    cin >> t;
    Arvore_B arvore(t);
    cout << "Tree successfully built!" << endl;

    do {
        cout << "Enter a number to insert: " << endl;
        cin >> aux2;
        arvore.inserir(aux2);
        cout << "Wanna insert more? \n 1 - Yes 2 - No" << endl;
        cin >> aux2;
    } while (aux2 == 1);


    cout << "Showing the values stored in the tree in ascending order: " << endl;
    arvore.percorrer();

    cout << "\nWhat value do you want to look for?? " << endl;
    cin >> k;

    if (arvore.procurar(k) == NULL) {
        cout << "Value not found." << endl;


    }
    else
        cout << k << "The value is in the tree!" << endl;


    cout << "What value do you want to remove?" << endl;
    cin >> aux2;

    arvore.remover(aux2);

    arvore.percorrer();


    return 0;
}