#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

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
* @brief Проверяет лежит ли переменная в интервале [min;max]
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Создаёт новый массив согласно условию 1
* @param arr - массив
* @param size - размер массива
*/
void defForTask1(int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию 2
* @param arr - массив
* @param size - размер массива
*/
void defForTask2(const int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию 3
* @param arr - массив
* @param size - размер массива
* @param k - значение k (вводится пользователем)
*/
int* defForTask3(const int* arr, const size_t size, const int k);

/**
* @brief Находит максимальный по модулю отрицательный элемент массива
* @param arr - массив
* @param size - размер массива
* @return Возвращает максимальный по модулю отрицательный элемент
*/
int defMaxAbsNegative(const int* arr, const size_t size);

/**
* @brief Проверяет, имеют ли два соседних элемента разные знаки
* @param a - первый элемент
* @param b - второй элемент
* @return Возвращает 1 если знаки разные, 0 если одинаковые
*/
bool haveDifferentSigns(int a, int b);

/**
* @brief Подсчитывает количество пар с разными знаками
* @param arr - массив
* @param size - размер массива
* @return Возвращает количество пар с разными знаками
*/
int countDiffSignPairs(const int* arr, const size_t size);

/**
@brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
@brief CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
@brief TASK_ONE - выполнение первого задания
@brief TASK_TWO - выполнение второго задания
@brief TASK_THREE - выполнение третьего задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Проверяет интервал на корректность ввода
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
* @brief Проверяет, удалось ли выделить память для массива
* @param arr - массив
*/
void check_pointer(const int* arr);

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
    printf("Числа массива будут в диапазоне [%d,%d]", min, max);

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


    printf("\nВведите значение k для третьей задачи: ");
    int k = getValid();
    checkValue(k, min, max);
    
    int* AforTask3 = defForTask3(copyA, size, k);

    printf("\nКакие будут преобразования?\n%d - Заменить максимальный по модулю отрицательный элемент массива нулем\n%d - Вставить число К между всеми соседними элементами, которые имеют разные знаки\n%d - Из элементов массива D сформировать массив A по правилу: первые k элементов: A[i] = -D[i]^2, остальные: A[i] = D[i]-1\n", TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = getValid();

    switch (second_choise)
    {
    case TASK_ONE:
        defForTask1(copyA, size);
        break;

    case TASK_TWO:
        defForTask2(copyA, size);
        break;

    case TASK_THREE:
        defPrintArr(AforTask3, size);
        break;

    default:
        fprintf(stderr, "Error");
        free(A);
        free(copyA);
        free(AforTask3);
        exit(1);
    }

    free(A);
    free(copyA);
    free(AforTask3);

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
        fprintf(stderr, "Error\nЧисло должно лежать в промежутке [%d;%d]", min, max);
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

    printf("\nМассив: \n");
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

void defForTask1(int* arr, const size_t size)
{
    check_pointer(arr);

    int maxAbsNeg = defMaxAbsNegative(arr, size);
    
    if (maxAbsNeg == 0)
    {
        printf("\nВ массиве нет отрицательных элементов\n");
        defPrintArr(arr, size);
        return;
    }

    printf("\nНовый массив (максимальный по модулю отрицательный элемент заменен на 0): \n");
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == maxAbsNeg)
        {
            arr[i] = 0;
        }
        printf("%d\n", arr[i]);
    }
}

void defForTask2(const int* arr, const size_t size)
{
    check_pointer(arr);

    int pairCount = countDiffSignPairs(arr, size);
    if (pairCount == 0)
    {
        printf("\nВ массиве нет пар соседних элементов с разными знаками\n");
        defPrintArr(arr, size);
        return;
    }

    printf("Введите число K: ");
    int K = getValid();

    size_t newSize = size + pairCount;
    int* newArr = calloc(newSize, sizeof(int));
    check_pointer(newArr);

    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        newArr[j++] = arr[i];
        
     
        if (i < size - 1 && haveDifferentSigns(arr[i], arr[i + 1]))
        {
            if (j < newSize)
            {
                newArr[j++] = K;
            }
        }
    }

    printf("\nНовый массив (с вставленным K между элементами с разными знаками):\n");
    defPrintArr(newArr, newSize);
    free(newArr);
}

int* defForTask3(const int* arr, const size_t size, const int k)
{
    check_pointer(arr);

    int* newArr = calloc(size, sizeof(int));
    check_pointer(newArr);

    for (size_t i = 0; i < size; i++)
    {
        if (i < (size_t)k)  
            newArr[i] = -(arr[i] * arr[i]); 
        }
        else  
        {
            newArr[i] = arr[i] - 1;  
        }
    }

    return newArr;
}

int defMaxAbsNegative(const int* arr, const size_t size)
{
    check_pointer(arr);

    int maxAbsNeg = 0;  
    int maxAbs = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            int absValue = -arr[i];  
            if (absValue > maxAbs)
            {
                maxAbs = absValue;
                maxAbsNeg = arr[i];
            }
        }
    }

    return maxAbsNeg;
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

bool haveDifferentSigns(int a, int b)
{

    if (a == 0 || b == 0) return false;
    return (a > 0 && b < 0) || (a < 0 && b > 0);
}

int countDiffSignPairs(const int* arr, const size_t size)
{
    check_pointer(arr);

    int count = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if (haveDifferentSigns(arr[i], arr[i + 1]))
        {
            count++;
        }
    }
    return count;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error");
        exit(1);
    }
}
