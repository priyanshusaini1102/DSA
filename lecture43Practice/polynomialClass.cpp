#include <iostream>

using namespace std;

class Polynomial{
    int *degCoeff;
    int n;

    public:

    int getCoefficient(int deg){
        if(deg >= this->n){
            return 0;
        }
        return this->degCoeff[deg];
    }

    Polynomial(){
        n = 3;
        degCoeff = new int[n];

        for(int i=0; i<n; i++){
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial &obj){
        this->n = obj.n;
        this->degCoeff = new int[this->n];

        for(int i=0; i<this->n; i++){
            this->degCoeff[i] = obj.degCoeff[i];
        }
    }

    void setCoefficient(int deg, int coeff){
        if(deg < n){
            this->degCoeff[deg] = coeff;
        }else{

            int *newArr = new int[deg*2];

            for(int i=0; i<(deg+1); i++){
                newArr[i] = 0;
            }

            for(int i=0;i<n;i++){
                newArr[i] = this->degCoeff[i];
            }

            newArr[deg] = coeff;
            this->n = deg+1;

            int *temp = this->degCoeff;
            this->degCoeff = newArr;

            delete[] temp;

        }
    }

    Polynomial operator + (Polynomial const &obj){
        Polynomial ans;

        int size = (this->n < obj.n)? this->n : obj.n;
        int i=0;
        while(i < size){
            ans.setCoefficient(i, this->degCoeff[i] + obj.degCoeff[i]);
            i++;
        }

        while(i<this->n){
            ans.setCoefficient(i, this->degCoeff[i]);
            i++;
        }

        while(i<obj.n){
            ans.setCoefficient(i, obj.degCoeff[i]);
            i++;
        }

        return ans;

    }

    Polynomial operator - (Polynomial const &obj){
        Polynomial ans;

        int size = (this->n < obj.n)? this->n : obj.n;
        int i=0;
        while(i < size){
            ans.setCoefficient(i, this->degCoeff[i] - obj.degCoeff[i]);
            i++;
        }

        while(i<this->n){
            ans.setCoefficient(i, this->degCoeff[i]);
            i++;
        }

        while(i<obj.n){
            ans.setCoefficient(i, -obj.degCoeff[i]);
            i++;
        }

        return ans;

    }

    Polynomial operator * (Polynomial const &obj){
        Polynomial ans;

        for(int i=0; i<this->n; i++){
            for(int j=0; j<obj.n; j++){
                ans.setCoefficient((i+j), ans.getCoefficient(i+j) + (this->degCoeff[i] * obj.degCoeff[j]));
            }
        }

        return ans;
    }

    void operator = (Polynomial const &obj){
      
        delete[] degCoeff;

        degCoeff = new int[obj.n];
        this->n = obj.n;
        for(int i=0; i<obj.n; i++){
            degCoeff[i] = obj.degCoeff[i];
        }
    }


    void print(){
        for(int i=0;i<this->n;i++){
            if(this->degCoeff[i] != 0){
                cout<<this->degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }

    ~Polynomial(){
        if(this->degCoeff != NULL){
            delete[] this->degCoeff;
        }
    }
};

int main(){

    Polynomial p;
    p.setCoefficient(0,0);
    p.setCoefficient(7,1);
    p.setCoefficient(2,2);
    p.setCoefficient(3,3);
    
    Polynomial q;
    q.setCoefficient(0,0);
    q.setCoefficient(2,2);
    q.setCoefficient(3,3);
    q.setCoefficient(4,1);
    
    Polynomial add;
    add = (p*q);
    cout << "\nMultiplication :\n";
    add.print();
    p.print();
    q.print();

    // Polynomial copyP(q);
    cout<<"\nCopy Constructor : \n";
    Polynomial copyP;
    copyP = q;
    cout<<"copy :";
    copyP.print();
    cout<<"\n q : ";
    q.print();


}