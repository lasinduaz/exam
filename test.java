public class test {
    public static void main(String[] args) {
        int a[] = {4, 2, 15, 30, 25};

        int i, j, m;
        i = ++a[1];
        j = a[1]++;
        m = a[i++];

        System.out.println(i + " " + j + " " + m);
    }
}
