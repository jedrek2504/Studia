import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Wypozyczalnia implements Interface<Klasa> {
    List<Klasa> list = new ArrayList<Klasa>();
    private int value = 0;

    public int getValue() {
        return value;
    }

    public boolean add(Klasa obj) {
        if(obj.getWartosc() > value) {
            value += obj.getWartosc();
            return list.add(obj);
        } 
        return false;
    }

    public boolean delete(Klasa obj) {
        value -= obj.getWartosc();
        return list.remove(obj);
    }

    public List<Klasa> getAll() {
        return Collections.unmodifiableList(list);
    }

    public Klasa getKlasa(int index) {
        return list.get(index);
    }

    public void setKolor(Klasa obj, String kolor) {
        obj.set();
    }

    public void setWartosc(Klasa obj, int wartosc) {
        obj.set();
    }

    public void set(Klasa obj, int zasieg) {
        obj.set();
    }

    public String raport() {
        StringBuilder str = new StringBuilder();
        str.append(this.toString() + "\nKlasa:\n");
        for (Klasa it : list) {
            str.append(it.toString() + "\n");
        }
        return str.toString();
    }

    @Override
    public String toString() {
        return value1 + ", " + value2 + ", " + value3
                + ", " + value4 + ", " + value5 + ", " + value6;
    }

    public void sort1() {
        Collections.sort(list);
    }

    public void sort2() {
        Collections.sort(list, Klasa.Comparator);
    }
}

