#include <iostream>
using namespace std;

class Employee {
protected:               
    double salary;
    int empID;

public:                
    string name;

    // Constructor
    Employee(string n, double s, int id) {
        name = n;
        salary = s;
        empID = id;
    }
    double getdhdh() {
        return salary;
    }
};

int main() {
    Employee emp("Fedrick", 50000, 101);
    cout << emp.getdhdh() << endl;   
    return 0;
}