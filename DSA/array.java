public class array {
    public static void main(String[] args) {
        int[] arrayName = new int[5];

        // Step 2: Assign values
        arrayName[0] = 10;
        arrayName[1] = 20;
        arrayName[2] = 30;
        arrayName[3] = 40;
        arrayName[4] = 50;
        System.err.println("== INT ==");

        // print array
        for (int i = 0; i < arrayName.length; i++) {
            System.out.println(arrayName[i]);
        }
        System.err.println("== Double ==");
        double[] gasPrices;
        gasPrices = new double[5];
        // Assign values to gasPrices array
        gasPrices[0] = 420.50;
        gasPrices[1] = 430.75;
        gasPrices[2] = 415.30;
        gasPrices[3] = 440.10;
        gasPrices[4] = 425.00;
        for (int j = 0; j < gasPrices.length; j++) {
            System.out.println(gasPrices[j]);
        }
    }

}
