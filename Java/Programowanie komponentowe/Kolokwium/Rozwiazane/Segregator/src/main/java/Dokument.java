import java.util.Comparator;

public class Dokument implements Comparable<Dokument> {
    private int id;
    private String dataUtworzenia;

    public Dokument(int id, String dataUtworzenia) {
        this.id = id;
        this.dataUtworzenia = dataUtworzenia;
    }

    public int getId() {
        return id;
    }

    public String getDataUtworzenia() {
        return dataUtworzenia;
    }

    @Override
    public String toString() {
        return id + ", " + dataUtworzenia;
    }

    public int compareTo(Dokument o) {
        return getDataUtworzenia().compareTo(o.getDataUtworzenia());
    }

    public static java.util.Comparator<Dokument> Comparator = new Comparator<Dokument>() {
        public int compare(Dokument o1, Dokument o2) {
            return o2.getDataUtworzenia().compareTo(o1.getDataUtworzenia());
        }
    };
}
