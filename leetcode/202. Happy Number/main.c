
#define true 1
#define false 0
typedef int bool;

int bitsum(int num)
{
    int result = 0;
    while (num > 0)
    {
        int rem = num % 10;
        result += rem * rem;
        num /= 10;
    }
    return result;
}

bool isHappy1(int n)
{
    int seen[1000] = {0};

    while (1)
    {
        n = bitsum(n);

        if (n == 1)
        {
            return 1;
        }
        else if (seen[n] == 1)
        {
            return 0;
        }
        else
        {
            seen[n] = 1;
        }
    }
}

bool isHappy2(int n)
{
    int slown = n;
    int fastn = n;

    while (1)
    {
        slown = bitsum(slown);
        fastn = bitsum(bitsum(fastn));
        if (slown == 1)
        {
            return 1;
        }
        else if (slown == fastn)
        {
            return 0;
        }
        else
        {
            // do nothing
        }
    }
}