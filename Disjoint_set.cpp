#include<bits/stdc++.h>
using namespace std;

class UF {
  int *id, cnt, *sz;

  public:

  UF(int N) {
    cnt = N;
    id = new int[N];
    sz = new int[N];
    for(int i=0; i<N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
  }

  ~UF() {
   delete [] id;
   delete [] sz;
  }

  int find(int p) {
   int root = p;

   while(root!=id[root]) root = id[root];

   while(p!=root) {
    int temp = id[p];
    id[p] = root;
    p = id[p];
   }

   return root;
  }

  void merge(int x, int y) {
    int i = find(x);
    int j = find(y);

    if(i==j) return;

    if(sz[i]<sz[j]) {
        id[i] = j;
        sz[j]+=sz[i];
    }
    else {
        id[j] = i;
        sz[i]+=sz[j];
    }

    cnt--;
  }

  bool connected(int x, int y) {
   return find(x)==find(y);
  }

  int count() {
   return cnt;
  }

};

int main() {
   UF L(7);
   cout<<L.count()<<endl;
}
