# List of file names
file_names = [
    "1000-sort_deck.c",
    "107-quick_sort_hoare.c",
    "106-bitonic_sort.c",
    "105-radix_sort.c",
    "104-heap_sort.c",
    "103-merge_sort.c",
    "102-counting_sort.c",
    "101-cocktail_sort_list.c",
    "100-shell_sort.c",
    "3-quick_sort.c",
    "2-selection_sort.c",
    "1-insertion_sort_list.c",
    "0-bubble_sort.c"
]

# Content for each file
file_content = '#include "sort.h"'

# Create the C files with no leading or trailing white spaces
for file_name in file_names:
    with open(file_name, 'w') as file:
        file.write(file_content + '\n')

print("C files created successfully.")
