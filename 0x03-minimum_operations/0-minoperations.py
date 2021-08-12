#!/usr/bin/python3
""" Minimum ops Module
"""


def minOperations(n):
    """
    Args: n [integer]
    ----
    Finds minumum operations required
    to make n Hs given only Copy All
    and Paste.
    Returns: min ops [int]
    Prime or Odd not div by 3: n - 1
    Even: unknown
    Modulo by 3: n/3 + 3
    """
    if n <= 0:
        return 0
    elif n % 3 == 0:
        if n == 3:
            return 3
        return int(n / 3 + 3)
    elif isPrime(n) is True:
        return n + 1
    else:
        res = 0
        for i in range(2, n):
            while (n % i == 0):
                res += i
                n = n / i
        return res


def isPrime(n):
    """
    Args: n [integer]
    ----
    Tests if number is prime
    Returns: True is prime
             False if not
    """
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    k = 3
    while k*k <= n:
        if n % k == 0:
            return False
        k += 2
    return True
