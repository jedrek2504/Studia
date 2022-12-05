import org.junit.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class TestBron {
    @Test
    public void test() {
        MagazynPodreczny magazynPodreczny = new MagazynPodreczny(10);
        Pistolet pistolet = new Pistolet(10 , 2, 0.5);
        Rewolwer rewolwer = new Rewolwer(10 , 2, 9);
        Sztucer sztucer = new Sztucer(11 , 6, 50.6);
        assertTrue(magazynPodreczny.dodaj(pistolet));
        assertTrue(magazynPodreczny.dodaj(rewolwer));
        assertTrue(magazynPodreczny.dodaj(sztucer));
        assertEquals(magazynPodreczny.ileWolnegoMiejsca(), 0);
        assertEquals(magazynPodreczny.podajWartosc(), 31);
        Sztucer sztucer2 = new Sztucer(11 , 6, 50.6);
        assertFalse(magazynPodreczny.dodaj(sztucer2));
        assertTrue(magazynPodreczny.pobierzWszystkie().get(0) == sztucer);
        assertTrue(magazynPodreczny.pobierzWszystkie().get(1) == rewolwer);
        assertTrue(magazynPodreczny.pobierzWszystkie().get(2) == pistolet);
    }

    public void test2() {
        MagazynPodreczny magazynPodreczny = new MagazynPodreczny(10);
        Pistolet pistolet = new Pistolet(10 , 2, 0.5);
        Rewolwer rewolwer = new Rewolwer(10 , 2, 9);
        Sztucer sztucer = new Sztucer(11 , 6, 50.6);
        assertTrue(magazynPodreczny.dodaj(pistolet));
        assertTrue(magazynPodreczny.dodaj(rewolwer));
        assertTrue(magazynPodreczny.dodaj(sztucer));
        assertEquals(magazynPodreczny.ileWolnegoMiejsca(), 0);
        assertEquals(magazynPodreczny.podajWartosc(), 31);
        assertTrue(magazynPodreczny.usun(pistolet));
        assertEquals(magazynPodreczny.ileWolnegoMiejsca(), 2);
        assertEquals(magazynPodreczny.podajWartosc(), 21);
        assertTrue(magazynPodreczny.pobierzWszystkie().get(0) == sztucer);
        assertTrue(magazynPodreczny.pobierzWszystkie().get(1) == rewolwer);
    }

}
