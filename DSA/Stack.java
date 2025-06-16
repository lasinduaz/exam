public class Stack {

    private int maxSize;
    private int[] stackArray;
    private int top;

    public Stack(int S) {
        maxSize = S;
        stackArray = new int[maxSize];
        top = -1;
    }

    // Push
    public void push(int value) {
        if ((top + 1) >= maxSize) {
            System.out.println("Stack is Full");
        } else {
            stackArray[++top] = value;
        }
    }

    // Peek
    public int peek() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return 9999;
        } else {
            return stackArray[top];
        }
    }

    // Pop
    public int pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return 9999;
        } else {
            return stackArray[top--];
        }
    }

    public static void main(String[] args) {
        Stack s = new Stack(3);
        s.push(10);
        s.push(20);
        s.push(30);
        //s.push(40); // Should print "Stack is Full"
        System.out.println("Top element: " + s.peek());
        System.out.println("Popped: " + s.pop());
        System.out.println("Top element after pop: " + s.peek());
    }
}