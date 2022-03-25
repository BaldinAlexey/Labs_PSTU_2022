#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <Windows.h>


using namespace std;
// Всех данных по 40 - штук
string names[50] = { "Андрей", "Иван", "Петр", "Дмитрий", "Евгений", "Александр", "Марк", "Ермак","Марсель","Климент","Дариуш" ,"Кирилл" ,"Денис" ,"Стас" ,"Руслан" ,"Матвей" ,"Павел" ,"Егор" ,"Савва" ,"Эдвард" ,"Ярик" ,"Стёпа" ,"Артём" ,"Макар" ,"Илья" ,"Эмин" ,"Василий" ,"Лев" ,"Никита" ,"Тимур" ,"Давид" ,"Валера" ,"Боир" ,"Владислав" ,"Ибрагим" ,"Артур" ,"Леонид" ,"Максим" ,"Златан" ,"Олег" };
string patronymic[50] = { "Андреевич", "Иванович", "Петрович", "Дмитриевич", "Евгеньевич", "Александрович", "Иванович", "Яковлевич","Адольфович","Даниилович","Еремеевич" ,"Станиславович" ,"Анатольевич" ,"Альбертович" ,"Миронович" ,"Тарасович" ,"Филиппович" ,"Эльдарович" ,"Ефимович" ,"Демьянович" ,"Федосеевич" ,"Никитевич" ,"Всеволодович" ,"Улебович" ,"Федорович" ,"Давидович" ,"Авксентьевич" ,"Аристархович" ,"Антонинович" ,"Оскарович" ,"Христофорович" ,"Ростиславович" ,"Степанович" ,"Сергеевич" ,"Филатович" ,"Евсеевич" ,"Аркадьевич" ,"Романович" ,"Егорович" ,"Семёнович" };
string surnames[50] = { "Смирнов","Маслов","Сафонов","Кузнецов","Горбачев","Костин","Брагин", "Савельев","Трофимов","Мясников","Сидоров" ,"Балдин" ,"Ахунов" ,"Кокшаров" ,"Гребнев" ,"Стрелков" ,"Данилов" ,"Мартынов" ,"Кудряшов" ,"Владимиров" ,"Лапин" ,"Лапенко" ,"Михеев" ,"Быков" ,"Громов" ,"Рыбаков" ,"Федосеев" ,"Фролов" ,"Шилов" ,"Шипов" ,"Афанасьев" ,"Артемьев" ,"Туров" ,"Ершов" ,"Пестов" ,"Пестриков" ,"Константинов" ,"Пономарёв" ,"Кузьмин" ,"Фомин" };
string adress[50] = { "Бл.Бухарестская","пр.Бухарестская","Сп.Космонавтов","Пр.Гагарина", "проезд Балканская, 96", "въезд Гагарина, 09", "въезд Ломоносова, 20", "шоссе Славы, 90", "пл. Славы, 86", "бульвар 1905 года, 38", "пер. Будапештсткая, 90", "пер. Ленина, 78", "ул. Гоголя, 59", "наб. Гагарина, 52", "бульвар Сталина, 77", "пл. Чехова, 40", "ул. Балканская, 33", "бульвар Косиора, 64", "ул. Кравченко, д. 61", "ул. Воронежская, д. 230", "шоссе Ладыгина, 53", "наб. Космонавтов, 99", "спуск Чехова, 55", "ул. Косиора, 26", "въезд Косиора, 73", "пер. Ладыгина, 85", "пл. Домодедовская, 43", "проспект Бяних д. 27", "проспект Додэское д. 89", "улица Лотрское д. 72", "проспект Торых д. 96", "проспект Сянодих д. 364", "улица Жюижское д. 18", "проспект Пяеых д. 97", "улица Жятаз д. 19", "улица Бусз д. 46", "проспект Хиуого д. 11", "улица Гефская д. 93-б", "улица Нэрс д. 278", "проспект Сежитых д. 51" };
string pasport[50] = { "4759 969117","4481 92688","5340 356756","4340 356756","4793 464759","4130 787754","4451 654897", "4525 109816","4830 199123","4617 428102","4170 831731" ,"4112 300133" ,"4536 791649" ,"4336 257171" ,"4766 920103" ,"4792 103547" ,"4255 183309" ,"4191 514206" ,"4832 635149" ,"4095 564919" ,"4461 727705" ,"4245 722611" ,"4144 536064" ,"4924 764248" ,"4022 388906" ,"4335 537814" ,"4357 137880" ,"4994 832426" ,"4020 748292" ,"4136 429766" ,"4159 487178" ,"4622 784039" ,"4988 404573" ,"4442 612117" ,"4564 709326" ,"4150 820695" ,"4262 281290" ,"4772 484282" ,"4314 634922" ,"4352 439569" };

struct Human
{
    Human()
    {
        full_name = "NULL";
        pasport = "NULL";
        adress = "NULL";

    }

    string full_name;
    string pasport;
    string adress;
};

int collisions_count = 0;

struct hash_table
{
    stack<Human>* array;
    hash_table(int size)
    {
        array = new stack<Human>[size];
    }

    ~hash_table()
    {
        delete[] array;
    }
    void add(Human temp, const int size);
    void find_index(string date_of_birth, const int size);
};

void show_info(const Human temp);
void show_hash_table(hash_table* object, const int size);
Human create_random_human();
string get_random_name(); string get_random_pasport(); string get_adress();
void print_array_humans(const Human* const array, const int size);
void fill_array_random_humans(Human* array, const int count);
int get_random_number();
int hash_function(string str, const int size);
void print_point(stack<Human> temp);
void add_point(Human x, stack<Human> temp);

void print_point(stack<Human> temp)
{

    while (!(temp.empty()))
    {
        show_info(temp.top());
        temp.pop();
    }
    cout << "\n";

}

void add_point(Human x, stack<Human> temp) {
    temp.push(x);
}

bool find_point(stack<Human> temp, string fio)
{
    while (!(temp.empty()))
    {
        if (temp.top().full_name == fio) {
            return true;
        }
        temp.pop();
    }
    return false;
}


void hash_table::find_index(string fio, const int size)
{
    int hash = hash_function(fio, size);
    int index = hash;
    bool F = false;
    F = find_point(array[index], fio);
    if (index >= size)
    {
        cout << "Человека по ФИО \"" << fio << "\" нет. \n\n";
    }
    else
    {
        if (F)
        {
            cout << "Человек с ФИО \"" << fio << "\" содержится по индексу " << index << endl << endl;
        }
        else
        {
            cout << "Человека по ФИО \"" << fio << "\" нет. \n\n";
        }
    }
}

void hash_table::add(Human temp, const int size)
{
    int index = hash_function(temp.full_name, size);
    int hash = index;
    if (!(array[index].empty()))
    {
        array[index].push(temp);
        return;
    }
    else
    {
        array[index].push(temp);
        collisions_count++;
        return;
    }
}



void show_hash_table(hash_table* table, const int size) {
    for (int i = 0; i < size; i++) {
        if (!(table->array[i].empty())) {
            print_point(table->array[i]);
        }
    }
}
int get_random_number()
{
    return rand() % 40; //кол данных в списке
}

int hash_function(string str, const int size)
{
    int a = 0;
    for (int i = 0; i < str.length(); i++) {
        a += (int)str[i];
    }
    int c = abs(a % size);
    return static_cast<int>(c);
}

int h = 1;
void show_info(const Human temp)
{
    cout << "Элемент " << h++ << endl;
    cout << "\nФИО         " << temp.full_name
        << "\n#Адрес      " << temp.adress
        << "\n#Паспорта   " << temp.pasport << endl << endl;
}


void print_array_humans(const Human* const array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        show_info(array[i]);
    }
}

void fill_array_random_humans(Human* array, const int count)
{
    for (int i = 0; i < count; i++)
    {
        array[i] = create_random_human();
    }
}

string get_random_pasport()
{
    return pasport[get_random_number()];
}

string get_adress()
{
    return adress[get_random_number()];
}

Human create_random_human()
{
    Human temp;
    temp.full_name = get_random_name();
    temp.pasport = get_random_pasport();
    temp.adress = get_adress();
    return temp;
}

string get_random_name()
{
    return(surnames[get_random_number()] + " " + names[get_random_number()] + " " + patronymic[get_random_number()]);
}
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    do {
        cout << "Введите количество элементов в массиве (не меньше 10): ";
        cin >> size;
    } while (size < 10);
    cout << endl;
    Human* array = new Human[size];
    hash_table table(size);
    fill_array_random_humans(array, size);
    for (int i = 0; i < size; i++)
    {
        table.add(array[i], size);
    }
    show_hash_table(&table, size);

    string FindFio = "";
    string f, y, o;
    cout << "Введите фамилию искомого человека: ";
    cin >> f;
    cout << endl << endl;
    cout << "Введите имя искомого человека: ";
    cin >> y;
    cout << endl << endl;
    cout << "Введите отчество искомого человека: ";
    cin >> o;
    cout << endl << endl;
    FindFio = f + " " + y + " " + o;
    table.find_index(FindFio, size);

    cout << endl << endl << "================" << endl << endl;
    cout << endl << "Количество коллизий для " << size << "  записей: " << collisions_count << endl << endl;
    delete[] array;
    return 0;
}

