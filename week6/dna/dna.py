import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usgae: python dna.py data.csv seqeuence.txt")

    # TODO: Read database file into a variable
    database = []
    try:
        with open(sys.argv[1], "r") as file:
            csvFile = csv.reader(file)
            for row in csvFile:
                database.append(row)

        subsequences = []
        for i in database[0][1:]:
            subsequences.append(i)

    except:
        sys.exit(1)

    try:
        with open(sys.argv[2], "r") as file:
            sequences = file.read()
    except FileNotFoundError:
        sys.exit(1)

    results = []  # results = [4, 1, 5]
    for i in subsequences:
        results.append(longest_match(sequences, i))
    # print("The results are", results)

    for i in range(len(database)-1):
        match = 0
        counter = 1

        for j in results:
            if int(database[i+1][counter]) == j:
                match += 1
                # print(database[i][0], "matched", match)
            # print(database[i+1][counter])
            counter += 1

        if match == len(results):
            print(database[i+1][0])
            sys.exit(0)

    print("No match")

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
