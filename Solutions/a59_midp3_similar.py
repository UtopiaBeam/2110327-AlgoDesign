#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def f(a, b):
    if a == b:
        return True
    if len(a) == 1 and len(b) == 1:
        return a == b
    al, ar = a[:len(a)//2], a[len(a)//2:]
    bl, br = b[:len(b)//2], b[len(b)//2:]
    return (f(al, bl) and f(ar, br)) or (f(al, br) and f(ar, bl))


a, b = input().strip(), input().strip()
print('YES' if f(a, b) else 'NO')
