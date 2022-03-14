#include <iostream>
#include <stack>
using namespace std;
stack <char> s1;

void make_point(int n)
{
    char x;
    for (int i = n; i > 0; i--)
    {
        cout << "Элемент " << i << " ";
        cin >> x;
        cout << endl;
        s1.push(char(x));
    }
}

void print_point()
{
    stack <char> first;
    first = s1;
    while (!(s1.empty()))
    {
        cout << s1.top() << " ";

        s1.pop();
    }
    cout << "\n";

    s1 = first;
}

void add_point(char a, char x) {
    stack <char> first;

    while (!(s1.empty())) {

        if (s1.top() == a) {
            first.push(s1.top());
            first.push(x);
        }
        else
        {
            first.push(s1.top());
        }
        s1.pop();
    }

    while (!(first.empty())) {
        s1.push(first.top());
        first.pop();
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    char x, a;
    cout << "Введите количество элементов стека: ";
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
        cout << "Созданный стек: ";
        print_point();
        cout << endl;
        cout << "Выберете элемент, после которого будет стоять новый элемент: ";
        cin >> a;
        cout << endl;

        cout << "Введите элемент, который будет стоять после указанного: ";
        cin >> x;
        add_point(a, x);
        cout << endl;
        cout << "Стек после преобразований: ";
        print_point();
        cout << endl << endl;
        return 0;
    }
}
