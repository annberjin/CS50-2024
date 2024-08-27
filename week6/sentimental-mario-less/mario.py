def main():
    height = get_int("Height: ")
    print_pyramid(height)


def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))

            if not 1 <= n <= 8:
                raise ValueError
            return n
        except ValueError:
            pass


def print_pyramid(height):
    for i in range(height):
        print((" " * (height-i-1)) + ("#"*(i+1)))

        """
        The print function for mario-more
        print((" " * (height-i-1)) + ("#"*(i+1)) + "  " + ("#"*(i+1)))
    
        """
        

if __name__ == "__main__":
    main()
