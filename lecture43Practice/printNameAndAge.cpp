#include<iostream>

using namespace std;

class Person {
    private:
    string name;
    int age;

    public:
    void setValue(string name, int age){
        this->name = name;
        this->age = age;
    }

    void getValue(){
        cout<<"The name of the person is "<<name<<" and the age is "<<age<<"."<<endl;
    }

};

int main() {

    //Write your code here
    Person p;
    string name;
    int age;

    cin>>name;
    cin>>age;

    p.setValue(name,age);
    p.getValue();

    return 0;
}