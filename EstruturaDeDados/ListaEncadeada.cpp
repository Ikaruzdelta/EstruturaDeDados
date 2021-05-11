#include <stdio.h>
#include <stdlib.h>

/*Implementação de lista encadeada feita em sala*/

/*Estrutura que representa um nó da lista*/
typedef struct no{
int dado;
struct no *proxNo;
}tipoNo;

/*Estrutura que guarda as informações de uma lista encadeada*/
typedef struct listaGerenciada{
tipoNo *inicio;
tipoNo *fim;
int quant;
}tipoLista;

/*Função que faz a inicialização da lista encadeada*/
void inicializa(tipoLista *listaEnc){
    listaEnc->inicio = NULL;
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
}

/*Função que faz a inserção de um nó em uma lista vazia*/
int insereListaVazia(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
novoNo = (tipoNo*) malloc(sizeof(tipoNo));
if(novoNo == NULL)
    return 0;
novoNo->dado = valor;
novoNo->proxNo = NULL;
listaEnc->inicio = novoNo;
listaEnc->fim = novoNo;
listaEnc->quant++;
return 1;
}


/*Função que percorre a lista exibindo todos os seus dados*/
void exibeLista(tipoLista *listaEnc){
tipoNo *atual;  /*Variável que será usada para percorrer a lista*/
atual = listaEnc->inicio;
printf("\nLista encadeada: ");
while(atual !=NULL){
    printf("%8d",atual->dado);
    atual = atual->proxNo;
}
}

/*Função que insere um nó na frente de uma lista encadeada*/
int insereNaFrente(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->inicio==NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado=valor;
    novoNo->proxNo=listaEnc->inicio;
    listaEnc->inicio=novoNo;
    listaEnc->quant++;
    return 1;
}
}

/*Função para inserir elemento no fim da lista encadeada*/
int insereNoFim(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->inicio == NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*) malloc(sizeof(novoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado=valor;
    novoNo->proxNo=NULL;
    listaEnc->fim->proxNo = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
}
}

/*Função que remove primeiro elemento da lista encadeada*/
void removeDaFrente(tipoLista *listaEnc){
tipoNo *aux;
aux = listaEnc->inicio;
listaEnc->inicio = listaEnc->inicio->proxNo;
if(listaEnc->quant == 1)
    listaEnc->fim = NULL;
listaEnc->quant--;
free(aux);
}

void main(){
    tipoLista lista;
    int aux, op;
    inicializa(&lista);
    do{
        printf("\nMenu\n1 - Insere em lista vazia");
        printf("\n2 - Insere na frente\n3 - Insere no fim");
        printf("\n4 - Remove da frente");
        printf("\n9 - Exibe a lista");
        printf("\n0 - Sai do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereListaVazia(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\ninsercao nao efetuada.");
            break;
        case 2: printf("\nDigite outro numero inteiro:");
            scanf("%d",&aux);
            if(insereNaFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 3: printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereNoFim(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nDado nao inserido");
            break;
        case 4: removeDaFrente(&lista);
            break;
        case 9: exibeLista(&lista);
            break;
        case 0: printf("\nEncerrando programa");
            break;
        default: printf("\nOpcao invalida!");
        }
    }while(op != 0);

    return 0;
}
