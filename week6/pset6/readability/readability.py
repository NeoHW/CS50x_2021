from cs50 import get_string


def main():
    # define variables
    letters = 0
    words = 1  # number of words = number of spaces +1
    sentences = 0
    
    # get user input
    text = get_string("Text: ")
    # number of chars (inclusive of words, whitespaces and symbols)
    char = len(text)
    
    for i in range(char):
        if text[i].isalpha():
            letters += 1
        
        if text[i].isspace():
            words += 1
        
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1
        
    # Coleman-Liau index
    index = round(0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8)
    
    # print grade level
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else: 
        print(f"Grade {index}")


main()