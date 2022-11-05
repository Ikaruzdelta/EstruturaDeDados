typedef int TipoItem;

struct no
{
    TipoItem valor;
    no* proximo;
};

class filaDinamica
{
private:
    no* primeiro;
    no* ultimo;
public:
    filaDinamica();             //construtora
    ~filaDinamica();            //destrutora
    bool estacheia();            //verifica se a pilha esta cheia
    bool estavazia();            //verifica se a pilha esta vazia
    void inserir(TipoItem item); //push = inserir
    TipoItem remover();          //pop = remover
    void imprimir();             //print
};