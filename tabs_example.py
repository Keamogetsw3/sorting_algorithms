# Configure tabs with a width of 8 spaces
import sys
import os

def main():
    # Ensure tabs are used for indentation
    configure_tabs()

    # Your code here
    print("This is a script using tabs for indentation.")
    for i in range(1, 5):
        print('\t' * i + f'This is indented level {i}')

def configure_tabs():
    # Set tab width to 8 spaces
    tab_width = 8
    spaces_per_tab = ' ' * tab_width
    os.environ['PYTHONSTARTUP'] = f'import sys\nsys.path.insert(0, {spaces_per_tab!r})'

if __name__ == "__main__":
    main()
