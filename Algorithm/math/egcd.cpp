/*
Under-construction...
*/

#include <tuple>
#include <utility>

#define i64 long long

using namespace std;

tuple<i64, i64, i64> egcd(i64 a, i64 b) {
    pair<i64, i64>
        r { a, b },
        z { 1, 0 },
        t { 0, 1 };
    
    auto& [r0, r1] = r;
    auto& [z0, z1] = z;
    auto& [t0, t1] = t;

    while (r1 > 0) {
        i64 q = r0 / r1;
        r = { r1, r0 - q * r1 };
        z = { z1, z0 - q * z1 };
        t = { t1, t0 - q * t1 };
    }

    return { r0, z0, t0 };
}