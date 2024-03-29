#include "base.h"
#include <random>
#include <ctime>

Sort::Sort(std::vector<int> v)
    : elements(v)
{}

Sort::~Sort()
{}

void Sort::swap(int& a, int& b)
{
    auto tmp = a;
    a = b;
    b = tmp;
}

void Sort::init(std::vector<int>& v)
{
    std::srand(std::time(nullptr));
    for ( auto p = v.begin(); p != v.end(); p++ ) {
	*p = std::rand() % v.size();
    }
}

bool Sort::check() const
{
    for ( auto p = elements.begin(); (p+1) != elements.end(); p++ ) {
	if ( *p > *(p+1) ) {
	    return false;
	}
    }

    return true;
}
