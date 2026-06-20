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

# include <vector>
# include <algorithm>
template<typename T>
void print(T d) {
    std::cout << "size "<< d.size();
}
int main() {
    // Employee emp("Fedrick", 50000, 101);
    // cout << emp.getdhdh() << endl;
    std::vector<int> v;
    for (size_t i = 0; i < 20; i++)
    {
        v.push_back(i);
        std::cout << "size :" << v.size() << std::endl;
        std::cout << "capacity :" << v.capacity() << std::endl;
    }
    
    
    // v.push_back(1);


    // std::cout << &it << std::endl;

    return 0;
}