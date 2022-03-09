#include <iostream>
using namespace std;

struct list
{
    int data; // поле данных
    list* next; // указатель на следующий элемент
    list* prev; // указатель на предыдущий элемент
};

// создание первого узла
//init(значение для 1 узла)
     list* init(int a) // number- значение первого узла
{
    list* lst;// выделение памяти под корень списка
    lst = new(list);
    lst->data = a;      //закидываем значение которое нам необходимо
    lst->next = NULL;   //адрес зануляем так как только создали элемент,указатель на следующий узел
    lst->prev = NULL; // адрес зануляем так как только создали элемент, указатель на предыдущий узел
    return(lst);
}

// добавление узла
// addelem(адрес последнего узла, значение нового узла)
     list* addelem(list* lst, int a)
{
    list* temp, * endAdr;
    temp = new(list);
    endAdr = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->data = a; // сохранение поля данных добавляемого узла
    temp->next = endAdr; // созданный узел указывает на следующий элемент
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    if (endAdr != NULL)
        endAdr->prev = temp;
    return(temp);
}

// удаление узла
//deletelem(адрес удаляемого узла)
     list* deletelem(list* lst)
{
    list* prev, * next;
    prev = lst->prev; // узел, предшествующий lst
    next = lst->next; // узел, следующий за lst
    if (prev != NULL)
        prev->next = lst->next; // переставляем указатель
    if (next != NULL)
        next->prev = lst->prev; // переставляем указатель
    return(next);
}

void listprint_new(list* lst)
{
    list* endAdr;
    endAdr = lst;

    do {
        //проверка на четные элементы
        if (endAdr->data % 2 == 0) {
            endAdr = deletelem(endAdr); //удаление четных элементов
        }
        else {
            cout << " " << endAdr->data; // вывод значения элемента endAdr
            endAdr = endAdr->next; // переход к следующему узлу
        }
    } while (endAdr != NULL);// условие окончания обхода
}

int main()
{
    setlocale(LC_ALL, "Russian");
    list* head, * endAdr; // head - адрес 1 узла, endAdr - адрес добавленного узла
    head = endAdr = 0;

    int col, x;
    cout << "Введите количество элементов: ";
    cin >> col;

    //защита от неправильного ввода
    if (col > 0) {

        for (int i = 0; i < col; i++)
        {
            if (i == 0) {
                cout << "Введите " << (i + 1) << " элемент: ";
                cin >> x;
                head = endAdr = init(x);
            }
            else {
                cout << "Введите " << (i + 1) << " элемент: ";
                cin >> x;
                endAdr = addelem(endAdr, x);
            }

        }

        //listprint изменили на listprint_new добавив удаление четных значений
        listprint_new(head);
    }

}