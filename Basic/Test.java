public class Test {
    int x;

    public static void main(String[] args) {
        Test obj1 = new Test();
        Test obj2 = new Test();

        obj1.x = 21;
        obj2.x = 22;
        System.out.println(obj1.x);
        System.out.println(obj2.x);

    }
}