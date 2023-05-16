#include "DynamicArray.h"
#include <iostream>

template <typename T> DynamicArray<T>::DynamicArray(){
    data= new T[0];
    size=0;
}

template <typename T> DynamicArray<T>::DynamicArray(T arr[], int size){
    this->size=size;
    data= new T[size];
    for (int i=0;i<size;i++)
        data[i]=arr[i];
}

template <typename T> DynamicArray<T>::DynamicArray(const DynamicArray &o){
    this->size=o.size;
    data= new T[o.size];
    for (int i=0;i<size;i++)
        data[i]=o.data[i];
}

template <typename T> void DynamicArray<T>::pushback(T value){
    size++;
    T* copia=new T[size];
    for(int i =0; i<size-1; i++)
        copia[i]=data[i];
    copia[size]=value;
    delete[] data;
    data=copia;
}

template <typename T> void DynamicArray<T>::insert(T value, int pos){
    size++;
    T*copia=new T[size];
    for(int i=0;i<size;i++){
        if (i<pos)
            copia[i]=data[i];
        else if(i==pos)
            copia[i]=value;
        else
            copia[i]=data[i-1];
    }
    
    delete[] data;
    data=copia;
        
}

template <typename T> void DynamicArray<T>::remove(int pos){
    size--;
    T* copia=new T[size];
    for (int i=0;i<size;i++){
        if (i<pos)
            copia[i]=data[i];
        else
            copia[i]=data[i+1];
        
    }

    delete [] data;
    data=copia;
}

template <typename T> void DynamicArray<T>::print () const{
    std::cout<<" [";
    for(int i=0;i<size;i++)
        std::cout<<data[i]<<" ";
    std::cout<<"]"<<endl;
}
//template <typename T>DynamicArray<T>::~DynamicArray(){
    //delete[] data;
//}
