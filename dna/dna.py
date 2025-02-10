import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("Missing command-line argument")

    # TODO: Read database file into a variable
    database = []
    database_name_file = sys.argv[1]
    with open(database_name_file, "r") as file:
        buffer = csv.DictReader(file)
        for row in buffer:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    sequence_name_file = sys.argv[2]
    with open(sequence_name_file, "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    people = []
    for row in database:
        person = {}
        for str_person in row.keys():
            if (str_person == "name"):
                person[str_person] = row[str_person]
                continue
            person[str_person] = longest_match(sequence, str_person) == int(row[str_person])
        people.append(person)

    # TODO: Check database for matching profiles
    for person in people:
        if (not False in person.values()):
            print(person["name"])
            break
    else:
        print("No match")
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
