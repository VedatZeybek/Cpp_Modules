#include "PMergeMe.hpp"
#include <cstdlib>

// list-based implementation

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe& other): _list(other._list), _que(other._que)
{

}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
    if (this != &other)
    {
        this->_list = other._list;
        this->_que = other._que;
    }
    return (*this);
}

PMergeMe::~PMergeMe()
{
}


void PMergeMe::parseInput(int argc, char **argv)
{
    std::set<int> seen;

    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        // 1) boş mu?
        if (arg.empty())
            throw std::runtime_error("Error");

        // 2) tamamen rakamlardan mı oluşuyor?
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]))
                throw std::runtime_error("Error");
        }

        // 3) sayıya çevir
        long value = std::strtol(arg.c_str(), NULL, 10);

        // 4) pozitif mi? (subject için en güvenlisi: sadece > 0)
        if (value <= 0)
            throw std::runtime_error("Error");

        // 5) int sınırında mı?
        if (value > INT_MAX)
            throw std::runtime_error("Error");

        // 6) duplicate var mı?
        if (seen.find(static_cast<int>(value)) != seen.end())
            throw std::runtime_error("Error");

        seen.insert(static_cast<int>(value));
        _list.push_back(static_cast<int>(value));
    }
}


const std::list<int>& PMergeMe::getList() const
{
    return _list;
}
std::list<int> PMergeMe::fordJohnsonList(const std::list<int>& lst)
{
    if (lst.size() <= 1)
        return lst;

    const size_t totalSize = lst.size();
    const bool isOdd = (totalSize % 2 != 0);
    const size_t pairCount = totalSize / 2;

    std::list<pair> pairs;
    pairs.clear();

    // build pairs
    std::list<int>::const_iterator it = lst.begin();
    for (size_t i = 0; i < pairCount; ++i)
    {
        int first = *it; ++it;
        int second = *it; ++it;
        pair p;
        if (first >= second)
        {
            p.big = first;
            p.small = second;
        }
        else
        {
            p.big = second;
            p.small = first;
        }
        pairs.push_back(p);
    }

    // main chain: list of bigs
    std::list<int> mainChain;
    for (std::list<pair>::const_iterator pi = pairs.begin(); pi != pairs.end(); ++pi)
        mainChain.push_back(pi->big);

    mainChain = fordJohnsonList(mainChain);

    // pending: smalls ordered by mainChain
    std::list<int> pending;
    for (std::list<int>::const_iterator mcIt = mainChain.begin(); mcIt != mainChain.end(); ++mcIt)
    {
        for (std::list<pair>::const_iterator pi = pairs.begin(); pi != pairs.end(); ++pi)
        {
            if (pi->big == *mcIt)
            {
                pending.push_back(pi->small);
                break;
            }
        }
    }

    // result starts as mainChain
    std::list<int> result = mainChain;

    // insert pending elements into result in order (linear search)
    for (std::list<int>::const_iterator pIt = pending.begin(); pIt != pending.end(); ++pIt)
    {
        std::list<int>::iterator insertPos = result.begin();
        while (insertPos != result.end() && *insertPos < *pIt)
            ++insertPos;
        result.insert(insertPos, *pIt);
    }

    // handle leftover if odd
    if (isOdd)
    {
        // leftover is last element of lst
        int leftover = lst.back();
        std::list<int>::iterator insertPos = result.begin();
        while (insertPos != result.end() && *insertPos < leftover)
            ++insertPos;
        result.insert(insertPos, leftover);
    }

    return result;
}


std::deque<int> PMergeMe::fordJohnsonDeque(const std::deque<int>& dq)
{
    std::list<int> lst(dq.begin(), dq.end());
    std::list<int> sorted = fordJohnsonList(lst);
    std::deque<int> result;
    for (std::list<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
        result.push_back(*it);
    return result;
}

