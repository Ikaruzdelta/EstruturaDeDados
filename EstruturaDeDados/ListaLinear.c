/*
#include <stdio.h>
#include <stdlib.h>

int maximo = 30;
int quantidade = 0;

//Função que cria dinamicamente uma lista vazia
int* criaLista()
{
    int *lista;

    lista = (int*) malloc(maximo * sizeof(int));

    if(lista)
        return lista;
    else
    {
        printf("\nAconteceu algum problema. A lista nao foi alocada.");
        exit(1);
    }
}

//Função que faz a inserção de um elemento em uma lista não ordenada
int insereNaoOrd(int *lista)
{
    if(quantidade < maximo)
    {
        printf("\nDigite um inteiro:");
        scanf("%d",&lista[quantidade++]);
        return 1;
    }
    return 0;
}

//Função que faz inserção ordenada de elemento em lista ordenada
int insereOrdenado(int *lista)
{
    int elemento, x = quantidade-1;
    if(quantidade < maximo)
    {
        printf("Digite o elemento:");
        scanf("%d",&elemento);
        while(elemento < lista[x] && x>=0)
        {
            lista[x+1] = lista[x];
            x--;
        };
        lista[x+1] = elemento;
        quantidade++;
        return 1;
    }
    else
        return 0;
}

//Função que exibe a lista
void mostraLista(int *lista)
{
    for(int x=0; x<quantidade; x++)
    {
        printf("%5d",lista[x]);
    }
}

//Função que faz pesquisa sequencial em lista não ordenada retornando o índice do elemento e
  -1 caso o elemento não seja encontrado
int pesqSequencial(int *lista, int chave)
{
    for(int x=0; x<quantidade; x++)
        if(chave == lista[x])
            return x;
    return -1;
}

//Função que faz remoção de lista ordenada
int removeOrdenado(int *lista, int chave)
{
    int resp;
    resp = pesqSequencial(lista, chave);
    if(resp != -1)
    {
        for(int x = resp; x < quantidade-1; x++)
            lista[x] = lista[x+1];
        quantidade--;
        return 1;
    }
    else
        return 0;
}

//Função que faz pesquisa binária - Obs: Só funciona em lista ordenada
int pesqBinaria(int *lista, int chave)
{
    int inicio = 0, fim = quantidade-1, meio;
    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;
        if(chave == lista[meio])
            return meio;
        else
        {
            if(chave < lista[meio])
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
    }
    return -1;
}

//Função que faz a remoção de um valor de uma lista não ordenada, caso o valor a ser removido
//não seja encontrado a função retorna 0

int removeNaoOrd(int *lista, int chave)
{
    int aux;
    aux = pesqSequencial(lista, chave);
    if(aux != -1)
    {
        lista[aux] = lista[quantidade - 1];
        quantidade--;
        return 1;
    }
    return 0;
}

void main()
{
    int* vetor;
    int op, aux, resp;
    vetor = criaLista();
    do
    {
        printf("\nEscolha uma opcao:");
        printf("\n1 - Insere elemento em lista nao ordenada");
        printf("\n2 - Pesquisa elemento em lista nao ordenada");
        printf("\n3 - Remocao nao ordenada");
        printf("\n4 - Insere elemento em lista ordenada");
        printf("\n5 - Remove ordenado");
        printf("\n6 - Pesquisa binaria");
        printf("\n7 - Exibe elementos da lista");
        printf("\n0 - Sair do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insereNaoOrd(vetor);
            break;
        case 2:
            printf("\nDigite o elemento a ser buscado:");
            scanf("%d",&aux);
            resp = pesqSequencial(vetor, aux);
            if(resp != -1)
                printf("\nElemento encontrado na posicao %d",resp);
            else
                printf("\nElemento nao encontrado");
            break;
        case 3:
            printf("\nDigite o elemento a ser removido:");
            scanf("%d",&aux);
            resp = removeNaoOrd(vetor, aux);
            if(resp)
                printf("\nRemocao realizada");
            else
                printf("\nRemocao nao realizada");
            break;
        case 4:
            insereOrdenado(vetor);
            break;
        case 5:
            printf("\nDigite o elemento a ser removido:");
            scanf("%d",&aux);
            resp = removeOrdenado(vetor, aux);
            if(resp)
                printf("\nRemocao realizada");
            else
                printf("\nRemocao nao realizada");
            break;
        case 6:
            printf("\nDigite o elemento a ser buscado:");
            scanf("%d",&aux);
            resp = pesqBinaria(vetor, aux);
            if(resp != -1)
                printf("\nElemento encontrado na posicao %d",resp);
            else
                printf("\nElemento nao encontrado");
            break;
        case 7:
            mostraLista(vetor);
            break;
        case 0:
            printf("\nEncerrando programa.");
            break;
        default:
            printf("\nOpcao invalida!");
        }
    }
    while(op != 0);
    free(vetor);
}
*/
