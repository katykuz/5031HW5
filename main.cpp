/*
 * Name: Ekaterina (Katy) Kuznetsova
 * Date: May 7th, 2023
 * Assignment: 5031Homework5
 * C++ Version: C++17
 *
 * Program description:
 * This program implements and tests a HeapSort algorithm. The algorithm was
 * referenced from GeeksForGeeks.
 *
 * The test cases include: (1) an empty array, (2) a sorted array,
 * (3) a fully unsorted array, (4) a partially sorted array, (5) an array
 * with negative numbers, (6) an array with several repeating values.
 *
 * The program will show each of the arrays before sorting and after sorting.
 */

#include <iostream>
#include <string>

using namespace std;

void heapSortAlg(int arr[], int num);

void heapify(int arr[], int num, int index);

void printArray(int arr[], int num);

#include <iostream>
using namespace std;



// main program
int main(){

    //regular scenario of a partially mixed array
    //--------------------- test unsorted array ----------------------------
    cout << "********** Test 1: Unsorted Array **********\n";
    const int size = 6;
    int unsortedArr[size] = {4,17,3,12,9,6};
    cout<<"Input unsorted array: " << endl;
    printArray(unsortedArr, size);
    heapSortAlg(unsortedArr, size);
    cout << "Sorted array: " << endl;
    printArray(unsortedArr, size);
    cout << endl;

    //tests what happens if algorithm has nothing to do
    //--------------------- test sorted array ----------------------------
    cout << "********** Test 2: Sorted Array **********\n";
    const int size1 = 6;
    int sortedArr[size1] = {6, 9, 12, 13, 17, 18};
    cout<<"Input sorted array: " << endl;
    printArray(sortedArr, size1);
    heapSortAlg(sortedArr, size1);
    cout << "Sorted array: " << endl;
    printArray(sortedArr, size1);
    cout << endl;

    //this test the worst case scenario of changing the location of every value
    //--------------------- test Max Heap array ----------------------------
    cout << "********** Test 3: Max Heap Array **********\n";
    int maxHeapArr[size1] = {18,17,13,12,9,6};
    cout<<"Input max heap array: " << endl;
    printArray(maxHeapArr, size1);
    heapSortAlg(maxHeapArr, size1);
    cout << "Sorted array: " << endl;
    printArray(maxHeapArr, size1);
    cout << endl;

    //also tests algorithm if there is nothing to do but also what does it do
    // when it comes across an array of size zero
    //--------------------- test empty array ----------------------------
    cout << "********** Test 4: Empty Array **********\n";
    const int size2 = 0;
    int emptyArr[size2];
    cout<<"Input empty array: " << endl;
    printArray(emptyArr, size2);
    heapSortAlg(emptyArr, size2);
    cout << "Sorted array: " << endl;
    printArray(emptyArr, size2);
    cout << endl;

    //tests algorithm with what to do if several values are the equal
    //------------------- test repeating values array ------------------------
    cout << "********** Test 5: Repeating Values Array **********\n";
    const int size3 = 6;
    int repeatArr[size3] = {13,6,18,13,9,6};
    cout<<"Input array with repeating values: " << endl;
    printArray(repeatArr, size3);
    heapSortAlg(repeatArr, size3);
    cout << "Sorted array: "<<endl;
    printArray(repeatArr, size3);
    cout << endl;

    //tests algorithm if every value is equal
    //------------------- test single value array ------------------------
    cout << "********** Test 6: Single Value Array **********\n";
    const int size4 = 6;
    int singleArr[size4] = {11,11,11,11,11,11};
    cout<<"Input array with a single value: " << endl;
    printArray(singleArr, size);
    heapSortAlg(singleArr, size);
    cout << "Sorted array: "<<endl;
    printArray(singleArr, size);
    cout << endl;

    //tests algorithm when it comes across zero and negative values, which
    // may have equal absolute value but one is negative
    //----------------- test negative & Zero value array ----------------------
    cout << "********** Test 7: Negative & Zero Value Array **********\n";
    const int size5 = 6;
    int negativeArr[size5] = {11,-11,0,5,-20,1};
    cout<<"Input array with negative and zero values: " << endl;
    printArray(negativeArr, size);
    heapSortAlg(negativeArr, size);
    cout << "Sorted array: "<<endl;
    printArray(negativeArr, size);
    cout << endl;

}

// print the array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int minimum = root; // root is the minimum element
    int l = 2*root + 1; // left = 2*root + 1
    int r = 2*root + 2; // right = 2*root + 2

    // If left child is less than current minimum, then update it
    if (l < n && arr[l] > arr[minimum])
        minimum = l;

    // If right child is less than the current minimum, then update it
    if (r < n && arr[r] > arr[minimum])
        minimum = r;

    // If minimum is not root
    if (minimum != root)
    {
        //swap root and minimum
        swap(arr[root], arr[minimum]);

        // Recursively heapify the sub-tree
        heapify(arr, n, minimum);
    }
}

// implementing heap sort
void heapSortAlg(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // removing items from heap one by one from the end
    for (int i=n-1; i>=0; i--)
    {
        // Swap the root with the end index
        swap(arr[0], arr[i]);

        // heapify the 'remaining' heap
        heapify(arr, i, 0);
    }
}

//int main() {
//
//    //test 1
//
//    //test 2
//    int size = 6;
//    int * arrSorted = new int[size]{0, 1, 2, 3, 4,5};
//    cout << "Sorted Array Before: ";
//    printArray(arrSorted, size);
//    heapSortAlg(arrSorted, size);
//
//    cout << "Sorted Array After: ";
//    printArray(arrSorted, size);
//
//
//    //test 3
//    int * arrUnSorted = new int[size]{9, 8, 7, 6, 5, 4};
//    cout << "UnSorted Array Before: ";
//    printArray(arrUnSorted, size);
//    heapSortAlg(arrUnSorted, size);
//
//    cout << "Sorted Array After: ";
//    printArray(arrUnSorted, size);
//
//
//}
//
//void heapSortAlg(int * arr, int num){
//
//    //building the heap
//    for (int i = num/2 - 1; i >= 0; i--) {
//        heapify(arr, num, i);
//    }
//
//    //for removing elements from end of heap
//    for (int i = num- 1; i > 0; i--) {
//        swap(arr[0], arr[i]);
//        heapify(arr, num, i);
//    }
//
//
//}
//
//void heapify(int * arr, int num, int index){
//
//    //set the index to be the 'min' value
//    int min = index;
//
//    //left leaf eqn: left = 2*i + 1
//    int leftLeafInd = 2 * index + 1;
//
//    //right leaf eqn: 2*i + 2
//    int rightLeafInd = 2 * index + 2;
//
//    //if left is less than min
//    if (leftLeafInd < num && arr[leftLeafInd] < arr[min]){
//        min = leftLeafInd;
//    }
//
//    //if right is less than min
//    if (rightLeafInd < num && arr[leftLeafInd] < arr[min]){
//        min = rightLeafInd;
//    }
//
//    //if min(root) is not the index, then swap
//    if (min != index){
//        swap(arr[index], arr[min]);
//
//        //
//        heapify(arr, num, index);
//    }
//
//}
//
//void printArray(int * arr, int num){
//
//    cout << "[";
//    for (int i = 0; i < num - 1; i++) {
//        cout << arr[i] << " ";
//    }
//
//    cout << arr[num - 1] << "]" << endl;
//}
