
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "sequence1.h"

using namespace std;

namespace coen79_lab3
{
    //////////// MEMBER FUNCTIONS ////////////
    sequence::sequence()
    {
        current_index = 0;
        used = 0;
    }
    void sequence::start()
    {
        current_index = 0;
    }
    void sequence::end()
    {
        current_index = used - 1;
    }
    void sequence::advance()
    {
        if (is_item() && size() != CAPACITY && current_index + 1 <= size())
            current_index++;
    }
    void sequence::retreat()
    {
        if (current_index != 0)
            current_index--;
    }
    void sequence::insert(const value_type &entry)
    { // insert before current_index
        if (size() < CAPACITY)
        {
            if (size() == 0)
            { // first entry in empty sequence
                data[current_index] = entry;
            }
            else
            { // add entry to first of non-empty sequence
                for (int i = size(); i >= current_index; i--)
                {
                    data[i] = data[i - 1];
                }
                data[current_index] = entry;
            }
            used++;
        }
    }
    void sequence::insert_front(const value_type &entry)
    { // how is this different from insert???
        if (size() < CAPACITY)
        {
            if (size() == 0)
            { // first entry in empty sequence
                data[current_index] = entry;
            }
            else
            { // add entry to first of non-empty sequence
                for (int i = size(); i >= current_index; i--)
                {
                    data[i] = data[i - 1];
                }
                data[current_index] = entry;
            }
            used++;
        }
    }
    void sequence::attach(const value_type &entry)
    {
        if (size() < CAPACITY)
        {
            if (size() == 0)
            { // first entry in empty sequence
                data[current_index] = entry;
            }
            else
            { // add entry to first of non-empty sequence
                for (int i = size(); i >= current_index; i--)
                {
                    data[i] = data[i + 1];
                }
                // current_index++;
                data[current_index] = entry;
            }
            used++;
        }
    }
    void sequence::attach_back(const value_type &entry)
    {
        if (size() < CAPACITY)
        {
            data[size() - 1] = entry;
            current_index = size() - 1;
            used++;
        }
    }
    void sequence::remove_current()
    {
        if (is_item())
        {
            for (int i = current_index; i < size() - 1; i++) // shift arr left over current index
            {
                data[i] = data[i + 1];
            }
            data[current_index];
            used--;
        }
    }
    void sequence::remove_front()
    {
        current_index = 0;
        remove_current();
        // used--; --> already in remove_current() function
    }
    //////////// CONSTANT MEMBER FUNCTIONS ////////////
    sequence::size_type sequence::size() const
    {
        return used; // used-1 ???
    }
    bool sequence::is_item() const
    {
        if (current_index < used) // or used !=0
            return true;
        else
            return false;
    }
    sequence::value_type sequence::current() const
    {
        if (is_item())
            return data[current_index];
        // else no return? b/c no current item
    }
    sequence::value_type sequence::operator[](int index) const
    {
        if (index < used && index > 0)
        {
            return data[index];
        }
    }
    double sequence::mean() const
    {
        double mean = 0;
        for (int i = 0; i < size(); i++)
        {
            mean += data[i];
        }
        mean /= size();
        return mean;
    }
    double sequence::standardDeviation() const
    {
        double standardDeviation = 0;
        double mean = this->mean();
        for (int i = 0; i < 10; ++i)
        {
            standardDeviation += pow(data[i] - mean, 2);
        }

        return standardDeviation;
    }
    //////////// FRIEND FUNCTIONS ////////////
    // NON-MEMBER functions for the statistician class:
    sequence operator+(const sequence &lhs, const sequence &rhs)
    {
        sequence womboCombo;
        // sum of used for both sequences cant be more than CAPACITY=30??
        if (lhs.size() + rhs.size() < 30)
        {
            // insert lhs first
            for (int i = 0; i < lhs.size(); i++)
            {
                womboCombo.insert(lhs[i]);
            }
            // attach rhs after lhs
            for (int i = 0; i < rhs.size(); i++)
            {
                womboCombo.attach(rhs[i]);
            }
        }
        else
        {
            // error ??
        }
    }
    sequence operator+=(sequence &lhs, sequence &rhs)
    {
        // attach rhs to lhs
        for (int i = 0; i < rhs.size(); i++)
        {
            // attach should check to see if add rhs member goes over CAPACITY
            lhs.attach(rhs[i]);
        }

        return lhs;
    }
    sequence::value_type summation(const sequence &s)
    {
        double sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum += s[i];
        }
        return sum;
    }

}