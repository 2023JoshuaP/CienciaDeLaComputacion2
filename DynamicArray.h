#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T> 
class DynamicArray {
    private:
        T* data;
        int size;
    public:
        DynamicArray();
        DynamicArray(T arr[], int);
        DynamicArray(const DynamicArray&);
        void pushback(T);
        void insert(T,int);
        void remove(int);
        void print()const;
        ~DynamicArray();
};
#endif