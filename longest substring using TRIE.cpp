#include<bits/stdc++.h>
using namespace std;

struct node {
  int cc[27];
  bool endmark;
  node *next[26+1];
  node() {
   memset(cc, 0, sizeof(cc));
   endmark = false;
   for(int i = 0; i<26; i++) next[i] = NULL;
  }
};

struct TRIE {
  node *root;
  bool pre;

  TRIE() {
   root = new node();
   pre = false;
  }

  void insert(string str) {
   node *curr = root;
   int cnt = 0;

   int len = str.size();
   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) {
            curr->next[id] = new node();
    }
    else cnt++;

    curr->cc[id]++;
    if(curr->endmark) pre = true;
    curr = curr->next[id];
   }

   if(cnt==len) pre = true;
   curr->endmark = true;
  }

  bool search(string str) {
   node *curr = root;
   int len = str.size();

   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) return false;
    curr = curr->next[id];
   }


   return curr->endmark;
  }

  int prefix_occurance(string s) {

   int res = INT_MAX;
   node *curr = root;

   for(int i=0; i<s.size(); i++) {
    int id = s[i] - 'a';
    if(curr==NULL) {
        res = 0;
        break;
    }

    res = min(res, curr->cc[id]);
    curr = curr->next[id];
   }

   return res;

  }

  void del(node *curr) {
   for(int i=0; i<26; i++) {
    if(curr->next[i]) del(curr->next[i]);
   }
   delete(curr);
  }

  int max_substring(node *curr) {

    int res = 1;

     for(int i=0; i<26; i++) {
        if(curr->next[i]!=NULL) {
         if(curr->cc[i]>1) return max(res, 1+max_substring(curr->next[i]));
         else return max(res, max_substring(curr->next[i]));
        }
     }
  }

  bool prefix() {
   return pre;
  }

};

int main() {
  TRIE a;
  a.insert("oggy");
  a.insert("ggy");
  a.insert("gy");
  a.insert("y");

  a.insert("pgfq");
  a.insert("gfq");
  a.insert("fq");
  a.insert("q");
 cout<<a.max_substring(a.root)<<endl;
}
