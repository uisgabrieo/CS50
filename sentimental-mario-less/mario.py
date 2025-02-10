from cs50 import get_int


def print_bricks(bricks: int) -> None:
    space = bricks - 1
    for brick in range(1, bricks + 1):
        print(" " * space + "#" * brick)
        space -= 1


if (__name__ == "__main__"):
    while True:
        try:
            height = get_int("Height: ")
            if 9 > height > 0:
                break
        except:
            continue

    print_bricks(height)
