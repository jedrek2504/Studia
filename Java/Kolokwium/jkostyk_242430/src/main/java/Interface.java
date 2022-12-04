import java.util.List;

public interface Interface <T> {
    boolean add(T obj);

    boolean delete(T obj);

    List<T> getAll();

    T getKlasa(int index);
}
