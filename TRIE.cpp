struct node{
  bool endmark;
  node *next[26+1];
  node() {
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

  void del(node *curr) {
   for(int i=0; i<26; i++) {
    if(curr->next[i]) del(curr->next[i]);
   }
   delete(curr);
  }

  bool prefix() {
   return pre;
  }

};


