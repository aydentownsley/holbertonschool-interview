#!/usr/bin/python3
"""
Log Parsing Script
------------------
This script takes input from
stdout and parses the strings
for the desired data.
It keeps a running total
of size and API status codes
"""
import random
import sys
from time import sleep
import datetime
import re
import signal


ip = "^(?:[0-9]{1,3}\.){3}[0-9]{1,3}"
date = " - \[\d{4}-\d{2}-\d{2} |d{2}:\d{2}:\d{2}\.\d{6}\]"
api = " \"GET /projects/260 HTTP/1.1\""
err_size = " [2345]0[01345] \d*$"
pattern = ip + date + api + err_size
status_code = {"200": 0, "301": 0, "400": 0,
               "401": 0, "403": 0, "404": 0,
               "405": 0, "500": 0}
line_count = 0
size = 0

try:
    for line in sys.stdin:
        if re.match(pattern, line):
            x = line.split()
            size += int(x[8])
            if x[7] in status_code:
                status_code[x[7]] += 1
            line_count += 1
        else:
            line_count += 1
        if line_count % 10 == 0:
                print("File size: {:d}".format(size))
                for key, value in status_code.items():
                    print("{}: {}".format(key, value))
except KeyboardInterrupt:
    print("File size: {:d}".format(size))
    for key, value in status_code.items():
        print("{}: {}".format(key, value))
