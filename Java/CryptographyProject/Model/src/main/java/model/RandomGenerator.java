package model;

import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Random;

public class RandomGenerator {
    private static final int NUM_BITS = 1024; // Number of bits for q, p
    private static final int PRIME_CERTAINTY = 100; // Probability that the number is prime: 1 - (1/2)^certainty

    public byte[] concatByteArrays(byte[] a, byte[] b) {
        byte[] result = new byte[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    // AES

    // generates AES key that is of random length {128, 192, 256} bits
    public byte[] generateAESKey() {
        SecureRandom random = new SecureRandom();
        int[] possibleNumbers = {16, 24, 32}; // in bytes
        int randomIndex = new Random().nextInt(possibleNumbers.length);
        byte[] key = new byte[possibleNumbers[randomIndex]];
        random.nextBytes(key);
        return key;
    }

    // DSA

    public BigInteger generateQ() {
        SecureRandom random = new SecureRandom();
        return BigInteger.probablePrime(NUM_BITS, random);
    }

    public BigInteger generateP(BigInteger q) {
        SecureRandom random = new SecureRandom();
        BigInteger p;
        do {
            p = new BigInteger(NUM_BITS + 64, random);
        } while (!p.isProbablePrime(PRIME_CERTAINTY) || !p.subtract(BigInteger.ONE).divide(q).testBit(0));
        return p;
    }

    public BigInteger generateG(BigInteger p, BigInteger q) {
        SecureRandom random = new SecureRandom();
        BigInteger h;
        do {
            h = new BigInteger(p.bitLength() - 1, random);
        } while (h.compareTo(BigInteger.ONE) <= 0 || h.compareTo(p.subtract(BigInteger.ONE)) >= 0);
        BigInteger g = h.modPow(p.subtract(BigInteger.ONE).divide(q), p);
        if (g.compareTo(BigInteger.ONE) == 0) {
            return generateG(p, q); // g cannot be 1
        }
        return g;
    }

    public BigInteger generateX(BigInteger q) {
        SecureRandom random = new SecureRandom();
        BigInteger x;
        do {
            x = new BigInteger(q.bitLength() - 1, random);
        } while (x.compareTo(BigInteger.ZERO) <= 0 || x.compareTo(q) >= 0);
        return x;
    }

    public BigInteger generateY(BigInteger p, BigInteger g, BigInteger x) {
        return g.modPow(x, p);
    }

    public BigInteger modP(BigInteger x, BigInteger p) {
        return x.mod(p);
    }

}
