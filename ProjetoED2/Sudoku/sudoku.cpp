#include <iostream>
using namespace std;
#define N 9

// Função que exibe a matriz
void print(int arr[N][N])
{
    int aux = 0;
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0)
                cout << "   ";
            cout << arr[i][j] << "|";
        }
        if (i % 3 == 2)
            cout << endl;
    }
}

//verifica se o numero para ser enserido
//já está alocado em determinada linha, coluna ou caixote
bool buscaError(int grid[N][N], int row,
            int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    int posicaoLinha = row - row % 3,
        posicaoColuna = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + posicaoLinha][j +
                                   posicaoColuna] == num)
                return false;

    return true;
}

bool sudoku(int grid[N][N], int row, int col)
{
    // Quando o numero de linhas for igual a 8
    // e o numero de colunas for igual a 9
    // quer dizer que o programa terminou e ele retorna True
    // assim finaliando o programa e imprimindo na tela
    if (row == N - 1 && col == N)
        return true;

    // Caso a coluna seja igual a 9
    // e a linha seja inferior a 8, ele entra nesta condição 
    // continuando o codigo e as verificações
    if (col == N)
    {
        row++;
        col = 0;
    }

    // Verifica se o numero que esta em determina opção é maior que 0, se for
    // é por conta que é um número já predefinido no inicio do programa
    if (grid[row][col] > 0)
        return sudoku(grid, row, col + 1);

    // For para testes de possiveis números
    for (int num = 1; num <= N; num++)
    {
        // Condição entra na função que verifica
        // se é possivel ou não colocar algum número de 1 até 8
        if (buscaError(grid, row, col, num))
        {
            // Caso não tenha dado nenhum erro
            // o numero é adcionado na posição que estamos no programa
            grid[row][col] = num;
            if (sudoku(grid, row, col + 1)){
                return true;
            } // Entra em condição para verificar a proxima coluna
        }
        // Caso o numero não possa ser add na matriz na determinada chamada
        // Ele add o 0 e depois tenta outro número

        // Já quando ocorre a recursão se tiver algum numero que foi add
        // ele add o 0 para que possa tentar com outros números 
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    /*
        Aqui estabele os numeros iniciais do sudoku e cria a matriz
    */
    int grid[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "======== MATRIZ INICIAL ==========";
    cout << endl;
    print(grid);
    cout << endl;

    cout << "======== MATRIZ FINAL ==========";
    cout << endl;
    if (sudoku(grid, 0, 0))
        print(grid);
    else
        // Caso altere os numeros iniciais se não ouver solução com o que colocou
        // ele informa que não tem solução
        cout << "Sudoku sem solução" << endl;
    return 0;
}