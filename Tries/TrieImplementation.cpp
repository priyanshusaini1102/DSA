#include <bits/stdc++.h>

using namespace std;

//TrieNode
class TrieNode{
    public:
    string ch;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(string ch){
        this->ch = ch;
        for(int i=0;i<26; i++){
            children.push_back(NULL);
        }
        isTerminal = false;
    }

};

//Trie
class Trie{
    public:
    TrieNode* root;

    Trie(){
        this->root = new TrieNode("\0");
    }

    //insert a new string in Trie.
    void insert(string ch) {
        int i=0;
        TrieNode* child = root;
        while(i<ch.size()){
            int index = ch[i]-'a';
            if(child->children[index] == NULL){
                TrieNode* newNode = new TrieNode(""+ch[i]);
                child->children[index] = newNode;
                child = newNode;
            }else{
                child = child->children[index];
            }
            i++;
        }

        child->isTerminal = true;
    }

    //searching any word in Trie.
    bool search(string ch,int i=0){
        TrieNode* child = root;
        while(i<ch.size()){
            int index = ch[i]-'a';
            if(child->children[index] == NULL){
                return false;
            }else{
                child = child->children[index];
            }
            i++;
        }

        if(child->isTerminal==true){
            return true;
        }else{
            return false;
        }

    }

     //searching any prefix of word in Trie.
    bool searchPrefix(string ch,int i=0){
        TrieNode* child = root;
        while(i<ch.size()){
            int index = ch[i]-'a';
            if(child->children[index] == NULL){
                return false;
            }else{
                child = child->children[index];
            }
            i++;
        }

        return true;

    }

    // delete any word from Trie.
    void deleteWord(string ch,int i=0) {
        TrieNode* child = root;

        while(i<ch.size()){
            int index = ch[i]-'a';

            if(child->children[index] == NULL) {
                return;
            }else{
                child = child->children[index];
            }
            i++;

        }
        if(child->isTerminal == true) {
            child->isTerminal = false;
        }
    }

};

int main(){
    Trie* T = new Trie();

    T->insert("what");

    cout<<T->search("what")<<endl;
    cout<<T->searchPrefix("wh")<<endl;
    T->deleteWord("what");
    cout<<T->search("what")<<endl;
    


}