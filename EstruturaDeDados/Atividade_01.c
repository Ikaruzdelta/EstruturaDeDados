#include <stdio.h>
#include <stdlib.h>

struct Alunos
{
    int nota1;
    int nota2;
    int nota3;
    int media;
    char nome[50];
};

struct Alunos dados[50];

int main()
{
    int media;

    for(int i=0; i < 3; i++)
    {
        printf("Digite o nome do aluno: \n");
        gets(dados[i].nome);

        gets("Digite a primeira nota: \n");
        fflush(stdin);
        scanf(dados[i].nota1);
        fflush(stdin);
        gets("Digite a segunda nota: \n");
        scanf(dados[i].nota2);
        fflush(stdin);
        gets("Digite a terceira nota: \n");
        scanf(dados[i].nota3);
        fflush(stdin);
    }
    return 0;
}
