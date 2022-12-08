#ifndef NSU_OOP_BIGINT_H
#define NSU_OOP_BIGINT_H
#include "iostream"
#include <string>
#define ASCII_ZERO 48

class BigInt {
private:
    bool isNeg;
    std::string number;

public:
    BigInt();
    BigInt(int);
    BigInt(std::string);
    BigInt(const BigInt&);
    ~BigInt();

    const std::string getNumber() const;

    BigInt& operator=(const BigInt&);

    BigInt operator~() const;

    BigInt& operator++();
    const BigInt operator++(int);
    BigInt& operator--();
    const BigInt operator--(int);

    BigInt& operator+=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);

    BigInt operator+() const;
    BigInt operator-() const;

    bool operator==(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator>=(const BigInt&) const;

    operator int() const;
    operator std::string() const;

    size_t size() const;
    std::string getNumber();
    static const BigInt* maxBinLen(BigInt *first, const BigInt &second);
    static const BigInt* minBinLen(BigInt *first, const BigInt &second);

};

BigInt operator+(const BigInt&, const BigInt&);
BigInt operator-(const BigInt&, const BigInt&);
BigInt operator*(const BigInt&, const BigInt&);
BigInt operator/(const BigInt&, const BigInt&);
BigInt operator^(const BigInt&, const BigInt&);
BigInt operator%(const BigInt&, const BigInt&);
BigInt operator&(const BigInt&, const BigInt&);
BigInt operator|(const BigInt&, const BigInt&);


void removeLeadingZeroes(std::string&);
BigInt pow(const BigInt &basis, const BigInt &exponent);
std::string fromDecToBin(std::string);
std::string fromBinToDec(std::string);
void binInverse(std::string&);

std::ostream& operator<<(std::ostream& o, const BigInt& i);

#endif //NSU_OOP_BIGINT_H
