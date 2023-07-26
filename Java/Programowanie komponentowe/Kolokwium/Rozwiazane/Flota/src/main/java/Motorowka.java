public class Motorowka extends Jednostka {

    public Motorowka(String nazwa, int tonaz, int dlugosc, int liczbaOsobZalogi, int wartosc, int zasieg) {
        super(nazwa, tonaz, dlugosc, liczbaOsobZalogi, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "[Motorowka " + super.toString();
    }
}
