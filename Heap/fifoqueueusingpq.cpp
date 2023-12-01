//Manvi, 12213106
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

class Queue {
    int cnt;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
public:
    Queue() : cnt(0) {}

    void enqueue(int n);
    void dequeue();
    int front();
    bool isEmpty();
};

void Queue::enqueue(int n) {
    cnt++;
    pq.push(pi(cnt, n));
}

void Queue::dequeue() {
    if (pq.empty()) {
        cout << "Nothing to dequeue!!!" << endl;
        return;
    }
    cnt--;
    pq.pop();
}

int Queue::front() {
    pi temp = pq.top();
    return temp.second;
}

bool Queue::isEmpty() {
    return pq.empty();
}

int main() {
    Queue* q = new Queue();
    q->enqueue(9);
    q->enqueue(2);
    q->enqueue(3);
    while (!q->isEmpty()) {
        cout << q->front() << endl;
        q->dequeue();
    }

    return 0;
}
