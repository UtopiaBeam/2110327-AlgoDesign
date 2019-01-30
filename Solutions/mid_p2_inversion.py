#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def mrg(l, r):
    tmp = []
    i, j = 0, 0
    ans = 0
    while i < len(l) and j < len(r):
        if l[i] <= r[j]:
            tmp.append(l[i])
            i += 1
        else:
            tmp.append(r[j])
            j += 1
            ans += len(l) - i
    tmp.extend(l[i:])
    tmp.extend(r[j:])
    return tmp, ans


def msort(ls):
    if len(ls) == 1:
        return ls, 0
    m = len(ls) // 2
    l, ansl = msort(ls[:m])
    r, ansr = msort(ls[m:])
    res, ans = mrg(l, r)
    return res, ans + ansl + ansr


_, ls = input(), list(map(int, input().split()))
print(msort(ls)[1])
