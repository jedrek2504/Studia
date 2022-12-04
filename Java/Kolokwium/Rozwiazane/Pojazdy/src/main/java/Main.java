public class Main {
    public static void main(String[] args) {
        Wypozyczalnia wypozyczalnia = new Wypozyczalnia();

        Osobowy osobowy1 = new Osobowy("abc", 10, 15, "df", 5, 8);
        Osobowy osobowy2 = new Osobowy("cde", 5, 25, "ef", 6, 7);

        Motor motor1 = new Motor("cdf", 5, 35, "ef", 6, 7);
        Motor motor2 = new Motor("cdg", 5, 45, "ef", 6, 7);

        Ciezarowy ciezarowy1 = new Ciezarowy("cdh", 55, 25, "ef", 6, 7);
        Ciezarowy ciezarowy2 = new Ciezarowy("cdi", 65, 25, "ef", 6, 7);

        wypozyczalnia.add(osobowy1);
        wypozyczalnia.add(osobowy2);
        wypozyczalnia.add(motor1);
        wypozyczalnia.add(motor2);
        wypozyczalnia.add(ciezarowy1);
        wypozyczalnia.add(ciezarowy2);

        System.out.println(ciezarowy1.toString());
        System.out.println("Laczna wartosc: " + wypozyczalnia.getLacznaWartosc());
        System.out.println("Baza" + wypozyczalnia.report());
        System.out.println("Sortowanie po nazwie:");
        wypozyczalnia.sortNazwa();
        System.out.println(wypozyczalnia.report());
        System.out.println("Sortowanie po masie:");
        wypozyczalnia.sortMasa();
        System.out.println(wypozyczalnia.report());


        System.out.println("Test usuniecia:");
        System.out.println(wypozyczalnia.delete(wypozyczalnia.getCar(0)));
        System.out.println(wypozyczalnia.report());

    }
}
