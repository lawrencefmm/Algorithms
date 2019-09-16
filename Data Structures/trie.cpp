#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* v[30];
    bool is_end_of_word;

    node()
    {
        for(int i = 0; i < 30; i++) v[i] = nullptr;
        is_end_of_word = false;
    }
};

// insert a word into the trie
void insert_word(node* trie, string s)
{
    node* at = trie;

    for(char u : s)
    {
        if(at->v[u - 'a'] == nullptr) at->v[u - 'a'] = new node();
        at = at->v[u - 'a'];
    }
    at->is_end_of_word = true;
}

// check if a word was already inserted
bool check(node* trie, string s)
{
    node* at = trie;
    for(char u : s)
    {
        if(at->v[u - 'a'] == nullptr) return false;
        at = at->v[u - 'a'];
    }
    return at->is_end_of_word;
}
