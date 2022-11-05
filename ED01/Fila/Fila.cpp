#include <iostream>
#include "fila.h"

using namespace std;

fila::fila()
{
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_intens];
}
fila::~fila()
{
    delete[] estrutura;
}
bool fila::estacheia()
{
    return (ultimo - primeiro == max_intens);
}
bool fila::estavazia()
{
    return (primeiro == ultimo);
}
void fila::inserir(TipoItem item)
{
    if (estacheia())
    {
        cout << "A fila esta cheia!\n";
        cout << "Este elemento não pode ser inserido!\n";
    }
    else
    {
        estrutura[ultimo % max_intens] = item;
        ultimo++;
    }
}
TipoItem fila::remover()
{
    if (estavazia())
    {
        cout << "A fila esta vazia!\n";
        cout << "Nenhum elemento foi removido!\n";
    }
    else
    {
        primeiro++;
        return estrutura[primeiro-1 % max_intens];
    }
}
void fila::imprimir()
{
    cout << "Fila: [ ";
    for (int i = primeiro; i<ultimo; i++)
    {
        cout << estrutura[i % max_intens] << " ";   
    }
    cout << "]\n";
}