def read_binary_file(file_path):
    with open(file_path, 'rb') as file:
        binary_data = file.read()

    return binary_data

def print_hex_and_text(binary_data, bytes_per_line=16):
    for i in range(0, len(binary_data), bytes_per_line):
        line = binary_data[i:i + bytes_per_line]

        # Hexadecimal representation
        hex_line = ' '.join(f'{byte:02x}' for byte in line)

        # ASCII text representation
        text_line = ''.join(chr(byte) if 32 <= byte <= 126 else '.' for byte in line)

        print(f'{hex_line.ljust(3 * bytes_per_line)}   {text_line}')

def main():
    file_path = "codeGen.linux"  # Update the file name
    binary_data = read_binary_file(file_path)

    # Print both hex and ASCII text
    print_hex_and_text(binary_data)

if __name__ == "__main__":
    main()
