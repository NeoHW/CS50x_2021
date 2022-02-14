from cs50 import get_int


def main():
    # get height from user
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    
    # i starts from 0 , range(height) does not include value of height
    for i in range(height):
        print(" " * (height - (i + 1)) + "#" * (i + 1) + " " * 2 + "#" * (i + 1))


main()