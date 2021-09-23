#!/usr/bin/python3
"""
Module for determining
wether given data is
a valid representation
of UTF-8 encoding.
"""


def validUTF8(data):
    """
    validate data
    return: true if UTF-8
    false if not
    """
    bytes = 0
    for i in data:
        bin = format(i, '#010b')[-8:]
        if bytes == 0:
            for bit in bin:
                if bit == '0':
                    break
                bytes += 1
            if bytes == 0:
                continue
            if bytes == 1 or bytes > 4:
                return False
        else:
            if not (bin[0] == '1' and bin[1] == '0'):
                return False
        bytes -= 1
    return bytes == 0
