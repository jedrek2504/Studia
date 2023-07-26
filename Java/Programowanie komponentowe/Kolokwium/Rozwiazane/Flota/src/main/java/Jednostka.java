import java.util.Comparator;

public class Jednostka implements Comparable<Jednostka> {
    private final String nazwa;
    private final int tonaz;
    private final int dlugosc;
    private int liczbaOsobZalogi;
    private int wartosc;
    private int zasieg;

    public Jednostka(String nazwa, int tonaz, int dlugosc, int liczbaOsobZalogi, int wartosc, int zasieg) {
        this.nazwa = nazwa;
        this.tonaz = tonaz;
        this.dlugosc = dlugosc;
        this.liczbaOsobZalogi = liczbaOsobZalogi;
        this.wartosc = wartosc;
        this.zasieg = zasieg;
    }

    public String getNazwa() {
        return nazwa;
    }

    public int getTonaz() {
        return tonaz;
    }

    public int getDlugosc() {
        return dlugosc;
    }

    public int getLiczbaOsobZalogi() {
        return liczbaOsobZalogi;
    }

    public int getWartosc() {
        return wartosc;
    }

    public int getZasieg() {
        return zasieg;
    }

    public void setLiczbaOsobZalogi(int liczbaOsobZalogi) {
        this.liczbaOsobZalogi = liczbaOsobZalogi;
    }

    public void setWartosc(int wartosc) {
        this.wartosc = wartosc;
    }

    public void setZasieg(int zasieg) {
        this.zasieg = zasieg;
    }

    @Override
    public String toString() {
        return nazwa + ", " + tonaz + ", " + dlugosc
                + ", " + liczbaOsobZalogi + ", " + wartosc + ", " + zasieg + "]";
    }

    public int compareTo(Jednostka o) {
        if (this.dlugosc == o.dlugosc) {
            return 0;
        } else if (this.dlugosc > o.dlugosc) {
            return 1;
        } else {
            return -1;
        }
    }

    public static java.util.Comparator<Jednostka> Comparator = new Comparator<Jednostka>() {
        public int compare(Jednostka o1, Jednostka o2) {
            return o1.nazwa.compareTo(o2.nazwa);
        }
    };
}
