#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
int getValid();

/**
* @brief Проверяет что переменная не меньше единицы
* @param input - значение проверяемой переменной
*/
void checkValueForN(const int input);

/**
* @brief Проверяет, лежит ли число в указанном диапазоне
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Считает сумму согласно условию №1
* @param arr - массив
* @param size - размер массива
* @return Посчитанное значение
*/
int defForTask1(const int* arr, const size_t size);

/**
* @brief Выполняет задание №2
* @param arr - массив
* @param size - размер массива
*/
void defForTask2(const int* arr, const size_t size);

/**
* @brief Выполняет задание №3
* @param arr - массив
* @param size - размер массива
*/
void defForTask3(const int* arr, const size_t size);

/**
* @brief Находит минимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращает минимальный элемент массива
*/
int defMINN(const int* arr, const size_t size);

/**
* @brief Находит максимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращает максимальный элемент массива
*/
int defMAXX(const int* arr, const size_t size);

/**
* @brief Проверяет диапазон на корректность ввода
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void defCheckMinMax(const int min, const int max);

/**
* @brief Заполняет массив элементами, который пользователь вводит с клавиатуры, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getManual(int* arr, const size_t size, const int min, const int max);

/**
* @brief Заполняет массив случайными элементами, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getRandom(int* arr, const size_t size, const int min, const int max);

/**
* @brief Выводит все элементы массива на экран
* @param arr - массив
* @param size - размер массива
*/
void defPrintArr(const int* arr, const size_t size);

/**
* @brief Копирует все элементы массива в новый
* @param arr - массив
* @param size - размер массива
* @return Новый массив, идентичный старому
*/
int* defcopyArr(const int* arr, const size_t size);

/**
* @brief Проверяет корректно ли выделена память под массив
* @param arr - массив
*/
void check_pointer(const int* arr);

/**
* @brief Находит минимальный индекс числа в массиве, который равен заданному числу
* @param arr - массив
* @param size - размер массива
* @param num - число
* @return Индекс числа
*/
const size_t defidx(const int* arr, const size_t size, const int num);

/**
* @brief Находит номер последней пары соседних элементов с разными знаками
* @param arr - массив
* @param size - размер массива
* @return Номер первого элемента в паре (0 если не найдено)
*/
size_t findLastDiffSignPair(const int* arr, const size_t size);

/**
* @brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
* @brief CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
* @brief TASK_ONE - выполнение первого задания
* @brief TASK_TWO - выполнение второго задания
* @brief TASK_THREE - выполнение третьего задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    system("chcp 1251");

    printf("Введите размер массива: ");
    size_t size = (size_t)getValid();
    checkValueForN(size);

    int* A = calloc(size, sizeof(int));
    check_pointer(A);

    printf("Введите диапазон, в котором будут задаваться числа массива: \n");
    const int min = getValid();
    const int max = getValid();
    defCheckMinMax(min, max);
    printf("Числа массива будут задаваться в диапазоне [%d,%d]\n", min, max);

    printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n", CHOISE_ONE, CHOISE_TWO);
    int choise = getValid();

    switch (choise)
    {
    case CHOISE_ONE:
        getManual(A, size, min, max);
        break;

    case CHOISE_TWO:
        getRandom(A, size, min, max);
        break;

    default:
        fprintf(stderr, "Error");
        free(A);
        exit(1);
    }

    defPrintArr(A, size);
    int* copyA = defcopyArr(A, size);
    check_pointer(copyA);

    printf("\nКакие будут преобразования?\n%d - Найти сумму отрицательных элементов\n%d - Найти количество тех элементов, значения которых положительны и не превосходят заданного числа А\n%d - Найти номер последней пары соседних элементов с разными знаками\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = getValid();

    switch (second_choise)
    {
    case TASK_ONE:
        printf("\nСумма отрицательных элементов = %d\n", defForTask1(copyA, size));
        break;

    case TASK_TWO:
        defForTask2(copyA, size);
        break;

    case TASK_THREE:
        defForTask3(copyA, size);
        break;

    default:
        fprintf(stderr, "Error");
        free(A);
        free(copyA);
        exit(1);
    }

    free(A);
    free(copyA);

    return 0;
}

int getValid()
{
    int valid = 0;
    if (!scanf_s("%d", &valid))
    {
        fprintf(stderr, "Error");
        exit(1);
    }
    return valid;
}

void checkValue(const int input, const int min, const int max)
{
    if (input > max || input < min)
    {
        fprintf(stderr, "Error\n Число должно лежать в промежутке [%d;%d]", min, max);
        exit(1);
    }
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);

    printf("\nВведи %zu элемент-а(ов) массива:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        int num = getValid();
        checkValue(num, min, max);
        printf("A[%zu] = %d\n", i, num);
        arr[i] = num;
    }
}

void defCheckMinMax(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error\n Неправильно указан диапазон");
        exit(1);
    }
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        int numm = (rand() % (max - min + 1)) + min;
        arr[i] = numm;
    }
}

void defPrintArr(const int* arr, const size_t size)
{
    check_pointer(arr);

    printf("\nВведённый массив: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void checkValueForN(const int input)
{
    if (input < 1)
    {
        fprintf(stderr, "Error\nЧисло должно быть не меньше 1");
        exit(1);
    }
}

int defForTask1(const int* arr, const size_t size)
{
    check_pointer(arr);

    int summ = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            summ += arr[i];
        }
    }
    return summ;
}

void defForTask2(const int* arr, const size_t size)
{
    check_pointer(arr);
    
    printf("Введите число A: ");
    int A = getValid();
    
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] <= A)
        {
            count++;
        }
    }
    
    printf("\nКоличество элементов, значения которых положительны и не превосходят %d: %d\n", A, count);
}

void defForTask3(const int* arr, const size_t size)
{
    check_pointer(arr);
    
    size_t result = findLastDiffSignPair(arr, size);
    
    if (result == 0)
    {
        printf("\nПары соседних элементов с разными знаками не найдены\n");
    }
    else
    {
        printf("\nНомер последней пары соседних элементов с разными знаками: %zu\n", result);
        printf("Элементы пары: arr[%zu] = %d, arr[%zu] = %d\n", 
               result - 1, arr[result - 1], result, arr[result]);
    }
}

int defMAXX(const int* arr, const size_t size)
{
    check_pointer(arr);

    int maxx = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}

int* defcopyArr(const int* arr, const size_t size)
{
    check_pointer(arr);

    int* copyArr = calloc(size, sizeof(int));
    check_pointer(copyArr);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int defMINN(const int* arr, const size_t size)
{
    check_pointer(arr);

    int minn = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < minn)
        {
            minn = arr[i];
        }
    }
    return minn;
}

const size_t defidx(const int* arr, const size_t size, const int num)
{
    size_t temp = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            temp = i;
            break;
        }
    }
    return temp;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Memory Error\n");
        exit(1);
    }
}

size_t findLastDiffSignPair(const int* arr, const size_t size)
{
    size_t lastPairIndex = 0;
    
    for (size_t i = 0; i < size - 1; i++)
    {
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
        {
            lastPairIndex = i + 1; 
        }
    }
    
    return lastPairIndex;
}
