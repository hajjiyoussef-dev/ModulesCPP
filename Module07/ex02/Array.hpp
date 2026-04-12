#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int size ;
    public:
        Array() : data(NULL), size(0){};
        Array(const Array& obj: size(obj.size) {
            data = new T[size];
            for (unsigned int i = 0; i < size; i++){
                data[i] = obj.data[i];
            }

        }
        ~Array(){

            delete[] data;
        }

        Array(unsigned int n){

            data  = new T[n];
            for (unsigned int i = 0; i < n; i++){
                data[i] = T();
            }
        }
        Array& operator=(const Array& obj){
            if (this != &obj){
                delete[] data;
                size = obj.size;
                data = new T[size];
                for (size_t i = 0; i < size; i++)
                {
                    data[i]  = obj.data[i];
                }
            }
            return (*this);
        };

};

#endif