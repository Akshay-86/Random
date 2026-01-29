#include <stdio.h>
#include <conio.h>
#define MAX 20
void insertion_sort(int[], int);
int main() {
    int i, a[MAX], n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    insertion_sort(a, n);

    printf("Sorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void insertion_sort(int a[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}
