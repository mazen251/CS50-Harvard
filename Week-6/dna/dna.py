import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Invalid line-argument input: databases/database_name(small/large).csv sequences/txt_file_number(1-20).txt")
        sys.exit(1)

    # TODO: Read database file into a variable

    database = []
    try:
        with open(f"{sys.argv[1]}") as file:
            reader = csv.DictReader(file)
            for dic in reader:
                database.append(dic)
    except FileNotFoundError:
        print(f"Database {sys.argv[1]} is not found")
        sys.exit(2)

    # TODO: Read DNA sequence file into a variable

    try:
        with open(f"{sys.argv[2]}") as file:
            txt = file.read()
        # characters = list(txt)
    except FileNotFoundError:
        print(f"File {sys.argv[2]} is not found")
        sys.exit(3)

    # print(database) # list of dicionaries
    # print(txt) # string
    # print(characters) # list of the txt string (1 char separated) (useless)
    # print(len(txt)) # length of the string txt (useless)

    # TODO: Find longest match of each STR in DNA sequence

    # OLD LOGIC WITH INITIAL IDEAS :(

    # i = 0
    # unique_lists = {} # dictionary of lists to hold keys: sector sizes (indexed for now) & values: lists of the elements_list (txt seperated in sectors)
    # list_of_strs = list(database[0].keys()) # list of the keys found in the database[0] list of dictionaries
    # list_of_strs.remove("name")
    # #print(f"These are the strs in the csv: {list_of_strs}")
    # for element in list_of_strs:
    #     element_list = [] # list of the txt file which is a string that is seperated in sectors
    #     sector = len(element)
    #     index = 0
    #     while index < len(txt):
    #         #print(txt[index:index + sector], " ", end ="")
    #         element_list.append(txt[index:index + sector])
    #         index += sector
    #     unique_lists[i] = element_list # (each item in the dictionary is a list of a certain sectore size of the txt string) (sector char separated) (the reason behind why it is made a dictionary not a list is to define each key in it to represent the value of the sector so that if a new element has the same sector size as a one came before it, no need to traverse the txt again and seperate it using the same sector size again because it will cause redunduncy in the dictionary as the keys are indexed for now. thus, we can write the keys not as index but as the number of the sector. in this case if we add a new key-value pair where the key (sector size) is already there, we can just let the compiler overwrite the value without causing any redunduncy in the dict or we can check for it before)
    #     i += 1
    #
    # print(unique_lists)
    # print()
    # print(element_list)

    # NEW LOGIC, WITH THE IMPLEMENTED IDEAS  all this work just to be useless :)

    # unique_lists = {}  # Dictionary to hold sector sizes as keys and lists of elements as values
    # list_of_strs = list(database[0].keys())  # List of keys from the first dictionary in the database (ALL THE KEYS ARE THE SAME FOR ALL THE DICTs)
    # list_of_strs.remove("name")  # Remove "name" from the list of keys
    #
    # for element in list_of_strs:
    #     sector = len(element)  # Determine the sector size based on the length of the current element
    #     if sector not in unique_lists:  # Check if the sector size is not already in the dictionary, if False, it will automatically skip this element
    #         element_list = []  # List to hold the elements from the txt string, separated by the sector size
    #         index = 0
    #         while index < len(txt):
    #             element_list.append(txt[index:index + sector])
    #             index += sector
    #         unique_lists[sector] = element_list  # Use sector size as the key in the dictionary
    #     # Now, unique_lists contains only unique sector sizes as keys and their corresponding lists as values
    #
    #
    # for STR in list_of_strs:
    #     counter = 0
    #     key = len(STR)
    #     if key in unique_lists:
    #         for value in unique_lists[key]:
    #             # print(value, " ", end = "")
    #             if STR == value:
    #                 counter += 1
    #     else:
    #         print(f"The key {key} is not found in the Dictionary")
    #     print(counter, " ", end = "")
    #
    #
    # print(unique_lists) # the dict
    # print()
    # print(list_of_strs) # the STR list

    STR_lengths = {}
    for key in database[0].keys():
        if key != 'name':
            STR_lengths[key] = longest_match(txt, key)

    # TODO: Check database for matching profiles

    for person in database:
        match = True
        for key in STR_lengths:
            if int(person[key]) != STR_lengths[key]:
                match = False
                break
        if match:
            print(person['name'])
            return

    print("No match")


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
