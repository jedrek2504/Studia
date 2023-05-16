package model;

import java.util.*;
import java.math.BigInteger;
import java.security.*;

public class DSA {
    BigInteger p, q, h, g, x, y, k, r, s, w, u1, u2, v, pm1, km1;
    MessageDigest digest; // compute the hash value of data using the SHA-256 algorithm.
    int keyLen = 512;
    Random random = new Random();

    public DSA() {
        try {
            // Create an instance of MessageDigest with SHA-256 algorithm
            digest = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    // Generates a random number between 512 and 1024
    private int generateRandomNumber() {
        return 512 + random.nextInt(513);
    }

    private int findNextMultipleOf64(int number) {
        while (number % 64 != 0) {
            // Increment the number by 1 until it is divisible by 64
            number++;
        }
        // Return the next multiple of 64
        return number;
    }

    // Generates a probable prime number with the specified bit length using the probablePrime method
    private BigInteger generateProbablePrime(int bitLength) {
        return BigInteger.probablePrime(bitLength, new Random());
    }

    // The constructor generates a random BigInteger with the specified bit length, random number is generated
    // using the provided Random instance
    private BigInteger generateRandomBigInteger(int bitLength) {
        return new BigInteger(bitLength, random);
    }

    public void generateKey() {
        // Generate a random number and find the next multiple of 64
        int rand = generateRandomNumber();
        keyLen = findNextMultipleOf64(rand);

        // Generate a probable prime q with bit length 160
        q = generateProbablePrime(160);

        BigInteger pom1, pom2;
        do {
            // Generate a probable prime number with the key length
            pom1 = generateProbablePrime(keyLen);

            // Calculate pom2 as pom1 - 1
            pom2 = pom1.subtract(BigInteger.ONE);

            // Adjust pom1 to be a multiple of q
            pom1 = pom1.subtract(pom2.remainder(q));
        } while (!pom1.isProbablePrime(2));

        // Assign pom1 as p and calculate pm1 as p - 1
        p = pom1;
        pm1 = p.subtract(BigInteger.ONE);

        // Generate a random BigInteger h with key length - 2
        h = generateRandomBigInteger(keyLen - 2);

        // Ensure h satisfies the condition h^(pm1/q) > 1
        while (h.modPow(pm1.divide(q), p).compareTo(BigInteger.ONE) <= 0) {
            h = generateRandomBigInteger(keyLen - 2);
        }

        // Calculate g as h^(pm1/q)
        g = h.modPow(pm1.divide(q), p);

        do {
            // Generate a random BigInteger x with bit length 158 < 160
            x = generateRandomBigInteger(158);

            // Repeat until x is greater than zero
        } while (x.compareTo(BigInteger.ZERO) != 1);

        // Calculate y as g^x mod p
        y = g.modPow(x, p);
    }


    public BigInteger[] sign(byte[] text) {
        // Generate a random BigInteger k with bit length 158 < 160
        k = generateRandomBigInteger(158);

        // Calculate r as g^k mod p mod q
        r = g.modPow(k, p).mod(q);

        // Calculate km1 as k^(-1) mod q
        km1 = k.modInverse(q);

        // Update the digest with the given text
        digest.update(text);

        // Compute the hash value of the digest as a positive BigInteger
        BigInteger hash = new BigInteger(1, digest.digest());

        // Calculate pom as hash + (x * r)
        BigInteger pom = hash.add(x.multiply(r));

        // Calculate s as km1 * pom mod q
        s = km1.multiply(pom).mod(q);

        // Create an array containing r and s as the signature
        BigInteger[] signature = {r, s};

        // Return the signature array
        return signature;
    }


    public boolean verify(byte[] plainText, BigInteger[] signature) {
        // Update the digest with the plainText
        digest.update(plainText);

        // Compute the hash value of the digest as a positive BigInteger
        BigInteger hash = new BigInteger(1, digest.digest());

        // Calculate w as signature[1]^(-1) mod q
        w = signature[1].modInverse(q);

        // Calculate u1 as hash * w mod q
        u1 = hash.multiply(w).mod(q);

        // Calculate u2 as signature[0] * w mod q
        u2 = signature[0].multiply(w).mod(q);

        // Calculate v as (g^u1 * y^u2 mod p) mod q
        v = g.modPow(u1, p).multiply(y.modPow(u2, p)).mod(p).mod(q);

        // Check if v is equal to the first component of the signature
        return v.equals(signature[0]);
    }

}
