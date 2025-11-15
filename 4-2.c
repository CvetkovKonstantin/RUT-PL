#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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


void replaceMaxAbsNegativeWithZero(int* arr, const size_t size);
int* insertKBetweenDifferentSigns(int* arr, const size_t size, int K, size_t* newSize);
int* createArrayAFromD(int* D, const size_t size, int k);

enum {RANDOM = 1, MANUAL};

int main()
{
    srand(time(NULL));
    
    size_t size = getSize("Введите размер массива: ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
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
            printf("Неверный выбор\n");
            free(arr);
            exit(1);
    }

    printf("Исходный массив D: ");
    printArray(arr, size);
    
  
    int* arr1 = copyArray(arr, size);
    replaceMaxAbsNegativeWithZero(arr1, size);
    printf("1. После замены макс. по модулю отриц. элемента на 0: ");
    printArray(arr1, size);
    
   
    printf("Введите число K для вставки: ");
    int K = Value();
    size_t newSize;
    int* arr2 = insertKBetweenDifferentSigns(arr, size, K, &newSize);
    printf("2. После вставки %d между элементами с разными знаками: ", K);
    printArray(arr2, newSize);
    
  
    printf("Введите k для формирования массива A: ");
    int k_val = Value();
    int* arrA = createArrayAFromD(arr, size, k_val);
    printf("3. Массив A, сформированный из D: ");
    printArray(arrA, size);
    
    free(arr);
    free(arr1);
    free(arr2);
    free(arrA);
    
    system("pause");
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
    int* copyArr = malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}


void replaceMaxAbsNegativeWithZero(int* arr, const size_t size)
{
    int maxAbsNegativeIndex = -1;
    int maxAbsValue = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0) 
        {
            int absValue = abs(arr[i]);
            if (maxAbsNegativeIndex == -1 || absValue > maxAbsValue)
            {
                maxAbsNegativeIndex = i;
                maxAbsValue = absValue;
            }
        }
    }
    
 
    if (maxAbsNegativeIndex != -1)
    {
        printf("   Заменен элемент [%d] = %d на 0\n", maxAbsNegativeIndex, arr[maxAbsNegativeIndex]);
        arr[maxAbsNegativeIndex] = 0;
    }
    else
    {
        printf("   Отрицательных элементов не найдено\n");
    }
}


int* insertKBetweenDifferentSigns(int* arr, const size_t size, int K, size_t* newSize)
{

    size_t insertCount = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
        {
            insertCount++;
        }
    }

    *newSize = size + insertCount;
    int* newArr = malloc(*newSize * sizeof(int));
    

    size_t newIndex = 0;
    for (size_t i = 0; i < size; i++)
    {
        newArr[newIndex++] = arr[i];
        
        if (i < size - 1 && ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0)))
        {
            newArr[newIndex++] = K;
        }
    }
    
    return newArr;
}


int* createArrayAFromD(int* D, const size_t size, int k)
{
    int* A = malloc(size * sizeof(int));
    
    for (size_t i = 0; i < size; i++)
    {
        if (i < k) 
        {
            A[i] = -D[i] * D[i]; 
        }
        else 
        {
            A[i] = D[i] - 1; 
        }
    }
    
    return A;
}
