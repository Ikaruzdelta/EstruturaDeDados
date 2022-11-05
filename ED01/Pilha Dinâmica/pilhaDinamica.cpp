#include <iostream>
#include "pilhaDinamica.h"
#include <cstddef> //Null

using namespace std;

pilhaDinamica::pilhaDinamica()
{
    noTopo == NULL;
}
pilhaDinamica::~pilhaDinamica()
{
    no* noTemp;
    while (noTopo != NULL)
    {
        noTemp = noTopo;
        noTopo = noTopo->proximo;
        delete noTemp;
    }
}
bool pilhaDinamica::estacheia()
{
    no* noNovo;
    try
    {
        noNovo = new no;
        delete noNovo;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
bool pilhaDinamica::estavazia()
{
    return(noTopo == NULL);
}
void pilhaDinamica::inserir(TipoItem item)
{
    if (estacheia())
    {
        cout << "A pilha esta cheia!\n";
        cout << "Não é possivel inserir este elemento!\n";
    }
    else
    {
        no* noNovo = new no;
        noNovo -> valor = item;
        noNovo -> proximo = noTopo;
        noTopo = noNovo;
    }
}
TipoItem pilhaDinamica::remover()
{
    if (estavazia())
    {
        cout << "A pilha esta vazia!\n";
        cout << "Não tem elemento para ser removido!\n";
        return 0;
    }
    else
    {
        no* noTemp;
        noTemp = noTopo;
        TipoItem item = noTopo->valor;
        noTopo = noTopo->proximo;
        delete noTemp;
        return item;
    }
}
void pilhaDinamica::imprimir()
{
    no* noTemp = noTopo;
    cout << "Pilha: [ ";
    while ((noTemp != NULL))
    {
        cout << noTemp->valor << " ";
        noTemp = noTemp->proximo;
    }
    cout << "]\n";
}