#include <iostream>
#include <stdarg.h>
using namespace std;

int Funcsum(int n, ...)
{
    int* parametr = &n;
    parametr++;
    int s = 0, a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++)
    {   
            a1 = (*parametr); //a1=parametr[1]
            a2 = *(++parametr); //a2=parametr[2]
            if (i % 2 == 0) //если чётное
            {
                s -= a1 * a2;
            }
            else
            {
                s += a1 * a2; //если нечётное
            }
    }
    return s;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout <<"C количеством параметров 5  :"<< Funcsum(5, 1, 4, 9, 3, 6) << endl;
    cout <<"C количеством параметров 10 :"<< Funcsum(10, 10, 11, 34, 4, 6, 2, 6, 7, 3, 15) << endl;
    cout <<"C количеством параметров 12 :"<< Funcsum(12, 3, 56, 6, 2, 7, 1, 23, 21, 10, 15, 11, 46) << endl;
    return 0;
}

