
#include "DynamicArray.h"
using namespace std;

int main() {
    int arr1[5]={1,2,3,4,5};
    DynamicArray<int> d1(arr1,5);
    d1.print();

}