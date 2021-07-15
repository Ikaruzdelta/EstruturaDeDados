#include <iostream>
#include "filaDinamica.h"

using namespace std;

filaDinamica::fila()
{
    primeiro = NULL;
    ultimo = NULL;
}
filaDinamica::~fila()
{
    no* temp;
    while(primeiro != NULL)
    {
        temp = primeiro;
        primeiro = primeiro->proximo;
        delete temp;
    }
    ultimo = NULL;
}
bool filaDinamica::estacheia()
{
    no* temp;
    try
    {
        temp = new no;
        delete temp;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
bool filaDinamica::estavazia()
{
    return (primeiro == NULL);
}
void filaDinamica::inserir(TipoItem item)
{
    if (estacheia())
    {
        cout << "A fila esta cheia!\n";
        cout << "Este elemento não pode ser inserido!\n";
    }
    else
    {
        no* noNovo = new no;
        noNovo -> valor = item;
        noNovo -> proximo = NULL;
        if(primeiro == NULL)
        {
            primeiro = noNovo;
        }
        else
        {
            ultimo->proximo = noNovo;
        }
        ultimo = noNovo;
    }
}
TipoItem filaDinamica::remover()
{
    if (estavazia())
    {
        cout << "A fila esta vazia!\n";
        cout << "Nenhum elemento foi removido!\n";
        return 0;
    }
    else
    {
        no* temp = primeiro;
        TipoItem item = primeiro->valor;
        primeiro = primeiro->proximo;
        if(primeiro == NULL)
        {
            ultimo = NULL;
        }
        delete temp;
        return item;
    }
}
void filaDinamica::imprimir()
{
    no* temp;
    cout << "Fila [ ";
    while (temp != NULL)
    {
        cout << temp->valor << " ";
        temp = temp->proximo;
    }
    cout << " ]\n";
}