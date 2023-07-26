import java.util.List;

public interface Kolekcja<T> {
    boolean add(T obj);

    boolean delete(T obj);

    List<T> getAll();

    T getCar(int index);
}
