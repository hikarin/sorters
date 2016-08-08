#include "bitonic.h"
#include <limits.h>

#include <iostream>

BitonicSort::BitonicSort(std::vector<int> v)
    : Sort(v)
{
    prev_size = v.size();
    int new_size = prev_size;
    while ( ( new_size & ( new_size-1 ) ) != 0  ) {
	elements.push_back(INT_MAX);
	++new_size;
    }
}

void BitonicSort::sort()
{
    const int element_size = elements.size();
    bitonic_sub(true, 0, element_size);
    int sz = element_size;
    while ( sz > prev_size ) {
	elements.pop_back();
	--sz;
    }
}

void BitonicSort::bitonic_sub(bool up, int start, int width)
{
    if ( width <= 1 )
	return;
    const int d = width/2;
    bitonic_sub(true, start, d);
    bitonic_sub(false, start+d, d);
    bitonic_merge(up, start, width);
}

void BitonicSort::bitonic_merge(bool up, int start, int width)
{
    if ( width <= 1 )
	return;
    const int d = width/2;
    const int middle = start+d;
    for ( int i=start; i<middle; ++i )
	bitonic_compare(up, i, i+d);
    bitonic_merge(up, start, d);
    bitonic_merge(up, middle, d);
}

void BitonicSort::bitonic_compare(bool up, int i, int j)
{
    if ( up == ( elements[i] > elements[j] ) )
	 swap(elements[i], elements[j]);
}
