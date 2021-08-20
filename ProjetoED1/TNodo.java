public class TNodo {
    TNodo esq;
    TInfo item;
    TNodo dir;
    TNodo pai;
    int bal = 0;
    int hesq = 0;
    int hdir = 0;

    public TNodo(TInfo item, TNodo pai) {
        this.item = new TInfo(item.CodUF, item.CodMun, item.Regiao, item.Estado, item.Municipio, item.nomeRegiao,
                item.Data, item.CasosAcumulados, item.CasosNovos, item.ObitosAcumulados, item.ObitosNovos);
        this.esq = null;
        this.dir = null;
        // this.pai = null;
        this.pai = pai;
    }
}
