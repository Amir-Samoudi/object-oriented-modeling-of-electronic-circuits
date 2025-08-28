import random

# Generate a list of numbers from 0 to 255
numbers = list(range(256))

# Shuffle the list to get them in random order
random.shuffle(numbers)

# Write the numbers in 16-bit binary format to a file, each on a new line
with open('RandomNumbers.txt', 'w') as file:
    for number in numbers:
        # Format the number as a 16-bit binary string
        binary_string = format(number, '016b')
        file.write(f"{binary_string}\n")

print("The numbers have been written to ShuffledBinaryNumbers.txt in shuffled 16-bit binary format.")

