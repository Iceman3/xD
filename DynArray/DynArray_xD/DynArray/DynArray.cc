#include "DynArray.hh"

// constructors
DynArray::DynArray(void) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_size];
}
/*DynArray::DynArray(size_t size) {
	
}*/
DynArray::DynArray(size_t size, const int &value) {
	m_capacity = size;
	m_size = size;
	m_data = new int[size];
	fill(m_data, (m_data + m_size), value);
}
DynArray::DynArray(int *arr, size_t size) {
	m_capacity = size;
	m_size = size;
	m_data = new int[size];
	for (size_t i = 0; i < size; i++) {
		m_data[i] = arr[i];
	}
}

// destructor
DynArray::~DynArray(void) {
	m_capacity = 0;
	m_size = 0;
	delete[] m_data;
}

// assignment operators
DynArray& DynArray::operator= (const DynArray &x) {
	m_capacity = x.m_size;
	m_size = x.m_size;
	m_data = new int[m_size];
	for (size_t i = 0; i < m_size; i++) {
		m_data[i] = x.m_data[i];
	}

	return *this;
}

// iterator methods
int* DynArray::begin(void) const {
	return &m_data[0];
}
int* DynArray::end(void) const {
	return &m_data[m_size];
}

// capacity methods
void DynArray::resize(size_t n) {
	int *_m_data = new int[n];
	for (size_t i = 0; i < m_size && i < n; i++) {
		_m_data[i] = m_data[i];
	}

	delete[] m_data;
	m_data = new int[n];
	for (size_t i = 0; i < n; i++) {
		m_data[i] = _m_data[i];
	}
	delete[] _m_data;

	m_capacity = n;
	m_size = n;
}
/*void DynArray::reserve(size_t n) {

}
void DynArray::shrink(void) {

}
bool DynArray::empty(void) const {

}
size_t DynArray::capacity(void) const {

}*/
size_t DynArray::size(void) const {
	return m_size;
}
/*size_t DynArray::maxSize(void) {

}*/

// element access methods
int& DynArray::operator[] (size_t n) const {
	if (n >= m_size){
		return m_data[0];
	}

	return m_data[n];
}
/*int& DynArray::at(size_t n) const {

}
int& DynArray::front(void) const {

}
int& DynArray::back(void) const {

}
int* DynArray::data(void) const {

}*/

// modifiers methods
/*void DynArray::assign(size_t n, const int& val) {

}*/
void DynArray::push(const int &val) {
	m_size++;
	if (m_size > m_capacity){
		int *_m_data = new int[m_size];
		for (size_t i = 0; i < m_size - 1; i++) {
			_m_data[i] = m_data[i];
		}
		delete[] m_data;

		m_data = new int[m_size];
		for (size_t i = 0; i < m_size - 1; i++) {
			m_data[i] = _m_data[i];
		}
		delete[] _m_data;
	}
	m_data[m_size - 1] = val;

	m_capacity++;
}
/*void DynArray::pop(void) {

}*/
void DynArray::insert(size_t position, const int &val) {
	m_data[position] = val;
}
/*void DynArray::erase(size_t position) {

}
void DynArray::erase(size_t first, size_t last) {

}
void DynArray::swap(DynArray &x) {

}*/
void DynArray::clear(void) {
	m_capacity = 0;
	m_size = 0;
	delete[] m_data;
	m_data = new int[m_size];
}

// relational operators
bool operator== (const DynArray& lhs, const DynArray& rhs) {
	if (lhs.m_size == rhs.m_size){
		int _m_size = lhs.m_size;
		for (size_t i = 0; i < _m_size; i++){
			if (lhs.m_data[i] != rhs.m_data[i]){
				return false;
			}
		}
		return true;
	}

	return false;
}
/*bool operator!= (const DynArray& lhs, const DynArray& rhs) {

}
bool operator<  (const DynArray& lhs, const DynArray& rhs) {

}
bool operator<= (const DynArray& lhs, const DynArray& rhs) {

}
bool operator>  (const DynArray& lhs, const DynArray& rhs) {

}
bool operator>= (const DynArray& lhs, const DynArray& rhs) {

}*/

// input/output operators
std::ostream& operator<< (std::ostream &out, const DynArray &x) {
	for (size_t i = 0; i < x.m_size; i++){
		out << x.m_data[i] << std::endl;
	}

	return out;
}

// utils methods
/*const size_t& DynArray::min(const size_t &lhs, const size_t &rhs) {

}*/
void DynArray::fill(int *first, int *last, int value) {
	for (int *it = first; it != last; it++){
		*it = value;
	}
}
/*void DynArray::copy(int *first, int *last, int *dest) {

}*/