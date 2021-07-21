#!/usr/bin/python3
"""
LockBox Module
-------
This module houses the defs for
recursing through the boxes
"""
from collections import OrderedDict


def box_recurse(boxes, unlocked, box):
    """
    boxes: list of lockboxes
    unlocked: list of keys
    box: current box
    """
    if len(unlocked) == len(boxes):
        return True
    for key in boxes[box]:
        if len(list(OrderedDict.fromkeys(boxes[box]))) == len(boxes):
            return True
        if key not in unlocked and key < len(boxes):
            unlocked.append(key)
            unlocked.sort()
            if box_recurse(boxes, unlocked, key) is True:
                return True
    return False


def canUnlockAll(boxes):
    """
    creates empty list and starts
    recursion at 0
    """
    unlocked = [0]
    box = 0
    return(box_recurse(boxes, unlocked, box))
