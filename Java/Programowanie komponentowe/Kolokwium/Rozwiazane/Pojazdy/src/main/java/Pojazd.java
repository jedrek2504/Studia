import java.util.Comparator;

public class Pojazd implements Comparable<Pojazd> {

    protected String nazwa;
    protected int pojemnosc;
    protected int masaDopuszczalna;

    protected String kolor;
    protected int wartosc;
    protected int zasieg;

    public Pojazd(String nazwa, int pojemnosc, int masaDopuszczalna, String kolor, int wartosc, int zasieg) {
        this.nazwa = nazwa;
        this.pojemnosc = pojemnosc;
        this.masaDopuszczalna = masaDopuszczalna;
        this.kolor = kolor;
        this.wartosc = wartosc;
        this.zasieg = zasieg;
    }

    public String getNazwa() {
        return nazwa;
    }

    public int getPojemnosc() {
        return pojemnosc;
    }

    public int getMasaDopuszczalna() {
        return masaDopuszczalna;
    }

    public String getKolor() {
        return kolor;
    }

    public int getWartosc() {
        return wartosc;
    }

    public int getZasieg() {
        return zasieg;
    }

    public void setKolor(String kolor) {
        this.kolor = kolor;
    }

    public void setWartosc(int wartosc) {
        this.wartosc = wartosc;
    }

    public void setZasieg(int zasieg) {
        this.zasieg = zasieg;
    }

    @Override
    public String toString() {
        return nazwa + ", " + pojemnosc + ", " + masaDopuszczalna
                + ", " + kolor + ", " + wartosc + ", " + zasieg;
    }

    public int compareTo(Pojazd o) {
        if (this.masaDopuszczalna == o.masaDopuszczalna) {
            return 0;
        } else if (this.masaDopuszczalna > o.masaDopuszczalna) {
            return 1;
        } else {
            return -1;
        }
    }

    public static java.util.Comparator<Pojazd> Comparator = new Comparator<Pojazd>() {
        public int compare(Pojazd o1, Pojazd o2) {
            return o1.nazwa.compareTo(o2.nazwa);
        }
    };
}
