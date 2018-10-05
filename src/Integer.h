#ifndef INTEGER_H
#define INTEGER_H

#include <iostream> // ostream, istream

/**
 * Integer: 
 *     class representing arbitrarily large integers
 * public methods: 
 *     constructors: empty, objects, strings, numerical primitives
 *     arithmetic: +, -, *, /, %
 *     comparison: <, <=, >, >=, ==, !=
 *     bitwise: &, |, ^, ~, <<, >>
 *     assignment: =, ++, --, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
 *     input/output: >>, <<
 */
class Integer {
    public:
        // constructors: empty, objects, strings, numerical primitives
        Integer();
        Integer(Integer &);
        Integer(const char *);
        Integer(const char &);
        Integer(long long int &);
        Integer(long double &);

        // arithmetic: +, -, *, /, %
        Integer operator+(const Integer &) const;
        Integer operator-(const Integer &) const;
        Integer operator*(const Integer &) const;
        Integer operator/(const Integer &) const;
        Integer operator%(const Integer &) const;

        // comparison: <, <=, >, >=, ==, !=
        bool operator<(const Integer &) const;
        bool operator<=(const Integer &) const;
        bool operator>(const Integer &) const;
        bool operator>=(const Integer &) const;
        bool operator==(const Integer &) const;
        bool operator!=(const Integer &) const;

        // bitwise: &, |, ^, ~, <<, >>
        Integer operator&(const Integer &) const;
        Integer operator|(const Integer &) const;
        Integer operator^(const Integer &) const;
        Integer operator~(const Integer &) const;
        Integer operator<<(const Integer &) const;
        Integer operator>>(const Integer &) const;

        // assignment: =, ++, --, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
        Integer & operator=(const Integer &);
        Integer & operator++(const Integer &);
        Integer & operator--(const Integer &);
        Integer & operator+=(const Integer &);
        Integer & operator*=(const Integer &);
        Integer & operator/=(const Integer &);
        Integer & operator%=(const Integer &);
        Integer & operator&=(const Integer &);
        Integer & operator|=(const Integer &);
        Integer & operator^=(const Integer &);
        Integer & operator<<=(const Integer &);
        Integer & operator>>=(const Integer &);

        // input/output: >>, <<
        friend std::ostream & operator<<(std::ostream &, const Integer &);
        friend std::istream & operator>>(std::istream &, const Integer &);

    private:
        List<int> i; // hold all the bits as a linked list of ints
};

#endif
