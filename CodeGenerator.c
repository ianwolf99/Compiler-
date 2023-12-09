#include <stdio.h>

// Symbol table structure to store information about variables and methods
struct SymbolTableEntry {
    char name[50]; // Variable or method name
    char type[20]; // Data type
    int size;      // Size of the data object (for arrays)
    int offset;    // Offset from the frame pointer
};

// Function to compute memory addresses and populate the symbol table
void computeMemoryAddresses(struct SymbolTableEntry* symbolTable, int numEntries) {
    int offset = 0; // Initialize offset

    for (int i = 0; i < numEntries; ++i) {
        // Compute offset based on data type
        if (strcmp(symbolTable[i].type, "int") == 0) {
            symbolTable[i].offset = -offset; // Locals have negative offsets
            offset += 4;                     // Assume integer size is 4 bytes
        } else if (strcmp(symbolTable[i].type, "int[]") == 0) {
            symbolTable[i].offset = -offset; // Locals have negative offsets
            offset += symbolTable[i].size * 4; // Size is in terms of integers
        } else if (strcmp(symbolTable[i].type, "method") == 0) {
            symbolTable[i].offset = offset; // Parameters have positive offsets
            offset += 4;                     // Assume method parameter size is 4 bytes
        }
    }
}

// Function to generate MIPS assembly code for method invocation prologue
void generatePrologue(struct SymbolTableEntry* symbolTable, int numEntries) {
    printf("# Method Prologue\n");

    for (int i = 0; i < numEntries; ++i) {
        if (strcmp(symbolTable[i].type, "method") == 0) {
            printf("    sw $ra, %d($fp) # Save return address\n", symbolTable[i].offset);
        }
    }

    // Add more prologue code as needed
}

// Function to generate MIPS assembly code for method invocation epilogue
void generateEpilogue(struct SymbolTableEntry* symbolTable, int numEntries) {
    printf("# Method Epilogue\n");

    for (int i = 0; i < numEntries; ++i) {
        if (strcmp(symbolTable[i].type, "method") == 0) {
            printf("    lw $ra, %d($fp) # Restore return address\n", symbolTable[i].offset);
        }
    }

    // Add more epilogue code as needed
}

// Function to emit MIPS assembly code for a call instruction
void emitCall(char* funcName, int numArg) {
    printf("    jal %s # call %s with %d arguments\n", funcName, funcName, numArg);
}

// Function to emit MIPS assembly code for a label
void emitLabel(int labelNum) {
    printf("L%d:\n", labelNum);
}

// Function to emit MIPS assembly code for unconditional and conditional jumps
void emitGoto(char* operator, int labelNum) {
    printf("    %s L%d\n", operator, labelNum);
}

// Function to emit MIPS assembly code for static data allocation
void emitData(char* name, char* type, int size) {
    printf("    .data\n");
    printf("    %s: .space %d\n", name, size);
}

// Function to emit MIPS assembly code for string constant definition
void emitStr(char* name, char* str) {
    printf("    .data\n");
    printf("    %s: .asciiz \"%s\"\n", name, str);
}

// Function to emit MIPS assembly code for most instructions
void emitMost(char* operator, char* type, int numOp, char* op1, char* op2, char* op3) {
    printf("    # Emitting MIPS instructions based on parameters\n");
    // Placeholder for MIPS instructions, replace with actual logic
    printf("    %s %s, %s, %s\n", operator, op1, op2, op3);
}

int main() {
    // Example usage of the emit functions
    emitCall("functionName", 3);
    emitLabel(102);
    emitGoto("bnez", 103);
    emitData("variableName", "int", 4);
    emitStr("stringName", "Hello, MIPS!");
    emitMost("add", "int", 3, "$t0", "$t1", "$t2");

    return 0;
}
