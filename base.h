#if !defined( __BASE_H__ )
#define __BASE_H__

#include <vector>
#include <string>

class Sort {
 public:
    Sort(std::vector<int> v);
    virtual ~Sort();

    virtual void sort() = 0;
    virtual std::string name() const = 0;

    bool check() const;

    static void init(std::vector<int>& v);
    std::vector<int> get_element() const { return elements; };
 protected:
    static void swap(int& a, int& b);
    std::vector<int> elements;
};
#endif
