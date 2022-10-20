leftQ

while(!lQueue.empty()){
    temp = lQueue.front();
    lQueue.pop();

    while(temp != NULL){
        cout << temp;

        if(temp->left){
            lQueue.push(temp->left);
        }
        if(temp->right){
            temp = temp->right;
        }
    }
}