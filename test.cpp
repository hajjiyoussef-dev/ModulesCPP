#include <iostream>


# include <vector>
#include <list>
# include <algorithm>
// template<typename T>
// void print(T d) {
//     std::cout << "size "<< d.size();
// }

// int main() {

//     std::vector<int> v;
//     // for (size_t i = 0; i < 10; i++)
//     // {
//     //     v.push_back(i);
//     //     std::cout << "size :" << v.size() << std::endl;
//     //     std::cout << "capacity :" << v.capacity() << std::endl;
//     // }
//     // std::vector<int> copy(v.begin(), v.end());
    
//     // for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
//     // {
//     //     // std::cout << *it << std::endl;
//     //     // std::cout << "size copy:" << copy.size() << std::endl;
//     //     // std::cout << "capacity copy:" << copy.capacity() << std::endl;
//     // }
    
//     v.push_back(11);
//     std::vector<int>::iterator it  = v.begin();
//     std::cout << *it << std::endl;
//     v.push_back(12);
//     it  = v.begin();
//     std::cout << *it << std::endl;
//     // v.push_back(13);
//     // it  = v.begin();

//     // std::cout << *it << std::endl;

//     std::list<std::string> l(5, "hello");

//     for (std::list<std::string>::iterator it = l.begin(); it != l.end(); it++){
//         std::cout << *it << std::endl;
//         std::cout  << l.max_size() << std::endl;
//     }
    
//     // for (size_t i = 0; i < l.size(); i++)
//     // {
//     //     l.
//     // }
    

//     return 0;
// }

// int main() {

//     int num, k = 0 ;
//     scanf("%d", &num);

//     for (size_t i = num; i >= 1; i--)
//     {
        
//         for (size_t k = num; k >= i; k--)
//             std::cout << "  ";
//         for (size_t j = 0; j <= i ; j++)
//             std::cout << k++;
//         std::cout << "\n";
        
//     }
    

//     return 0;
// }

// C Program to Illustrate the use of clock() Function
#include <iostream>
#include <ctime>

int main() {
    // 1. Start the clock
    std::clock_t start = std::clock();

    // ... run your code here ...
    for (volatile int i = 0; i < 1000000; ++i); 

    // 2. End the clock
    std::clock_t end = std::clock();

    // 3. Calculate duration in microseconds (us)
    double duration_us = (static_cast<double>(end - start) * 1000000.0) / CLOCKS_PER_SEC;

    std::cout << "Execution time: " << duration_us << " us\n";

    return 0;
}