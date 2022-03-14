#include <iostream>
#include <queue>
using namespace std;
queue <int> s1;


void make_point(int n)
{
    int x;
    for (int i = n; i > 0; i--)
    {
        cout << "Элемент " << i << " ";
        cin >> x;
        cout << endl;
        s1.push(x);
    }
}

void print_point()
{
    queue <int> first;
    first = s1;
    while (!(s1.empty()))
    {
        cout << s1.front() << " ";

        s1.pop();
    }
    cout << "\n";

    s1 = first;
}

void del_chet() {
    queue <int> first;

    while (!(s1.empty())) {
        if (s1.front() % 2 != 0) {
            first.push(s1.front());
        }
        s1.pop();
    }
    s1 = first;
}


int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите количество элементов очереди: ";
    int n;
    cin >> n;
    while (n <= 0)
    {
        cout << "Введите еще раз! ";
        cin >> n;
        cout << endl;
    }
    while (n >= 1)
    {
        make_point(n);
        cout << "Очередь до преобразований: ";
        print_point();
        cout << endl;
        del_chet();
        cout << "Очередь после преобразований: ";
        print_point();
        cout << endl << endl;
        return 0;
    }
}
