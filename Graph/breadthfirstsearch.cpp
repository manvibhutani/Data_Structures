#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 20
class Queue
{
    public:
    int front=-1,rear=0,arr[max];
    bool isEmpty()
    {
        return (front-rear)==-1;
    }
    void enqueue(int a)
    {
        arr[++front]=a;
    }
    int dequeue()
    {
        return arr[rear++];
    }
    void printQueue()
    {
        for(int i=rear; i<=front; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
class Node
{
public:
int val;
Node* next;

};
class Graph
{
    public:
    int V;
    Node **adj;
    void createGraph(int v)
    {
        V=v;
        adj=new Node*[V];
        for(int i=1; i<=V; i++)
        {
            adj[i]=nullptr;
        }
    }
    void addEdge(int src, int dest)
    {
        Node *newNode;
        newNode->val=dest;
        newNode->next=adj[src];
        adj[src]->next=newNode;

    }
    void printGraph()
    {
        for(int i=1; i<=V; i++)
        {
            Node *curr=adj[i];
            while(curr!=nullptr)
            {
                cout<<curr->val<<" ";
            }
            cout<<"Null"<<"\n";
        }
    }








};
int main()
{
    Graph g;
    g.createGraph(8);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4,8);
    g.addEdge(8,7);
    g.addEdge(7,3);
    g.addEdge(7,6);
    g.addEdge(6,2);
    g.addEdge(6,5);
    g.addEdge(5,1);
    g.printGraph();

return 0;
}