#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    while (n < 0 || n < 5)
    {
        cout << "Нельзя вводить такие значения! ";
        cout << "Введите еще раз: ";
        cin >> n;
    }
    while (n > 0 && n >= 5)
    {
        cout << endl;
        char* mas = new char[n];
        int a = 1;
        char h;
        int count = 0;
        cout << "Введите элемент, который хотите удалить из массива: ";
        cin >> h;
        cout << endl;
        cout << "Введите элементы массива: " << endl;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Элемент " << a << " ";
            cin >> mas[i];
            if (h == mas[i])
            {
                count++;
            }
            cout << endl;
            a++;
        }

        char* mas_final = new char[n - count];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (mas[i] != h)
            {
                mas_final[j] = mas[i];
                j++;
            }
        }
        cout << "До преобразований: ";
        for (int i = 0; i < n; i++)
        {
            cout << mas[i] << " ";
        }

        cout << endl << endl;
        cout << "После преобразований: ";
        for (int j = 0; j < n - count; j++)
        {
            cout << mas_final[j] << " ";
        }

        cout << endl << endl << "Количество встретившихся элементов, которые удалили: " << count;
        cout << endl;
        return 0;
    }
}

