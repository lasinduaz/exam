public class acessmodi {

    private String stuName;
    private String school;
    public int age;
    public boolean gender;
    protected int acemicYear;

    public static void main(String[] args) {
        acessmodi obj = new acessmodi();
        obj.stuName = "John"; // OK: private, but accessed inside the class
        obj.school = "ABC School"; // OK: private, but accessed inside the class
        obj.age = 20; // OK: public
        obj.gender = true; // OK: public
        obj.acemicYear = 2024; // OK: protected
        System.out.println(obj.stuName);
        System.out.println(obj.school);
        System.out.println(obj.age);
        System.out.println(obj.gender);
        System.out.println(obj.acemicYear);
    }

}
