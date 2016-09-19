#include "heap.h"

HeapSort::HeapSort(std::vector<int> v)
    : Sort(v)
{}

void HeapSort::sort()
{
    int leaf = elements.size()-1;
    int root = leaf/2;

    while ( root >= 0 ) {
	down_heap(leaf, root);
	root--;
    }

    while ( leaf >= 0 ) {
	swap(elements[0], elements[leaf]);
	leaf--;
	down_heap(leaf, 0);
    }
}

void HeapSort::down_heap(int leaf , int root)
{
    int i = root*2+1;
    while( i <=leaf ){
	if(i<leaf && elements[i+1]>elements[i])
	    i++;
	if(elements[root] >= elements[i])
	    break;
	swap(elements[root], elements[i]);

	root = i;
	i=root*2+1;
    }
}
