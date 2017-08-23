#include<bits/stdc++.h>
using namespace std;

struct HEAP {
    int heap[100], top;

    HEAP() {
        top=0;
    }

    void insert_(int val) {
        top+=1;
        heap[top]=val;
        heapifyUp(top);
    }

    int parent(int node) {
        int ret=node/2;
        if(node==1) return -1;
        else return ret;
    }

    int left(int node) {
        int ret=2*node;
        if(ret<=top || node==0) return ret;
        else return -1;
    }

    int right(int node) {
        int ret=2*node+1;
        if(ret<=top || node==0) return ret;
        else return -1;
    }

    void heapifyUp(int node) {
        if(node==0) return;

        if(node>1 && parent(node)>=1 && heap[parent(node)]<heap[node]) {
            swap(heap[parent(node)], heap[node]);
            heapifyUp(parent(node));
        }

    }

    void heapifyDown(int node) {
        int L=left(node);
        int R=right(node);

        if(L>=1 && R>=1 && heap[L]<heap[R]) {
            L=R;
        }
        if(L>=1 && node>=1 && heap[node]<heap[L]) {
            swap(heap[L], heap[node]);
            heapifyDown(L);
        }
    }

    void delete_max() {
        if(top==0) return;

        heap[1]=heap[top];
        top--;
        heapifyDown(1);
    }

    int maxi() {
    if(top==0) {
            return -1;
        } else return heap[1];
    }

};

int main() {
    HEAP L;
    L.insert_(1);
    L.insert_(5);
    L.insert_(8);

    cout<<L.maxi()<<endl;
    L.delete_max();

    cout<<L.maxi()<<endl;

    return 0;
}
