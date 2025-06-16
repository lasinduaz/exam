public class Queue {

    private int maxSize;
    private int QueueArray[];
    private int front;
    private int rear;
    private int nIteam;

    public Queue(int Q) {
        maxSize = Q;
        QueueArray = new int[maxSize];
        front = 0;
        rear = -1;
        nIteam = 0;
    }

    // Other functions
    boolean isEmpty() {
        return (nIteam == 0);
    }

    boolean isFull() {
        return (rear == maxSize - 1);
    }

    int size() {
        return nIteam;
    }

    // methds
    public void insert(int value) {
        if (isFull()) {
            System.out.println("Quea Is Full");
        } else {
            QueueArray[++rear] = value;
            nIteam++;
        }

    }

    public int remove() {
        if (isEmpty()) {
            System.out.println("Queae is empty");
            return -999;
        } else {
            nIteam--;
            return QueueArray[front++];
        }

    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Quease is Empty");
            return -999;
        } else {
            return QueueArray[front];
        }

    }

    public void displayQuese() {
        for (int i = front; i <= rear; i++) {
            System.out.print(QueueArray[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Queue Q = new Queue(5);
        Q.insert(10);
        Q.insert(20);
        Q.insert(30);
        Q.insert(40);
        Q.insert(50);
        Q.insert(50);

        Q.displayQuese();
        // System.out.println(Q.peek());
        Q.remove();
        Q.displayQuese();
        Q.displayQuese();
        Q.remove();
        Q.displayQuese();
        Q.remove();
        Q.displayQuese();
        Q.remove();
        Q.displayQuese();
        Q.remove();
        Q.displayQuese();
        Q.remove();
        Q.displayQuese();

        // System.out.println(Q.peek());

    }
}
