public class Typecasting {
    public static void main(String[] args) {
        int myInt = 9;
        double myDouble = myInt; // Automatic casting: int to double

        System.out.println(myInt); // Outputs 9
        System.out.println(myDouble); // Outputs 9.0
        String txt = "The character \\ is called backslash.";
        System.out.println(txt);

        String [] cars = { "Volvo", "BMW", "Ford", "Mazda" };
        for (String i: cars)
        {
            System.out.println(i);
        }

    }
}