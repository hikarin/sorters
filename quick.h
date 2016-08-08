#include "base.h"

class QuickSort : public Sort {
public:
    QuickSort(std::vector<int> v);
    ~QuickSort(){};

    virtual void sort();
    virtual std::string to_string() { return "Quick Sort   "; };
 private:
    void sort_sub(int start, int end);
};
