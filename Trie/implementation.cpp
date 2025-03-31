#include<iostream>
using namespace std;

class Trienode {
    public:
    char data;
    Trienode* children[26];
    bool isterminal;

    Trienode(char ch){
        data=ch;
         
        for(int i=0;i<26;i++){
            children[i]=NULL;
            }
            isterminal=false;
    }
};

class Trie{
    public:
    Trienode *root;

    Trie(){
        root=new Trienode('\0');
    }
                                                //insertion
    void insertUtil (Trienode* root,string word){
        if(word.empty()){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'A';
        Trienode* child;
        if(root->children[index]==NULL){
            root->children[index]=new Trienode(word[0]);
            }else{
                child = new Trienode(word[0]);
                root->children[index] =child;
            }

            //recursion
            insertUtil(root->children[index],word.substr(1));
    }


    void insertword(string word){
        insertUtil(root,word);
    }

                                        //search
    bool searchutil(Trienode* root, string word){
        if(word.empty()){
            return root->isterminal;
            }
            int index=word[0]-'A';
            Trienode* child;

            if(root->children[index]!=NULL){
                child = root->children[index];
                }
                else{
                    return false;
                }

                //recursion
                return searchutil(child,word.substr(1));
    }

    bool search(string word){
       return searchutil(root,word);
    }


                            //removal

    void removeUtil(Trienode* root, string word){
        if(word.empty()){
            if(root==NULL){
                return;
                }
                root->isterminal=false;
                }
                int index=word[0]-'A';
                Trienode* child;
                if(root->children[index]!=NULL){
                    child = root->children[index];
                    }
                    else{
                        return;
                        }
                        //recursion
                        removeUtil(child,word.substr(1));
    }

    void remove(string word){
        removeUtil(root,word);
    }
};

int main()
{

    Trie *t = new Trie();
    t->insertword("ARYAN");
    cout<<"word present or not: "<<t->search("ARYAN")<<endl;
    t->remove("ARYAN");
    cout<<"word present or not: "<<t->search("ARYAN")<<endl;
   return 0;
}