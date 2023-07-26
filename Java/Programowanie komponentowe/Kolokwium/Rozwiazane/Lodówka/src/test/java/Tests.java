import org.junit.Test;
import static org.junit.jupiter.api.Assertions.*;

public class Tests {

    @Test
    public void test1() {
        Lodowka lodowka = new Lodowka(35);
        Jajka jajka1 = new Jajka(10);
        Mieso mieso1 = new Mieso(20);
        Mleko melko1 = new Mleko(5);
        lodowka.dodaj(jajka1);
        lodowka.dodaj(mieso1);
        lodowka.dodaj(melko1);
        assertEquals(lodowka.ileWolnegoMiejsca(), 0);
        assertEquals(lodowka.ileZajetegoMiejsca(), 35);
        Mleko melko2 = new Mleko(5);
        assertFalse(lodowka.dodaj(melko2));
    }
}
