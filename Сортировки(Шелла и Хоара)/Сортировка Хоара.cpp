#include <iostream>

using namespace std;
const int n = 10;
int left, right;
void quick_sort(int* array, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot) 
        {
            i++;
        }
        while (array[j] > pivot) 
        {
            j--;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > left)
        quick_sort(array, left, j);
    if (i < right)
        quick_sort(array, i, right);
}


    void main()
    {
        setlocale(LC_ALL, "Rus");
        int* A = new int[n];
        srand(time(NULL));
        cout << "Исходный массив: ";
        for (int i = 0; i < n; i++)
        {
            A[i] = rand() % 10;
            cout << A[i] << " ";
        }
       int left = 0; 
       int  right = n - 1;
       quick_sort(A, left, right);
        cout << endl << "Результирующий массив: ";
        for (int i = 0; i < n; i++) cout << A[i] << " ";
        delete[]A;
        system("pause>>void");
    }





