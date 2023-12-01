//Manvi, 12213106
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &inputArray) {
    int N = inputArray.size();
    int Max = 0;
    for(int i = 0; i < N; i++) {
        Max = max(Max, inputArray[i]);
    }
    return Max;
}

void countSortByPlace(vector<int> &inputArray, int exp) {
    const int N = inputArray.size();
    vector<int> outputArray(N);
    vector<int> counterArray(10, 0);

    for(int i = 0; i < N; i++) {
        counterArray[(inputArray[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++) {
        counterArray[i] += counterArray[i - 1];
    }

    for(int i = N - 1; i >= 0; i--) {
        outputArray[counterArray[(inputArray[i] / exp) % 10] - 1] = inputArray[i];
        counterArray[(inputArray[i] / exp) % 10]--;
    }

    for(int i = 0; i < N; i++) {
        inputArray[i] = outputArray[i];
    }
}

void radixSort(vector<int> &inputArray) {
    int Max = findMax(inputArray);

    for(int exp = 1; Max / exp > 0; exp *= 10) {
        countSortByPlace(inputArray, exp);
    }
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(a);

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
