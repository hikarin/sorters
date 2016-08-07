#include <vector>

class Sort {
 public:
    Sort(std::vector<int> v);
    virtual ~Sort();

    virtual void sort() = 0;

    bool check() const;
 protected:
    static void swap(int a, int b);
    std::vector<int> elements;
};
