#include <iostream>

using namespace std;

class point
{
public:
    char key;
    point* next;
    friend point* make_point(int n);
    friend point* print_point(point* first);
    friend point* add_point(point* first, char a, char x);

};

 point* make_point(int n) /*создает список/стэк*/
{
    char x;
    point* first, * p;
    first = NULL;
    for (int i = n; i > 0; i--)
    {
        cout << "Элемент " << i << " ";
        cin >> x;
        cout << endl;
        p = new(point);
        p->key = char(x);
        p->next = first;
        first = p;
    }
    return first;
}

point* print_point(point* first) /*печатает*/
{

    if (first == NULL)return NULL;
    point* p = first;
    while (p != NULL)
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << "\n";
    return first;
}

point* add_point(point* first, char a, char x) /*добавляет элемент после определенного элемента*/
{
    point* p;
    point* f = first;
    while (f != NULL)
    {
        if (f->key == a)
        {
            p = new(point);
            p->key = x;
            p->next = f->next;
            f->next = p;
            f = f->next;
        }
        f = f->next;
    }
    return first;
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
        point* l = make_point(n);
        cout << "Созданный стек: ";
        print_point(l);
        cout << endl;
        cout << "Выберете элемент, после которого будет стоять новый элемент: ";
        cin >> a;
        cout << endl;
        cout << "Введите элемент, который будет стоять после указанного: ";
        cin >> x;
        cout << endl;
        cout << "Стек после преобразований: ";
        l = add_point(l, a, x);
        print_point(l);
        return 0;
    }
}