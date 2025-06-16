public class array1 {
    private int[] numbers;
    private int maxSize;
    private int numElement;

    public array1(int size) {
        maxSize = size;
        numbers = new int[maxSize];
        numElement = 0;
    }

    // insert values
    public boolean insertValue(int values)
            {
                
            if (numElement < maxSize)
            {
                numbers[numElement] = values;
                numElement ++;
                return true;
            }
                else 
                {
                    System.out.println("Array is Full");
                    return false;
                }
            }
            
}