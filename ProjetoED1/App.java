import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String path1 = "C:/Users/Ikaruz/Documents/ProjectsVscode/C++/EstruturaDeDados/ProjetoED1/Arquivos usados/HIST_PAINEL_COVIDBR_2021_Parte1_08jul2021.csv";
        String path2 = "C:/Users/Ikaruz/Documents/ProjectsVscode/C++/EstruturaDeDados/ProjetoED1/Arquivos usados/HIST_PAINEL_COVIDBR_2021_Parte2_08jul2021.csv";

        TArvoreAVL arvore = new TArvoreAVL();

        TInfo i = new TInfo();
        TInfo info = new TInfo();
        /// ============================================
        int op;

        do {
            System.out.println("------------------------------------------");
            System.out.println("1 - Cadastrar arvore Part-1");
            System.out.println("2 - Cadastrar arvore Part-2");
            System.out.println("3 - Casos novos e acumulados por cidade");
            System.out.println("4 - Obitos novos e acumulados por cidade");
            System.out.println("5 - Total de casos e obitos por regiao");
            System.out.println("6 - Total de casos e obitos no Brasil");
            System.out.println("0 - Sair do programa");
            System.out.println("------------------------------------------");
            System.out.println("Escolha uma opcao => ");

            op = scan.nextInt();

            switch (op) {
                case 1 -> {
                    /// Percorrendo todo meu arquivo
                    info = new TInfo();
                    arvore.preencher(info, i, path1);
                }

                case 2 -> arvore.preencher(info, i, path2);

                case 3 -> {
                    /// Pesquisando por codigo
                    System.out.println("Digite o Codigo do Municipio: ");
                    i.CodMun = scan.next();
                    TNodo nodoCodPesq = arvore.pesquisa(i);

                    if (nodoCodPesq != null) {
                        System.out.println("CODMUN: " + nodoCodPesq.item.CodMun + " MUNICIPIO: "
                                + nodoCodPesq.item.Municipio + " CASOS NOVOS: " + nodoCodPesq.item.CasosNovos
                                + " CASOS ACUMULADOS: " + nodoCodPesq.item.CasosAcumulados);
                    } else {
                        System.out.println("Nao Encontrado");
                    }
                }

                case 4 -> {
                    /// Pesquisando por codigo
                    System.out.println("Digite o Codigo do Municipio: ");
                    i.CodMun = scan.next();
                    TNodo nodoCodPesq = arvore.pesquisa(i);
                    if (nodoCodPesq != null) {
                        System.out.println("CODMUN: " + nodoCodPesq.item.CodMun + " MUNICIPIO: "
                                + nodoCodPesq.item.Municipio + " OBITOS NOVOS: " + nodoCodPesq.item.ObitosNovos
                                + " OBITOS ACUMULADOS: " + nodoCodPesq.item.ObitosAcumulados);
                    } else {
                        System.out.println("Nao Encontrado");
                    }
                }

                case 5 -> {
                    /// Pesquisando por codigo
                    System.out.println("Digite o Codigo UF: ");
                    i.CodMun = "";
                    i.CodUF = scan.next();
                    TNodo nodoCodPesq = arvore.pesquisa(i);
                    if (nodoCodPesq != null) {
                        System.out.println("CODUF: " + nodoCodPesq.item.CodUF + " REGIAO: " + nodoCodPesq.item.Regiao
                                + " TOTAL CASOS: " + nodoCodPesq.item.CasosAcumulados + " TOTAL OBITO: "
                                + nodoCodPesq.item.ObitosAcumulados);
                    } else {
                        System.out.println("Nao Encontrado");
                    }
                }

                case 6 -> arvore.TotaisBrasil();

                case 0 -> System.out.println("Encerrando...");

                default -> System.out.println("Opcao invalida");
            }
        } while (op != 0);
    }
}