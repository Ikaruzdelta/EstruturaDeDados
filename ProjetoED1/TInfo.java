public class TInfo {
    public String CodMun;
    public String CodUF;
    public String Regiao;
    public String Estado;
    public String Municipio;
    public String nomeRegiao;
    public String Data;
    public String CasosAcumulados;
    public String CasosNovos;
    public String ObitosAcumulados;
    public String ObitosNovos;

    public TInfo(String codUF, String codMun, String regiao, String estado, String municipio, String nomeRegiao,
            String data, String casosAcumulados, String casosNovos, String obitosAcumulados, String obitosNovos) {
        this.CodUF = codUF;
        this.CodMun = codMun;
        this.Regiao = regiao;
        this.Estado = estado;
        this.Municipio = municipio;
        this.nomeRegiao = nomeRegiao;
        this.Data = data;
        this.CasosAcumulados = casosAcumulados;
        this.CasosNovos = casosNovos;
        this.ObitosAcumulados = obitosAcumulados;
        this.ObitosNovos = obitosNovos;
    }

    public TInfo() {

    }

    public String toString() {
        return "COD UF: " + CodUF + " CODMUN: " + CodMun + " DATA: " + Data + " REGIAO: " + Regiao + " MUNICIPIO: "
                + Municipio + " CASOS NOVOS: " + CasosNovos + " CASOS ACUMULADOS: " + CasosAcumulados
                + " OBITOS NOVOS: " + ObitosNovos + " OBITOS ACUMULADOS: " + ObitosAcumulados;
    }

    public String getCodMun() {
        return CodMun;
    }
}