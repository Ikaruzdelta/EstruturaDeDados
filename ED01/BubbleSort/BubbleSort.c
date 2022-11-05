#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

/*
    "BubbleSort" ou "Ordenação por bolha"

    A ideia do método da Bolha é inicia comparando os dois últimos elementos ou o contrario !

    - Compara pares de elementos adjacentes e
    os troca de lugar se estiverem na ordem errada

    - Esse Processo se repete até que mais nenhumma
    troca seja necessaria (elementos já ordenados)

    "Performace"
    - Melhor caso: O(N)
    - Pior caso: O(N^2)
    - Não recomenda para grandes conjuntos de dados
*/

int main()
{
    setlocale(LC_ALL, "");
    int numeros[TAM];
    int i, aux, contador;

    printf("Entre com dez numeros para preencher o array e pressione enter após digitar cada um:\n");
    for (i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Ordem atual dos numeros na array:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }
    //Algoritmo de ordenação BubbleSort:
    for (contador = 1; contador < TAM; contador++)
    {
        for (i = 0; i < TAM - 1; i++)
        {
            if (numeros[i] > numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }
    printf("\nElementos com ordenacao BubbleSort:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }
    return 0;
}