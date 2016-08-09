#include "bitonic.h"
#include <limits.h>

#include <iostream>

BitonicSort::BitonicSort(std::vector<int> v)
    : Sort(v)
{}

void BitonicSort::sort()
{
    // adjust vector size
    const size_t prev_size = elements.size();
    int new_size = prev_size;
    while ( ( new_size & ( new_size-1 ) ) != 0  ) {
	elements.push_back(INT_MAX);
	++new_size;
    }

    bitonic_sub(true, 0, new_size);
    while ( new_size > prev_size ) {
	elements.pop_back();
	--new_size;
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
