#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def g(n, sz):
    if sz == 0:
        return 'g' if n == 1 else 'a'
    if n <= l[sz-1]:
        return g(n, sz-1)
    if n <= l[sz-1] + sz + 3:
        return 'g' if n-l[sz-1] == 1 else 'a'
    return g(n-l[sz-1]-sz-3, sz-1)


l = [3]
while l[-1] <= 1e9:
    l.append(2*l[-1] + len(l) + 3)
print(g(int(input()), len(l)))
