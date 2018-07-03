#include "PFAString.hpp"

//Will remove later
#include <iostream>

PFAString::PFAString()
	:arr(nullptr)
	,_capacity(0)
	,_size(0)
{}

PFAString::PFAString(unsigned int icapacity, std::string istring )
	:_capacity(icapacity)
	,_size(icapacity)
{
	arr=new std::string[_capacity];
	for(unsigned int i=0;i<_capacity;i++){
		arr[i]=istring;
	}

}

PFAString::PFAString(const PFAString &rhs)
{
	(*this)._capacity=rhs._size;
	(*this)._size=rhs._size;
	std::string *new_arr=new std::string[_capacity];
	for(unsigned int i=0;i<_size;i++){
		new_arr[i]=rhs[i];
	}
	arr=new_arr;
}

PFAString::PFAString(PFAString &&rhs){
	if(this == &rhs){
		std::cout<<"Cannot use move constructor with the object itself"<<std::endl;
	}
	else{
		(*this)._capacity=rhs._capacity;
		(*this)._size=rhs._size;
		(*this).arr=rhs.arr;

		//Must change pointer of rhs before deleting rhs 
		rhs.arr=nullptr;	
	}
}

PFAString::~PFAString(){
	if(arr!=nullptr){
		delete [] arr;
		arr=nullptr;
	}
}

unsigned int PFAString::capacity() const{
	return _capacity;
}

unsigned int PFAString::size() const{
	return _size;
}

void PFAString::reallocate(){
	std::string *new_arr=new std::string[_capacity*2];
	for(unsigned int i=0;i<_size;i++){
		new_arr[i]=arr[i];
	}
	delete [] arr;
	arr=new_arr;
	_capacity=_capacity*2;
}

void PFAString::push_back(const std::string& strVal){
	if (_capacity==0){
		_size++;
		arr=new std::string[_size];
		arr[_size-1]=strVal;
		_capacity++;
		return;
	}
	else{
		if(_size==_capacity){
			(*this).reallocate();
		}
		arr[_size]=strVal;
		_size++;
	}
}

void PFAString::resize(size_type n,const std::string& value){
	if (n==_size)
		return;
	else if(n<_size){

		for(unsigned int i=n;i< _size;i++){
			arr[i]=std::string();
		}
		_size=n;
	}
	else {
		if (n<=_capacity){		
			unsigned int needfill=n-_size;
			for(unsigned int i=0;i<needfill;i++){
				(*this).push_back(value);
			}
		}
		else{
			//Create a new space that appropriate with new input
			std::string *new_arr=new std::string[n];
			for(unsigned int i=0;i<_capacity;i++){
				new_arr[i]=arr[i];
			}	
			for(unsigned int i=_capacity;i<n;i++){
				new_arr[i]=value;
			}
			delete [] arr;
			arr=new_arr;
			_size=n;
			_capacity=n;
		}
	}
}
void PFAString::pop_back(){
	if (_size>0){
		arr[_size-1]=std::string();
		_size--;
	}
	else{
		std::cout<<"Can not pop back anymore"<<std::endl;
	}
}

void PFAString::empty_array(){
	_size=0;
}

std::string& PFAString::operator[](unsigned int iter){
	return arr[iter];
}

const std::string& PFAString::operator[](unsigned int iter) const{
	return arr[iter];
}

PFAString& PFAString::operator=(const PFAString& rhs){
	if(&rhs == this){
		return *this;
	}
	else{
		if ((*this).arr != nullptr){ //Need to free the memory before doing assignment
			delete [] arr;
		}

		_size=rhs._size;
		_capacity=rhs._size;

		std::string *new_arr=new std::string[_capacity];
		for(unsigned int i=0;i<_size;i++){
			new_arr[i]=rhs[i];
		}

		arr=new_arr;

		return *this;
	}
}

PFAString& PFAString::operator=(PFAString&& rhs){
	if(&rhs == this){
		return *this;
	}
	else{
		if ((*this).arr != nullptr){ //Need to free the memory before doing assignment
			delete [] arr;
		}
		_size=rhs._size;
		_capacity=rhs._capacity;
		arr=rhs.arr;

		//Must change pointer of rhs before deleting rhs 
		
		rhs.arr=nullptr;
		return *this;		
	}	
}


bool PFAString::operator<(const PFAString& rhs) const {
	unsigned int min_size= (*this)._size<rhs._size ? _size:rhs._size;
	for(unsigned int i=0;i<min_size;i++){
		if ( arr[i] < rhs[i]){
			return true;
		}
	} 
	if(_size<rhs._size){
		return true;
	}else
		return false;
}

bool PFAString::operator>(const PFAString& rhs) const{
	return (rhs < (*this))? true : false;
}

bool PFAString::operator<=(const PFAString& rhs) const{
	return ((*this) > rhs) ? false: true ;
}

bool PFAString::operator>=(const PFAString& rhs) const{
	return ((*this)<rhs) ? false: true ;
}

bool PFAString::operator==(const PFAString& rhs) const{
	if ((( *this <rhs) == false) && ((*this>rhs) ==false)) {
		return true;
	}
	else 
		return false;
}

bool PFAString::operator!=(const PFAString& rhs) const{
	return ((*this)== rhs) ? false:true;
}

void printVector(const PFAString& lhs){
	std::cout<<"Capacity: "<<\
	std::setw(3)<<std::right<<lhs.capacity();
	std::cout<<std::setw(10);
	std::cout <<"Size :"<<\
	std::setw(3)<<std::right<<lhs.size();
	
	std::cout<<std::setw(5)<<std::right<<"Data: ";
	for(unsigned int i=0;i<lhs.size();i++){
		std::cout<<lhs[i]<<" ";
	}
	std::cout<<"\n";
}

