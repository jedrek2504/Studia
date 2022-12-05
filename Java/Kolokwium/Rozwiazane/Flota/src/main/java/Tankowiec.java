public class Tankowiec extends Jednostka {

    public Tankowiec(String nazwa, int tonaz, int dlugosc, int liczbaOsobZalogi, int wartosc, int zasieg) {
        super(nazwa, tonaz, dlugosc, liczbaOsobZalogi, wartosc, zasieg);
    }

    @Override
    public String toString() {
        return "[Tankowiec " + super.toString();
    }
}
