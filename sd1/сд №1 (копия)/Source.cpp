#include <iostream>

using namespace std;

struct DinamicArray // Dynamic Array
{
    int capacity;
    int length;
    int* shelf;
};
bool flag = false;
bool isCreateDinamicArray = true;

//инициализация массива
void Massiv(DinamicArray* shelf)
{
    cout << "введите длину  массива ";
    cin >> shelf->length;
    shelf->capacity = shelf->length + 4;
    shelf->shelf = new int[shelf->capacity];
    for (int i = 0; i < shelf->length; i++)
    {
        cout << "введите эллемент № " << i + 1 << "  ";
        cin >> shelf->shelf[i];
    }
    cout << endl;
    isCreateDinamicArray = false;
}


//сортировка массива
void BubbleSort(DinamicArray* shelf)
{
        if (isCreateDinamicArray)
        {
            cout << "создайте и инициализируйте массив " << endl;
            system("pause");
        }
        else
        {
            int temp = 0;
            for (int i = 0; i < shelf->length - 1; i++)
            {
                for (int j = 0; j < shelf->length - i - 1; j++)
                {
                    if (shelf->shelf[j] > shelf->shelf[j + 1])
                    {
                        temp = shelf->shelf[j];
                        shelf->shelf[j] = shelf->shelf[j + 1];
                        shelf->shelf[j + 1] = temp;
                    }
                }
            }
            cout << endl;
            flag = true;
            cout << endl;
        }
  
}


// линейный поиск
void LinearSearch(DinamicArray* shelf)
{
        cout << "введите элемент поиска ";
        int element = 0;
        int count = 0;
        cin >> element;
        for (int i = 0; i < shelf->length; i++)
        {
            if (shelf->shelf[i] == element)
            {
                cout << "элемент найден, индекс № " << i;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "элемент не найден, попробуйте еще раз";
        }
        cout << endl;

}

// функция показывающая массив
void ShowMass(DinamicArray* shelf)
{
    cout << "ваш массив" << endl;
    for (int i = 0; i < shelf->length; i++)
    {
        cout << shelf->shelf[i] << " ";
    }
    cout << endl;
}

//бинарный поиск
void BinarySearch(DinamicArray* shelf)
{
    if (flag)
    {
        cout << "массив автоматический отсортирован";
        BubbleSort(shelf);
        ShowMass(shelf);
    }
    bool flag1 = false;
        // левая граница
        int l = 0;
        // правая граница
        int r = shelf->length;
        int mid = 0;
        int key = 0;
        cout << "введите искомое число ";
        cin >> key;
        while ((l <= r) && (flag1 != true))
        {
            mid = (l + r) / 2;
            if (shelf->shelf[mid] == key)
            {
                flag1 = true;
            }
            if (shelf->shelf[mid] > key)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (flag1)
        {
            cout << "элемент найден, Индекс элемента в массиве равен: " << mid << " ";
        }
        else
        {
            cout << "элемент не найден, попробуйте еще раз";
        }
}


//вставка в конец 
void ArrayInsertionEnd(DinamicArray* shelf)
{

    if (isCreateDinamicArray)
    {
        cout << "создайте и инициализируйте массив "<<endl;
        system("pause");
    }
    else
    {
        if (shelf->length >= shelf->capacity)
        {
            shelf->capacity = shelf->capacity * 2;
        }
        cout << "введите элемент ";
        cin >> shelf->shelf[shelf->length + 1];
        int Value;
        Value = shelf->shelf[shelf->length + 1];
        for (int i = 0; i < shelf->length + 1; i++)
        {
            shelf->shelf[shelf->length] = Value;
        }
        shelf->length++;
        flag = true;
    }
}


//вставка в начало
void ArrayInsertionStart(DinamicArray* shelf)
{
    if (isCreateDinamicArray)
    {
        cout << "создайте и инициализируйте массив " << endl;
        system("pause");
    }
    else
    {
        if (shelf->length >= shelf->capacity)
        {
            shelf->capacity = shelf->capacity * 2;
        }
        int temp = 0;
        temp = shelf->shelf[shelf->length - 1];
        for (int i = shelf->length - 1; i >= 0; i--)
        {
            shelf->shelf[i + 1] = shelf->shelf[i];
        }
        shelf->shelf[shelf->length] = temp;
        cout << "введите элемент для вставки в начало ";
        int Value = 0;
        cin >> Value;
        shelf->shelf[0] = Value;
        shelf->length++;
        flag = true;
    }
}


// вставка в массив по индексу
void IndexInsert(DinamicArray* shelf)
{
    if (isCreateDinamicArray)
    {
        cout << "создайте и инициализируйте массив " << endl;
        system("pause");
    }
    else
    {
        if (shelf->length >= shelf->capacity)
        {
            shelf->capacity = shelf->capacity * 2;
        }
        cout << "введите индекс после которого нужна вставка ";
        int index;
        cin >> index;
        cout << "введите вставляемый элемент ";
        int element;
        cin >> element;
        int temp = 0;
        temp = shelf->shelf[shelf->length - 1];
        for (int i = shelf->length - 1; i >= index; i--)
        {
            shelf->shelf[i + 1] = shelf->shelf[i];
        }
        shelf->shelf[shelf->length] = temp;
        shelf->shelf[index + 1] = element;
        shelf->length++;
        flag = true;
    }
}


// удаление элемента
void Remove(DinamicArray* shelf)
{
    if (isCreateDinamicArray)
    {
        cout << "создайте и инициализируйте массив " << endl;
        system("pause");
    }
    else
    {
        if (shelf->length >= shelf->capacity)
        {
            shelf->capacity = shelf->capacity * 2;
        }
        cout << "введите индекс элемента который надо удалить ";
        int index;
        cin >> index;
        if (index >= shelf->length || index < 0)
        {
            cout << "неверный индекс";
        }
        for (int i = index + 1; i < shelf->length; i++)
        {
            shelf->shelf[i - 1] = shelf->shelf[i];
        }
        --(shelf->length);
        flag = true;
    }
}

// меню
void ShowMenu()
{
    cout << "1 Функция создания и инициализации полей массива (length, capacity, array)" << endl;
    cout << "2 Удаление элемента из массива" << endl;
    cout << "3 Вставка элемента в начало" << endl;
    cout << "4 Вставка элемента в конец" << endl;
    cout << "5 Вставка после определенного элемента" << endl;
    cout << "6 Сортировка массива" << endl;
    cout << "7 Линейный поиск элемента в массиве" << endl;
    cout << "8 Бинарный поиск элемента в массиве" << endl;
    cout << "9  выход" << endl;
}


// проверка корректного ввода
int Security(int const min, int const max, string line)
{
    string str;

    int value1 = 0;

    bool wrong = true;

    while (wrong)
    {
        int temp, value2 = 0;

        cout << line;
        cin >> str;
        wrong = false;
        for (int i = 0; i < str.size(); i++)
        {
            value2 += str[i] - 48;

            if (str.size() > 1 && i < str.size() - 1)
            {
                value2 *= 10;
            }
        }
        if (value2 >= min && value2 <= max)
        {
            for (int i = 0; i < str.size(); i++)
            {
                temp = str[i];

                if (temp < 48 || temp  > 57)
                {
                    cout << endl << "Введено неверное значение. Повторите попытку  ";
                    wrong = true;
                    break;
                }
            }
        }
        else
        {
            cout << endl << "Введено неверное значение. Повторите попытку  ";
            wrong = true;
        }
        if (!wrong)
        {
            value1 = value2;
        }
    }
    return value1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    DinamicArray* basket = new DinamicArray;
    int count = 0;
    int result;
    
    do
    {
        ShowMenu();
        ShowMass(basket);
        cout << "выберите номер меню ";
        result = Security(1, 9, "выберите номер меню ");
        switch (result)
        {
            case 1:
            {
                Massiv(basket);
                break;
            }
            case 2:
            {
                Remove(basket);
                break;
            }
            case 3:
            {
                ArrayInsertionStart(basket);
                break;
            }
            case 4:
            {
                ArrayInsertionEnd(basket);
                break;
            }
            case 5:
            {
                IndexInsert(basket);
                break;
            }
            case 6:
            {
                BubbleSort(basket);
                break;
            }
            case 7:
            {
                LinearSearch(basket);
                system("pause");
                break;
            }
            case 8:
            {
                BinarySearch(basket);
                system("pause");
                break;
            }
            case 9:
            {
                delete basket;
                exit(EXIT_SUCCESS);
            }
        }
        if (result > 0)
        {
            system("cls");
        }
    } while (result != 9);
}