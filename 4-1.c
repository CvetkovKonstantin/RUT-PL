#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

size_t getSize(char* message);

void fillArray(int* arr, const size_t size);
void printArray(int* arr, const size_t size);
void fillRandom(int* arr, const size_t size);
int* copyArray(const int* arr, const size_t size);

// Функции для варианта 10
int sumNegativeElements(int* arr, const size_t size);
int countPositiveLessThanA(int* arr, const size_t size, int A);
int findLastPairDifferentSigns(int* arr, const size_t size);

enum {RANDOM = 1, MANUAL};

int main()
{
    srand(time(NULL)); 
    
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    
    printf("Выберите способ заполнения массива:\n"
            "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("error");
            free(arr);
            exit(1);
    }

    printf("Исходный массив: ");
    printArray(arr, size);
   
    int sumNeg = sumNegativeElements(arr, size);
    printf("\n1. Сумма отрицательных элементов: %d\n", sumNeg);
    
   
    printf("Введите число A для задания 2: ");
    int A = Value();
    int countPos = countPositiveLessThanA(arr, size, A);
    printf("2. Количество положительных элементов <= %d: %d\n", A, countPos);
    

    int lastPairIndex = findLastPairDifferentSigns(arr, size);
    if (lastPairIndex != -1) {
        printf("3. Номер последней пары с разными знаками: %d (элементы %d и %d)\n", 
               lastPairIndex, arr[lastPairIndex], arr[lastPairIndex + 1]);
    } else {
        printf("3. Пар с разными знаками не найдено\n");
    }

    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент [%zu]: ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    int start = -100;
    int end = 200;
    printf("Заполнение случайными числами в диапазоне [%d, %d]\n", start, end);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
    for (size_t i =0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}


int sumNegativeElements(int* arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}


int countPositiveLessThanA(int* arr, const size_t size, int A)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] <= A)
        {
            count++;
        }
    }
    return count;
}


int findLastPairDifferentSigns(int* arr, const size_t size)
{
    int lastIndex = -1;
    for (size_t i = 0; i < size - 1; i++)
    {
        
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
        {
            lastIndex = i; 
        }
    }
    return lastIndex;
}
