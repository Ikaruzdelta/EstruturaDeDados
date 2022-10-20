#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compartimento_hash.h"
#include "cliente.h"

#include "encadeamento_exterior.h"

int thash (int num){
	return num % 7;
}

void cria_hash(char *nome_arquivo_hash, int tam)
{
	//TODO: criar a tabela hash

    CompartimentoHash *out;
    FILE  *escrever;
    escrever = fopen(nome_arquivo_hash,"wb");
    if(escrever == NULL){
        printf("\nabertura do arquivo falhou");
    }else{
        for(int i = 0; i < tam; i++){
            out = compartimento_hash(-1);
            salva_compartimento(out,escrever);
        }
    }
    fclose(escrever);
}

int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	FILE *filehas = fopen(nome_arquivo_hash,"rb");
	FILE *filedad = fopen(nome_arquivo_dados,"rb");
	int pos = 0,hash = cod_cli%7;
	if (filedad == NULL && filehas == NULL){
		return -1;
	}else{
		Cliente *cli;
		CompartimentoHash  *aux;

		fseek(filehas,(hash*tamanho_compartimento()),SEEK_SET);
		aux = le_compartimento(filehas);

		if (aux->prox == -1){
			return -1;
		}else{
			fseek(filedad,(aux->prox*tamanho_cliente()),SEEK_SET);
			cli = le_cliente(filedad);
			if (cli->cod_cliente == cod_cli && cli->status == OCUPADO){
				pos = aux->prox;
				return pos;
			}else{
				
				while(cli!= NULL){
					pos++;
					if (cli->cod_cliente == cod_cli && cli->status == OCUPADO){
						return pos;
					}
					cli = le_cliente(filedad);
					
				}
			}
		}

	}

	fclose(filehas);
	fclose(filedad);

    return -1;
}


int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros)
{
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    FILE* arqhash;
    FILE* arqdados;

    int hash, contLinhas = 0;

    CompartimentoHash *aux;
    Cliente *auxCliente, *percorre, *novo;

    arqhash = fopen(nome_arquivo_hash,"rb+");
    arqdados = fopen(nome_arquivo_dados,"rb+");
    hash = cod_cli % 7;


    if(arqdados == NULL || arqhash == NULL){
        printf("\nerro ao abrir o arquivo");
    }else{
        fseek(arqhash, (hash*tamanho_compartimento()),SEEK_SET);
        aux = le_compartimento(arqhash);
        if(aux->prox == -1){
            auxCliente = le_cliente(arqdados);
            while(auxCliente != NULL){
                if(auxCliente->cod_cliente == cod_cli){
                    return -1;
                }
                auxCliente = le_cliente(arqdados);
                contLinhas++;
            }

            novo = cliente(cod_cli,nome_cli,-1,OCUPADO);
            salva_cliente(novo,arqdados);

           

            CompartimentoHash* novocomp = compartimento_hash(contLinhas);
            fseek(arqhash, (hash*tamanho_compartimento()),SEEK_SET);
            salva_compartimento(novocomp,arqhash);
        }else{

           
            fseek(arqdados,(aux->prox*tamanho_cliente()),SEEK_SET);
            auxCliente = le_cliente(arqdados);
            percorre = auxCliente;
            if(auxCliente->cod_cliente == cod_cli){
                return -1;
            }
            Cliente *ant;
            if(auxCliente->prox != -1){
                while(percorre->prox != -1 && percorre->status != LIBERADO){
                    ant = percorre;
                    fseek(arqdados,(percorre->prox*tamanho_cliente()),SEEK_SET);
                    percorre = le_cliente(arqdados);
                }
            }
            if(percorre->status == LIBERADO){
               novo = cliente(cod_cli, nome_cli, percorre->prox, OCUPADO);
               fseek(arqdados,(ant->prox*tamanho_cliente()),SEEK_SET);
               salva_cliente(novo, arqdados);
               contLinhas = ant->prox;
            }else {
                
                contLinhas = ant->prox + 1;
                
                fseek(arqdados, ((contLinhas) * tamanho_cliente()), SEEK_SET);
                novo = cliente(cod_cli, nome_cli, -1, OCUPADO);
                salva_cliente(novo, arqdados);
                fseek(arqdados, ((ant->prox) * tamanho_cliente()), SEEK_SET);
                percorre->prox = contLinhas;
                salva_cliente(percorre, arqdados);
            }
        }
    }
    fclose(arqhash);
    fclose(arqdados);

    return contLinhas;
}

int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
	FILE *dados = fopen(nome_arquivo_dados,"rb+");
	Cliente *auxcli;
	int apaga = busca(cod_cli,nome_arquivo_hash,nome_arquivo_dados);
	if(dados == NULL){
		return -1;
	}else{
		fseek(dados,apaga*tamanho_cliente(),SEEK_SET);
		auxcli = le_cliente(dados);
		if(cod_cli == auxcli->cod_cliente){
			auxcli->status = LIBERADO;
			fseek(dados,apaga*tamanho_cliente(),SEEK_SET);
			salva_cliente(auxcli,dados);
		}
	}
	fclose(dados);
    return apaga;
}
