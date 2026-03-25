public class Cliente {

    public static void main(String[] args) {

        System.out.println("Cliente iniciado");

        Implementador implBD = new PublicacaoImplBD();
        Implementador implXML = new PublicacaoImplXML();

        Publicacao livro = new Livro(implBD);
        livro.obterDados(livro);
        livro.getTitulo();
        livro.getAutor(1);

        System.out.println();

        Publicacao revista = new Revista(implXML);
        revista.obterDados(revista);
        revista.getTitulo();
        revista.getAutor(2);

    }

}