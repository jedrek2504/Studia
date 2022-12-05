import java.util.List;

public interface Magazyn<T> {
    boolean dodaj(T obj);

    boolean usun(T obj);

    List<T> pobierzWszystkie();
}
