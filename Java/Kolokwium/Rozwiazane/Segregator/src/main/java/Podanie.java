public class Podanie extends Dokument {

    public Podanie(int id, String dataUtworzenia) {
        super(id, dataUtworzenia);
    }

    @Override
    public String toString() {
        return "Podanie " + super.toString();
    }
}
