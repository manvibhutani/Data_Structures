//Manvi, 12213106
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int Parent(int i) {
    return (i - 1) / 2;
}

int Left(int i) {
    return 2 * i + 1;
}

int Right(int i) {
    return 2 * i + 2;
}

void MaxHeapify(int A[], int i, int heapSize) {
    int largest = i;
    int left = Left(i);
    int right = Right(i);
    
    if (left < heapSize && A[left] > A[largest])
        largest = left;
    
    if (right < heapSize && A[right] > A[largest])
        largest = right;
    
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest, heapSize);
    }
}

void BuildMaxHeap(int A[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, i, size);
    }
}

int Maximum(int A[]) {
    return A[0];
}

int ExtractMax(int A[], int *heapSize) {
    if (*heapSize < 1) {
        printf("Error: Priority Queue underflow.\n");
        return INT_MIN;
    }
    
    int max = A[0];
    A[0] = A[*heapSize - 1];
    (*heapSize)--;
    MaxHeapify(A, 0, *heapSize);
    
    return max;
}

void IncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        printf("Error: New key is smaller than the current key.\n");
        return;
    }
    
    A[i] = key;
    
    while (i > 0 && A[Parent(i)] < A[i]) {
        int temp = A[i];
        A[i] = A[Parent(i)];
        A[Parent(i)] = temp;
        
        i = Parent(i);
    }
}

void Insert(int A[], int key, int *heapSize) {
    if (*heapSize == MAX_SIZE) {
        printf("Error: Priority Queue overflow.\n");
        return;
    }
    
    (*heapSize)++;
    A[*heapSize - 1] = INT_MIN;
    IncreaseKey(A, *heapSize - 1, key);
}

void Delete(int A[], int i, int *heapSize) {
    if (i >= *heapSize) {
        printf("Error: Invalid index.\n");
        return;
    }
    
    A[i] = A[*heapSize - 1];
    (*heapSize)--;
    MaxHeapify(A, i, *heapSize);
}

void PrintHeap(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void MinHeapify(int A[], int i, int heapSize) {
    int smallest = i;
    int left = Left(i);
    int right = Right(i);

    if (left < heapSize && A[left] < A[smallest])
        smallest = left;

    if (right < heapSize && A[right] < A[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        MinHeapify(A, smallest, heapSize);
    }
}

void BuildMinHeap(int A[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        MinHeapify(A, i, size);
    }
}
int ExtractKthMax(int A[], int *heapSize, int k) {
    if (k <= 0 || k > *heapSize) {
        printf("Error: Invalid value of k.\n");
        return INT_MIN;
    }


    int minHeap[k];
    for (int i = 0; i < k; i++) {
        minHeap[i] = A[i];
    }
    BuildMinHeap(minHeap, k);

 
    for (int i = k; i < *heapSize; i++) {
        if (A[i] > minHeap[0]) {
           
            minHeap[0] = A[i];
            MinHeapify(minHeap, 0, k);
        }
    }

    return minHeap[0];
}

int main() {
    int A[MAX_SIZE];
    int heapSize = 0;

    Insert(A, 4, &heapSize);
    Insert(A, 9, &heapSize);
    Insert(A, 2, &heapSize);
    Insert(A, 7, &heapSize);
    Insert(A, 5, &heapSize);
    
    printf("Heap after insertion: ");
    PrintHeap(A, heapSize);
    
    
   printf("%dth-max element, %d", 2,ExtractKthMax(A,&heapSize,2));
    
    return 0;
}