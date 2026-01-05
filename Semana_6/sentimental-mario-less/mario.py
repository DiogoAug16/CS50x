def print_row(spaces, bricks):
    print(" " * spaces + "#" * bricks)

def ask_height():
    while True:
        try:
            height = int(input("Enter the height of the pyramid (1-8): "))
            if 1 <= height <= 8:
                return height
            else:
                print("Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter an integer between 1 and 8.")

def main():
    height = ask_height()
    for i in range(1, height + 1):
        print_row(height - i, i)

if __name__ == "__main__":
    main()
