#include "quick.h"

QuickSort::QuickSort(std::vector<int> v)
    : Sort(v)
{

}

void QuickSort::sort()
{
    sort_sub(0, elements.size()-1);
}

void QuickSort::sort_sub(int start, int end)
{
    if ( start >= end )
	return;
    int piv_pos = end;
    int pivot = elements[piv_pos];
    int smaller = start;
    int greater = end;

    while(true) {
	while( elements[smaller] <= pivot && smaller < end )
	    smaller++;
	while( elements[greater] > pivot && greater > start )
	    greater--;
	if ( greater > smaller ) {
	    if ( elements[greater] < elements[smaller] ) {
		swap(elements[greater], elements[smaller]);
	    } else {
		smaller++;
		greater--;
	    }
	} else {
	    if ( elements[greater] > elements[piv_pos] )
		swap(elements[greater], elements[piv_pos]);
	    break;
	}
    }
    sort_sub(start, smaller-1);
    sort_sub(greater+1, end);
}
