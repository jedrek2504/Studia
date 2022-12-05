public class Pistolet extends Bron {
    public Pistolet(double cena, int iloscMiejsca, double kaliber) {
        super(cena, iloscMiejsca, kaliber);
    }

    @Override
    public String toString() {
        return "Pistolet " + super.toString();
    }
}
