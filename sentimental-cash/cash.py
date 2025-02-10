from cs50 import get_float


def change_cash(cash: float) -> int:
    cash_ = cash * 100
    coins = [25, 10, 5, 1]
    count = 0
    for i in coins:
        count += (cash_//i)
        cash_ %= i
    return int(count)


if (__name__ == "__main__"):

    while True:
        cash = get_float("Change: ")
        if (cash > 0):
            break

    print(change_cash(cash))
