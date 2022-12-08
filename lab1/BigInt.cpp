#include "BigInt.h"
#include <cmath>
#include <algorithm>


/**                             CONSTRUCTORS                             **/

BigInt::BigInt() {
    number = "0";
    isNeg = false;
}

BigInt::BigInt(int val) {
    if (val >= 0) {
        number = std::to_string(val);
        isNeg = false;
    } else {
        number = std::to_string(-val);
        isNeg = true;
    }
}

BigInt::BigInt(std::string val) {
    if (val[0] == '-') {
        isNeg = true;
        val.erase(0, 1);
    } else {
        isNeg = false;
    }
    removeLeadingZeroes(val);
    for (int i = 0; i < val.length(); ++i) {
        if (std::isdigit(val[i])) {
            number.insert(i, 1, val[i]);
        } else {
            throw std::invalid_argument("Not a digit");
        }
    }
}

BigInt::BigInt(const BigInt &val) {
    this->number = val.number;
    this->isNeg = val.isNeg;
}

BigInt::~BigInt() {}



bool isLess(const std::string &s1, const std::string &s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    } else {
        return s1 <= s2;
    }
}


std::string maxBigInt(const std::string &number1, const std::string &number2) {
    if (number1.size() > number2.size()) {
        return number1;
    }
    if (number1.size() == number2.size()) {
        if (number1 > number2) {
            return number1;
        }
        return number2;
    }
    return number2;
}


std::string minBigInt(const std::string &number1, const std::string &number2) {
    if (number1.size() > number2.size()) {
        return number2;
    }
    if (number1.size() == number2.size()) {
        if (number1 > number2) {
            return number2;
        }
        return number1;
    }
    return number1;
}

BigInt &BigInt::operator+=(const BigInt &other) {
    std::string temp1;
    std::string temp2;
    if (this->isNeg == other.isNeg) {
        temp1 = maxBigInt(this->number, other.number);
        temp2 = minBigInt(this->number, other.number);
    } else {
        this->isNeg = !this->isNeg;
        *this -= other;
        this->isNeg = !this->isNeg;
        return *this;
    }
    size_t maxStringSize = std::max(temp1.length(), temp2.length());
    size_t minStringSize = std::min(temp1.length(), temp2.length());
    std::reverse(temp1.begin(), temp1.end());
    std::reverse(temp2.begin(), temp2.end());
    for (size_t i = 0; i < maxStringSize; i++) {
        if (i < minStringSize) {
            if (temp1[i] - ASCII_ZERO + temp2[i] - ASCII_ZERO >= 10) {
                if (isdigit(temp1[i + 1])) {
                    temp1[i + 1] = temp1[i + 1] + 1;
                } else {
                    temp1.push_back('1');
                }
            }
            temp1[i] = (temp1[i] - ASCII_ZERO + temp2[i] - ASCII_ZERO) % 10 + ASCII_ZERO;
        } else {
            if (temp1[i] - ASCII_ZERO == 10) {
                if (isdigit(temp1[i + 1])) {
                    temp1[i + 1] = temp1[i + 1] + 1;
                } else {
                    temp1.insert(i + 1, 1, '1');
                }
            }
            temp1[i] = (temp1[i] - ASCII_ZERO) % 10 + ASCII_ZERO;
        }
    }
    std::reverse(temp1.begin(), temp1.end());
    this->number = temp1;
    return *this;
}


BigInt &BigInt::operator*=(const BigInt &other) {
    bool tempNeg = this->isNeg != other.isNeg;
    std::string temp1 = maxBigInt(this->number, other.number);
    std::string temp2 = minBigInt(this->number, other.number);
    std::string temp3;
    *this = 0;
    std::reverse(temp1.begin(), temp1.end());
    std::reverse(temp2.begin(), temp2.end());
    temp3 = temp1;
    size_t minStringSize = std::min(temp1.size(), temp2.size());
    size_t maxStringSize = std::max(temp1.size(), temp2.size());
    int rem = 0;
    for (size_t i = 0; i < minStringSize; i++) {
        for (size_t j = 0; j < maxStringSize; j++) {
            temp3[j] = ((temp1[j] - ASCII_ZERO) * (temp2[i] - ASCII_ZERO) + rem) % 10 + ASCII_ZERO;
            if ((temp1[j] - ASCII_ZERO) * (temp2[i] - ASCII_ZERO) + rem >= 10) {
                rem = ((temp1[j] - ASCII_ZERO) * (temp2[i] - ASCII_ZERO) + rem) / 10;
            } else {
                rem = 0;
            }
        }
        if (rem != 0) {
            temp3.insert(maxStringSize, 1, rem + ASCII_ZERO);
            rem = 0;
        }
        temp3.insert(0, i, '0');
        std::reverse(temp3.begin(), temp3.end());
        *this += BigInt(temp3);
        this->isNeg = tempNeg;
        temp3 = temp1;
    }
    return *this;
}


BigInt &BigInt::operator-=(const BigInt &other) {
    std::string temp1, temp2;
    if (this->isNeg == other.isNeg) {
        temp1 = maxBigInt(this->number, other.number);
        temp2 = minBigInt(this->number, other.number);
    } else {
        this->isNeg = !this->isNeg;
        *this += other;
        this->isNeg = !this->isNeg;
        return *this;
    }
    size_t maxStringSize = std::max(temp1.length(), temp2.length());
    size_t minStringSize = std::min(temp1.length(), temp2.length());
    std::reverse(temp1.begin(), temp1.end());
    std::reverse(temp2.begin(), temp2.end());
    int t = 0;
    int s;
    for (int i = 0; i < maxStringSize; i++) {
        if (i < minStringSize) {
            s = temp1[i] - temp2[i] + t;
        } else {
            s = temp1[i] + t - ASCII_ZERO;
        }
        if (s < 0) {
            s += 10;
            t = -1;
        } else {
            t = 0;
        }
        temp1[i] = char(ASCII_ZERO + s);
    }
    while (maxStringSize > 1 && temp1[maxStringSize - 1] == ASCII_ZERO) {
        temp1.pop_back();
        maxStringSize--;
    }
    std::reverse(temp1.begin(), temp1.end());
    this->number = temp1;
    if (*this < other) {
        if (!other.isNeg) {
            this->isNeg = true;
        }
    } else {
        if (other.isNeg) {
            this->isNeg = false;
        }
    }
    return *this;
}

BigInt &BigInt::operator/=(const BigInt &other) {
    if (other == BigInt(0)) {
        throw std::invalid_argument("operator/=: division by zero!");
    }
    if (*this == BigInt(0)) {
        return *this;
    }
    if (other == BigInt(1)) {
        return *this;
    }
    this->isNeg = this->isNeg != other.isNeg;
    BigInt otherCopy(other.number);
    std::string temp1;
    std::string res;
    BigInt temp;
    BigInt temp2;
    for (size_t i = 0; i < this->number.size(); i++) {
        temp1 += this->number[i];
        removeLeadingZeroes(temp1);
        if (isLess(otherCopy.number, temp1)) {
            temp = temp1;
            for (BigInt i = 1; i <= BigInt(10); i++) {
                if (otherCopy * i > temp) {
                    res.insert(res.end(), (i - BigInt(1)).number[0]);
                    temp -= ((i - BigInt(1)) * otherCopy);
                    break;
                }
            }
            temp1 = temp.number;
        } else {
            res.insert(res.end(), '0');
        }
    }
    removeLeadingZeroes(res);
    this->number = res;
    return *this;
}

BigInt &BigInt::operator%=(const BigInt &other) {
    if (other == BigInt(0)) {
        throw std::invalid_argument("operator%=: modulo by zero!");
    }
    if (*this == BigInt(0)) {
        return *this;
    }
    if (other == BigInt(1)) {
        return (*this = 0);
    }
    this->isNeg = this->isNeg != other.isNeg;
    BigInt otherCopy(other.number);
    std::string tmp1 = "";
    BigInt tmp;
    BigInt tmp2;
    for (size_t i = 0; i < this->number.size(); i++) {
        tmp1 += this->number[i];
        removeLeadingZeroes(tmp1);
        if (isLess(otherCopy.number, tmp1)) {
            tmp = BigInt(tmp1);
            for (BigInt i = 1; i <= BigInt(10); i++) {
                if (otherCopy * i > tmp) {
                    tmp -= ((i - BigInt(1)) * otherCopy);
                    break;
                }
            }
            tmp1 = tmp.number;
        }
    }
    *this = BigInt(tmp1);
    return *this;
}

BigInt pow(const BigInt &basis, const BigInt &exponent) {
    BigInt res = 1;
    for (BigInt i = 0; i < exponent; i++) {
        res *= basis;
    }
    return res;
}

/**                             BITWISE OPERATORS                             **/

BigInt &BigInt::operator&=(const BigInt &other) {
    const BigInt *bimax = maxBinLen(this, other);
    const BigInt *bimin = minBinLen(this, other);
    std::string maxBin = fromDecToBin(std::string(*bimax));
    std::string minBin = fromDecToBin(std::string(other));
    std::string binResult;
    size_t leadingZeroes = maxBin.length() - minBin.length();
    if (bimin->isNeg) {
        minBin.insert(minBin.begin(), leadingZeroes, '1');
    } else {
        minBin.insert(minBin.begin(), leadingZeroes, '0');
    }
    for (size_t i = 0; i < maxBin.length(); i++) {
        if (maxBin[i] == '1' && minBin[i] == '1') {
            binResult.append("1");
        } else {
            binResult.append("0");
        }
    }
    if (this->isNeg & other.isNeg) {
        binResult.insert(0, 1, '-');
    }
    *this = BigInt(fromBinToDec(binResult));
    return *this;
}

BigInt &BigInt::operator|=(const BigInt &other) {
    const BigInt *bimax = maxBinLen(this, other);
    const BigInt *bimin = minBinLen(this, other);
    std::string maxBin = fromDecToBin(std::string(*bimax));
    std::string minBin = fromDecToBin(std::string(other));
    std::string binResult;
    size_t leadingZeroes = maxBin.length() - minBin.length();
    if (bimin->isNeg) {
        minBin.insert(minBin.begin(), leadingZeroes, '1');
    } else {
        minBin.insert(minBin.begin(), leadingZeroes, '0');
    }
    for (size_t i = 0; i < maxBin.size(); i++) {
        if (maxBin[i] == '0' && minBin[i] == '0') {
            binResult.append("0");
        } else {
            binResult.append("1");
        }
    }
    if (this->isNeg | other.isNeg) {
        binResult.insert(0, 1, '-');
    }
    *this = BigInt(fromBinToDec(binResult));
    return *this;
}


BigInt &BigInt::operator^=(const BigInt &other) {
    const BigInt *bimax = maxBinLen(this, other);
    const BigInt *bimin = minBinLen(this, other);
    std::string maxBin = fromDecToBin(std::string(*bimax));
    std::string minBin = fromDecToBin(std::string(other));
    size_t leadingZeroes = maxBin.length() - minBin.length();
    if (bimin->isNeg) {
        minBin.insert(minBin.begin(), leadingZeroes, '1');
    } else {
        minBin.insert(minBin.begin(), leadingZeroes, '0');
    }
    std::string binResult;
    for (size_t i = 0; i < maxBin.size(); i++) {
        if (maxBin[i] == minBin[i]) {
            binResult.insert(binResult.end(), '0');
        } else {
            binResult.insert(binResult.end(), '1');
        }
    }
    if (this->isNeg ^ other.isNeg) {
        binResult.insert(binResult.begin(), '-');
    }
    *this = BigInt(fromBinToDec(binResult));
    return *this;
}

BigInt BigInt::operator~() const {
    BigInt res(*this);
    res++;
    res.isNeg = !res.isNeg;
    return res;
}


void binInverse(std::string &binNotation) {
    for (size_t i = 0; i < binNotation.size(); i++) {
        if (binNotation[i] == '1') binNotation[i] = '0';
        else binNotation[i] = '1';
    }
}


std::string fromDecToBin(std::string str) {
    BigInt cur(str);
    std::string binNotation;
    if (cur < BigInt(0)) {
        str.erase(str.begin());
        binNotation = fromDecToBin(str);
        for (size_t i = 0; i < binNotation.size(); i++) {
            if (binNotation[i] == '1') {
                binNotation[i] = '0';
            } else if (binNotation[i] == '0') {
                binNotation[i] = '1';
            }
        }
        binNotation.insert(binNotation.begin(), '1');
        binNotation = std::string(BigInt(fromBinToDec(binNotation)) + BigInt(1));
        binNotation = fromDecToBin(binNotation);
        binNotation.erase(binNotation.begin());
    } else {
        while (cur > BigInt(0)) {
            if ((cur % BigInt("2")) > BigInt(2)) {
                std::cout << " / " << cur.getNumber() << " / " << std::endl;
            }
            binNotation.append((cur % BigInt(2)).operator std::string());
            cur /= 2;
        }
        std::reverse(binNotation.begin(), binNotation.end());
    }
    return binNotation;
}

std::string fromBinToDec(std::string str) {
    BigInt decadeNotation;
    if (str[0] == '-') {
        str.erase(0, 1);
        str.insert(0, 1, '1');
        BigInt current(str);
        str = std::string(BigInt(fromBinToDec(str)) - BigInt(1));
        str = fromDecToBin(str);
        str.erase(str.begin());
        binInverse(str);
        decadeNotation = -BigInt(fromBinToDec(str));
    } else {
        for (int i = 0; i < str.size(); i++) {
            decadeNotation += BigInt(str[i] - ASCII_ZERO) * pow(BigInt(2), BigInt(str.size() - i - 1));
        }
    }
    return std::string(decadeNotation);
}

const BigInt *BigInt::maxBinLen(BigInt *first, const BigInt &second) {
    if (fromDecToBin(std::string(*first)).length() > fromDecToBin(std::string(second)).length()) {
        return first;
    }
    if (fromDecToBin(std::string(*first)).length() == fromDecToBin(std::string(second)).length()) {
        return first;
    }
    return &second;
}

const BigInt *BigInt::minBinLen(BigInt *first, const BigInt &second) {
    if (fromDecToBin(std::string(*first)).length() < fromDecToBin(std::string(second)).length()) {
        return first;
    }
    if (fromDecToBin(std::string(*first)).length() == fromDecToBin(std::string(second)).length()) {
        return &second;
    }
    return &second;
}


/**                             UNARY OPERATORS                             **/

BigInt &BigInt::operator=(const BigInt &val) {
    if (this != &val) {
        this->number = val.number;
        this->isNeg = val.isNeg;
    }
    return *this;
}

BigInt &BigInt::operator++() {
    return *this += 1;
}

const BigInt BigInt::operator++(int) {
    BigInt res = *this;
    *this += 1;
    return res;
}

BigInt &BigInt::operator--() {
    return *this -= 1;
}

const BigInt BigInt::operator--(int) {
    BigInt res = *this;
    *this -= 1;
    return res;
}


BigInt BigInt::operator+() const {
    return BigInt(*this);
}

BigInt BigInt::operator-() const {
    BigInt thisCopy(*this);
    thisCopy.isNeg = !(this->isNeg);
    return thisCopy;
}

/**                             COMPARISON OPERATORS                             **/

bool BigInt::operator==(const BigInt &other) const {
    return this->number == other.number && this->isNeg == other.isNeg;
}

bool BigInt::operator!=(const BigInt &other) const {
    return this->number != other.number || this->isNeg != other.isNeg;
}

bool BigInt::operator<(const BigInt &other) const {
    if (this->isNeg == other.isNeg) {
        if (!isNeg) {
            if (this->number.size() != other.number.size()) {
                return this->number.size() < other.number.size();
            } else {
                return this->number < other.number;
            }
        } else {
            if (this->number.size() != other.number.size()) {
                return this->number.size() > other.number.size();
            } else {
                return this->number > other.number;
            }
        }
    } else {
        return this->isNeg;
    }
}

bool BigInt::operator>(const BigInt &other) const {
    return !(*this <= other);
}

bool BigInt::operator<=(const BigInt &other) const {
    if (this->isNeg == other.isNeg) {
        if (!isNeg) {
            if (this->number.size() != other.number.size()) {
                return this->number.size() < other.number.size();
            } else {
                return this->number <= other.number;
            }
        } else {
            if (this->number.size() != other.number.size()) {
                return this->number.size() > other.number.size();
            } else {
                return this->number >= other.number;
            }
        }
    } else {
        return this->isNeg;
    }
}

bool BigInt::operator>=(const BigInt &other) const {
    return !(*this < other);
}

BigInt::operator int() const {
    int number = 0;
    for (size_t i = 0; i < this->number.size(); i++) {
        number += (this->number[i] - '0') * int(pow(10, this->number.size() - i - 1));
    }
    if (this->isNeg) {
        number = -number;
    }
    return number;
}

BigInt::operator std::string() const {
    std::string str;
    if (this->isNeg && this->number != "0") {
        str += "-";
    }
    return str += this->number;
}

size_t BigInt::size() const {
    return this->number.size();
}


std::string BigInt::getNumber() {
    return number;
}


void removeLeadingZeroes(std::string &s) {
    size_t strSize = s.size();
    for (size_t i = 0; i < strSize - 1; i++) {
        if (s[0] != '0') {
            break;
        } else {
            s.erase(s.begin());
        }
    }
}


BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res += b;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res -= b;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res *= b;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res /= b;
}

BigInt operator^(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res ^= b;
}

BigInt operator%(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res %= b;
}

BigInt operator&(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res &= b;
}

BigInt operator|(const BigInt &a, const BigInt &b) {
    BigInt res = a;
    return res |= b;
}

std::ostream &operator<<(std::ostream &o, const BigInt &i) {
    return o << std::string(i);
}


