#pragma once
#include<iostream>  
using namespace std;  
  
class lexicon {  
private:  
  
  
    struct node {  
      
        int times;  
        string word;  
        node* left; node* right;  
      
        node(string s, int n=1, node* l=nullptr, node* r=nullptr)  :  
            word(s), left(l), right(r), times(n) {};  
    };  
  
    node* root;  
  
    void Print(const node* p) const {  
        if (p == nullptr)return;  
        Print(p->left);  
        cout << p->word << " " << p->times << endl;  
        Print(p->right);  
    }  
  
  
  
    static void deletenode(node** p) {  
        if ((*p) == nullptr)return;  
        if ((*p)->left == nullptr && (*p)->right == nullptr) {    
          
            delete *p;  
            *p = nullptr;  
              
        }  
        else if ((*p)->left == nullptr) {  
            node* temp = (*p)->right;  
            (*p)->word = temp->word;  
            (*p)->times = temp->times;  
            (*p)->right = temp->right;  
            (*p)->left = temp->left;  
            delete temp;  
        }  
        else if ((*p)->right == nullptr) {  
            node* temp = (*p)->left;  
            (*p)->word = temp->word;  
            (*p)->times = temp->times;  
            (*p)->right = temp->right;  
            (*p)->left = temp->left;  
            delete temp;  
        }  
        else {  
           
           
            node** maxLeft = &((*p)->left);  
            while ((*maxLeft)->right != nullptr) {  
                maxLeft = &((*maxLeft)->right);  
            }  
  
              
            (*p)->word = (*maxLeft)->word;  
            (*p)->times = (*maxLeft)->times;  
  
              
            deletenode(maxLeft);  
  
  
  
  
        }  
    }  
  
  
  
  
  
public:  
  
    lexicon() {  
        root = nullptr;  
    }  
  
    void insert(const string& s) {  
  
        if (root == nullptr) {  
            root = new node(s);  
            return;  
        }  
  
        node** p = &root;  
        while (*p != nullptr) {  
  
            if (s == (*p)->word) { (*p)->times += 1; return; }  
            else if (s > (*p)->word) { p = &((*p)->right); }  
            else { p = &((*p)->left); }  
        }  
        *p = new node(s);  
        return;  
    }  
  
    int lookup(const string& s) {  
          
        node* p = root;  
      
        while (p != nullptr) {  
  
            if (p->word == s) { return p->times; }  
            else if (s > p->word) { p = p->right; }  
            else { p = p->left; }  
        }  
  
        return 0;  
    }  
  
    int depth(const string& s) {  
          
        int deep = 0;  
        node* p = root;  
  
        while (p != nullptr) {  
  
            if (p->word == s) { return deep; }  
            else if (s > p->word) { p = p->right; deep +=1; }  
            else { p = p->left; deep += 1; }  
        }  
  
        return -1;  
  
    }  
  
    void replace(const string& s1, const string& s2) {  
  
        int k = 0;  
        node** p = &root;  
  
        while (*p != nullptr && (*p)->word != s1) {  
            if (s1 > (*p)->word) { p = &((*p)->right); }  
            else { p = &((*p)->left); }  
        }  
  
        if (*p == nullptr) { return; }  
  
        k = (*p)->times;  
          
        deletenode(p);  
  
        for (int i = 0; i < k; i++) { insert(s2); }  
  
    }  
    friend ostream& operator << (ostream& out, const lexicon& l) {  
  
        l.Print(l.root);  
        return out;  
  
    }  
  
  
};  

