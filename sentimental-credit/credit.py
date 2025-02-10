import re
from cs50 import get_string


def validator_input(input: str) -> bool:
    validator = r"^\d+$"
    if (re.match(validator, input)):
        return True
    return False


def sum_total(number_card: str) -> int:
    change = False
    sum_total = 0
    for num in number_card[::-1]:
        num = int(num)
        if (change):
            num *= 2
            num = (num//10) + (num % 10)
        sum_total += num
        change = not change
    return sum_total


def select_card(number_card: str) -> None:
    size = len(number_card)
    first_digits = int(number_card[0:2])

    if ((size == 15) and (first_digits == 34 or first_digits == 37)):
        print("AMEX")
    elif ((size == 16 or size == 13) and (first_digits // 10) == 4):
        print("VISA")
    elif ((size == 16) and 55 >= first_digits >= 51):
        print("MASTERCARD")
    else:
        print("INVALID")


if (__name__ == "__main__"):
    while True:
        number = get_string("Number: ")
        if (validator_input(number)):
            break

    if (sum_total(number) % 10 == 0):
        select_card(number)
    else:
        print("INVALID")
