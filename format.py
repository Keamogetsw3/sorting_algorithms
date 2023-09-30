#!/usr/bin/env python3

import os
import re
import subprocess
import sys

def format_c_file(file_path):
    # Define the tab spacing and call autopep8 to format the file
    tab_spacing = 8
    subprocess.run(['autopep8', '--in-place', '--indent-size', str(tab_spacing), file_path])

    # Remove trailing and leading whitespace
    with open(file_path, 'r') as file:
        lines = file.readlines()

    with open(file_path, 'w') as file:
        for line in lines:
            # Remove trailing whitespace
            line = re.sub(r'\s+$', '', line)

            # Remove leading whitespace
            line = re.sub(r'^\s+', '', line)

            file.write(line)

def format_c_files_in_folder(folder_path):
    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".c"):
                file_path = os.path.join(root, file)
                format_c_file(file_path)
                print(f"Formatted and cleaned {file_path}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ./format.py <folder_path>")
        sys.exit(1)

    folder_path = sys.argv[1]

    if os.path.isdir(folder_path):
        format_c_files_in_folder(folder_path)
    else:
        print(f"Folder not found: {folder_path}")
