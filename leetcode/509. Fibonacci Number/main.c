

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int p = 0, q = 0, r = 1;
    for (int i = 1; i < n; i++)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}