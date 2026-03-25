public class Revista extends Publicacao {

    public Revista(Implementador imp) {
        super(imp);
    }

    public String getArtigo() {
        System.out.println("Revista.getArtigo() chamado");
        return "";
    }

    @Override
    public String getTitulo() {
        System.out.println("Revista.getTitulo() chamado");
        return "";
    }

    @Override
    public String getAutor(int id) {
        System.out.println("Revista.getAutor() chamado");
        return "";
    }

}