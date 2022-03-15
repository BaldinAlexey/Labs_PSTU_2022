#include <iostream>

using namespace std;
struct point
{
    int key;
    point* next;
};

point* make_point(int n) /*создает список/стэк*/
{
    point* first, * p, * l;

    p = new(point);
    p->key = n;
    p->next = NULL;
    first = p;
    l = p;
    for (int i = n - 1; i > 0; i--)
    {
        p = new(point);
        p->key = i;
        l->next = p;
        p->next = NULL;
        l = p;
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

point* del_chet_point(point* first) /*удаляет четные элементы*/
{
    if (first == NULL)return NULL;
    point* p = first;
    while (p != NULL)
    {
        if (p->key % 2 == 0) { /*если четный первый то переместить указатель first*/
            first = p->next;

        }
        if (p->next != NULL) {
            if (p->next->key % 2 == 0) {
                if (p->next->next != NULL) { /*если четный в середине*/
                    p->next = p->next->next;
                }
                else {
                    p->next = NULL;   /*если четный в конце*/
                }
            }
        }
        p = p->next;
    }
    return first;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    point* l = make_point(10);
    cout << "Очередь до преобразований: ";
    print_point(l);
    cout << endl;
    l = del_chet_point(l);
    cout << "Очередь после преобразований: ";
    print_point(l);
    cout << endl << endl;
    return 0;
}
