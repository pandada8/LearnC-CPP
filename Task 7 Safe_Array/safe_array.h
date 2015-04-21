#include <iostream>

using namespace std;

class OutRangeError{};

class Array{
	public:
		Array(int number);
		~Array();
		const int operator[] (int Position) const throw (OutRangeError);
		int& operator[] (int Position) throw (OutRangeError);
		friend ostream& operator << (ostream& output, Array& array);
	private:
		int * data;
		int length;
};



