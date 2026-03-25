public abstract class Publicacao {

    protected Implementador imp;

    public Publicacao(Implementador imp) {
        this.imp = imp;
    }

    public void obterDados(Object tipo) {
        System.out.println("Publicacao.obterDados() chamado");
        imp.getDados(tipo);
    }

    public abstract String getTitulo();

    public abstract String getAutor(int id);

}