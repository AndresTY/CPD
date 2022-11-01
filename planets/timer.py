import time


def timer(func, *args, **kwargs):
    start = time.time()
    func(*args, **kwargs)
    return time.time()-start
