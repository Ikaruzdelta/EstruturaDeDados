import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class TArvoreAVL {
    public TNodo nodo;
    private int h;

    public String totalCasosBrasil;
    public String totalObitosBrasil;

    public TArvoreAVL() {
        nodo = null;

    }

    public TNodo raiz() {
        return nodo;
    }

    public void insere(TInfo item) {
        System.out.println("Inserindo " + item.CodMun + " - " + item.Regiao + " - " + item.Municipio);
        nodo = insere(nodo, item, null);
        AVL(nodo);
    }

    public TNodo insere(TNodo nodo, TInfo item, TNodo pai) {
        if (nodo == null) {
            nodo = new TNodo(item, pai);
            this.nodo = nodo;
        } else {
            pai = nodo;

            if (item.Regiao.compareToIgnoreCase("Brasil") == 0) {
                this.totalCasosBrasil = item.CasosAcumulados;
                this.totalObitosBrasil = item.ObitosAcumulados;
            }

            if (item.CodMun.compareToIgnoreCase(nodo.item.CodMun) < 0) {
                nodo.esq = insere(nodo.esq, item, pai);
            } else if (item.CodMun.compareToIgnoreCase(nodo.item.CodMun) > 0) {
                nodo.dir = insere(nodo.dir, item, pai);
            }
        }
        return nodo;
    }

    public void preencher(TInfo info, TInfo i, String path) {
        String line;
        try {
            BufferedReader br = new BufferedReader(new FileReader(path));

            while ((line = br.readLine()) != null) {
                String[] values = line.split(";");
                try {

                    TInfo item = new TInfo(values[3], values[4], values[0], values[1], values[2], values[6], values[7],
                            values[10], values[11], values[12], values[13]);
                    insere(item);
                    i = item;
                } catch (ArrayIndexOutOfBoundsException e) {

                }
            }
        } catch (FileNotFoundException e) {

        } catch (IOException e) {

        }
    }

    public TNodo pesquisa(TInfo item) {
        return pesquisa(nodo, item);
    }

    public TNodo pesquisa(TNodo nodo, TInfo item) {
        if (nodo == null) {
            return nodo;
        } else {
            if (!item.CodMun.equals("")) {
                if (item.CodMun.compareToIgnoreCase(nodo.item.CodMun) == 0) {
                    return nodo;
                } else {
                    if (item.CodMun.compareToIgnoreCase(nodo.item.CodMun) < 0) {
                        nodo = pesquisa(nodo.esq, item);
                    } else {
                        nodo = pesquisa(nodo.dir, item);
                    }
                }
            } else {
                if (item.CodUF.compareToIgnoreCase(nodo.item.CodUF) == 0) {
                    return nodo;
                } else {
                    if (item.CodUF.compareToIgnoreCase(nodo.item.CodUF) > 0) {
                        nodo = pesquisa(nodo.esq, item);
                    } else {
                        nodo = pesquisa(nodo.dir, item);
                    }
                }
            }
        }
        return nodo;
    }

    public void TotaisBrasil() {
        System.out.println(
                "TOTAL CASOS BRASIL: " + this.totalCasosBrasil + " TOTAL OBITOS BRASIL: " + this.totalObitosBrasil);
    }

    public void AVL(TNodo nodo) {
        if (nodo != null) {
            nodo.bal = balanco(nodo);

            if (nodo.bal < 2) {
                AVL(nodo.pai);
            } else {
                if (nodo.hesq >= nodo.hdir) {
                    if (nodo.esq.hesq >= nodo.esq.hdir) {
                        rotacaoDireita(nodo);
                    } else {
                        rotacaoEsquerda(nodo.esq);
                        rotacaoDireita(nodo);
                    }
                }

                if (nodo.hdir >= nodo.hesq) {
                    if (nodo.dir.hdir >= nodo.dir.hesq) {
                        rotacaoEsquerda(nodo);
                    } else {
                        rotacaoDireita(nodo.dir);
                        rotacaoEsquerda(nodo);
                    }
                }
            }
        }
    }

    public int balanco(TNodo nodo) {
        h = 0;
        balpreOrdem(nodo.esq, 0);
        nodo.hesq = h;
        return Math.abs(nodo.hesq - nodo.hdir);
    }

    private void balpreOrdem(TNodo nodo, int v) {
        if (nodo != null) {
            v++;
            balpreOrdem(nodo.esq, v);
            balpreOrdem(nodo.dir, v);
        } else {
            if (v > h) {
                h = v;
            }
        }
    }

    public void rotacaoDireita(TNodo nodo) {
        TNodo apu = nodo.esq;
        nodo.esq = apu.dir;

        if (apu.dir != null) {
            apu.dir.pai = nodo;
        }

        apu.pai = nodo.pai;
        apu.dir = nodo;
        nodo.pai = apu;
        nodo.bal = 0;

        if (apu.pai == null) {
            this.nodo = apu;
        } else {
            if (apu.item.CodMun.compareToIgnoreCase(apu.pai.item.CodMun) < 0) {
                apu.pai.esq = apu;
            } else {
                apu.pai.dir = apu;
            }
        }
    }

    public void rotacaoEsquerda(TNodo nodo) {
        TNodo apu = nodo.dir;
        nodo.dir = apu.esq;

        if (apu.esq != null) {
            apu.esq.pai = nodo;
        }

        apu.pai = nodo.pai;
        apu.esq = nodo;
        nodo.pai = apu;
        nodo.bal = 0;

        if (apu.pai == null) {
            this.nodo = apu;
        } else {
            if (apu.item.CodMun.compareToIgnoreCase(apu.pai.item.CodMun) < 0) {
                apu.pai.esq = apu;
            } else {
                apu.pai.dir = apu;
            }
        }
    }
}