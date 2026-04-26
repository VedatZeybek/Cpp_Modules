#ifndef PMergeMe_HPP
# define PMergeMe_HPP

#include "vector"
#include "iostream"
#include "deque"
#include "set"

#define INT_MAX 2147483647

class PMergeMe
{
private:
    std::vector<int>    _vec;
    std::deque<int>     _que;


    struct pair
    {
        int big;
        int small;
    };
    
public:
    PMergeMe();
    PMergeMe(const PMergeMe& other);
    PMergeMe& operator=(const PMergeMe& other);
    ~PMergeMe();

    void parseInput(int argc, char **argv);
    const std::vector<int>& getVector() const;

    std::vector<int> fordJohnson(std::vector<int> v);
};

#endif
