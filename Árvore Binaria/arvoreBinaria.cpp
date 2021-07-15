#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node *pai;
    struct node *filhoEsq;
    struct node *filhoDir;

} tipoNode;

tipoNode *criaNo(int n)
{
    tipoNode *novo;
    novo = (tipoNode *)malloc(sizeof(tipoNode));
    novo->dado = n;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}

void exibeInOrdem(tipoNode *atual)
{
    if(atual != NULL)
    {
        exibeInOrdem(atual->filhoEsq);
        printf("%8d", atual->dado);
        exibeInOrdem(atual->filhoDir);
    }
}

int main()
{
    tipoNode *raiz;
    raiz = criaNo(10);
    raiz->filhoEsq = criaNo(5);
    raiz->filhoDir = criaNo(12);
    raiz->filhoEsq->filhoDir = criaNo(7);
    exibeInOrdem(raiz);
}