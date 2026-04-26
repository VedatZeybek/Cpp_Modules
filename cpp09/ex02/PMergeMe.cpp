#include "PMergeMe.hpp"

#include <algorithm>

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe& other): _vec(other._vec)
{

}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
    if (this != &other)
    {
        this->_vec = other._vec;
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
        _vec.push_back(static_cast<int>(value));
    }
}


const std::vector<int>& PMergeMe::getVector() const
{
	return _vec;
}


std::vector<int> PMergeMe::fordJohnson(std::vector<int> v)
{
    if (v.size() <= 1)
        return v;

    const size_t totalSize = v.size();
    const bool isOdd = (totalSize % 2 != 0);
    const size_t pairCount = totalSize / 2;

    std::vector<pair> pairs;
    pairs.reserve(pairCount);

    for (size_t i = 0; i < pairCount; ++i)
    {
        int first = v[i * 2];
        int second = v[i * 2 + 1];
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

    std::vector<int> mainChain;
    mainChain.reserve(pairCount);
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].big);

    mainChain = fordJohnson(mainChain);

    std::vector<int> pending;
    pending.reserve(pairCount);
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].big == mainChain[i])
            {
                pending.push_back(pairs[j].small);
                break;
            }
        }
    }

    std::vector<int> result = mainChain;
    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pending[i]);
        result.insert(pos, pending[i]);
    }

    if (isOdd)
    {
        int leftover = v[totalSize - 1];
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), leftover);
        result.insert(pos, leftover);
    }

    return result;
}

