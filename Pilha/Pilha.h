typedef int TipoItem;
const int max_intens = 100;

class pilha
{
private:
    int tamanho;
    TipoItem *estrutura;

public:
    pilha();                     //construtora
    ~pilha();                    //destrutora
    bool estacheia();            //verifica se a pilha esta cheia
    bool estavazia();            //verifica se a pilha esta vazia
    void inserir(TipoItem item); //push = inserir
    TipoItem remover();          //pop = remover
    void imprimir();             //print
    int qualtamanho();           //lenght
};