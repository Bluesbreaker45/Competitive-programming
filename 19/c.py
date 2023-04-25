def run(startNum, path):
    res = startNum
    while len(path) > 0:
        c = path[0]
        path = path[1:]
        if c == 'H':
            res *= 3
        else:
            res //= 2
    return res