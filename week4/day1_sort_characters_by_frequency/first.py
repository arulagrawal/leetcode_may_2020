from collections import Counter
from functools import cmp_to_key


class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)

        def func(x, y):
            if c[y] > c[x]:
                return 1
            elif c[y] == c[x]:
                return 1 if y > x else -1
            else:
                return -1

        return "".join(sorted(s, key=cmp_to_key(func)))


