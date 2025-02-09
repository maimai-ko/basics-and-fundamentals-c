#include <iostream>
using namespace std;

void mergeAndSort(int array1[], int size1, int array2[], int size2, int merged[], int mergedSize)
{
    mergedSize = size1 + size2;
    for (int i = 0; i < size1; i++)
    {
        merged[i] = array1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        merged[size1 + i] = array2[i];
    }

    for (int i = 0; i < mergedSize; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < mergedSize; j++)
        {
            if (merged[j] > merged[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            int temp = merged[i];
            merged[i] = merged[maxIndex];
            merged[maxIndex] = temp;
        }
    }
}

int getValidInput(int min, int max)
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail() || value < min || value > max)
        {
            cin.clear();
            cin.ignore();
            cout << endl
                 << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
        }
        else
        {
            break;
        }
    }
    return value;
}

void getArrayInput(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        arr[i] = getValidInput(-10000, 10000);
    }
}

int main()
{
    int array1[10], array2[10], merged[20];
    int size1, size2, mergedSize;

    cout << "Enter the number of elements for Array 1 (max 10): ";
    size1 = getValidInput(1, 10);

    cout << "Enter the elements for Arrray 1: " << endl;
    getArrayInput(array1, size1);

    cout << "Enter the number of elements for Array 2 (max 10): ";
    size2 = getValidInput(1, 10);

    cout << "Enter the elements for Arrray 2: " << endl;
    getArrayInput(array2, size2);

    mergedSize = size1 + size2;

    mergeAndSort(array1, size1, array2, size2, merged, mergedSize);

    cout << "Merged and sorted array in descending order: ";
    for (int i = 0; i < mergedSize; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
}
