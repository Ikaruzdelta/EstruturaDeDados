#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool buscaError(int valorInserido, int posicao, int* vetor)
{
    if(valorInserido == 0)
        return true;

    int linha = posicao / 9; //Para saber em que linha tá
    for(int i = linha * 9 ; i < linha * 9 + 9 ; i++) // percorre a linha para verificar se o N foi inserido
    {
        if(vetor[i] == valorInserido)
        {
            return false;
        }
    }

    int coluna = posicao % 9; //Para saber em que coluna tá
    for(int i = coluna % 9 ; i <= 8 * 9 + coluna % 9 ; i+=9) //Percorre a coluna para verficação
    {
        if(vetor[i] == valorInserido)
        {
            return false;
        }
    }

    //checa submatriz
    int submatrizX, submatrizY;
    if(linha < 3)
        submatrizY = 0;
    else if(linha >= 3 && linha < 6)
        submatrizY = 1;
    else if(linha >= 6)
        submatrizY = 2;

    if(coluna < 3)
        submatrizX = 0;
    else if(coluna >= 3 && coluna < 6)
        submatrizX = 1;
    else if(coluna >= 6)
        submatrizX = 2;

    for(int y = 0 ; y < 3 ; y++)
        for(int x = 0 ; x < 3 ; x++)
        {
            int pos = (x + submatrizX * 3) + ((y * 9) + (submatrizY * 9 * 3));
            if(vetor[pos] == valorInserido)
            {
                //printf("VIOLACAO DE SUBMATRIZ: posicao %d.\n", pos);
                //getchar();
                return false;
            }
        }
    return true;
}

bool verificaSeTerminou(int* vetor)
{
    for(int i = 0 ; i < 81 ; i++)
        if(vetor[i] == 0)
            return false;
    return true;
}

void imprimeVetor(int* vetor)
{
    for(int linha = 0 ; linha < 9 ; linha++)
    {

        for(int coluna = 0 ; coluna < 9 ; coluna++){

            printf("  %d ", vetor[linha * 9 + coluna]);
            if (coluna % 3 == 2) printf("  ");

        }
        printf("\n");

        if (linha % 3 == 2) printf(" \n");
    }
}

void backTracing(int* sudoku, bool* posicaoPreenchida, int posicao);

void computaSudoku(int* sudoku, bool* posicaoPreenchida, int posicao)
{
    while(posicaoPreenchida[posicao] == true) // Enquanto a posição já tiver preenchida
        posicao++;                            // Passa para a próxima

    int tentativa = sudoku[posicao] + 1;

    if(tentativa > 9) //só entra quando a posição for maior que 9
    {
        backTracing(sudoku, posicaoPreenchida, posicao);
        tentativa = 1;
    }

    /*
    Verifica se a tentativa 
    */
    while(!buscaError(tentativa, posicao, sudoku))
    {
        tentativa++;
        if(tentativa > 9)
        {
            backTracing(sudoku, posicaoPreenchida, posicao);
            tentativa = 1;
        }
    }

    sudoku[posicao] = tentativa;

    if(verificaSeTerminou(sudoku))
    {
        printf("****************************************\n");
        printf("\tResolucao Final: \n\n");

        imprimeVetor(sudoku);
        printf("****************************************\n");
        exit(0);
    }
    computaSudoku(sudoku, posicaoPreenchida, posicao + 1);
}

void backTracing(int* sudoku, bool* posicaoPreenchida, int posicao)
{
    sudoku[posicao] = 0;
    posicao--;
    while(posicaoPreenchida[posicao] == true)
        posicao--;
    computaSudoku(sudoku, posicaoPreenchida, posicao);
}

int main()
{
    int sudoku[81]         = {0};
    bool posicaoPreenchida[81]  = {false};

    // Os vetores que estão marcadas como true é para sinalizar que
    // a mesma não popde ser alterada, já é um número fixo

    sudoku[0] = 5; posicaoPreenchida[0] = true;
    sudoku[1] = 3; posicaoPreenchida[1] = true;
    sudoku[4] = 7; posicaoPreenchida[4] = true;

    sudoku[9] = 6; posicaoPreenchida[9] = true;
    sudoku[12] = 1; posicaoPreenchida[12] = true;
    sudoku[13] = 9; posicaoPreenchida[13] = true;
    sudoku[14] = 5; posicaoPreenchida[14] = true;

    sudoku[19] = 9; posicaoPreenchida[19] = true;
    sudoku[20] = 8; posicaoPreenchida[20] = true;
    sudoku[25] = 6; posicaoPreenchida[25] = true;

    sudoku[27] = 8; posicaoPreenchida[27] = true;
    sudoku[31] = 6; posicaoPreenchida[31] = true;
    sudoku[35] = 3; posicaoPreenchida[35] = true;

    sudoku[36] = 4; posicaoPreenchida[36] = true;
    sudoku[39] = 8; posicaoPreenchida[39] = true;
    sudoku[41] = 3; posicaoPreenchida[41] = true;
    sudoku[44] = 1; posicaoPreenchida[44] = true;

    sudoku[45] = 7; posicaoPreenchida[45] = true;
    sudoku[49] = 2; posicaoPreenchida[49] = true;
    sudoku[53] = 6; posicaoPreenchida[53] = true;

    sudoku[55] = 6; posicaoPreenchida[55] = true;
    sudoku[60] = 2; posicaoPreenchida[60] = true;
    sudoku[61] = 8; posicaoPreenchida[61] = true;

    sudoku[66] = 4; posicaoPreenchida[66] = true;
    sudoku[67] = 1; posicaoPreenchida[67] = true;
    sudoku[68] = 9; posicaoPreenchida[68] = true;
    sudoku[71] = 5; posicaoPreenchida[71] = true;

    sudoku[76] = 8; posicaoPreenchida[76] = true;
    sudoku[79] = 7; posicaoPreenchida[79] = true;
    sudoku[80] = 9; posicaoPreenchida[80] = true;

    printf("\n++++++++++++++++++++++++++++++++++++++\n");
    printf("\tTabuleiro inicial: \n\n");

        imprimeVetor(sudoku);

    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\n");
    computaSudoku(sudoku, posicaoPreenchida, 0);

    return 0;
}
