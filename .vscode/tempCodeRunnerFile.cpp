void printPattern(int num){
    int k=1;
    while(k<=num){

        if(k == 1){
        cout<<"*";
        }

        if(k>1 && k<num){
            cout<<"*";
            for(int i=1;i<k;i++){
                cout<<"^";
            }
            cout<<"*";
        }

        if(k==num){
            for(int i=1; i<=num;i++){
                cout<<"*";
            }
        }

        cout<<endl;
        k++;
    }

}