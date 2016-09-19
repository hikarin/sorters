#include "base.h"

class CombSort : public Sort {
public:
    CombSort(std::vector<int> v);
    ~CombSort(){};

    virtual void sort();
    virtual std::string name() const { return "Comb"; }
private:
};
