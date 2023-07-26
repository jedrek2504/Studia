public class Zwolnienie extends Dokument {

    public Zwolnienie(int id, String dataUtworzenia) {
        super(id, dataUtworzenia);
    }

    @Override
    public String toString() {
        return "Zwolnienie " + super.toString();
    }
}
