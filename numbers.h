/**************************************
   CS2401 Spring 2013	Lab Assignment 4
	John Dolan
   A little class that holds a dynamic array of numbers
***************************************/
#include<ctime>
#include <iostream>
#include <string>
#include <fstream>
#include<iostream>
//#ifndef NUMBERS_H
//#define NUMBERS_H

size_t byte_count = 0;
class Numbers{
    public:
		Numbers();
		// Numbers(const Numbers &obj);
		// You will need to add a destructor in here
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);
		unsigned long* reveal_address()const;
		void operator = (const Numbers& other);
		// This is used in Part 2 and would normally not be in a container	unsigned long * reveal_address()const;
		//This is a function that you add in Part 2
		~Numbers();
    private: 
		unsigned long * data;
		std::size_t used;
		std::size_t capacity;
};

Numbers::Numbers()
{
	data = new unsigned long[5];
	used = 0;
	capacity = 5;
	byte_count += 5*sizeof(unsigned long);
}

// Numbers::Numbers(const Numbers &Obj)
// {
// 	tmp 
// }


void Numbers::add(unsigned long item)
{
	if(used == capacity)
	{
	   resize();
	}
	data[used] = item;
	used++;
}

void Numbers::resize()
{
	unsigned long *tmp;
	tmp = new unsigned long[capacity+5];
	std::copy(data, data+used, tmp);
	delete [] data;
	capacity += 5;
	byte_count += 5*sizeof(unsigned long);
	data = tmp;
}

void Numbers::remove_last()
{
	used--;
}

void Numbers::display(std::ostream& outs)
{
	for(std::size_t i = 0; i < used; ++i)
	{
	    outs << data[i] << ' ';
	}
}

unsigned long *Numbers::reveal_address()const
{
	return data;
}


void Numbers::operator = (const Numbers& other)
{
	if(data != other.reveal_address()) {
		delete [] data;
		used = other.used;
		capacity = other.capacity;
		std::copy(other.reveal_address(), other.reveal_address()+other.used, data);
	}
}

Numbers::~Numbers()
{
	delete [] data;
	byte_count = byte_count - capacity*sizeof(unsigned long);
}
