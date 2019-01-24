from sys import stdin as kb

kb.readline()
st, qr = set(map(int, kb.readline().split())), list(
    map(int, kb.readline().split()))
for q in qr:
    for x in st:
        if q-x in st:
            print('YES')
            break
    else:
        print('NO')
