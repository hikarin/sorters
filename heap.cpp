#include "heap.h"

HeapSort::HeapSort(std::vector<int> v)
    : Sort(v)
{}

void HeapSort::sort()
{
    const int sz = elements.size();
    create_heap(sz);
    int x = sz-1;
    while ( x >= 0 ) {
	swap( elements[0], elements[x] );
	create_heap(x--);
    }
}

void HeapSort::create_heap(int sz)
{
    int scanned = 1;
    while ( scanned < sz ) {
	int x = scanned;
	while ( x > 0 ) {
	    int parent = (x-1)/2;
	    if ( elements[x] > elements[parent] )
		swap(elements[x], elements[parent]);
	    x = parent;
	}
	++scanned;
    }
}
