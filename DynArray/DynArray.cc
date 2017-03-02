#include "DynArray.hh"

// constructors
DynArray::DynArray(void) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_size];
}
DynArray::DynArray(size_t size) {
	
}
DynArray::DynArray(size_t size, const int &value) {
	
}
DynArray::DynArray(int *arr, size_t size) {
	m_capacity = sizeof(arr);
	m_size = size;
	m_data = new int[size];

	for (int i = 0; i < size; i++) {
		m_data[i] = arr[i];
	}
}

// destructor
DynArray::~DynArray(void) {
	m_capacity = 0;
	m_size = 0;
	delete [] m_data;
}

// assignment operators
DynArray& DynArray::operator= (const DynArray &x) {
	DynArray *ptr = new DynArray(x.m_data, x.m_size);
	return *ptr;
}

// iterator methods
int* DynArray::begin(void) const {
	 
}
int* DynArray::end(void) const {
	//
}

// capacity methods
void DynArray::resize(size_t n) {

}
/*void DynArray::reserve(size_t n) {

}
void DynArray::shrink(void) {

}
bool DynArray::empty(void) const {

}
size_t DynArray::capacity(void) const {

}
size_t DynArray::size(void) const {

}
size_t DynArray::maxSize(void) {

}*/

// element access methods
int& DynArray::operator[] (size_t n) const {
	//
}
int& DynArray::at(size_t n) const {

}
int& DynArray::front(void) const {

}
int& DynArray::back(void) const {

}
int* DynArray::data(void) const {

}

// modifiers methods
void DynArray::assign(size_t n, const int& val) {

}
void DynArray::push(const int &val) {

}
void DynArray::pop(void) {

}
void DynArray::insert(size_t position, const int &val) {

}
void DynArray::erase(size_t position) {

}
void DynArray::erase(size_t first, size_t last) {

}
void DynArray::swap(DynArray &x) {

}
void DynArray::clear(void) {

}

// relational operators
bool operator== (const DynArray& lhs, const DynArray& rhs) {
	//
}
bool operator!= (const DynArray& lhs, const DynArray& rhs) {

}
bool operator<  (const DynArray& lhs, const DynArray& rhs) {

}
bool operator<= (const DynArray& lhs, const DynArray& rhs) {

}
bool operator>  (const DynArray& lhs, const DynArray& rhs) {

}
bool operator>= (const DynArray& lhs, const DynArray& rhs) {

}

// input/output operators
std::ostream& operator<< (std::ostream &out, const DynArray &x) {

}

// utils methods
const size_t& DynArray::min(const size_t &lhs, const size_t &rhs) {

}
void DynArray::fill(int *first, int *last, int value) {
	//
}
void DynArray::copy(int *first, int *last, int *dest) {

}