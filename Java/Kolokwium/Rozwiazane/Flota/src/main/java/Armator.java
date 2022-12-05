import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Armator implements Kolekcja<Jednostka> {
    List<Jednostka> jednostki = new ArrayList<Jednostka>();
    private int lacznaWartoscFloty = 0;

    public boolean add(Jednostka obj) {
        if(obj.getWartosc() > 0) {
            lacznaWartoscFloty += obj.getWartosc();
            return jednostki.add(obj);
        } 
        return false;
    }

    public boolean delete(Jednostka obj) {
        lacznaWartoscFloty -= obj.getWartosc();
        return jednostki.remove(obj);
    }

    public List<Jednostka> getAll() {
        return Collections.unmodifiableList(jednostki);
    }

    public Jednostka getShip(int index) {
        return jednostki.get(index);
    }

    public int getLacznaWartoscFloty() {
        return lacznaWartoscFloty;
    }

    public void setZasieg(Jednostka obj, int zasieg) {
        obj.setZasieg(zasieg);
    }

    public void setLiczbaOsobZalogi(Jednostka obj, int liczbaOsobZalogi) {
        obj.setLiczbaOsobZalogi(liczbaOsobZalogi);
    }

    public String raport() {
        StringBuilder str = new StringBuilder();
        str.append(this.toString() + "\nJednostka:\n");
        for (Jednostka it : jednostki) {
            str.append(it.toString() + "\n");
        }
        return str.toString();
    }

    @Override
    public String toString() {
        return "Armator: " + lacznaWartoscFloty;
    }

    public void sortDlugosc() {
        Collections.sort(jednostki);
    }

    public void sortNazwa() {
        Collections.sort(jednostki, Jednostka.Comparator);
    }
}

