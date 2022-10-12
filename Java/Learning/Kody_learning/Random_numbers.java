package first;

import java.util.Random; //Random class

public class Main {
    public static void main(String[] args) {
        Random rand = new Random(); //trzeba zrobic obiekt klasy random u nas rand

        int x = rand.nextInt(6) + 1; //dodajemy 1 zeby nie miec przedzialu 0-5
        System.out.println(x);
        double y = rand.nextDouble(); //jezlei nic nie wpiszemy to bedzie przedzial <0.0-1.0>
        System.out.println(y);
        boolean z = rand.nextBoolean(); //true/false -> bool piszemy boolean
        System.out.println(z);
    }
}
