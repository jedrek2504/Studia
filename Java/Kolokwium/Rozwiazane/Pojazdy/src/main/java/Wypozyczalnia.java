import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Wypozyczalnia implements Kolekcja<Pojazd> {
    List<Pojazd> pojazdy = new ArrayList<Pojazd>();
    private int lacznaWartosc=0;

    public boolean add(Pojazd obj) {
        lacznaWartosc += obj.getWartosc();
        return pojazdy.add(obj);
    }


    public boolean delete(Pojazd obj) {
        lacznaWartosc -= obj.getWartosc();
        return pojazdy.remove(obj);
    }


    public List<Pojazd> getAll() {
        return Collections.unmodifiableList(pojazdy);
    }


    public Pojazd getCar(int index) {
        return pojazdy.get(index);
    }

    public int getLacznaWartosc() {
        return lacznaWartosc;
    }

    public void setKolor(Pojazd obj, String kolor) {
        obj.setKolor(kolor);
    }

    public void setWartosc(Pojazd obj, int wartosc) {
        obj.setWartosc(wartosc);
    }

    public void setZasieg(Pojazd obj, int zasieg) {
        obj.setZasieg(zasieg);
    }

    public String report() {
        StringBuilder str = new StringBuilder();
        for(Pojazd it : pojazdy) {
            str.append(it.toString() + '\n');
        }
        return str.toString();
    }

    public void sortMasa() {
        Collections.sort(pojazdy);
    }

    public void sortNazwa() {
        Collections.sort(pojazdy, Pojazd.Comparator);
    }
}
