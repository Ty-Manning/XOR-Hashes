#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

// Function to read SHA256 hash from a file
std::vector<unsigned char> readHashFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Read the hash (assuming SHA256 produces 32 bytes)
    std::vector<unsigned char> hash(32);
    file.read(reinterpret_cast<char*>(hash.data()), 32);
    
    file.close();
    return hash;
}

// Function to compute XOR of two hashes
std::vector<unsigned char> computeXor(const std::vector<unsigned char>& hash1, const std::vector<unsigned char>& hash2) {
    std::vector<unsigned char> result(32);
    for (int i = 0; i < 32; ++i) {
        result[i] = hash1[i] ^ hash2[i];
    }
    return result;
}

// Function to write hash to a file
void writeHashToFile(const std::vector<unsigned char>& hash, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    
    file.write(reinterpret_cast<const char*>(hash.data()), 32);
    file.close();
}

int main(int argc, char* argv[]) {
    // Check if two filenames are provided as command-line arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <hash_file1> <hash_file2>" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Read hashes from files
    std::vector<unsigned char> hash1 = readHashFromFile(argv[1]);
    std::vector<unsigned char> hash2 = readHashFromFile(argv[2]);
    
    // Compute XOR of the two hashes
    std::vector<unsigned char> finalHash = computeXor(hash1, hash2);
    
    // Print final hash to the command line
    std::cout << "Final Hash: ";
    for (const auto& byte : finalHash) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    std::cout << std::endl;
    
    // Write final hash to "finalkey.key" file
    writeHashToFile(finalHash, "finalkey.key");
    
    return EXIT_SUCCESS;
}
