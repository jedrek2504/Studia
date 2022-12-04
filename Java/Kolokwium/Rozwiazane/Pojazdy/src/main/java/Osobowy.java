public class Osobowy extends Pojazd {

    public Osobowy(String nazwa, int pojemnosc, int masaDopuszczalna, String kolor, int wartosc, int zasieg) {
        super(nazwa, pojemnosc, masaDopuszczalna, kolor, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "Osobowy " + super.toString();
    }

}
