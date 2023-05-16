#include <iostream>
using namespace std;

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

template <typename T> DynamicArray<T>::DynamicArray(){
    data= new T[0];
    size=0;
}

template <typename T> DynamicArray<T>::DynamicArray(T arr[], int size){
    this->size=size;
    data = new T[size];
    for (int i = 0;i < size; i++)
        data[i] = arr[i];
}

template <typename T> DynamicArray<T>::DynamicArray(const DynamicArray &o){
    this->size=o.size;
    data= new T[o.size];
    for (int i=0;i<size;i++)
        data[i]=o.data[i];
}

template <typename T> void DynamicArray<T>::pushback(T value){
    this->size=size+1;
    T *copia=new T[size];
    for(int i =0; i<size-1; i++)
        copia[i]=data[i];
    copia[size-1]=value;
    delete[] data;
    data = copia;
}

template <typename T> void DynamicArray<T>::insert(T value, int pos){
    this->size=size+1;
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
    this->size=size-1;
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
    cout << " [";
    for(int i=0;i<size;i++)
        cout << data[i] << " ";
    cout << "]" << endl;
}

template <typename T>DynamicArray<T>::~DynamicArray(){
    delete [] data;
}

class Estudiante{
	private:
		string nombre;
	public:
		Estudiante(){};
    	Estudiante(const string& nombre) : nombre(nombre) {}
    	friend ostream& operator<<(ostream& os, const Estudiante& estudiante);
};

ostream& operator<<(ostream& os, const Estudiante& estudiante) {
    os << estudiante.nombre;
    return os;
}

int main(){
	int opc;
	cout << "Elije: ";
	cin >> opc;
	if(opc == 1){
		int arr1[3]={1,2,3};
    	DynamicArray<int> d1(arr1,3);
    	cout << "Array Original" << endl;
    	d1.print();
    	cout << "Pushback" << endl;
    	d1.pushback(4);
    	d1.print();
    	cout << "Insert" << endl;
    	d1.insert(0,1);
    	d1.print();
    	cout << "Remove" << endl;
    	d1.remove(4);
    	d1.print();
	}
	else if(opc == 2){
		float arr2[3]={1.3,2.2,3.9};
    	DynamicArray<float> d2(arr2,3);
    	cout << "Array Original" << endl;
    	d2.print();
    	cout << "Pushback" << endl;
    	d2.pushback(4.1);
    	d2.print();
    	cout << "Insert" << endl;
    	d2.insert(9.8,1);
    	d2.print();
    	cout << "Remove" << endl;
    	d2.remove(4.1);
    	d2.print();
	}
	else if(opc == 3){
		char arr3[3]={'h','o','m'};
    	DynamicArray<char> d3(arr3,3);
    	cout << "Array Original" << endl;
    	d3.print();
    	cout << "Pushback" << endl;
    	d3.pushback('a');
    	d3.print();
    	cout << "Insert" << endl;
    	d3.insert('t',1);
    	d3.print();
    	cout << "Remove" << endl;
    	d3.remove('a');
    	d3.print();
	}
	else if(opc == 4){
		double arr4[3]={1.4,2,3.1};
    	DynamicArray<double> d4(arr4,3);
    	cout << "Array Original" << endl;
    	d4.print();
    	cout << "Pushback" << endl;
    	d4.pushback(8);
    	d4.print();
    	cout << "Insert" << endl;
    	d4.insert(1.7,1);
    	d4.print();
    	cout << "Remove" << endl;
    	d4.remove(2);
    	d4.print();
	}
	else if(opc == 5){
		Estudiante e1("A"), e2("B"), e3("C"), e4(""), e5("");
		Estudiante arr5[3] = {e1,e2,e3};
    	DynamicArray<Estudiante> d4(arr5,3);
    	cout << "Array Original" << endl;
    	d4.print();
    	cout << "Pushback" << endl;
    	d4.pushback(e4);
    	d4.print();
    	cout << "Insert" << endl;
    	d4.insert(e5,1);
    	d4.print();
    	cout << "Remove" << endl;
    	d4.remove(2);
    	d4.print();
	}
    return 0;
}