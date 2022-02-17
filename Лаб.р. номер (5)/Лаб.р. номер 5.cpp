#include <iostream>
using namespace std;
int Sklrsumstr(int** mas, int n, int m)   // Функция для скалярного произведения каждой пары различных строк
{
    int s = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    s += (mas[i][j]) * (mas[k][j]);
                }
                else
                {
                    continue;
                }
            }
        }
    }
    if (s == 0)
    {
        flag = true;
    }
    else { flag = false; }

    return flag;
}
int Sklrstr(int** mas, int n, int m) // Функция для скалярного произведения строки самой на себя
{
    bool flag1 = false;
    int k = 0;
    int square = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            square += mas[i][j] * mas[i][j];    // Сумма скалярного произведения всех строк
        }
        k++;                                    // счетчик для каждой строки, он на каждом проходе, равен сумме (square)
        if (square - k == 0)                    // И проверяем что в сумму (square) на каждом проходе добавляется только единица, иначе, матрица не ортонормированная
        {                                       
            continue;
        }
        else { square = 20; }                   // Если матрица не ортонормированная, то сумму (square) заполняю 20, чтобы просто по итогу сумма была больше 3, и flag = false
    }

    if (square == 3)
    {
        flag1 = true;
    }
    else { flag1 = false; }
    return flag1;
}



int main()
{
    setlocale(LC_ALL, "RUS");
    bool flag = false, flag1 = false;
    int n = 3, m = 3;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }

    cout << "Введите элементы матрицы (первая строка элементов, вторая и т. д.): " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
    }


    flag = Sklrsumstr(a, n, m);
    flag1 = Sklrstr(a, n, m);
    if ((flag == true) && (flag1 == true))
    {
        cout << endl;
        cout << "Ортонормированная матрица" << endl;
    }
    else 
    {
        cout << endl;
        cout << "НЕ ортонормированная матрица" << endl; 
    }

    for (int i = 0; i < n; i++)
    {
        delete[]a[i];
    }
    delete[]a;
    return 0;
}