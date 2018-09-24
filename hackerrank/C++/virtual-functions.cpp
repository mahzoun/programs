#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
public:
  string name;
  int age;
  virtual void getdata(){}
  virtual void putdata(){}
};

class Professor : public Person {
public:
  int publication;
  int cur_id;
  static int id;
  Professor(){
    Professor::id++;
    cur_id = Professor::id;
  }
  void getdata() {
    cin >> Professor::name >> Professor::age >> Professor::publication;
  }
  void putdata() {
    cout << Professor::name << " " << Professor::age << " " << Professor::publication << " " << Professor::cur_id << endl;
  }
};

class Student : public Person {
public:
  int marks[6];
  int sum;
  int cur_id;
  static int id;
  Student(){
    Student::id++;
    cur_id = Student::id;
  }
  void getdata() {
    cin >> Student::name >> Student::age;
    sum = 0;
    for (int i = 0; i < 6; i++){
      cin >> Student::marks[i];
      sum += marks[i];
    }
  }
  void putdata() {
    cout << Student::name << " " << Student::age << " " << Student::sum << " " Student::cur_id << endl;
  }
};
int Professor::id = 0;
int Student::id = 0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
