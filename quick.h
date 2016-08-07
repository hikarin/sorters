#include "base.h"

class QuickSort : public Sort {
public:
    QuickSort(std::vector<int> v);
    ~QuickSort(){};

    virtual void sort();

 private:
    void sort_sub(int start, int end);
};
