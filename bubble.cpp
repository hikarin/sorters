#include "bubble.h"

BubbleSort::BubbleSort(std::vector<int> v)
    : Sort(v)
{}

void BubbleSort::sort()
{
    const int sz = elements.size();
    for ( int i=0; i<sz; ++i ) {
	for ( int j=0; j<i; ++j ) {
	    if ( elements[i] < elements[j] )
		swap(elements[i], elements[j]);
	}
    }
}
