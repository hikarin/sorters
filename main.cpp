#include <iostream>
#include "bubble.h"
#include "quick.h"

int get_number(char* pchar)
{
    std::string str(pchar);
    int num = 0;
    for ( auto p = str.begin(); p != str.end(); p++ ) {
	num *= 10;
	num += (*p - '0');
    }

    return num;
}

int main(int argc, char** argv)
{
    if ( argc >= 2 ){
	int num = get_number(argv[1]);
	if ( num > 0 ){
	    std::vector<int> v(num);
	    Sort::init(v);

	    BubbleSort b(v);
	    b.sort();

	    QuickSort q(v);
	    q.sort();
	}
    } else {
	std::cout << "Usage: ./sorters <elements num>" << std::endl;
    }
}
