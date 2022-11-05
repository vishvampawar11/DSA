#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;
    
    bool contains(char c) {
        return links[c - 'a'] != NULL;    
    }
    
    void put(char c, Node *node) {
        links[c - 'a'] = node;    
    }

    Node *get(char c) {
        return links[c - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node *root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *p = root;
        
        for(int i=0;i<word.size();i++) {
            if(!p->contains(word[i])) {
                p->put(word[i], new Node());
            }
            p = p->get(word[i]);
        }
        p->setEnd();
    }
    
    bool search(string word) {
        Node *p = root;
        for(int i=0;i<word.size();i++) {
            if(!p->contains(word[i]))
                return false;
            p = p->get(word[i]);
        }
        return p->isEnd();
    }
    
    bool startsWith(string word) {
        Node *p = root;
        for(int i=0;i<word.size();i++) {
            if(!p->contains(word[i]))
                return false;
            p = p->get(word[i]);
        }
        return true;
    }
};

int main() {
  
}
