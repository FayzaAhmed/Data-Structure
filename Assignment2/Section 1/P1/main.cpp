#include <iostream>
#include <ctime>
using namespace std;
/*
Name: Norhan Abdelkader Ali
ID: 20190600
Group: S4
*/


//Merge Sort Functions
void mergeArray(int arr[], int startIndex, int middleIndex, int endIndex)
{
    int sizeLeftArr = middleIndex - startIndex + 1;
    int sizeRightArr = endIndex - middleIndex;

    int leftArr[sizeLeftArr];
    int rightArr[sizeRightArr];

    for(int i = 0; i < sizeLeftArr; i++)
    {
        leftArr[i] = arr[startIndex + i];
    }
    for(int i = 0; i < sizeRightArr; i++)
    {
        rightArr[i] = arr[middleIndex + i + 1];
    }

    int inFirstSubArr = 0;
    int inSecondSubArr = 0;
    int inMrgSubArr = startIndex;

    //Compare the left array elements with right array to put the smallest in merge array
    while (inFirstSubArr < sizeLeftArr && inSecondSubArr < sizeRightArr)
    {
        if (leftArr[inFirstSubArr] <= rightArr[inSecondSubArr])
        {
            arr[inMrgSubArr] = leftArr[inFirstSubArr];
            inFirstSubArr++;
        }
        else
        {
            arr[inMrgSubArr] = rightArr[inSecondSubArr];
            inSecondSubArr++;
        }
        inMrgSubArr++;
    }

    //In case the left array has remaining elements
    while (inFirstSubArr < sizeLeftArr)
    {
        arr[inMrgSubArr] = leftArr[inFirstSubArr];
        inMrgSubArr++;
        inFirstSubArr++;
    }

    //In case the right array has remaining elements
    while (inSecondSubArr < sizeRightArr)
    {
        arr[inMrgSubArr] = rightArr[inSecondSubArr];
        inMrgSubArr++;
        inSecondSubArr++;
    }
}

void performMergeSort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int mid = (startIndex + (endIndex - 1)) / 2;
        performMergeSort(arr, startIndex, mid);
        performMergeSort(arr, mid + 1, endIndex);
        mergeArray(arr, startIndex, mid, endIndex);
    }
}
//Quick Sort Functions
int partitionArray(int arr[], int startIndex, int endIndex)
{
    //take the last element as pivot
    int pivotNum = arr[endIndex];
    int swapPoint = (startIndex - 1);
    int tmp;

    for(int i = startIndex; i <= (endIndex-1); i++)
    {
        if(arr[i]<pivotNum)
        {
            swapPoint++;
            tmp = arr[i];
            arr[i] = arr[swapPoint];
            arr[swapPoint] = tmp;
        }
    }
    tmp = arr[swapPoint+1];
    arr[swapPoint+1] = arr[endIndex];
    arr[endIndex] = tmp;

    return (swapPoint + 1);
}
void performQuickSort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int index = partitionArray(arr, startIndex, endIndex);

        //Sort sub-parts in both right and left the pivot
        performQuickSort(arr, startIndex, (index - 1));
        performQuickSort(arr, (index + 1), endIndex);
    }
}

int main()
{
    int counter = 0;
    for (int capacity = 5000 ; capacity <= 100000 ; capacity += 5000)
    {
        int arr[capacity];

        for(int i = 0; i < capacity; i++)
        {
            int randNum = 0;
            randNum = rand()%1200;
            arr[i] = randNum;
        }

        double startTime = clock();
        performQuickSort(arr, 0, capacity - 1);
        double finishTime = clock();

        double passTime = (double)(finishTime - startTime)/CLOCKS_PER_SEC;
        cout << "\nArray size: " << capacity << endl;
        cout << counter + 1 << "- Quick Sort Time: " << passTime << endl;

        startTime = clock();
        performMergeSort(arr, 0, capacity - 1);
        finishTime = clock();

        passTime = (double)(finishTime - startTime)/CLOCKS_PER_SEC;
        cout << counter + 1 << "- Merge Sort Time: " << passTime << endl;

        counter ++;
    }
    return 0;
}
