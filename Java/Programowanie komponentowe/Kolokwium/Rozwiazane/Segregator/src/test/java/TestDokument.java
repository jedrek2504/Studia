import org.junit.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TestDokument {
    @Test
    public void test1() {
        Segregator Segregator = new Segregator(4);
        Zwolnienie Zwolnienie1 = new Zwolnienie(1, "2022-12-12");
        Zwolnienie Zwolnienie2 = new Zwolnienie(2, "2022-12-1");
        Podanie Podanie1 = new Podanie(3,"2010-12-12");
        Podanie Podanie2 = new Podanie(4, "2010-12-1");
        Segregator.dodaj(Zwolnienie1);
        Segregator.dodaj(Zwolnienie2);
        Segregator.dodaj(Podanie1);
        Segregator.dodaj(Podanie2);
        assertEquals(Segregator.getzajeteMiejsce(), 4);
        assertTrue(Segregator.getDokument(0) == Podanie2);
        assertTrue(Segregator.getDokument(1) == Podanie1);
        Rachunek Rachunek1 = new Rachunek(5, "2009-13-1");
        assertFalse(Segregator.dodaj(Rachunek1));
        assertTrue(Segregator.getDokument(0) == Podanie2);

    }
    @Test
    public void test2() {
        Segregator Segregator = new Segregator(4);
        Zwolnienie Zwolnienie1 = new Zwolnienie(1, "2022-12-12");
        Zwolnienie Zwolnienie2 = new Zwolnienie(2, "2022-12-1");
        Podanie Podanie1 = new Podanie(3,"2010-12-12");
        Podanie Podanie2 = new Podanie(4, "2010-12-1");
        Segregator.dodaj(Zwolnienie1);
        Segregator.dodaj(Zwolnienie2);
        Segregator.dodaj(Podanie1);
        Segregator.dodaj(Podanie2);
        assertEquals(Segregator.getzajeteMiejsce(), 4);
        assertTrue(Segregator.getDokument(0) == Podanie2);
        assertTrue(Segregator.getDokument(1) == Podanie1);
        assertTrue(Segregator.usun(Zwolnienie1));
        assertEquals(Segregator.getzajeteMiejsce(), 3);
    }
}
