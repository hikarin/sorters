#include "base.h"

Sort::Sort(std::vector<int> v)
    : elements(v)
{}

Sort::~Sort()
{}

void Sort::swap(int a, int b)
{
    auto tmp = a;
    a = b;
    b = tmp;
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
