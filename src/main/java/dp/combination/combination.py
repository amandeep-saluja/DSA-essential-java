def fn(n, idx, k, res, temp):
    if k == 0:
        res.append(temp.copy())
        return

    for i in range(idx, n + 1):
        temp.append(i)
        fn(n, i + 1, k - 1, res, temp)
        temp.pop()

fn(4, 1, 3, [], [])

#https://www.recursionvisualizer.com/

# def fn(n, idx, k, res, temp):
#     if k == len(temp):
#         res.append(temp)
#         return
#
#     if idx > n:
#         return
#
#     temp.append(idx)
#     fn(n, idx + 1, k, res, temp)
#     temp.pop()
#
#     fn(n, idx + 1, k, res, temp)
# fn(4, 1, 3, [], [])