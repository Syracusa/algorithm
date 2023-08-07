def quicksort(l: list):
    if len(l) < 2:
        return l
    pivot_idx = len(l) - 1
    less_idx = 0
    for i in range(0, len(l) - 1):
        if l[i] < l[pivot_idx]:
            l[less_idx], l[i] = l[i], l[less_idx]
            less_idx += 1
    l[less_idx], l[pivot_idx] = l[pivot_idx], l[less_idx]
    return [*quicksort(l[:less_idx]), l[less_idx], *quicksort(l[less_idx + 1:])]

print(*quicksort([5, 7, 1, 3, 2, 8, 5, 2, 1, 4, 3]), sep=",")