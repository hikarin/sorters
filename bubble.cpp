#include "bubble.h"

BubbleSort::BubbleSort(std::vector<int> v)
    : Sort(v)
{}

void BubbleSort::sort()
{
    const int sz = elements.size();
    for ( int i=0; i<sz-1; ++i ) {
	bool changed = false;
	for ( int j=sz-1; j>i; --j ) {
	    if ( elements[j] < elements[j-1] ){
		swap(elements[j], elements[j-1]);
		changed = true;
	    }
	}
	if(!changed){
	    break;
	}
    }
}
