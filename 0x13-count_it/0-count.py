#!/usr/bin/python3
import requests
import sys
""" Query reddit api for hot articles from
    a given subreddit and count given keywords
"""

def count_words(subreddit, word_list, count=0):
	number = 0
	headers = {'User-Agent': 'parse_hot'}
	url = "http://www.reddit.com/r/{}/hot.json".format(sys.argv[1])
	response = requests.get(url, headers=headers)
	data = response.json()
	for value in response.json()['data']['children']:
		for res in value['data'].items():
			if res[0].lower() == 'title':
				if word_list[count] in res[1]:
					number += 1
	if count + 1 < len(word_list):
		count_words(subreddit, word_list, count + 1)
	print("{}: {}".format(word_list[count], number))

