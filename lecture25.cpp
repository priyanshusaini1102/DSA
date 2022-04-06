#include <iostream>

using namespace std;

void fun(int a[]) {
    cout<<"in function :" << a[0] << " ";
}

int main(){

    int a[] = {1, 2, 3, 4};
    fun(a+1);
    cout<<"out of function : " << a[0];

    //Simple Pointer 
    // int num = 23;
    // int *numPtr = &num;
    // cout<<"Address store at numPtr : "<<numPtr<<endl;
    // cout<<"Value store at numPtr : "<<*numPtr<<endl;

    //Null Pointer
    // int *nullPtr = 0;
    // cout<<"value in null pointer, nullPtr : "<<nullPtr<<endl;

    //Double pointer
    // int a = 10;
    // int *ptr1 = &a;
    // int **ptr2 = &ptr1;
    // cout<<"value of a using a : \t\t"<<a<<endl;
    // cout<<"value of a using *ptr1 : \t"<<*ptr1<<endl;
    // cout<<"value of a using **ptr2 : \t"<<**ptr2<<endl;
    // cout<<"---------After increment--------------------"<<endl;
    // cout<<"value of a using **ptr2 : \t"<<++(**ptr2)<<endl;
    // cout<<"value of a using *ptr1 : \t"<<(*ptr1)<<endl;
    // cout<<"value of a using a : \t\t"<<a<<endl;

    //Void Pointer
    // void *voidPtr;
    // int b = 10;
    // voidPtr =&b;
    // cout<<"Address of b using \t\t &b : "<<b<<endl;
    // cout<<"Address of b using \t voidPtr : "<<voidPtr<<endl;
    // cout<<"Value of b using \t\t b : "<<b<<endl;
    // cout<<"Value of b using \t *voidPtr : "<<(int)*voidPtr<<endl;

    //Wild Pointer
    // int *wildPtr;       //it is a wild pointer till it points to a known variable.
    // int c = 1;
    // wildPtr = &c        //Now it is not a wild pointer.

    //Dangling Pointer
    // A dangling pointer is a pointer pointing to a memory location that has been freed (or deleted). 
    // There are three different ways where Pointer acts as a dangling pointer.
    //Reference - https://www.codingninjas.com/codestudio/guided-paths/pointers/content/235645/offering/3168908

    // int a[] = {1, 2, 3, 4};
    // cout << *(a) << " " << *(a+1);

    // int a[] = {1, 2};
    // int *ptr = a++;       //gives error TODO: clear confusion why??
    // int *ptr = a+1;      //gives the address of a[1] = 2
    // cout<<*ptr<<endl;
    // cout<<0[a];

    // char str[] = "abc";
    // char *ptr = &str[0];
    // cout<<ptr<<endl;

    // char s[]= "hello";
    // char *p = s;
    // cout << s[0] << " " << p[0]<<1[s+1];

    // 🙊 Special fact about arr print.
    // int arr[] = {0,1,2,3};
    // for(int i=0; i<4; i++){
    //     cout<<arr[i]<<" "<<i[arr]<<endl;
    // }


}