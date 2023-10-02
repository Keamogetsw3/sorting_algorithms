import os

directory_path = '/sorting_algorithms'

# Get a list of all files in the directory
file_list = os.listdir(directory_path)

# Process each C file in the directory
for filename in file_list:
    if filename.endswith('.c'):
        file_path = os.path.join(directory_path, filename)
        with open(file_path, 'r') as file:
            lines = file.readlines()

        with open(file_path, 'w') as file:
            for line in lines:
                file.write(line.lstrip())
