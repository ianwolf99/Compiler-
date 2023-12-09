def read_binary_file(file_path):
    with open(file_path, 'rb') as file:
        binary_data = file.read()

    return binary_data

def print_text(binary_data):
    # Decode binary data as ASCII text
    text_data = binary_data.decode('utf-8', errors='replace')

    # Print the text data
    print(text_data)

def main():
    file_path = "codeGen.linux"  # Update the file name
    binary_data = read_binary_file(file_path)

    # Print only the ASCII text
    print_text(binary_data)

if __name__ == "__main__":
    main()
