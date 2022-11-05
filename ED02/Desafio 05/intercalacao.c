//
// Created by Vanessa Braganholo.
// Updated by Raphael Oliveira.

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "intercalacao.h"
#include "nomes.h"
#include "cliente.h"
#include <limits.h>
#include <string.h>

typedef struct vetor{
    TCliente *cli;
    FILE *f;
}TVet;

/*
 * Definicao de tipo para no de arvore de vencedores
 */
typedef struct No {
    TCliente *vencedor;
    struct No *endVencedor;
    FILE *f;
    struct No *pai;
    struct No *dir;
    struct No *esq;
} TNo;

void intercalacao_basico(char *nome_arquivo_saida,  int num_p, Nomes *nome_particoes) {

    int fim = 0; //variavel que controla fim do procedimento
    FILE *out; //declara ponteiro para arquivo

    //abre arquivo de saida para escrita
    if ((out = fopen(nome_arquivo_saida, "wb")) == NULL) {
        printf("Erro ao abrir arquivo de saida\n");
    } else {
        //cria vetor de particoes
        TVet v[num_p];
        
        //abre arquivos das particoes, colocando variavel de arquivo no campo f do vetor
        //e primeiro cliente do arquivo no campo cli do vetor
        for (int i=0; i < num_p; i++) {
            v[i].f = fopen(nome_particoes->nome, "rb");
            if (v[i].f != NULL) {
                TCliente *c = le_cliente(v[i].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posicao do vetor
                    v[i].cli = cliente(INT_MAX, "");
                }
                else {
                    //conseguiu ler cliente, coloca na posicao atual do vetor
                    v[i].cli = c;
                }
            }
            else {
                fim = 1;
            }
            nome_particoes = nome_particoes->prox;
        }
        
        while (!(fim)) { //conseguiu abrir todos os arquivos
            int menor = INT_MAX;
            int pos_menor;
            //encontra o cliente com menor chave no vetor
            for(int i = 0; i < num_p; i++){
                if(v[i].cli->cod_cliente < menor){
                    menor = v[i].cli->cod_cliente;
                    pos_menor = i;
                }
            }
            if (menor == INT_MAX) {
                fim = 1; //terminou processamento
            }
            else {
                //salva cliente no arquivo de saida
                salva_cliente(v[pos_menor].cli, out);
                //atualiza posicao pos_menor do vetor com proximo cliente do arquivo
                TCliente *c = le_cliente(v[pos_menor].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posicao do vetor
                    v[pos_menor].cli = cliente(INT_MAX, "");
                }
                else {
                    v[pos_menor].cli = c;
                }
                
            }
        }
        
        //fecha arquivos das particoes de entrada
        for(int i = 0; i < num_p; i++){
            fclose(v[i].f);
        }
        //fecha arquivo de saida
        fclose(out);
    }
}

void intercalacao_arv_vencedores(char *nome_arquivo_saida, int num_p, Nomes *nome_particoes){
    //TODO: Implementar essa função 

}

Nomes *getItemPorPosicao(int posicao, Nomes *nome_particoes) {
    int cont = 1;
    Nomes *aux = nome_particoes;
    
    while (cont < posicao && aux != NULL)
    {
        aux = aux->prox;
        cont++;
    }
    return aux;
    
}

void criarNomeArquivo(int valor, char *saida){
    char numero[10];
    strcat(saida, "p");
    sprintf(numero, "%d", valor);
    strcat(saida, numero);
    strcat(saida, ".dat");
}

void pushNome(Nomes *lista, Nomes *novoValor) {
    Nomes *aux = lista;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novoValor;
    
}

void intercalacao_otima(char *nome_arquivo_saida, int num_p, Nomes *nome_particoes, int f) {
    int posicaoFinal = num_p; // Posicao fina recebe quantidade de arquivos
    int quantidadeDeArquivos = num_p; // Quantidade de arquivos
    char nome[10];
    Nomes *nomes = NULL;

    Nomes *aux;
    Nomes *auxRetorno;
    Nomes *retorno;
    int contador = 0;

    do{
        auxRetorno = NULL;
        retorno = NULL;
        memset(nome,0,10);
        contador = 0;
        
        aux = getItemPorPosicao(posicaoFinal - quantidadeDeArquivos + 1, nome_particoes); // retorna a posicao
        while (f-1 > contador && aux != NULL){
            if(auxRetorno != NULL) {
                //cria segundo arquivo da logica
                auxRetorno->prox = aux;
                auxRetorno = auxRetorno->prox;
                aux = aux->prox;
            }else{
                //Cria o primeiro arquivo da logica
                retorno = aux;
                auxRetorno = retorno;
                aux = aux->prox;
            }
            contador++;
        }

        if(quantidadeDeArquivos > f-1){
            criarNomeArquivo(quantidadeDeArquivos + 1, nome);
            intercalacao_basico(nome, contador, retorno);
            pushNome(nome_particoes, cria_nomes(nome, NULL));
        }
        else{
            intercalacao_basico("saida.dat", contador, retorno);
        }
        posicaoFinal++;
        quantidadeDeArquivos = quantidadeDeArquivos - contador + 1;
    }while (quantidadeDeArquivos > 1);

}


//  gcc ./cliente.c ./intercalacao.c ./lista_clientes.c ./nomes.c ./test_intercalacao.c -o main