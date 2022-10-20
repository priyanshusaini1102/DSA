#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node()
    {
    }
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    node *buildTree(node *root)
    {
        int data;
        cout << "Enter the data";
        cin >> data;

        if (data == -1)
            return NULL;
        root = new node(data);

        cout << "\nEnter the data for left of " << data << " : " << endl;
        root->left = buildTree(root->left);
        cout << "\nEnter the data for right of " << data << " : " << endl;
        root->right = buildTree(root->right);
        return root;
    }

    void inOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        };

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void levelOrder(node *root)
    {
        queue<node *> q;
        stack<int> st;
        if (root == NULL)
            return;
        q.push(root);
        cout << "LevelOrder :";
        while (q.empty() == false)
        {

            node *temp = q.front();
            q.pop();
            st.push(temp->data);
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                // cout<<(temp->left)->data<<" ";
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                // cout<<(temp->right)->data<<" ";
                q.push(temp->right);
            }
        }
        cout << endl;
        cout << "Reverse Level order :";
        while (st.empty() == false)
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
};

void levelOrderR(queue<node *> q,int &count)
{
    if (q.empty()) return;
    int n = q.size();
    int* arr = new int[n];
    for(int i = 0; i <n; i++){

        node *temp = q.front();
        // cout<<temp->data<<" ";
        arr[i] = temp->data;
        q.pop();
        if (temp->left != NULL)
        {
            // cout<<(temp->left)->data<<" ";
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            // cout<<(temp->right)->data<<" ";
            q.push(temp->right);
        }
    
    }
    levelOrderR(q,count);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    count++;
}

int height(node* root) {
    if(root == NULL) return 0;

    int h1 = root->left ? height(root->left) : 0;
    int h2 = root->right ? height(root->right) : 0;

    int max = (h2>h1) ? h2 : h1;
    return max + 1;

}

int main()
{

    node *root = NULL;
    int maxHeight = 0;
    // root = new node();
    root = root->buildTree(root);
    cout << "InOrder : ";
    root->inOrder(root);
    cout << endl;
    root->levelOrder(root);

    queue<node*> q;
    q.push(root);
    cout<<"\nlevelOrder by recurssion : \n";
    levelOrderR(q,maxHeight);
    cout<<"\nHeight : "<<height(root)<<endl;
}