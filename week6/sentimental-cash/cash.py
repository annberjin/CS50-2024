def main():
    change = get_float("Change: ")
    print(calculate(change))


def get_float(prompt):
    while True:
        try:
            n = float(input(prompt))

            if n < 0:
                raise ValueError
            return n

        except ValueError:
            pass


def calculate(change):
    change *= 100

    quarters = change // 25
    change -= quarters * 25

    dimes = change // 10
    change -= dimes * 10

    nickels = change // 5
    change -= nickels * 5

    pennies = change / 1

    counter = quarters + dimes + nickels + pennies
    return int(counter)


if __name__ == "__main__":
    main()
