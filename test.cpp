#include <iostream>


# include <vector>
# include <algorithm>
template<typename T>
void print(T d) {
    std::cout << "size "<< d.size();
}

int main() {

    std::vector<int> v;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     v.push_back(i);
    //     std::cout << "size :" << v.size() << std::endl;
    //     std::cout << "capacity :" << v.capacity() << std::endl;
    // }
    // std::vector<int> copy(v.begin(), v.end());
    
    // for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
    // {
    //     // std::cout << *it << std::endl;
    //     // std::cout << "size copy:" << copy.size() << std::endl;
    //     // std::cout << "capacity copy:" << copy.capacity() << std::endl;
    // }
    
    v.push_back(11);
    std::vector<int>::iterator it  = v.begin();
    std::cout << *it << std::endl;
    v.push_back(12);
    it  = v.begin();
    std::cout << *it << std::endl;
    // v.push_back(13);
    // it  = v.begin();

    // std::cout << *it << std::endl;

    return 0;
}

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