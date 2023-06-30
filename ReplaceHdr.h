#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
class Node
{
    public:
        Node(int,Node*);
        int number;
        Node* next;
};

class Replace{
    public:
        Replace();
        void getdetails();
        void display();
        int getFirstpos();
        void deletenode(int);
        int search(int*,int**,int,int);
        void insert(Node*);
        bool comp(int,int);
        int findmin(int[]);
        int findmax(int[]);
        int findindex1(int*,int,int);
        int findindex(int*,int,int);
        void pop();
        void swap(int*,int*);
        void FIFO(int*,int**,int,int);
        void LRU(int*,int**,int,int);
        void Optimal(int*,int**,int,int);
        int *arr;
        Node *first;
        int n;
        int *page;
        int m;
        int **frame;
        int hit,fault;
};
