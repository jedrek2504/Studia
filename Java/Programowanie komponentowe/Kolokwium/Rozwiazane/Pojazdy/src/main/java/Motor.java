public class Motor extends Pojazd {

    public Motor(String nazwa, int pojemnosc, int masaDopuszczalna, String kolor, int wartosc, int zasieg) {
        super(nazwa, pojemnosc, masaDopuszczalna, kolor, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "Motor " + super.toString();
    }
}
