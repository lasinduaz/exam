#include <stdio.h>

int PARTITION(int A[], int p, int r) {
    int x = A[r];          // pivot = last element
    int i = p - 1;         // index of smaller element

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;           // move boundary forward
            // swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // place pivot in correct position
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;   // return pivot index
}

void QUICKSORT(int A[], int p, int r) {
    if (p < r) {
        int q = PARTITION(A, p, r);   // partition index
        QUICKSORT(A, p, q - 1);       // sort left part
        QUICKSORT(A, q + 1, r);       // sort right part
    }
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    QUICKSORT(a, 0, n - 1);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
