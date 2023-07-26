public class Rachunek extends Dokument {

    public Rachunek(int id, String dataUtworzenia) {
        super(id, dataUtworzenia);
    }

    @Override
    public String toString() {
        return "Rachunek " + super.toString();
    }
}
