public class Main {
    public static void main(String[] args) {
        Wypozyczalnia wypozyczalnia = new Wypozyczalnia();

        KlasaPierwsza klasapierwsza1 = new KlasaPierwsza();
        KlasaPierwsza klasapierwsza2 = new KlasaPierwsza();

        KlasaDruga klasadruga1 = new KlasaDruga();
        KlasaDruga klasadruga2 = new KlasaDruga();

        KlasaTrzecia klasatrzecia1 = new KlasaTrzecia();
        KlasaTrzecia klasatrzecia2 = new KlasaTrzecia();


        wypozyczalnia.add(klasapierwsza1);
        wypozyczalnia.add(klasapierwsza2);
        wypozyczalnia.add(klasadruga1);
        wypozyczalnia.add(klasadruga2);
        wypozyczalnia.add(klasatrzecia1);
        wypozyczalnia.add(klasatrzecia2);

        System.out.println("Laczna ...: " + wypozyczalnia.getLaczna());
        System.out.println(wypozyczalnia.raport());
        System.out.println("Sortowanie:");
        wypozyczalnia.sort1();
        System.out.println(wypozyczalnia.raport());
        System.out.println(wypozyczalnia.raport());


        System.out.println("Test usuniecia:");
        System.out.println(wypozyczalnia.delete(wypozyczalnia.getKlasa(0)));
        System.out.println(wypozyczalnia.raport());
    }
}
