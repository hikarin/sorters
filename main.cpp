#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>

#include "bubble.h"
#include "quick.h"
#include "comb.h"
#include "bitonic.h"
#include "heap.h"

using namespace std::chrono;

int get_number(char* pchar)
{
    std::string str(pchar);
    int num = 0;
    for ( auto p = str.begin(); p != str.end(); p++ ) {
	if ( *p == ',' || *p == '_' )
	    // delimiter
	    continue;
	if ( !( '0' <= *p && *p <= '9' ) )
	    return 0;
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
    
    std::string name = sort.name();
    std::stringstream name_ss;
    name_ss << std::setw(10) << std::left << name;
    //name_ss << name << std::setw(10);
    if ( sort.check() ) {
	auto duration = duration_cast<milliseconds>(end-start).count();
	std::stringstream time_ss;
	time_ss << std::setw(12) << duration;
	std::cout << name_ss.str() << ": " << time_ss.str() << "[ms]" << std::endl;
    } else {
	// failure
	std::cout << name_ss.str() << ": sort failed" << std::endl;
    }
}

void measure_all(std::vector<int>& v)
{
    QuickSort q(v);
    measure_one(q);

    CombSort c(v);
    measure_one(c);

    BitonicSort bi(v);
    measure_one(bi);

    BubbleSort b(v);
    measure_one(b);
    
    HeapSort h(v);
    measure_one(h);

    std::cout << std::endl;
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
