import java.util.Comparator;

public class Klasa implements Comparable<Klasa> {







    @Override
    public String toString() {
        return value1 + ", " + value2 + ", " + value3
                + ", " + value4 + ", " + value5 + ", " + value6;
    }

    public int compareTo(Pojazd o) {
        if (this.value == o.value) {
            return 0;
        } else if (this.value > o.value) {
            return 1;
        } else {
            return -1;
        }
    }

    public static java.util.Comparator<Klasa> Comparator = new Comparator<Klasa>() {
        public int compare(Klasa o1, Klasa o2) {
            return o1.value.compareTo(o2.value);
        }
    };
}
