public class Main {
    public static void main(String[] args) {
        Segregator Segregator = new Segregator(10);

        Zwolnienie Zwolnienie1 = new Zwolnienie(1, "2022-12-12");
        Zwolnienie Zwolnienie2 = new Zwolnienie(2, "2022-12-1");

        Rachunek Rachunek1 = new Rachunek(3, "2009-13-1");
        Rachunek Rachunek2 = new Rachunek(4, "2009-13-2");

        Podanie Podanie1 = new Podanie(5,"2010-12-12");
        Podanie Podanie2 = new Podanie(6, "2010-13-12");


        Segregator.dodaj(Zwolnienie1);
        Segregator.dodaj(Zwolnienie2);
        Segregator.dodaj(Rachunek1);
        Segregator.dodaj(Rachunek2);
        Segregator.dodaj(Podanie1);
        Segregator.dodaj(Podanie2);

        System.out.println("Laczne zajete miejsce: " + Segregator.getzajeteMiejsce());
        System.out.println(Segregator.raport());
        System.out.println("Sortowanie:");
        Segregator.sort();
        System.out.println(Segregator.raport());
        System.out.println(Segregator.raport());


        System.out.println("Test usuniecia:");
        System.out.println(Segregator.usun(Segregator.getDokument(0)));
        System.out.println(Segregator.raport());
    }
}
