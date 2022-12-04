public class main {
    public static void main(String[] args) {
        Lodowka lodowka = new Lodowka(100);
        Jajka jajka1 = new Jajka(10);
        Jajka jajka2 = new Jajka(10);

        Mieso mieso1 = new Mieso(20);
        Mieso mieso2 = new Mieso(20);

        Mleko melko1 = new Mleko(5);
        Mleko melko2 = new Mleko(5);

        lodowka.dodaj(jajka1);
        lodowka.dodaj(jajka2);
        lodowka.dodaj(mieso1);
        lodowka.dodaj(mieso2);
        lodowka.dodaj(melko1);
        lodowka.dodaj(melko2);

        System.out.println("WolneMiejsce: " + lodowka.ileWolnegoMiejsca());

        System.out.println("Baza: ");
        System.out.println(lodowka.report());
    }
}
