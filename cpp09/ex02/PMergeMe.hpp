#ifndef PMergeMe_HPP
# define PMergeMe_HPP

#include <list>
#include <iostream>
#include <deque>
#include <set>

#define INT_MAX 2147483647

class PMergeMe
{
private:
    std::list<int>      _list;
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
    const std::list<int>& getList() const;

    std::list<int> fordJohnsonList(const std::list<int>& lst);
    std::deque<int> fordJohnsonDeque(const std::deque<int>& dq);
};

#endif
