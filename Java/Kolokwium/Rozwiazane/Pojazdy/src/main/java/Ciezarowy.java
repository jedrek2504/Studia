public class Ciezarowy extends Pojazd {
    public Ciezarowy(String nazwa, int pojemnosc, int masaDopuszczalna, String kolor, int wartosc, int zasieg) {
        super(nazwa, pojemnosc, masaDopuszczalna, kolor, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "Ciezarowy " + super.toString();
    }
}
