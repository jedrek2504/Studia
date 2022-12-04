import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Lodowka implements Kontener<Jedzenie> {
    List<Jedzenie> jedzenie = new ArrayList<Jedzenie>();
    private final int pojemnosc;
    private int zajeteMiejsce = 0;

    public Lodowka(int pojemnosc) {
        this.pojemnosc = pojemnosc;
    }

    public int getPojemnosc() {
        return pojemnosc;
    }

    public int ileZajetegoMiejsca() {
        return zajeteMiejsce;
    }

    public int ileWolnegoMiejsca() {
        return pojemnosc-zajeteMiejsce;
    }


    public boolean dodaj(Jedzenie obj) {
        if(obj.getRozmiar()<=ileWolnegoMiejsca()) {
            zajeteMiejsce+=obj.getRozmiar();
            jedzenie.add(obj);
            return true;
        }
        return false;
    }

    public boolean usun(Jedzenie obj) {
        zajeteMiejsce-=obj.getRozmiar();
        return jedzenie.remove(obj);
    }

    public List<Jedzenie> pobierzWszystkie() {
        return Collections.unmodifiableList(jedzenie);
    }

    public String report() {
        StringBuilder str = new StringBuilder();
        for (Jedzenie it : jedzenie) {
            str.append(it.toString() + "\n");
        }

        return str.toString();
    }
}
