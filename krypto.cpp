#include "krypto.h"

void gcd(int first, int second, int gcdFS_x_y[])
{
    int q, v[3] = {second, 0, 1}, t[3];
    gcdFS_x_y[0] = first;
    gcdFS_x_y[1] = 1;
    gcdFS_x_y[2] = 0;
    while (v[0] != 0)
    {
        q = gcdFS_x_y[0] / v[0];
        t[0] = gcdFS_x_y[0] % v[0];
        t[1] = gcdFS_x_y[1] - q * v[1];
        t[2] = gcdFS_x_y[2] - q * v[2];
        for (int i = 0; i < 3; i++)
        {
            gcdFS_x_y[i] = v[i];
            v[i] = t[i];
        }
    }
}

int exp_mod(long long a, long long x, long long p)
{
    int x_one_bin, answer = 1;
    while(x > 0)
    {
        x_one_bin = x & 1;
        x = x>>1;
        if(x_one_bin == 1)
        {
            answer = answer * a % p;
        }
        a = a * a % p;
    }
    return answer;
}
bool is_prime_number(long long number)
{
    if (number <= 1) {
        return false;
    }
    int v = 2;
    while (v * v <= number) {
        if (number % v++ == 0) return false;
    };
    return true;
}

