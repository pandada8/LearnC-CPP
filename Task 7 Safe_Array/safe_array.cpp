#include "safe_array.h"

Array::Array(int number){
	data = new int[number];
	length = number;
}

Array::~Array(){
	delete[] data;
}

const int Array::operator [] (int pos) const throw(OutRangeError){
	if (pos < length){
		return data[pos];
	}else{
		throw OutRangeError();
	}
};

int& Array::operator [] (int pos) throw(OutRangeError) {
	if(pos < length){
		return data[pos];
	}else{
		throw OutRangeError();
	}
};

ostream& operator << (ostream& output, Array& array){
    output << "[";
    int i;
    for(i = 0; i < array.length - 1 ; i++){
        output << array[i] << ",";
    };
    output<<array[i]<< "]";
    return output;
}
