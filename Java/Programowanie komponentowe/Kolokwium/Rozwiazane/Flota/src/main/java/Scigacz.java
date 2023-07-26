public class Scigacz extends Jednostka {

    public Scigacz(String nazwa, int tonaz, int dlugosc, int liczbaOsobZalogi, int wartosc, int zasieg) {
        super(nazwa, tonaz, dlugosc, liczbaOsobZalogi, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "[Scigacz " + super.toString();
    }
}
