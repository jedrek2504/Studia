
interface WaterBottleInterface{
    String color = "Blue";

    void fillUp();

}


public class InterfaceExample implements WaterBottleInterface {

    public static void main(String[] args) {
        System.out.println(color);

        InterfaceExample ex = new InterfaceExample();
        ex.fillUp();
    }

    @Override //to mowi ze implementuje funkcje ktora juz zostala zaimplementowana w interfacie
    public void fillUp() {
        System.out.println("It's in fillUp");
    }
}
