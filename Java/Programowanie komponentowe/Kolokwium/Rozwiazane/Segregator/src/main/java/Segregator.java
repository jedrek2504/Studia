import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Segregator implements Kontener<Dokument> {
    List<Dokument> dokumenty = new ArrayList<Dokument>();
    private int pojemnosc;
    private int zajeteMiejsce = 0;

    public Segregator(int pojemnosc) {
        this.pojemnosc = pojemnosc;
    }

    public int getzajeteMiejsce() {
        return zajeteMiejsce;
    }

    public boolean dodaj(Dokument obj) {
        if(zajeteMiejsce < pojemnosc) {
            zajeteMiejsce += 1;
            dokumenty.add(obj);
            this.sort();
            return true;
        } 
        return false;
    }

    public boolean usun(Dokument obj) {
        zajeteMiejsce -= 1;
        return dokumenty.remove(obj);
    }

    public List<Dokument> pobierzWszystkie() {
        return Collections.unmodifiableList(dokumenty);
    }

    public Dokument getDokument(int index) {
        return dokumenty.get(index);
    }

    public String raport() {
        StringBuilder str = new StringBuilder();
        str.append(this.toString() + "\nDokumenty:\n");
        for (Dokument it : dokumenty) {
            str.append(it.toString() + "\n");
        }
        return str.toString();
    }

    public void sort() {
        Collections.sort(dokumenty);
    }

    @Override
    public String toString() {
        return "Segregator: " + pojemnosc + ", " + zajeteMiejsce;
    }

}

