import subprocess

def disassemble_elf(file_path):
    try:
        # Use WSL to run readelf and disassemble the ELF file
        result = subprocess.run(["wsl", "readelf", "-a", file_path], capture_output=True, text=True)
        
        if result.returncode == 0:
            return result.stdout
        else:
            print(f"Error disassembling ELF file:\n{result.stderr}")
            return None
    except Exception as e:
        print(f"Error disassembling ELF file: {e}")
        return None

def main():
    file_path = "codeGen.linux"  # Update the file name

    # Disassemble ELF file using readelf via WSL
    disassembly_output = disassemble_elf(file_path)

    if disassembly_output is not None:
        print(disassembly_output)

if __name__ == "__main__":
    main()
