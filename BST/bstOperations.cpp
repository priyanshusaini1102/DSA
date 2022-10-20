#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node* left,*right;
        int data;

        Node(int data){
            left = NULL;
            right = NULL;
            this->data = data;
        }
};


    Node* insertInBST(Node* root, int data){
        if(root==NULL){
            Node* newNode = new Node(data);
            return newNode;
        }

        if(data>root->data){
            root->right = insertInBST(root->right, data);
        }else{
            root->left = insertInBST(root->left, data);
        }

        return root;
    }

    void inOrderUsingMorris(Node* root){
        Node* curr = NULL;
        curr = root;
        if(root==NULL) return;
        Node* pred = NULL;

        while(curr!=NULL){
            
            if(curr->left!=NULL){

                pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr)
                    pred = pred->right;

                if(pred->right==NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    cout<<curr->data<<" ";
                    curr = curr->right;
                }

            }else{
                cout<<curr->data<<" ";
                curr = curr->right;
            }

        }
    }

    void inOrder(Node* root){
        if(root==NULL) return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    Node* searchInBST(Node* root, int key){

        if(root==NULL || root->data == key)return root;

        if(key>root->data){
            return searchInBST(root->right, key);
        }else{
            return searchInBST(root->left, key);
        } 
    }

    Node* deleteFromBST(Node* root, int val) {
        if(root==NULL) return NULL;

        if(root->data==val){
            if(root->right!=NULL && root->left!=NULL){
                Node* pred = root->left;
                while(pred->right!=NULL){
                    pred = pred->right;
                }

                root->data = pred->data;
                root->left = deleteFromBST(root->left, pred->data);
                return root;
                
            }else{
                Node* temp = root->left!=NULL ? root->left : root->right;
                delete root;
                return temp;
            }


        }

        if(val>root->data){
            root->right = deleteFromBST(root->right, val);
        }else{
            root->left = deleteFromBST(root->left, val);
        }
        return root;

    }

int main(){
    int op,val;
    Node* root = NULL;
    Node* foundNode = NULL;

    while(1){
        cout<<"\n1.Insert\t2.Print \t3.Search\t4.Delete\t5.Exit\nEnter your choice : ";
        cin>>op;

        switch(op){
            case 1: 
                cout<<"\nEnter the value to insert : ";
                cin>>val;
                root = insertInBST(root,val);
                cout<<"\nSuccessfully Inserted.";
                break;
            case 2:
                cout<<"\nBinary Search Tree : ";
                inOrderUsingMorris(root);
                break;
            case 3:
                cout<<"\nEnter value to search in BST : ";
                cin>>val;
                foundNode = searchInBST(root,val);
                cout<<"\nIs found : "<<(foundNode!=NULL)<<endl;
                break;
            case 4:
                cout<<"\nEnter the value to delete : ";
                cin>>val;
                root = deleteFromBST(root,val);
                cout<<"\nSuccessfully Deleted\n";
                break;
            case 5:
                cout<<"\nHappy Coding!\n\n"; 
                exit(0);
            default:
                cout<<"\nEnter valid option."<<endl;
        }
    }
    
}