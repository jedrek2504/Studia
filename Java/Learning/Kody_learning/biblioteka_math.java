package first;

public class Main {
    public static void main(String[] args) {
        //biblioteka Math;
        double x=3.14;
        int y=10;

        double z = Math.max(x,y);
        System.out.println("Max: "+z);
        z = Math.min(x,y);
        System.out.println("Min: "+z);
        z = Math.abs(y);
        System.out.println("Modul: "+z);
        z = Math.sqrt(x);
        System.out.println("Pierwiastek: "+z);
        z = Math.round(x);
        System.out.println("Zaokraglone: "+z);
        z = Math.ceil(x);
        System.out.println("Sufit: "+z);
        z = Math.floor(x);
        System.out.println("Podloga: "+z);
    }
}
