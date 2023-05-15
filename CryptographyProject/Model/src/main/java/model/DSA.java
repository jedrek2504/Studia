package model;

import java.lang.*;
import java.util.*;
import java.math.BigInteger;
import java.security.*;

public class DSA {
    class DSAKeyException extends Exception {
        public DSAKeyException(String msg) {
            super(msg);
        }

        ;
    }

    BigInteger p, q, h, g, x, y, k, r, s, w, u1, u2, v, pm1, km1;
    MessageDigest digest;
    int keyLen = 512;
    int ilZnHex = keyLen / 4;//ilość znaków hex wyświetlanych w polu klucza
    Random random = new Random();

    public DSA() {
        try {
            digest = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException ex) {
            ex.printStackTrace();
        }
    }

    public void generateKey() {
        //todo
        int rand = 512 + (int) random.nextFloat() * 512;
        while (true)
            if (rand % 64 == 0) break;
            else rand++;
        keyLen = rand;
        q = BigInteger.probablePrime(160, new Random());
        BigInteger pom1, pom2;
        do {
            pom1 = BigInteger.probablePrime(keyLen, new Random());
            pom2 = pom1.subtract(BigInteger.ONE);
            pom1 = pom1.subtract(pom2.remainder(q));
        } while (!pom1.isProbablePrime(2));
        p = pom1;
        pm1 = p.subtract(BigInteger.ONE);
        h = new BigInteger(keyLen - 2, random);
        while (true)
            if (h.modPow(pm1.divide(q), p).compareTo(BigInteger.ONE) > 0) break;
            else h = new BigInteger(keyLen - 2, random);
        g = h.modPow(pm1.divide(q), p);
        do
            x = new BigInteger(160 - 2, random);
        while (x.compareTo(BigInteger.ZERO) != 1);
        y = g.modPow(x, p);
    }


    public BigInteger[] sign(byte[] tekst) {
        k = new BigInteger(160 - 2, random);
        r = g.modPow(k, p).mod(q);
        km1 = k.modInverse(q);

        digest.update(tekst);
        BigInteger hash = new BigInteger(1, digest.digest());
        BigInteger pom = hash.add(x.multiply(r));
        s = km1.multiply(pom).mod(q);
        BigInteger[] podpis = new BigInteger[2];
        podpis[0] = r;
        podpis[1] = s;
        return podpis;
    }

    public boolean verify(byte[] tekstJawny, BigInteger[] podpis) {
        digest.update(tekstJawny);
        BigInteger hash = new BigInteger(1, digest.digest());
        w = podpis[1].modInverse(q);
        u1 = hash.multiply(w).mod(q);
        u2 = podpis[0].multiply(w).mod(q);
        v = g.modPow(u1, p).multiply(y.modPow(u2, p)).mod(p).mod(q);
        return v.compareTo(podpis[0]) == 0;
    }

}
