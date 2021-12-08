#!/usr/bin/python3
""" Query reddit api for hot articles from
    a given subreddit and count given keywords
"""
import requests
import sys


def count_words(subreddit, word_list, count=0):
    """gets count of words in hot list of subreddit

    Args:
        subreddit ([type]): [description]
        word_list ([type]): [description]
        count (int, optional): [description]. Defaults to 0.
    """
    number = 0
    headers = {'User-Agent': 'parse_hot'}
    url = "http://www.reddit.com/r/{}/hot.json".format(sys.argv[1])
    response = requests.get(url, headers=headers)
    data = response.json()
    for value in response.json()['data']['children']:
        for res in value['data'].items():
            if res[0] == 'title':
                if word_list[count] in res[1].lower():
                    number += 1
    if count + 1 < len(word_list):
        count_words(subreddit, word_list, count + 1)
    print("{}: {}".format(word_list[count], number))
