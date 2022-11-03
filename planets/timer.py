import time


def 時間(func, *args, **kwargs):
    start = time.time()
    func(*args, **kwargs)
    return time.time()-start
