#include "comb.h"

CombSort::CombSort(std::vector<int> v)
    : Sort(v)
{}

void CombSort::sort()
{
    const int sz = elements.size();
    int h = sz/2;
    bool changed = false;

    while(h>=1) {
	changed = false;
	for ( int i=0; i<sz; i++ ) {
	    if ( i+h >= sz )
		break;
	    if ( elements[i] > elements[i+h] ) {
		swap( elements[i], elements[i+h] );
		changed = true;
	    }
	}
	if ( h==1 && changed )
	    continue;
	h = h/1.3f;
    }
}
