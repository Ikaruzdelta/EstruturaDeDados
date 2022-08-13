/*
 * balanceLine.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */

#include <stdio.h> /* define FILE */
#include <stdlib.h>
#include <string.h> // lidar com funções de string (ex.: strcpy())
#include <math.h>

int tamanhoCliente()
{
	return sizeof(int)				 // cod
				 + sizeof(char) * 40 // nome
				 + sizeof(char) * 12 // data de nascimento
			;
}

int tamanhoTransacao()
{
	return sizeof(int)				 // cod
				 + sizeof(char)			 // data_nascimento
				 + sizeof(char) * 40 // nome
				 + sizeof(char) * 40 // cpf
			;
}

int tamanhoArquivo(FILE *arq, int tamanho)
{
	fseek(arq, 0, SEEK_END);
	return trunc(ftell(arq) / tamanho);
}

void balanceLine(FILE *fMestre, FILE *fTransacao, FILE *fNovoMestre, FILE *fErro)
{
	// * Ler arquivo mestre e armazenar na memoria
	TCliente *mestre[tamanhoArquivo(fMestre, tamanhoCliente())];
	TTransacao *transacao[tamanhoArquivo(fTransacao, tamanhoTransacao())];
	int posicaoMestre = 0;
	int posicaoTransacao = 0;

	fseek(fMestre, 0, SEEK_SET);
	while ((mestre[posicaoMestre] = leCliente(fMestre)) != NULL)
	{
		posicaoMestre++;
	}

	// * Ler arquivo transação e armazenar na memoria
	fseek(fTransacao, 0, SEEK_SET);
	while ((transacao[posicaoTransacao] = leTransacao(fTransacao)) != NULL)
	{
		posicaoTransacao++;
	}

	// ! POSICIONANDO CURSOR NO INICIO DOS ARRAYS
	posicaoMestre = 0;
	posicaoTransacao = 0;

	// * Escrever arquivo novo mestre
	printf("\n\n-------------------------------------------------------------------\n");
	while (posicaoTransacao < tamanhoArquivo(fTransacao, tamanhoTransacao()) && posicaoMestre < tamanhoArquivo(fMestre, tamanhoCliente()))
	{
		printf("\nPassou aqui cliente: %d transicao: %d ", mestre[posicaoMestre]->codCliente, transacao[posicaoTransacao]->codCliente);
		switch (transacao[posicaoTransacao]->tipoTransacao)
		{
		case 'E':
			printf("EXCLUIR");
			// * Excluir

			while (mestre[posicaoMestre]->codCliente < transacao[posicaoTransacao]->codCliente)
			{
				salvaCliente(mestre[posicaoMestre], fNovoMestre);
				imprimeCliente(mestre[posicaoMestre]);
				posicaoMestre++;
			}

			if (mestre[posicaoMestre]->codCliente == transacao[posicaoTransacao]->codCliente)
			{
				posicaoMestre++;
				posicaoTransacao++;
			}
			else
			{
				salvaCliente(mestre[posicaoMestre], fNovoMestre);
			}
			break;

		case 'M':
			printf("\nMODIFICAR");
			while (mestre[posicaoMestre]->codCliente < transacao[posicaoTransacao]->codCliente)
			{
				salvaCliente(mestre[posicaoMestre], fNovoMestre);
				posicaoMestre++;
			}

			if (mestre[posicaoMestre]->codCliente == transacao[posicaoTransacao]->codCliente)
			{
				// Gravar valor modificado
				if (strcmp(transacao[posicaoTransacao]->valor01, "Nome") == 0)
					strcpy(mestre[posicaoMestre]->nome, transacao[posicaoTransacao]->valor02);
				else if (strcmp(transacao[posicaoTransacao]->valor01, "Data de Nascimento") == 0)
					strcpy(mestre[posicaoMestre]->dataNascimento, transacao[posicaoTransacao]->valor02);

				salvaCliente(mestre[posicaoMestre], fNovoMestre);
				posicaoTransacao++;
				posicaoMestre++;
			}
			else
			{
				// Erro
				TCliente *erro = Cliente(transacao[posicaoTransacao]->codCliente, "Usuario não encontrado", "");
				salvaCliente(erro, fErro);
				posicaoTransacao++;
			}

			// posicaoTransacao++;
			break;

		case 'I':
			printf("\nINSERIR");
			while (mestre[posicaoMestre]->codCliente < transacao[posicaoTransacao]->codCliente)
			{
				salvaCliente(mestre[posicaoMestre], fNovoMestre);
				posicaoMestre++;
			}

			if (mestre[posicaoMestre]->codCliente == transacao[posicaoTransacao]->codCliente)
			{
				// O valor já existe
				// Erro
				TCliente *erro = Cliente(transacao[posicaoTransacao]->codCliente, "O usuario ja foi cadastrado", "");
				salvaCliente(erro, fErro);
				salvaCliente(mestre[posicaoMestre], fNovoMestre);
				posicaoTransacao++;
			}
			else
			{
				// Grava o novo valor
				TCliente *novoCliente = Cliente(transacao[posicaoTransacao]->codCliente, transacao[posicaoTransacao]->valor01, transacao[posicaoTransacao]->valor02);
				salvaCliente(novoCliente, fNovoMestre);
				// salvaCliente(mestre[posicaoMestre], fNovoMestre);
				posicaoTransacao++;
				printf("\n Gravou novo registro");
			}
			// posicaoTransacao++;
			break;

		default:
			printf("\nOPERACAO INVALIDA");
			posicaoTransacao++;
			break;
		}
		// imprimeCliente(mestre[posicaoMestre]);
	}
	posicaoMestre++;
	while (posicaoMestre < tamanhoArquivo(fMestre, tamanhoCliente()))
	{
		salvaCliente(mestre[posicaoMestre], fNovoMestre);
		posicaoMestre++;
	}

	printf("\n-------------------------------------------------------------------\n\n\n");
}