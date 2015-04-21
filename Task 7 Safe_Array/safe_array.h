class OutRangeError{};

class Array{
	public:
		Array(int number);
		~Array();
		const int operator[] (int Position) const throw (OutRangeError);
		int& operator[] (int Position) throw (OutRangeError);
	private:
		int * data;
		int length;
};

