# Specify the path to your file
file_path = 'try.txt'

# Read data from the file
with open(file_path, 'r') as file:
    data = file.read()

# Rest of the script remains the same

# Split the data into lines
lines = data.strip().split('\n')

# Extract RANK values
ranks = [int(line.split('// RANK: ')[1].split(' //')[0]) for line in lines]

# Check if the ranks are in increasing order, semi-ordered, or unordered
semi_ordered = False
unordered = False

for i in range(len(ranks) - 1):

    if ranks[i] < ranks[i + 1]:
        semi_ordered = True
    elif ranks[i] > ranks[i + 1]:
        unordered = True

if semi_ordered and not unordered:
    print("The set is semi-ordered.")
elif unordered and not semi_ordered:
    print("The set is unordered.")
else:
    print("The set is a combination of semi-ordered and unordered.")
