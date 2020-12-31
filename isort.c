#include <stdio.h>
#define SIZE 50

int shift_element(int *arr, int i)
{
    for (int j = i; j > 0; j--)
    {
        *(arr + j) = *(arr + j-1);
    }
    return 0;
}

/* Function to sort an array using insertion sort*/

int insertion_sort(int *arr, int len)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;

        while (j >= 0 && *(arr + j) > key)
        {
            j--;
        }
        shift_element((arr + j + 1), (i - j-1));
        *(arr + j + 1) = key;
    }
    return 0;
}

int main()
{

    int array[SIZE];
    for (int i = 0; i < SIZE; i++) //  add end of file
    {
        scanf("%d", (array + i));
    }

    insertion_sort(array, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d,", *(array + i));
    }
    printf("\n");
    return 0;
}