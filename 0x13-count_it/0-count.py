#!/usr/bin/python3
""" Query reddit api for hot articles from
    a given subreddit and count given keywords
"""
import requests
import operator


def count_words(subreddit, word_list, counts={}, after=None):
    """gets count of words in hot list of subreddit

    Args:
        subreddit ([type]): [description]
        word_list ([type]): [description]
        count (int, optional): [description]. Defaults to 0.
    """
    if after:
        url = "https://api.reddit.com/r/{}/hot?after={}".format(
            subreddit, after)
    else:
        url = "http://api.reddit.com/r/{}/hot".format(subreddit)

    headers = {'User-Agent': 'parse_hot'}
    response = requests.get(url, headers=headers)

    try:
        data = response.json()
    except:
        return None

    if 'data' not in data:
        return None

    for result in data['data']['children']:
        for word in result['data']['title'].split():
            for find in word_list:
                if find.lower() == word.lower():
                    if find.lower() in counts.keys():
                        counts[find.lower()] += 1
                    else:
                        counts[find.lower()] = 1

    after = data['data']['after']

    if after:
        return (count_words(subreddit, word_list, counts, after))

    for key in sorted(counts.items(), key=operator.itemgetter(1),
                      reverse=True):
        print("{}: {}".format(key[0], key[1]))
