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
    if (n <= 0):
        return 0
    curr = 1
    pasteVal = 1
    ops = 1
    if n % 2 == 0:
        num = 1
        while (num < n / 2):
            if (n % num == 0):
                div1 = num
                div2 = n / num
            num += 1
        # print("num1: {}, num2: {}".format(int(div1), int(div2)))
        # while curr != n:
        #     if curr + pasteVal > n:
        #         break
        #     curr = curr + pasteVal
        #     ops += 1
        #     if curr * 2 > n:
        #         break
        #     pasteVal = curr * 2
        #     ops += 2
        return (int(div2) + minOperations(div1))
    elif (n % 3 == 0):
        if n == 3:
            return 3
        return int(n / 3 + 3)
    else:
        return n - 1


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
