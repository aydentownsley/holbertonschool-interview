#!/usr/bin/python3


def box_recurse(boxes, unlocked, box):
    if len(unlocked) == len(boxes):
        return True
    for key in boxes[box]:
        if key not in unlocked and key < len(boxes):
            unlocked.append(key)
            unlocked.sort()
            if box_recurse(boxes, unlocked, key) is True:
                return True
    return False
        

def canUnlockAll(boxes):
    unlocked = [0]
    box = 0
    return(box_recurse(boxes, unlocked, box))
