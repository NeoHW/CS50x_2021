import csv
import sys


def main():
    
    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    
    # Naming of argv
    data = sys.argv[1]
    text = sys.argv[2]
    
    # Read data from databases csv file into memeory
    with open(data) as data_file:
        reader = csv.DictReader(data_file)
        # create a list of people
        people = list(reader)
    
    # print(people) # CHECK DONE
    
    # Read data from sequences text file into memory
    with open(text) as text_file:
        # return contents of text as string
        sequences = text_file.read()
    
    # print(sequences) # CHECK DONE
    
    # Create an empty list to store max counts of STR
    max_count = []
    # loop through fieldnames attribute and store keys in max_count list
    # start from 1 as 0 is names which is not useful
    for i in range(1, len(reader.fieldnames)):
        STR = reader.fieldnames[i]
        # add a new value 0 inside array that can be manipulated later
        max_count.append(0)
        # Compute individuals STR accounts
        for j in range(len(sequences)):
            STR_count = 0
            
            if sequences[j:j+len(STR)] == STR:
                k = 0
                # use k to account for consecutive repeats
                while sequences[(j + k):(j + k + len(STR))] == STR:
                    STR_count += 1
                    k += len(STR)
                # update max_counts 
                # max_count[i - 1] as when i is 1, max count array position is 0
                if STR_count > max_count[i - 1]:
                    max_count[i - 1] = STR_count
    
    # Compare against people dict
    # iterate over everyone in the database
    for i in range(len(people)):
        matches = 0 
        
        # iterate over each STR
        for j in range(1, len(reader.fieldnames)):
            if max_count[j - 1] == int(people[i][reader.fieldnames[j]]):
                matches += 1
            if matches == (len(reader.fieldnames) - 1):
                print(people[i]["name"])
                exit(0)
            
    print("No Match")


main()