#include "base.h"

class BitonicSort : public Sort {
public:
    BitonicSort(std::vector<int> v);
    ~BitonicSort(){};

    virtual void sort();
    virtual std::string name() const { return std::string("Bitonic"); }
private:
    void bitonic_sub(bool up, int start, int width);
    void bitonic_merge(bool up, int start, int width);
    void bitonic_compare(bool up, int i, int j);
};
