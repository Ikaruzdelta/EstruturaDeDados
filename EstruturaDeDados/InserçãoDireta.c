#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

/*
A ideia o m�todo da Inser��o Direta � um pouco diferentes do Bolha e Sele��o, naqueles ap�s cada la�o interno
um elemento maior ficava em sua posi��o "definitiva", no Inser��o n�o. A ideia do Inser��o � (na etapa i de
ordena��o): suponha que V[0] at� V[i-1] esteja ordenado, ent�o podemos estender a ordem localizando o primeiro
elemento, da direita para a esqueda, que n�o seja maior que V[i], digamos que seja o V[j], ent�o move-se todos
eles uma posi��o para a sua direita, abrindo a posi��o V[j] para inserir o V[i].
*/


/*
int main()
{
    setlocale(LC_ALL, "");

    int numeros[TAM];
    int i, aux, contador, k, temp;

    printf("Entre com dez n�meros para preencher o array e pressione enter ap�s digitar cada um:\n");
    for(i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Ordem atual dos numeros na array:\n");
    for(i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }

    //Algoritmo de Inser��o Direta:
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

    printf("\nElementos com ordenal��o BubbleSort:\n");
    for(i = 0; i < TAM; i++)
    {
        printf("%3d", numeros[i]);
    }
    return 0;
}
*/
