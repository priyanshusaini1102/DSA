#include <iostream>

//OOPS Concept

using namespace std;

class Student{
    private:
    string name;

    public:
    void setName(string name){
        this->name = name;
    }
    void behaviour(){
        cout<<"Studying..."<<endl;
    }
};

class Player: public Student{
    public:
    void behaviour(){
        cout<<"Playing..."<<endl;
    }
};

class Singer: public Student{
    public:
    void behaviour(){
        cout<<"Singing..."<<endl;
    }
};

class Competitor: public Player ,public Singer{
    private:
    string date = "25-May-2022";

    public:
    void competitionOn(){
        cout<<("Competition On "+date)<<endl;
    }

};

int main(){

    Student student;
    student.setName("Student");

    Player player;
    player.setName("Player");

    Singer singer;
    singer.setName("Singer");

    /*
    player.behaviour();
    singer.behaviour();
    singer.Student::behaviour();
    student.behaviour();
    */

   Competitor competitor;
   competitor.Player::setName("competitor");
   competitor.Singer::behaviour();
   competitor.competitionOn();

}