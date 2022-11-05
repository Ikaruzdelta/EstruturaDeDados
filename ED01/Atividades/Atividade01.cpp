#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
 //Ícaro Gabriel
 //Lucas Pereira

//Funções:
void CadastrarAluno();
void ListarIdade();
void ListarMedia();

//Structs:
struct Alunos
{
    double nota1;
    double nota2;
    double nota3;
    double media;
    int idade;
    string nome;
};
struct Alunos dados[50];

//Váriavel Global
int contador = 0, opcao;

int main()
{
    setlocale(LC_ALL,"portuguese");

    cout << "=========ATIVIDADADE_01==========" << endl;
    cout << "== 1- Cadastrar Aluno ===========" << endl;
    cout << "== 2- Listar alunos por idade ===" << endl;
    cout << "== 3- Listar alunos por media ===" << endl;
    cout << "== 4- Para finalizar programa ===" << endl;
    cout << "Escolha a opção: ";
    cin>>opcao;
    switch(opcao)
    {
    case 1:
        system("cls");
        CadastrarAluno();
        break;
    case 2:
        system("cls");
        ListarIdade();
        break;
    case 3:
        system("cls");
        ListarMedia();
        break;
    case 4:
        cout << endl;
        cout << "Programa encerrado";
        cout << endl;
        exit(0);
    default:
        cout << "Numero invalido" << endl;
        system("pause");
        main();
        break;

        return 0;
    }
}

void CadastrarAluno()
{
    do
    {
        if(contador <= 49)
        {
            fflush(stdin);
            cout << "Digite o nome do aluno: " << endl;
            getline(cin,dados[contador].nome);
            fflush(stdin);
            cout << "Digite a idade do aluno: \n";
            cin >> (dados[contador].idade);
            fflush(stdin);
            cout << "Digite a primeira nota: \n";
            cin >> (dados[contador].nota1);
            fflush(stdin);
            cout << "Digite a segunda nota: \n";
            cin >> (dados[contador].nota2);
            fflush(stdin);
            cout << "Digite a terceira nota: \n";
            cin >> (dados[contador].nota3);
            fflush(stdin);
            dados[contador].media = (dados[contador].nota1 + dados[contador].nota2 + dados[contador].nota3)/3;
            contador++;
            cout << "Deseja cadastrar outro aluno?" << endl;
            cout << "Se sim digite 0: ";
            cin >> opcao;
            system("cls");
        }
        else
        {
            cout << endl;
            cout << "Cadatramentro cheio!" << endl;
            system("pause");
            system("cls");
            main();
        }
    }
    while(opcao == 0);
    system("cls");
    main();
}


void ListarIdade()
{
    string aux;
    int aux2;
    double aux3;
    double aux4;
    double aux5;
    double aux6;

    //Por idade usei o método por bolha
    for(int j = 1; j < contador; j++)
    {
        for (int i = 0; i < contador - 1; i++)
        {
            if(dados[i].idade > dados[i+1].idade)
            {
                //Trocar nome
                aux = dados[i].nome;
                dados[i].nome = dados[i + 1].nome;
                dados[i + 1].nome = aux;

                //Trocar idade
                aux2 = dados[i].idade;
                dados[i].idade = dados[i + 1].idade;
                dados[i + 1].idade = aux2;

                //Trocar Nota01
                aux3 = dados[i].nota1;
                dados[i].nota1 = dados[i + 1].nota1;
                dados[i + 1].nota1 = aux3;

                //Trocar nota02
                aux4 = dados[i].nota2;
                dados[i].nota2 = dados[i + 1].nota2;
                dados[i + 1].nota2 = aux4;

                //Trocar nota3
                aux5 = dados[i].nota3;
                dados[i].nota3 = dados[i + 1].nota3;
                dados[i + 1].nota3 = aux5;

                //Trocar media
                aux6 = dados[i].media;
                dados[i].media = dados[i + 1].media;
                dados[i + 1].media = aux6;
            }
        }
    }
    cout << "=======LISTANDO ALUNO POR ORDEM DE NOTA=======" << endl;
    for (int i = 0; i < contador; i++)
    {
        cout << "Aluno: " << dados[i].nome << endl;
        cout << "Idade: " << dados[i].idade << endl;
        cout << "Nota 01: " << dados[i].nota1 << endl;
        cout << "Nota 02: " << dados[i].nota2 << endl;
        cout << "Nota 03: " << dados[i].nota3 << endl;
        cout << "Media: " << dados[i].media << endl;
        cout << endl;
    }
    system("pause");
    system("cls");
    main();
}

void ListarMedia()
{
    //Aqui usei a inserção direta para ordenação
    double temp, temp2, temp3, temp4;
    int k;
    int aux;
    string aux2;
    for(int j = 1; j < contador; j++)
    {
        k = j;
        temp = dados[j].media;
        temp2 = dados[j].nota1;
        temp3 = dados[j].nota2;
        temp4 = dados[j].nota3;
        aux = dados[j].idade;
        aux2 = dados[j].nome;

        while((k > 0)&&(temp > dados[k-1].media))
        {
            dados[k].media = dados[k-1].media;
            dados[k].nota1 = dados[k-1].nota1;
            dados[k].nota2 = dados[k-1].nota2;
            dados[k].nota3 = dados[k-1].nota3;
            dados[k].idade = dados[k-1].idade;
            dados[k].nome = dados[k-1].nome;
            k--;
        }
        dados[k].media = temp;
        dados[k].nota1 = temp2;
        dados[k].nota2 = temp3;
        dados[k].nota3 = temp4;
        dados[k].idade = aux;
        dados[k].nome = aux2;
    }

    cout << "=======LISTANDO ALUNO POR ORDEM DA MEDIA=======" << endl;
    for (int i = 0; i < contador; i++)
    {
        cout << "Aluno: " << dados[i].nome << endl;
        cout << "Idade: " << dados[i].idade << endl;
        cout << "Nota 01: " << dados[i].nota1 << endl;
        cout << "Nota 02: " << dados[i].nota2 << endl;
        cout << "Nota 03: " << dados[i].nota3 << endl;
        cout << "Media: " << dados[i].media << endl;
        cout << endl;
    }
    system("pause");
    system("cls");
    main();
}