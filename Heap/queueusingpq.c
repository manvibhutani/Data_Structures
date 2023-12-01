//Manvi, 12213106
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

struct Heap {
    int elements[MAX_SIZE];
    int size;
};

void initializeHeap(struct Heap* heap) {
    heap->size = 0;
}

int Parent(int i) {
    return (i - 1) / 2;
}

int Left(int i) {
    return 2 * i + 1;
}

int Right(int i) {
    return 2 * i + 2;
}

void MaxHeapify(struct Heap* heap, int i) {
    int largest = i;
    int left = Left(i);
    int right = Right(i);

    if (left < heap->size && heap->elements[left] > heap->elements[largest])
        largest = left;

    if (right < heap->size && heap->elements[right] > heap->elements[largest])
        largest = right;

    if (largest != i) {
        int temp = heap->elements[i];
        heap->elements[i] = heap->elements[largest];
        heap->elements[largest] = temp;
        MaxHeapify(heap, largest);
    }
}

void BuildMaxHeap(struct Heap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        MaxHeapify(heap, i);
    }
}

int Maximum(struct Heap* heap) {
    return heap->elements[0];
}

int ExtractMax(struct Heap* heap) {
    if (heap->size < 1) {
        printf("Error: Priority Queue underflow.\n");
        return INT_MIN;
    }

    int max = heap->elements[0];
    heap->size--;
    heap->elements[0] = heap->elements[heap->size];
    MaxHeapify(heap, 0);

    return max;
}

void IncreaseKey(struct Heap* heap, int i, int key) {
    if (key < heap->elements[i]) {
        printf("Error: New key is smaller than the current key.\n");
        return;
    }

    heap->elements[i] = key;

    while (i > 0 && heap->elements[Parent(i)] < heap->elements[i]) {
        int temp = heap->elements[i];
        heap->elements[i] = heap->elements[Parent(i)];
        heap->elements[Parent(i)] = temp;

        i = Parent(i);
    }
}

void Insert(struct Heap* heap, int key) {
    if (heap->size == MAX_SIZE) {
        printf("Error: Priority Queue overflow.\n");
        return;
    }

    heap->size++;
    heap->elements[heap->size - 1] = INT_MIN;
    IncreaseKey(heap, heap->size - 1, key);
}

void Delete(struct Heap* heap, int i) {
    if (i >= heap->size) {
        printf("Error: Invalid index.\n");
        return;
    }

    heap->elements[i] = heap->elements[heap->size - 1];
    heap->size--;
    MaxHeapify(heap, i);
}

void PrintHeap(struct Heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->elements[i]);
    }
    printf("\n");
}

struct FIFOQueue {
    struct Heap heap;
    int priorityCounter;
};

void initializeFIFOQueue(struct FIFOQueue* queue) {
    initializeHeap(&queue->heap);
    queue->priorityCounter = 0;
}

int isFIFOQueueEmpty(struct FIFOQueue* queue) {
    return queue->heap.size == 0;
}

void enqueue(struct FIFOQueue* queue, int data) {
    Insert(&queue->heap, data);
}

int dequeue(struct FIFOQueue* queue) {
    return ExtractMax(&queue->heap);
}

int main() {
    struct FIFOQueue queue;
    initializeFIFOQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeue: %d\n", dequeue(&queue));
    printf("Dequeue: %d\n", dequeue(&queue));

    enqueue(&queue, 4);
    printf("Dequeue: %d\n", dequeue(&queue));

    return 0;
}
