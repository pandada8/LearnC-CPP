#include "safe_array.h"

Array::Array(int number){
	data = new int[number];
	length = number;
}

Array::~Array(){
	delete[] data;
}

const int Array::operator [] (int Position) const throw(OutRangeError){
	if (Position < length){
		return data[Position];
	}else{
		throw OutRangeError();
	}
};

int& Array::operator [] (int Position) throw(OutRangeError) {
	if(Position < length){
		return data[Position];
	}else{
		throw OutRangeError();
	}
};
