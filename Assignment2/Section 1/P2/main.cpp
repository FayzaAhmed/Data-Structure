/*
author: Mariam Amr Mohamed
ID: 20190520
Date: 2019/06/09
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;

//Insertion Sort using linear search
void linearInsertionSort(int arr[],int arrSize)
{
    int i, j, tmp;
    for (i = 1; i < arrSize; i++)
    {
        j = i-1;
        while (j >= 0 && arr[j] > arr[j+1])
        {
            tmp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

//Binary search
int binarySearch(int arr[], int selectedItem,int low, int high)
{
    if (high <= low)
    {
        if(selectedItem < arr[low])
        {
            return low;
        }
        else
        {
            return (low+1);
        }
    }

    int mid = (low + high) / 2;

    if (selectedItem == arr[mid])
    {
        return mid + 1;
    }

    else if (selectedItem > arr[mid])
    {
        return binarySearch(arr, selectedItem, mid + 1, high);
    }

    else
    {
        return binarySearch(arr, selectedItem, low, mid - 1);
    }
}

//Insertion sort using Binary search
void binaryInsertionSort(int arr[], int n)
{
    int i, j, temp,elemPosition;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        temp = arr[i];
        elemPosition = binarySearch(arr, temp, 0, j);

        //if j greater than the location of the element
        //swap till the element reach it's position
        while (j >= elemPosition)
        {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

//Printing sorted arrays.
void printArr(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int arrLinear[]= {10,9,6,8,3,4,5,7,2,1};
    linearInsertionSort(arrLinear,10);
    cout<<"Linear InsertionSort: "<<endl;
    printArr(arrLinear,10);

    int arrBinary[]= {10,9,6,3,4,5,7,12,1};
    binaryInsertionSort(arrBinary,9);
    cout<<"Binary InsertionSort: "<<endl;
    printArr(arrBinary,9);

    //Comparing both insertions
    cout<<"\nComparison: "<<endl;
    int  arrSize, count=1;
    for(int i=0; i<6; i++)
    {
        //Getting random size for the array between 40000 and 1000000
        arrSize=40000+rand()%100000;
        cout<<"\nSize of array " <<count<<": "<<arrSize<<endl;

        //Initializing array with the random size
        int randArray[arrSize];
        int randArray2[arrSize];

        //Filling two array with random elements with values 0-99 to be used in the comparison
        for(int i=0; i<arrSize; i++)
        {
            randArray[i]=rand()%100;
            randArray2[i]=randArray[i];
        }

        //Calculating time taken by linear search
        clock_t tStart = clock();
        linearInsertionSort(randArray,arrSize);
        clock_t tEnd= clock();
        clock_t timeTaken= tEnd-tStart;
        cout << "Time taken by Linear InsertionSort:" << (double)timeTaken/CLOCKS_PER_SEC << endl;

        //Calculating time taken by Binary search
        clock_t tStart2 = clock();
        binaryInsertionSort(randArray2,arrSize);
        clock_t tEnd2= clock();
        clock_t timeTaken2= tEnd2-tStart2;
        cout << "Time taken by Binary InsertionSort:" << (double)timeTaken2/CLOCKS_PER_SEC << endl;
        count++;
    }
    return 0;
}

