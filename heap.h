#include "base.h"

class HeapSort : public Sort {
public:
    HeapSort(std::vector<int> v);
    ~HeapSort(){};

    virtual void sort();
    virtual std::string to_string() { return "Heap Sort    "; };
private:
    void create_heap(int sz);
};
