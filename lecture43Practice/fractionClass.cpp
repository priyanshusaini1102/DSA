#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {

    int numerator,denominator;

    public:
    Fraction(int numerator,int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void add(Fraction &obj){
        this->numerator = (this->numerator * obj.denominator) + (this->denominator * obj.numerator);
        this->denominator = this->denominator * obj.denominator;
    }

    void multiply(Fraction &obj){
        this->numerator = this->numerator * obj.numerator;
        this->denominator = this->denominator * obj.denominator;
    }

    void simplify(){
        int factor = __gcd(this->numerator, this->denominator);

        if(factor>1){
            this->numerator = this->numerator / factor;
            this->denominator = this->denominator / factor;
        }
    }

    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }

};

int main() {

    //Write your code here
    int n1,d1,n2,d2,ch;
    cin>>n1>>d1;
    int n;
    cin>>n;
    Fraction f1(n1,d1);
    for(int i=0;i<n;i++){
        cin>>ch>>n2>>d2;
        Fraction f2(n2,d2);
        switch(ch){
            case 1:
                f1.add(f2);
                f1.simplify();
                f1.print();
                break;
            case 2:
                f1.multiply(f2);
                f1.simplify();
                f1.print();
                break;
            default:
                break;
        }
    }
    return 0;
}