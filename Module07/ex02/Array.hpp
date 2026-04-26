#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int size1 ;
    public:
        Array() : data(NULL), size1(0){};
        Array(const Array& obj): size1(obj.size1) {
            data = new T[size1];
            for (unsigned int i = 0; i < size1; i++){
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
                size1 = obj.size1;
                data = new T[size1];
                for (size_t i = 0; i < size1; i++)
                {
                    data[i]  = obj.data[i];
                }
            }
            return (*this);
        };

        T &operator[](unsigned int index){

            if (index >= size1){
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        T &operator[](unsigned int index) const {

            if (index >= size1){
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        unsigned int size() const{

            return size1;
        }

};

#endif