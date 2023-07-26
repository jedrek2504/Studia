import java.util.List;

public interface Kontener<T> {
    boolean dodaj(T obj);

    boolean usun(T obj);

    List<T> pobierzWszystkie();

    T getDokument(int index);
}
