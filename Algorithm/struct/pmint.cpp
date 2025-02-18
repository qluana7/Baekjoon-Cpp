/*
Under Construction
*/

#include <iosfwd>

namespace types {

template <typename T>
struct mulmod {
    T operator()(T a, T b, T m) const {
        return a * b % m;
    }
};

template <typename T, T mod, typename _MMFunc = mulmod<T>>
struct pmint {
    explicit pmint(T value = 0) : _M_value(value % mod) { }

private:
    T _M_value;

    constexpr static inline T powmod(T a, T b, T m) {
        T r = 1;

        while (b) {
            if (b & 1) r = _MMFunc{}(r, a, m);
            a = _MMFunc{}(a, a, m);
            b >>= 1;
        }

        return r;
    }

    constexpr static inline T invmod(T a, T m)
    { return powmod(a, m - 2, m); }
    
    void __inv() { _M_value = invmod(_M_value, mod); }

public:
    T value() const { return _M_value; }

    pmint exp(pmint k) const
    { return pmint(powmod(_M_value, k._M_value, mod)); }

    pmint exp(T k) const
    { return pmint(powmod(_M_value, k, mod)); }

    pmint inv() const
    { return invmod(_M_value, mod); }

    pmint& operator=(T k)
    { return this->_M_value = k % mod, *this; }

    pmint& operator=(pmint k)
    { return this->_M_value = k._M_value, *this; }

    pmint& operator+=(pmint k)
    { if ((this->_M_value += k._M_value) >= mod) this->_M_value -= mod; return *this; }

    pmint& operator-=(pmint k)
    { if ((this->_M_value -= k._M_value) >= mod) this->_M_value += mod; return *this; }

    pmint& operator*=(pmint k)
    { return this->_M_value = _MMFunc{}(this->_M_value, k._M_value, mod), *this; }

    pmint& operator/=(pmint k)
    { return this->_M_value = _MMFunc{}(this->_M_value, invmod(k._M_value, mod), mod), *this; }

    pmint operator+(pmint k) const
    { return pmint(*this) += k; }

    pmint operator-(pmint k) const
    { return pmint(*this) -= k; }

    pmint operator*(pmint k) const
    { return pmint(*this) *= k; }

    pmint operator/(pmint k) const
    { return pmint(*this) /= k; }

    pmint& operator++()
    { if (++this->_M_value == mod) this->_M_value = 0; return *this; }

    pmint& operator--()
    { if (this->_M_value-- == 0) this->_M_value = mod - 1; return *this; }

    pmint operator++(int)
    { pmint __tmp(*this); return ++*this, __tmp; }

    pmint operator--(int)
    { pmint __tmp(*this); return --*this, __tmp; }

    bool operator==(pmint k) const
    { return this->_M_value == k._M_value; }

    bool operator!=(pmint k) const
    { return this->_M_value != k._M_value; }

    bool operator<(pmint k) const
    { return this->_M_value < k._M_value; }

    bool operator>(pmint k) const
    { return this->_M_value > k._M_value; }

    bool operator<=(pmint k) const
    { return this->_M_value <= k._M_value; }

    bool operator>=(pmint k) const
    { return this->_M_value >= k._M_value; }

    template<typename _CharT, typename _Traits>
    friend std::basic_istream<_CharT, _Traits>& operator>>(std::basic_istream<_CharT, _Traits>& __is, pmint& __x)
    { T x; __is >> x, __x = x; return __is; }

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, pmint __x)
    { return __os << __x._M_value; }
};

#define u64 unsigned long long
#define i64 long long

struct mulmod_u64x {
    u64 operator()(u64 a, u64 b, u64 m) const {
        i64 r = a * b - m * (u64)(1.L / m * a * b);
        return r + m * (r < 0) - m * (r >= (i64)m);
    }
};

template <u64 mod>
using piu64 = pmint<u64, mod>;

template <u64 mod>
using piu64x = pmint<u64, mod, mulmod_u64x>;

#undef u64
#undef i64

}