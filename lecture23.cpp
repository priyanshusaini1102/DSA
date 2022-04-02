#include <iostream>
//~~~~~~~~~~~~~~~ALL ABOUT 2D ARRAY~~~~~~~~~~~~~~~~~~//

using namespace std;

void getArrRowWise(int arr[][3], int row, int col){
    cout<<"Enter elements row wise : ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
}

void getArrColWise(int arr[][3], int row, int col){
    cout<<"Enter elements column wise : ";
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cin>>arr[j][i];
        }
    }
}

void printRowWiseSum(int arr[][3], int row, int col){

    for(int i=0; i<row; i++){
        int sum =0 ;
        for(int j=0; j<col; j++){
            sum+=arr[i][j];
        }
        cout<<"For "<<(i+1)<<" row, Sum is "<<sum<<"."<<endl;
    }
}

void printColWiseSum(int arr[][3], int row, int col){

    for(int i=0; i<col; i++){
        int sum =0 ;
        for(int j=0; j<row; j++){
            sum+=arr[j][i];
        }
        cout<<"For "<<(i+1)<<" column, Sum is "<<sum<<"."<<endl;
    }
}

void printColWiseMaxSum(int arr[][3], int row, int col){
    int maxSum = -1;
    for(int i=0; i<col; i++){
        int sum =0;
        for(int j=0; j<row; j++){
            sum+=arr[j][i];
        }
        maxSum = sum > maxSum ? sum : maxSum;
    }
    cout<<"Column wise Maxium Sum is "<<maxSum<<endl; 
}

void printRowWiseMaxSum(int arr[][3], int row, int col){
    int maxSum = -1;
    for(int i=0; i<row; i++){
        int sum =0 ;
        for(int j=0; j<col; j++){
            sum+=arr[i][j];
        }
        maxSum = sum > maxSum ? sum : maxSum;
    }

    cout<<"Row wise Maxium Sum is "<<maxSum<<endl;
    
}

bool linearSearch(int arr[][3], int row, int col, int key){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(key == arr[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

void printArr(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

//🙋‍♂️ Ques-106 ✅ : Wave Print ⬇️⬆️⬇️
void wavePrint(int arr[][3], int row, int col){

    for(int i=0; i<col; i++){
        if(i&1){
            //Handle for odd case
            for(int j=row-1; j>=0; j--){
                cout<<arr[j][i]<<" ";
            }
        }else{
            //Handle for even case
            for(int j=0; j<row; j++){
                cout<<arr[j][i]<<" ";
            }
        }
    }
}

//🙋‍♂️ Ques-107 ✅ : Spiral Print
void spiralPrint(int arr[][3], int row, int col){

    //set indexes.
    int startingRow = 0, lastCol = col-1, lastRow = row-1, startingCol = 0;

    int totalElements = col*row;
    int count = 0;

    while(count < totalElements){
        //for first row
        for(int i=startingCol;count < totalElements && i<=lastCol; i++){
            cout<<arr[startingRow][i]<<" ";
            count++;
        }
        startingRow++;

        //for last COlumn
        for(int i=startingRow;count < totalElements && i<=lastRow; i++){
            cout<<arr[i][lastCol]<<" ";
            count++;
        }
        lastCol--;

        //for last row
        for(int i = lastCol;count < totalElements && i>=startingCol; i--){
            cout<<arr[lastRow][i]<<" ";
            count++;
        }
        lastRow--;

        //for first Column
        for(int i = lastRow;count < totalElements && i>=startingRow; i--){
            cout<<arr[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
}

//🙋‍♂️ Ques-108 ✅ : Rotate (NxN - square matrix) array by 90 degrees clockwise aka rotate image.
void rotateArr(int arr[][3], int row, int col){
    //TRANSPOSE MATRIX
    for(int i=0; i<row; i++){
        for(int j=i+1; j<col; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // INVERSE MATRIX ROWWISE EX - 12 = 21
    for(int i=0; i<row; i++){
        int j=0,k=col-1;
        while(j<k){
            swap(arr[i][j++],arr[i][k--]);
        }
    }


}

//🙋‍♂️ Ques-109 ✅ : Binary Search in 2d array(level-1) 
bool binarySearch1(int arr[][3], int row, int col, int key){
    int start = 0;
    int end = (row*col)-1;

    int mid = start + (end-start)/2;

    while(start<=end){
        if(key == arr[mid/col][mid%row])
            return 1;

        if(key > arr[mid/col][mid%row]){
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return 0;
} 

//🙋‍♂️ Ques-110 ✅ : Binary Search in 2d array(level-2)  
bool binarySearch2(int arr[][3], int row,int col,int key){
    int startingRow =0;         //starting row
    int lastCol = col-1;    //last column
    
    while(startingRow<row && lastCol>=0){
        if(key == arr[startingRow][lastCol])
            return 1;

        if(key > arr[startingRow][lastCol]){
            startingRow++;
        }else{
            lastCol--;
        }
    }

    return 0;
    
}

int main(){
    // int arr[3][3];

    //✔️ To initialise array.
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};  //this is also row wise.

    //✔️ To get input row wise.
    // getArrRowWise(arr,3,3);

    //✔️ To get input column wise.
    // getArrColWise(arr,3,3);

    //✔️ To print 2d array
    printArr(arr,3,3);

    //✔️ To print row wise sum.
    // printRowWiseSum(arr,3,3);

    //✔️ To print column wise sum.
    // printColWiseSum(arr,3,3);

    //✔️ To print row wise maximum sum.
    // printRowWiseMaxSum(arr,3,3);

    //✔️ To print column wise maximum sum.
    // printColWiseMaxSum(arr,3,3);

    //✔️ To linear search in 2d array.
    // int key;
    // cout<<"Enter element to find in the array : ";
    // cin>>key;
    // if(linearSearch(arr,3,3,key)){
    //     cout<<"yes, "<<key<<" found successfully"<<endl;
    // }else{
    //     cout<<"no, "<<key<<" not found in the array"<<endl;
    // }

    //🙋‍♂️ Ques-106 ✅ : Wave Print ⬇️⬆️⬇️
    // wavePrint(arr,3,3);

    //🙋‍♂️ Ques-107 ✅ : Spiral Print
    // cout<<"Spiral Print : ";
    // spiralPrint(arr,3,3);
    // cout<<endl;

    //🙋‍♂️ Ques-108 ✅ : Rotate (NxN - square matrix) array by 90 degrees clockwise aka rotate image.
    // rotateArr(arr,3,3);
    // printArr(arr,3,3);

    //🙋‍♂️ Ques-109 ✅ : Binary Search in 2d array(level-1) 
    // int key;
    // cout<<"Enter key to find : ";
    // cin>>key;
    // if(binarySearch1(arr,3,3,key)){
    //     cout<<key<<" is found successfully."<<endl;
    // }else{
    //     cout<<key<<" is not found."<<endl;
    // }
    
    //🙋‍♂️ Ques-110 ✅ : Binary Search in 2d array(level-2)  
    // int key;
    // cout<<"Enter key to find : ";
    // cin>>key;
    // if(binarySearch2(arr,3,3,key)){
    //     cout<<key<<" is found successfully."<<endl;
    // }else{
    //     cout<<key<<" is not found."<<endl;
    // }

}