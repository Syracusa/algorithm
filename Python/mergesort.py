# https://github.com/TheAlgorithms/Python/blob/master/sorts/merge_sort.py
def merge_sort(l: list) -> list:
    def merge(ll: list, rl: list):
        def merge_generator():
            while ll and rl:
                yield (ll if ll[0] <= rl[0] else rl).pop(0)
            yield from ll
            yield from rl
        return list(merge_generator())
    if len(l) < 2:
        return l
    mid = len(l) // 2
    return merge(merge_sort(l[:mid]), merge_sort(l[mid:]))

print(*merge_sort([5, 7, 1, 3, 2, 8, 5, 2, 1, 4, 3]), sep=",")
