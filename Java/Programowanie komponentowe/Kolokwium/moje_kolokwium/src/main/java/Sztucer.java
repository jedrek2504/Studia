public class Sztucer extends Bron {
    public Sztucer(double cena, int iloscMiejsca, double kaliber) {
        super(cena, iloscMiejsca, kaliber);
    }

    @Override
    public String toString() {
        return "Sztucer " + super.toString();
    }
}
