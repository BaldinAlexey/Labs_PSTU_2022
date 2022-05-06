
#include <iostream>
#include <conio.h>
#include <iostream>

using namespace std;

struct Node {
    Node* l, * r;
    char  x;
};
void Node_Add(Node*& p, char x);
int  Node_Height(const Node* p);
int tabs = 0; 
void print(Node* aBranch)

{

    if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего

    tabs += 5; //Иначе увеличим счетчик рекурсивно вызванных процедур

    //Который будет считать нам отступы для красивого вывода

    print(aBranch->l); //Выведем ветку и ее подветки слева

    for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы

    cout << aBranch->x << endl; //Данные этой ветки

    print(aBranch->r);//И ветки, что справа

    tabs -= 5; //После уменьшим кол-во отступов

    return;

}

void is_Empty(Node*& aBranch)

{

    if (!aBranch)

    {

        cout << "Дерево пустое...";

    }

    else

    {

        cout << "Дерево не пустое...";

    }

}

void FreeTree(Node* aBranch)

{

    if (!aBranch) return;

    FreeTree(aBranch->l);

    FreeTree(aBranch->r);

    delete aBranch;

    return;

}

Node* del_elem(Node*& aBranch, char a) {

    if (aBranch == NULL)

        return aBranch;

    if (a == aBranch->x) {

        Node* tmp;

        if (aBranch->r == NULL)

            tmp = aBranch->l;

        else {

            Node* ptr = aBranch->r;

            if (ptr->l == NULL) 
            {

                ptr->r = aBranch->l;

                tmp = ptr;

            }

            else {

                Node* pmin = ptr->l;

                while (pmin->l != NULL) {

                    ptr = pmin;

                    pmin = ptr->l;

                }

                ptr->l = pmin->r;

                pmin->l = aBranch->l;

                pmin->r = aBranch->r;

                tmp = pmin;

            }

        }

        delete aBranch;

        return tmp;

    }

    else if (a < aBranch->x)

        aBranch->l = del_elem(aBranch->l, a);

    else

        aBranch->r = del_elem(aBranch->r, a);

    return aBranch;

}

void pr_obh(Node*& aBranch)
{

    if (NULL == aBranch) return; //Если дерева нет, выходим



    pr_obh(aBranch->l); //Обошли левое поддерево
    cout << aBranch->x << endl; //Посетили узел
    pr_obh(aBranch->r); //Обошли правое поддерево
}

//вставка
void Node_Add(Node*& p, char x)
{
    if (p == NULL) {
        p = new (std::nothrow) Node();
        if (p != NULL) {
            p->l = p->r = NULL;
            p->x = x;
        }
    }
    else if (x < p->x)
        Node_Add(p->l, x);
    else
        Node_Add(p->r, x);
}


//высота дерева
int Node_Height(const Node* p) {
    int l, r, h = 0;
    if (p != NULL) {
        l = Node_Height(p->l);
        r = Node_Height(p->r);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}

void add_elem(char aData, Node*& aBranch)

{

    if (!aBranch)

    {

        aBranch = new Node;

        aBranch->x = aData;

        aBranch->l = 0;

        aBranch->r = 0;

        return;

    }

    else

    {

        if (aData < aBranch->x) {

            add_elem(aData, aBranch->l);

        }

        else if (aData > aBranch->x) {

            add_elem(aData, aBranch->r);

        }

    }

}

int main(void) {

    Node* tr = NULL;

    setlocale(LC_ALL, "Russian"); // Моё
    int n;
    char x;

    cout << "Сколько узлов будет в дереве ? (Введите кол-во узлов (min : 2))" << endl;
    for (int menu = 0; menu == 0;)
    {
        cin >> n;
        if (n > 1)
        {
            menu++;
        }
        else
        {
            cout << "Введено неправильное кол-во узлов. Попробуйте еще." << endl;
        }
    }

    is_Empty(tr);
    cout << endl << endl;
    char* s = new char[n];
    int count = 0;
    for (; count < n; count++)
    {
        cout << "Введите элемент " << count + 1 << " : ";
        cin >> s[count];
        cout << endl;
        Node_Add(tr, s[count]);
    }

    is_Empty(tr);
    cout << endl;

    cout << "Вывод бинарного дерева: " << endl;

    print(tr);

    cout << endl;

    cout << "Прямой обход бинарного дерева: " << endl;

    pr_obh(tr);

    cout << endl;

    cout << "Добавим новый элемент в бинарное дерево:" << endl;

    cout << "Введите новый элемент: ";

    cin >> x;

    add_elem(x, tr);

    cout << "Вывод бинарного дерева: " << endl;

    print(tr);

    cout << endl;

    cout << "Удалим элемент из бинарного дерева:" << endl;

    cout << "Введите элемент: ";

    cin >> x;

    del_elem(tr, x);

    cout << "Вывод бинарного дерева: " << endl;

    print(tr);

    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "Высота дерева равна: " << Node_Height(tr) << endl << endl;
    FreeTree(tr);
    cout << endl;
    cout << "Вся динамическая память очищена..." << endl;
    cout << "-------------------------------" << endl;
    cout << endl << endl;
    return 0;
}


