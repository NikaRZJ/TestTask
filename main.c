#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CheckLength(int *length, int size, int n);
void SortUp(int *array, int size);
void SortDown(int *array, int size);
void Print(int *array, int size);
int Input ();

int main() {
    int n = Input();
    int length[n];
    int mas[BUFSIZ];
    int k = 0;
    for (int i = 0; i < n; i++) {
        int *array;
        srand(time(NULL));
        int size = 1 + rand()%10;
        while (CheckLength(length, size, n))
            size = 1 + rand()%10;
        length[i] = size;
        array = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            array[j] = 1 + rand()%100;
        }
        if (i % 2 == 0)
            SortUp(array, size);
        else
            SortDown(array, size);
        for (int j = 0; j < size; j++) {
            mas[k] = array[j];
            k++;
        }
        Print(array, size);
        free(array);
    }
    Print(mas, k);
    return 0;
}

int CheckLength(int *length, int size, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (length[i]) {
            if (length[i] == size) {
                res = 1;
                break;
            }
        }
    }
    return res;
}

void SortUp(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void SortDown(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (array[j - 1] < array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Print(int *array, int size) {
    for (int i = 0; i < size; i++)
        if (i != size - 1)
            printf("%d ", array[i]);
        else
            printf("%d\n", array[i]);
}
int Input () {
    int f = 0;
    double n;
    char t;
    while (f == 0) {
        printf("Enter natural number: ");
        if (scanf("%le%c", &n, &t) == 2 && t == '\n') {
            fflush(stdin);
            if ((n == (int)n) && (n > 0))
                f = 1;
            else {
                printf("n/a\n");
            }

        }
        else {
            printf("n/a\n");
        }
    }
    return (int)n;
}

