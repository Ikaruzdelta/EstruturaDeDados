#include <stdio.h>  // lidar com arquivos (ex.: FILE)
#include <stdlib.h> // lidar com constantes (ex.: NULL)
#include <string.h> // lidar com funções de string (ex.: strcpy())
#include <math.h> // lidar com contas matematicas

typedef struct Funcionario
{
  int cod;
  char nome[50];
  char cpf[15];
  char data_nascimento[11];
  double salario;
} TFunc;

// Imprime funcionario
void imprime(TFunc *func);

// Cria funcionario. Lembrar de usar free(funcionario)
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out);

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho();

// ordena um arquivo com o insertion sort
void ordena_InsertionSort(FILE *in, FILE *out);

// ordena um arquivo com o insertion sort
void ordena_BubbleSort(FILE *in, FILE *out);

// ordena um arquivo com o insertion sort
void ordena_QuickSort(FILE *in, FILE *out);

// retorna o tamanho do arquivo
int tamanhoArquivo(FILE *arq);

// Imprime funcionario
void imprime(TFunc *func)
{
  printf("**********************************************");
  printf("\nFuncionario de código ");
  printf("%d", func->cod);
  printf("\nNome: ");
  printf("%s", func->nome);
  printf("\nCPF: ");
  printf("%s", func->cpf);
  printf("\nData de Nascimento: ");
  printf("%s", func->data_nascimento);
  printf("\nSalário: ");
  printf("%4.2f", func->salario);
  printf("\n**********************************************");
}

// Cria funcionario. Lembrar de usar free(func)
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario)
{
  TFunc *func = (TFunc *)malloc(sizeof(TFunc));
  // inicializa espaço de memória com ZEROS para os valores inteiros
  if (func)
    memset(func, 0, sizeof(TFunc));
  // copia valores para os campos de func
  func->cod = cod;
  strcpy(func->nome, nome);
  strcpy(func->cpf, cpf);
  strcpy(func->data_nascimento, data_nascimento);
  func->salario = salario;
  return func;
}

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out)
{
  fwrite(&func->cod, sizeof(int), 1, out);
  fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
  fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
  fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
  fwrite(&func->salario, sizeof(double), 1, out);
}

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in)
{
  TFunc *func = (TFunc *)malloc(sizeof(TFunc));
  if (0 >= fread(&func->cod, sizeof(int), 1, in))
  {
    free(func);
    return NULL;
  }
  else
  {
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
  }
  return func;
}

// Retorna tamanho do funcionario em bytes
int tamanho()
{
  return sizeof(int)         // cod
         + sizeof(char) * 50 // nome
         + sizeof(char) * 15 // cpf
         + sizeof(char) * 11 // data_nascimento
         + sizeof(double);   // salario
}

// ordena um arquivo com o Insertion sort
void ordena_InsertionSort(FILE *in, FILE *out)
{
  // TODO
}

// ordena um arquivo com o Bubble sort
void ordena_BubbleSort(FILE *in, FILE *out)
{
  int tam, trocou;
  TFunc *aux; // * Ler arquivo de entrada
  TFunc *arquivos[tamanhoArquivo(in)]; // recebe o tamanho do arquivo
  int posicao = 0;

  fseek(in, 0, SEEK_SET);
  TFunc *f;
  while ((arquivos[posicao] = le(in)) != NULL)
  {
    posicao++; // Carrega o arquivo para a memoria
  }

  // * Ordenar
  tam = tamanhoArquivo(in);
  trocou = 1;

  while (trocou && tam > 0)
  {
    trocou = 0;
    for (int i = 0; i < tam - 1; i++)
    {
      if (arquivos[i]->cod > arquivos[i + 1]->cod)
        // Procura o primeiro numero maior 
        // que encontrar e arrasta para o final
        {
          aux = arquivos[i];
          arquivos[i] = arquivos[i + 1];
          arquivos[i + 1] = aux;
          trocou = 1;
        }
    }
    tam--;
  }

  // Gravar no arquivo de saida
  for (int i = 0; i < tamanhoArquivo(in); i++)
  {
    salva(arquivos[i], out);
  }
}

int tamanhoArquivo(FILE *arq)
{
  fseek(arq, 0, SEEK_END);
  return trunc(ftell(arq) / tamanho());
}

// ordena um arquivo com o Quick sort
void ordena_QuickSort(FILE *in, FILE *out)
{
  int i, j, x, left, right;
  TFunc *y; // * Ler arquivo de entrada
  TFunc *arquivos[tamanhoArquivo(in)]; // recebe o tamanho do arquivo
  int tam = 0;

  fseek(in, 0, SEEK_SET);
  TFunc *f;
  while ((arquivos[tam] = le(in)) != NULL)
  {
    tam++; 
  }

  left = 0;
  right = tam -1;
  i = 0;
  j = tam - 1;
  x = arquivos[(i + j) / 2];

  while(i <= j)
  {
    while(arquivos[i]->cod < x && i < right) {
            i++;
        }
        while(arquivos[j]->cod > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = arquivos[i];
            arquivos[i] = arquivos[j];
            arquivos[j] = y;
            i++;
            j--;
        }
    }
    //incompleto, falta de coerencia na hora da recursão
    if(j > left) {
        ordena_QuickSort(FILE *in, FILE *out);
    }
    if(i < right) {
        ordena_QuickSort(FILE *in, FILE *out);
    }
}