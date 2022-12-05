public class Main {
    public static void main(String[] args) {
        Armator armator = new Armator();

        Motorowka motorowka1 = new Motorowka("Pila Tango", 1, 1, 10, 100, 50);
        Motorowka motorowka2 = new Motorowka("Pila Tango2", 1, 1, 10, 100, 50);

        Tankowiec tankowiec1 = new Tankowiec("BigBen", 2, 2, 20, 200, 100);
        Tankowiec tankowiec2 = new Tankowiec("BigBen2", 2, 3, 20, 200, 100);

        Scigacz scigacz1 = new Scigacz("Wroooom", 3, 5, 1, 550, 200);
        Scigacz scigacz2 = new Scigacz("Wroooom2", 3, 5, 1, 550, 200);

        armator.add(motorowka1);
        armator.add(motorowka2);
        armator.add(tankowiec1);
        armator.add(tankowiec2);
        armator.add(scigacz1);
        armator.add(scigacz2);

        System.out.println("Laczna wartosc floty: " + armator.getLacznaWartoscFloty());
        System.out.println(armator.raport());
        System.out.println("Sortowanie po nazwie:");
        armator.sortNazwa();
        System.out.println(armator.raport());
        System.out.println("Sortowanie po dlugosci:");
        armator.sortDlugosc();
        System.out.println(armator.raport());

        System.out.println("Test usuniecia:");
        System.out.println("usunieto element o indeksie 0? :" + armator.delete(armator.getShip(0)));
        System.out.println(armator.raport());
    }
}
