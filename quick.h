#include "base.h"

class QuickSort : public Sort {
public:
    QuickSort(std::vector<int> v);
    ~QuickSort(){};

    virtual void sort();
    virtual std::string name() const { return "Quick"; }
 private:
    void sort_sub(int start, int end);
};
