# \r的拓展应用

import time

class ProgressBar:
    def __init__(self):
        self.whole_percent = 100  # in progress, the whole percent is 100%

    def progress(self, total, name="Progress"):
        step = total / self.whole_percent
        for i in range(total + 1):
            num = round(step * self.whole_percent)  # each second the increase number of # sign
            num_hashtag = num * i
            rest = self.whole_percent - 1 - num_hashtag
            time.sleep(1)
            print(f"\r{name} :|{'#' * num_hashtag}{' ' * rest} |{round(step * i * 100, 3)}/{self.whole_percent}.0", end="")


if __name__ == '__main__':
    main = ProgressBar()
    time_ = 10
    main.progress(total=10)
