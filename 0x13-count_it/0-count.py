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
    new_list = []
    for i in word_list:
        i.lower()
    for i in word_list:
        if i not in new_list:
            new_list.append(i)
    number = 0
    headers = {'User-Agent': 'parse_hot'}
    url = "http://www.reddit.com/r/{}/hot.json".format(subreddit)
    response = requests.get(url, headers=headers)
    if response.status_code == 404:
        exit()
    data = response.json()
    for value in response.json()['data']['children']:
        for res in value['data'].items():
            if res[0] == 'title':
                if new_list[count] in res[1].lower():
                    tile_arr = res[1].lower().split()
                    for i in tile_arr:
                        if i == new_list[count]:
                            number += 1
    if count + 1 < len(new_list):
        count_words(subreddit, new_list, count + 1)
    print("{}: {}".format(new_list[count], number))
