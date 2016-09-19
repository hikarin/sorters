#include "base.h"

class HeapSort : public Sort {
public:
    HeapSort(std::vector<int> v);
    ~HeapSort(){};

    virtual void sort();
    virtual std::string name() const { return std::string("Heap"); }
private:
    void create_heap(int sz);
    void down_heap(int leaf, int root);
};
