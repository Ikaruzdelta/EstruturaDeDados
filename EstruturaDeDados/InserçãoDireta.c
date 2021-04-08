#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

/*
A ideia o método da Inserção Direta é um pouco diferentes do Bolha e Seleção, naqueles após cada laço interno
um elemento maior ficava em sua posição "definitiva", no Inserção não. A ideia do Inserção é (na etapa i de
ordenação): suponha que V[0] até V[i-1] esteja ordenado, então podemos estender a ordem localizando o primeiro
elemento, da direita para a esqueda, que não seja maior que V[i], digamos que seja o V[j], então move-se todos
eles uma posição para a sua direita, abrindo a posição V[j] para inserir o V[i].
*/


/*
int main()
{
    setlocale(LC_ALL, "");

    int numeros[TAM];
    int i, aux, contador, k, temp;

    printf("Entre com dez números para preencher o array e pressione enter após digitar cada um:\n");
    for(i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Ordem atual dos numeros na array:\n");
    for(i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }

    //Algoritmo de Inserção Direta:
    for(contador = 1; contador < TAM; contador++)
    {
        k = contador;
        temp = numeros[contador];
        while((k > 0)&&(temp < numeros[k-1])){
            numeros[k] = numeros[k-1];
            k--;
        }
        numeros[k] = temp;
    }

    printf("\nElementos com ordenalção BubbleSort:\n");
    for(i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }
    return 0;
}
*/
