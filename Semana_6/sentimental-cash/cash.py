from cs50 import get_float

def main():
    while True:
        owed = get_float("Owed: ")
        if owed >= 0:
            break

    cents = round(owed * 100)

    coins = 0
    denominations = [25, 10, 5, 1]

    for coin in denominations:
        coins += cents // coin
        cents %= coin

    print(coins)


if __name__ == "__main__":
    main()
