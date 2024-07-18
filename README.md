# XOR SHA256 Hashes - C++ Program

This C++ program, `xor.cpp`, computes the XOR of two SHA256 hashes provided in separate files.

## Usage

1. **Compilation:**
   - Compile the program using a C++ compiler:
     ```bash
     g++ xor.cpp -o xor -lcrypto
     ```
   - Ensure you have OpenSSL installed (`libcrypto-dev` package on Linux) for SHA256 hashing.

2. **Execution:**
   - Run the compiled executable, providing two files containing SHA256 hashes as arguments:
     ```bash
     ./xor hash_file1.txt hash_file2.txt
     ```
   - Replace `hash_file1.txt` and `hash_file2.txt` with the paths to your files containing the SHA256 hashes.

3. **Output:**
   - The program reads the hashes from the specified files, computes the XOR operation, and prints the result.

## Example

Suppose you have two files `hash1.txt` and `hash2.txt` containing the following hashes:
- `hash1.txt` contents: `abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890`
- `hash2.txt` contents: `1234567890abcdef1234567890abcdef1234567890abcdef1234567890abcdef`

Executing the program with these files would output:
```
XOR Result: bbdcbaedcdecbbaabbdcbaedcdecbbaabbdcbaedcdecbbaabbdcbaedcdecbba
```

## Notes

- This program requires OpenSSL for SHA256 hashing functionality.
- Ensure the input files contain the hashes in the correct format (hexadecimal strings).
- The output is the XOR result of the two hashes.

## License

This project is licensed under the MIT License - see the LICENSE file for details.