#include<iostream>

using namespace std;

class ComplexNumbers {
    public:
    int real,imaginary;

    public:
    ComplexNumbers(){};
    ComplexNumbers(int real,int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    void print(){
        cout<<real<<" + i"<<imaginary;
    }

    void plus(ComplexNumbers &obj){
        this->real = this->real + obj.real;
        this->imaginary = this->imaginary + obj.imaginary;
    }

    void multiply(ComplexNumbers &obj){
        int real1 = (this->real * obj.real) - (this->imaginary * obj.imaginary);
        this->imaginary = (this->imaginary * obj.real) + (this->real * obj.imaginary);
        this->real = real1;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}