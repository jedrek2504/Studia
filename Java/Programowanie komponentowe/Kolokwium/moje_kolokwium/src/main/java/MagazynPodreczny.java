import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MagazynPodreczny implements Magazyn<Bron> {
    List<Bron> bronie = new ArrayList<Bron>();
    private final int wielkosc;

    public MagazynPodreczny(int wielkosc) {
        this.wielkosc = wielkosc;
    }

    public boolean dodaj(Bron obj) {
        if(ileWolnegoMiejsca()>0) {
            bronie.add(obj);
            this.sort();
            return true;
        } 
        return false;
    }

    public boolean usun(Bron obj) {
        return bronie.remove(obj);
    }

    int ileWolnegoMiejsca() {
        int suma = 0;
        for(Bron it : bronie) {
            suma+=it.getIloscMiejsca();
        }
        return wielkosc - suma;
    }

    double podajWartosc() {
        double suma=0;
        for(Bron it : bronie) {
            suma+=it.getCena();
        }
        return suma;
    }

    public List<Bron> pobierzWszystkie() {
        return Collections.unmodifiableList(bronie);
    }



    public String raport() {
        StringBuilder str = new StringBuilder();
        str.append(this.toString() + "\nBron:\n");
        for (Bron it : bronie) {
            str.append(it.toString() + "\n");
        }
        return str.toString();
    }

    @Override
    public String toString() {
        return "MagazynPodreczny: " + wielkosc;
    }

    public void sort() {
        Collections.sort(bronie);
    }

}

