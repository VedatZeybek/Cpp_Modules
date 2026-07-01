#include "PmergeMe.hpp"
#include <cstdlib>
#include <vector>
#include <cerrno>

// ===================== Internal Ford-Johnson Helpers =====================

namespace
{
    struct FJItem
    {
        int value;
        size_t id;
    };

    struct FJPair
    {
        FJItem small;
        FJItem big;
    };

    std::vector<size_t> buildJacobsthalOrder(size_t n)
    {
        std::vector<size_t> order;

        if (n == 0)
            return order;

        order.push_back(1);

        size_t prev = 1;
        size_t jacob = 3;

        while (prev < n)
        {
            size_t upper = jacob;
            if (upper > n)
                upper = n;

            for (size_t i = upper; i > prev; --i)
                order.push_back(i);

            size_t next = jacob + 2 * prev;
            prev = jacob;
            jacob = next;
        }

        return order;
    }

    template <typename Container>
    typename Container::iterator findById(Container& c, size_t id)
    {
        typename Container::iterator it = c.begin();

        while (it != c.end())
        {
            if (it->id == id)
                return it;
            ++it;
        }
        return c.end();
    }

    template <typename Container>
    void boundedInsert(Container& result, const FJItem& item, size_t partnerBigId)
    {
        typename Container::iterator bound = findById(result, partnerBigId);
        typename Container::iterator pos = result.begin();

        while (pos != bound && pos->value < item.value)
            ++pos;

        result.insert(pos, item);
    }

    template <typename Container>
    void fullInsert(Container& result, const FJItem& item)
    {
        typename Container::iterator pos = result.begin();

        while (pos != result.end() && pos->value < item.value)
            ++pos;

        result.insert(pos, item);
    }

    template <typename Container>
    Container fordJohnsonItems(const Container& input)
    {
        if (input.size() <= 1)
            return input;

        const size_t totalSize = input.size();
        const bool hasOdd = (totalSize % 2 != 0);
        const size_t pairCount = totalSize / 2;

        std::vector<FJPair> pairs;
        pairs.reserve(pairCount);

        typename Container::const_iterator it = input.begin();

        for (size_t i = 0; i < pairCount; ++i)
        {
            FJItem first = *it;
            ++it;
            FJItem second = *it;
            ++it;

            FJPair p;

            if (first.value >= second.value)
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

        FJItem leftover;
        if (hasOdd)
            leftover = input.back();

        Container mainChain;

        for (size_t i = 0; i < pairs.size(); ++i)
            mainChain.push_back(pairs[i].big);

        mainChain = fordJohnsonItems(mainChain);

        std::vector<FJPair> pending;
        pending.reserve(pairs.size());

        for (typename Container::const_iterator mcIt = mainChain.begin();
             mcIt != mainChain.end(); ++mcIt)
        {
            for (size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs[i].big.id == mcIt->id)
                {
                    pending.push_back(pairs[i]);
                    break;
                }
            }
        }

        Container result = mainChain;

        std::vector<size_t> order = buildJacobsthalOrder(pending.size());

        for (size_t i = 0; i < order.size(); ++i)
        {
            size_t index = order[i] - 1;

            if (index < pending.size())
                boundedInsert(result, pending[index].small, pending[index].big.id);
        }

        if (hasOdd)
            fullInsert(result, leftover);

        return result;
    }
}

// ===================== Orthodox Canonical Form =====================

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe& other)
    : _list(other._list), _que(other._que)
{
}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
    if (this != &other)
    {
        this->_list = other._list;
        this->_que = other._que;
    }
    return *this;
}

PMergeMe::~PMergeMe()
{
}

// ===================== Input Parsing =====================

void PMergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg.empty())
            throw std::runtime_error("Error");

        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error");
        }

        errno = 0;
        long value = std::strtol(arg.c_str(), NULL, 10);

        if (errno == ERANGE)
            throw std::runtime_error("Error");

        if (value <= 0)
            throw std::runtime_error("Error");

        if (value > INT_MAX)
            throw std::runtime_error("Error");

        _list.push_back(static_cast<int>(value));
        _que.push_back(static_cast<int>(value));
    }
}

// ===================== Getters =====================

const std::list<int>& PMergeMe::getList() const
{
    return _list;
}

const std::deque<int>& PMergeMe::getDeque() const
{
    return _que;
}

// ===================== Ford-Johnson for list =====================

std::list<int> PMergeMe::fordJohnsonList(const std::list<int>& lst)
{
    std::list<FJItem> items;
    size_t id = 0;

    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        FJItem item;
        item.value = *it;
        item.id = id++;
        items.push_back(item);
    }

    std::list<FJItem> sortedItems = fordJohnsonItems(items);

    std::list<int> result;

    for (std::list<FJItem>::const_iterator it = sortedItems.begin();
         it != sortedItems.end(); ++it)
    {
        result.push_back(it->value);
    }

    return result;
}

// ===================== Ford-Johnson for deque =====================

std::deque<int> PMergeMe::fordJohnsonDeque(const std::deque<int>& dq)
{
    std::deque<FJItem> items;
    size_t id = 0;

    for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
    {
        FJItem item;
        item.value = *it;
        item.id = id++;
        items.push_back(item);
    }

    std::deque<FJItem> sortedItems = fordJohnsonItems(items);

    std::deque<int> result;

    for (std::deque<FJItem>::const_iterator it = sortedItems.begin();
         it != sortedItems.end(); ++it)
    {
        result.push_back(it->value);
    }

    return result;
}

