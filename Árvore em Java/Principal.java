
public class Principal {
	public static void main (String[] args) {
		TArvore T1 = new TArvore();

		System.out.print("========INSERINDO========\n");

		System.out.print("Inserindo a chave 37\n");
		TInfo item = new TInfo(37,"Alicia");
		T1.insere(item);
		T1.mostraArvore();
	
		System.out.print("Inserindo a chave 20\n");
		item.chave = 20; item.nome = "Alan";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 10\n");
		item.chave = 10; item.nome = "Maria";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 30\n");
		item.chave = 30; item.nome = "Olívia";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 80\n");
		item.chave = 80; item.nome = "Elen";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 100\n");
		item.chave = 100; item.nome = "Lucas";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 5\n");
		item.chave = 5; item.nome = "Sônia";
		T1.insere(item);
		T1.mostraArvore();

		System.out.print("Inserindo a chave 180\n");
		item.chave = 180; item.nome = "Luiz";
		T1.insere(item);		
		T1.mostraArvore();

		System.out.print("Inserindo a chave 90\n");
		item.chave = 90; item.nome = "Eunice";
		T1.insere(item);		
		T1.mostraArvore();
		
    	//--------------------- PESQUISA
		System.out.print("========PESQUISANDO========\n");
		System.out.print("Pesquisando a chave 180\n");
		item.chave = 180;
		TNodo nodoPesq = T1.pesquisa(item);
		if (nodoPesq != null)
			System.out.print("Elemento encontrado: " + nodoPesq.item.chave + " - " + nodoPesq.item.nome + "\n");
		else
			System.out.print("Elemento não encontrado.\n");

		System.out.print("Pesquisando a chave 81\n");
		item.chave = 81;
		nodoPesq = T1.pesquisa(item);
		if (nodoPesq != null)
			System.out.print("Elemento encontrado: " + nodoPesq.item.chave + " - " + nodoPesq.item.nome + "\n");
		else
			System.out.print("Elemento não encontrado.\n");
		System.out.println("...................................................................");
			
		//--------------------- REMOVENDO
		System.out.print("========REMOVENDO========\n");
		System.out.print("Removendo a chave 180\n");
		System.out.print("Nó folha, sem filhos\n");
		item.chave = 180;
		T1.Remove(T1.raiz( ), item);
		T1.mostraArvore();

		System.out.print("Removendo a chave 80\n");
		System.out.print("Nó com filhos apenas para a direita\n");
		item.chave = 80;
		T1.Remove(T1.raiz(), item);
		T1.mostraArvore();
		
		System.out.print("Removendo a chave 10\n");
		System.out.print("Nó com filhos apenas para a esquerda\n");
		item.chave = 10;
		T1.Remove(T1.raiz(), item);
		T1.mostraArvore();
		
		System.out.print("Removendo a chave 20\n");
		System.out.print("Nó com filhos para a direira e para a esquerda\n");
		item.chave = 20;
		T1.Remove(T1.raiz(), item);
		T1.mostraArvore();
		
		System.out.print("Removendo a chave 37\n");
		System.out.print("Nó raiz\n");
		item.chave = 37;
		T1.Remove(T1.raiz(), item);
		T1.mostraArvore();

		
		System.out.print("Removendo a chave 250\n");
		System.out.print("Elemento não existe\n");
		item.chave = 250;
		T1.Remove(T1.raiz(), item);
		T1.mostraArvore();
		
		
		System.out.print("========CAMINHAMENTOS========\n");
		System.out.print("Pré-Ordem: ");
		T1.preOrdem(T1.raiz()); System.out.print("\n");
		System.out.print("Em-Ordem: ");
		T1.emOrdem(T1.raiz());  System.out.print("\n");
		System.out.print("Pós-Ordem: ");
		T1.posOrdem(T1.raiz()); System.out.print("\n\n");
		
	}
}