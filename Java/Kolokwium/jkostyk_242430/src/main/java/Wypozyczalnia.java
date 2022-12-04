import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Wypozyczalnia implements Interface<Klasa> {
    List<Klasa> lista = new ArrayList<Klasa>();
    private int laczne = 0;

    public boolean add(Klasa obj) {
        if(obj.getWartosc() > laczne) {
            laczne += obj.getWartosc();
            return lista.add(obj);
        } 
        return false;
    }

    public boolean delete(Klasa obj) {
        laczne -= obj.getWartosc();
        return lista.remove(obj);
    }

    public List<Klasa> getAll() {
        return Collections.unmodifiableList(lista);
    }

    public Klasa getKlasa(int index) {
        return lista.get(index);
    }


    public String raport() {
        StringBuilder str = new StringBuilder();
        str.append(this.toString() + "\nKlasa:\n");
        for (Klasa it : lista) {
            str.append(it.toString() + "\n");
        }
        return str.toString();
    }

    @Override
    public String toString() {
        return "Wypozyczalnia: " + value1 + ", " + value2 + ", " + value3
                + ", " + value4 + ", " + value5 + ", " + value6;
    }

    public void sort1() {
        Collections.sort(lista);
    }

    public void sort2() {
        Collections.sort(lista, Klasa.Comparator);
    }
}

