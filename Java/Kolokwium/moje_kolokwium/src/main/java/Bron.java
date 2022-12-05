import java.util.Objects;

public class Bron implements Comparable<Bron> {
    private final double cena;
    private final int iloscMiejsca;
    private final double kaliber;

    public Bron(double cena, int iloscMiejsca, double kaliber) {
        this.cena = cena;
        this.iloscMiejsca = iloscMiejsca;
        this.kaliber = kaliber;
    }

    public double getCena() {
        return cena;
    }

    public int getIloscMiejsca() {
        return iloscMiejsca;
    }

    public double getKaliber() {
        return kaliber;
    }

    @Override
    public String toString() {
        return cena + ", " + iloscMiejsca + ", " + kaliber;

    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Bron bron = (Bron) o;
        return Double.compare(bron.cena, cena) == 0 && iloscMiejsca == bron.iloscMiejsca && Double.compare(bron.kaliber, kaliber) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(cena, iloscMiejsca, kaliber);
    }

    public int compareTo(Bron o) {
        if (this.kaliber == o.kaliber) {
            return 0;
        } else if (this.kaliber > o.kaliber) {
            return -1;
        } else {
            return 1;
        }
    }

}
