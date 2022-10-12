package first;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); //skladnia obiektu uzywanego do inputu
//deklaracja zmiennych
        double x;
        double y;
        double z;

        System.out.println("Podaj x:");
        x = scanner.nextDouble(); //trzeba ulamki dac za pomoca przecinka ","
        System.out.println("Podaj y:");
        y = scanner.nextDouble();

        z = Math.sqrt((x*x)+(y*y));

        System.out.println("Przeciwprostokatna: "+z);

        scanner.close(); //mozna tak robic oplaca sie

    }
}
