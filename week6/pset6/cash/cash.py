from cs50 import get_float


def main():
    # get input from user
    while True:
        dollars = get_float("changed owed: ")
        if dollars > 0:
            break
    
    # round to nearest int
    cents = round(dollars * 100)
    
    count = 0
    while cents > 0:
        if cents >= 25:
            cents -= 25
        elif cents >= 10:
            cents -= 10
        elif cents >= 5:
            cents -= 5
        elif cents >= 1:
            cents -= 1
        count += 1
    
    print(count)


main()