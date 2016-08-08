#include <iostream>
#include <chrono>
#include <string.h>
#include "bubble.h"
#include "quick.h"
#include "comb.h"
#include "bitonic.h"

using namespace std::chrono;

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

void measure_one(Sort& sort)
{
    auto start = system_clock::now();
    sort.sort();
    auto end = system_clock::now();
    if ( sort.check() ) {
	auto duration = duration_cast<microseconds>(end-start).count();
	std::cout << sort.to_string() << ": " << duration << std::endl;
    } else {
	// failure
	std::cout << sort.to_string() << ": sort failed" << std::endl;
    }
}

void measure_all(std::vector<int>& v)
{
    //    BubbleSort b(v);
    //    measure_one(b);

    QuickSort q(v);
    measure_one(q);

    CombSort c(v);
    measure_one(c);

    BitonicSort bi(v);
    measure_one(bi);

    std::cout << std::endl;
}

void putstring(std::string str)
{

}

int main(int argc, char** argv)
{
    if ( argc >= 2 ){
	int num = get_number(argv[1]);
	if ( num > 0 ){
	    std::vector<int> v(num);
	    Sort::init(v);

	    measure_all(v);
	}
    } else {
	std::cout << "Usage: ./sorters <elements num>" << std::endl;
    }
}
