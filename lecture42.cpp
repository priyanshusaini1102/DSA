#include <iostream>

using namespace std;

class A
{
public:
    string name;
    int power;

    A(string name, int power)
    {
        this->name = name;
        this->power = power;
    }



    void print()
    {
        cout << "\n{ name: " << name << ", power: " << this->power << " }" << endl;
    }
};

class students
{
    int age;
    public:
    char *names;

    students(int age, char *names)
    {
        this->age = age;
        // shallow copy 
        this->names = names;    // here we are putting same array. // we are just coping the refrence
        
    }

    void print(){
         cout << "\n{ names: " << names << ", age: " << this->age << " }" << endl;
    }
};

class B{
    public:
    int *x;

    void setX(int val){
        *x=val;
    }
    B(){

    }

    B(int val){

    }
    B(B& a){
        x = new int;
        *(this->x)=*(a.x);
    }

    void print(){
        cout<<"\n{ x: " << *x <<" }"<<endl;
    }

    void increment(){
        *x = *x+1;
    }

};

class D{
    public:
    int *x;

    void setX(int val){
        x = new int;
        *x=val;
    }

    void increment(){
        *x = *x+1;
    }

    void print(){
        cout<<"\n{ x: " << *x <<" }"<<endl;
    }
};

int main()
{
    /*
    char names[6] = {'a', 'b', 'c', 'd', 'e','\0'};
    char names2[4] = {'k','l','m','\0'};
    students class1(5,names);
    class1.print();

    students class2(class1);
    class2.names = names2;
    class2.print();
    class1.print();

    A a("priyanshu", 100);
    a.print();

    A b(a);
    b.name = "nikhil";
    b.print();
    a.print();
    */

   //Shallow Copy

   B b;
   int val = 5;
   b.x = &val;
   b.print();

   B copyB(b);
   copyB.print();
   b.increment();
   copyB.print();
    b.print();


//    cout<<endl<<b.x<<copyB.x<<endl;

    //Deep Copy
    /*
   D b;
   int val = 5;
   b.x = &val;
   b.print();

   D copyB(b);
   copyB.print();
   b.increment();
   copyB.print();
   b.print();
   */




}