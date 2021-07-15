#include <iostream>
#include "FilaDinamica.h"

using namespace std;

int main()
{
    pilhaDinamica filha1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de filha: \n";
    do
    {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a pilha!\n";
        cout << "Qual opcao deseja: ";

        cin >> opcao;
        if (opcao == 1)
        {
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            filha1.inserir(item);
        }
        else if (opcao == 2)
        {
            item = filha1.remover();
            cout << "Elemento removido: " << item << endl;
        }
        else if (opcao == 3)
        {
            filha1.imprimir();
        }

    } while (opcao != 0);

    return 0;
}