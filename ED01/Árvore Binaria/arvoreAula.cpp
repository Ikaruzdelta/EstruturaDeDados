#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node *pai;
    struct node *filhoEsq;
    struct node *filhoDir;

} tipoNode;

tipoNode *achou;

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
    if (atual != NULL)
    {
        exibeInOrdem(atual->filhoEsq);
        printf("%8d", atual->dado);
        exibeInOrdem(atual->filhoDir);
    }
}

void buscaNo(tipoNode *atual, int n)
{
    if (atual != NULL)
    {
        if (atual->dado == n)
        {
            achou = atual;
            return;
        }
        buscaNo(atual->filhoEsq, n);
        buscaNo(atual->filhoDir, n);
    }
}

int temFilhoEsq(tipoNode *no)
{
    if (no->filhoEsq != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int temFilhoDir(tipoNode *no)
{
    if (no->filhoDir != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserNo(tipoNode *pai, int n, char tipoFilho)
{
    tipoNode *novo;
    if (tipoFilho == 'e')
    {
        if (temFilhoEsq(pai))
        {
            printf("\nImpossivel Inserir! No ja tem filho na Esquerda");
            return 0;
        }
        else
        {
            pai->filhoEsq = criaNo(n);
            return 1;
        }
    }
    else
    {
        if (temFilhoDir(pai))
        {
            printf("\nImpossivel Inserir! No ja tem filho na Direita");
            return 0;
        }
        else
        {
            pai->filhoDir = criaNo(n);
            return 1;
        }
    }
}

int main()
{
    tipoNode *raiz = NULL;
    int op, valor, valorpai;
    char esqOrDir;
    do
    {
        printf("\nEsolha sua opcao:");
        printf("\n1- Insere um no na arvore");
        printf("\n2- Exibe a arvore em ordem simetrica");
        printf("\n0- Encerra o programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n Digite o dado que deseja inserir na arvore: ");
            scanf("%d", &valor);
            if (raiz == NULL) //É o primeiro da arvore
            {
                raiz = criaNo(valor);
            }
            else
            {
                printf("\nDigite o pai do no: ");
                scanf("%d", &valorpai);
                achou = NULL;
                buscaNo(raiz, valorpai);
                if (achou == NULL)
                {
                    printf("\nNão achei o Pai!");
                }
                else
                {
                    fflush(stdin);
                    printf("\nDigite se o seu filho sera da esquerda <e> ou Direita <d>: ");
                    scanf("%c", &esqOrDir);
                    inserNo(achou, valor, esqOrDir);
                    if (inserNo(achou, valor, esqOrDir))
                    {
                        printf("\nNo inserido com sucesso!");
                    }
                }
            }
            break;
        case 2:
            exibeInOrdem(raiz);
            break;
        case 0:
            printf("\nEncerrando programa...");
            break;
        }
    } while (op != 0);
}