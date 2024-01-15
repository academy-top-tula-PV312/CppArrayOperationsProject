#include <iostream>

void ArrayInit(int array[], int size);
void ArrayPrint(int array[], int size);
int ArrayMinValue(int array[], int size);
int ArrayMinIndex(int array[], int size);
void ArrayReverse(int array[], int size);
void ArrayShiftLeft(int array[], int size, int steps);

int main()
{
    srand(time(nullptr));

    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    std::cout << "Min = " << ArrayMinValue(array, size) << "\n";
    std::cout << "Min index = " << ArrayMinIndex(array, size) << "\n";

    ArrayReverse(array, size);
    ArrayPrint(array, size);

    ArrayShiftLeft(array, size, 2);
    ArrayPrint(array, size);
}

void ArrayInit(int array[], int size)
{
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int array[], int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int ArrayMinValue(int array[], int size)
{
    int min = array[0];
    for (int i{ 1 }; i < size; i++)
        if (min > array[i])
            min = array[i];
    return min;
}

int ArrayMinIndex(int array[], int size)
{
    int minIndex{};
    for (int i{ 1 }; i < size; i++)
        if (array[minIndex] > array[i])
            minIndex = i;
    return minIndex;
}

void ArrayReverse(int array[], int size)
{
    int temp;
    for (int i{}; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

void ArrayShiftLeft(int array[], int size, int steps)
{
    //steps = steps % size;
    steps %= size;
    for (int s{}; s < steps; s++)
    {
        int temp{ array[0] };
        for (int i{}; i < size - 1; i++)
            array[i] = array[i + 1];
        array[size - 1] = temp;
    }
}
