public class Main {
    public static void main(String[] args) {
        MagazynPodreczny magazynPodreczny = new MagazynPodreczny(100);

        Rewolwer rewolwer1 = new Rewolwer(12.5 , 1, 9);
        Rewolwer rewolwer2 = new Rewolwer(16.5 , 1, 9);

        Pistolet pistolet1 = new Pistolet(20.5 , 2, 0.5);
        Pistolet pistolet2 = new Pistolet(21.5, 2, 10.11);

        Sztucer sztucer1 = new Sztucer(50.5 , 6, 50.6);
        Sztucer sztucer2 = new Sztucer(60.5 , 6, 15);

        magazynPodreczny.dodaj(rewolwer1);
        magazynPodreczny.dodaj(rewolwer2);
        magazynPodreczny.dodaj(pistolet1);
        magazynPodreczny.dodaj(pistolet2);
        magazynPodreczny.dodaj(sztucer1);
        magazynPodreczny.dodaj(sztucer2);

        System.out.println("Wolne miejsce: " + magazynPodreczny.ileWolnegoMiejsca());
        System.out.println("Laczna wartosc: " + magazynPodreczny.podajWartosc());
        System.out.println(magazynPodreczny.raport());
    }
}
