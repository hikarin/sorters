#include "base.h"

class BubbleSort : public Sort {
 public:
    BubbleSort(std::vector<int> v);
    ~BubbleSort(){};
    virtual void sort();
    virtual std::string to_string() { return "Bubble Sort  "; };
};
