#include <iostream>
using namespace std;

class DynamicIntegerArray{
	private:
		int *data;
		int size;
	public:
		DynamicIntegerArray(){
			this -> size = 0;
			data = new int[0];
		}
		DynamicIntegerArray(int arr[], int size){
			this -> size = size;
			data = new int[size];
			for(int i = 0; i<size; i++){
				data[i] = arr[i];
			}
		}
		DynamicIntegerArray(const DynamicIntegerArray &o){
			this -> size = o.size;
			data = new int[o.size];
			for(int i = 0; i<o.size; i++){
				data[i] = o.data[i];
			}
		}
		void print() const{
			cout << "[ ";
			for(int i = 0; i<size; i++){
				cout << data[i] << " ";
			}
			cout << "]" << endl;
		}
		~DynamicIntegerArray(){
			delete[] data;
		}
		void pushback(int num){
			int aux[size];
			for(int i = 0; i<size; i++)
				aux[i] = data[i];
			delete [] data;
			size++;
			data = new int[size];
			for(int i = 0; i<size-1; i++)
				data[i] = aux[i];
			data[size-1] = num;
		}
		void insert(int num, int pos){
			int aux[size];
			for(int i = 0; i<size; i++)
				aux[i] = data[i];
			delete[] data;
			size++;
			data = new int[size];
			for(int i = 0; i<pos; i++)
				data[i] = aux[i];
			data[pos] = num;
			for(int i = pos+1; i<size; i++)
				data[i] = aux[i];
		}
		void remove(int pos){
			int aux[size];
			for(int i = 0; i<size; i++)
				aux[i] = data[i];
			delete [] data;
			size--;
			data = new int[size];
			for(int i = 0; i<pos; i++)
				data[i] = aux[i];
			for(int i = 0; i<size; i++)
				data[i] = aux[i];
		}
};

int main() {
    int arr[] = {2, 4, 6};
    int tam = 3;
    DynamicIntegerArray a(arr, tam);
    a.print();
    a.pushback(3);
    a.print();
    a.insert(10, 1);
    a.print();
    a.remove(2);
    a.print();
    return 0;
}