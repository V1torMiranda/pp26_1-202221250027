public class Livro extends Publicacao {

    public Livro(Implementador imp) {
        super(imp);
    }

    public String getISBN() {
        System.out.println("Livro.getISBN() chamado");
        return "";
    }

    @Override
    public String getTitulo() {
        System.out.println("Livro.getTitulo() chamado");
        return "";
    }

    @Override
    public String getAutor(int id) {
        System.out.println("Livro.getAutor() chamado");
        return "";
    }

}