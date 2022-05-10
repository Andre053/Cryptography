#include <iostream>
#include <fstream>

// function declarations
std::string caesarCipher(std::string input);
void caesarEncrypt(int idx, int offset, std::string in, char out[]);
int cipherSelection();
int choose_message_input_type();
//std::string get_text_file_content();
//std::string get_command_line_message();

std::string caesarCipher(std::string input) {
    int offset;
    char output[input.length()];

    std::cout << "Please enter an offset for the cipher" << std::endl;
    std::cin >> offset;

    std::cout << "\nEncoding '" << input << "/" << output << "' with offset: " << offset << std::endl;

    if (-26 > offset || offset > 26) exit(0);

    for (int i=0; i<input.length(); i++) {
        caesarEncrypt(i, offset, input, output);
    }
    std::cout << "Encryption finished" << std::endl;
    std::string s(output);
    return s;

}

char intToAscii(int i) {
    return '0' + i;
}

void caesarEncrypt(int idx, int offset, std::string in, char out[]) {

    // char is an ASCII representation
    // lowercase letters: 65-90
    // uppercase letters: 97-122

    char input = (unsigned char)in[idx];

    std::cout << "Current char: " << input << std::endl;

    if (64 < input && input < 91) { 
        // lowercase
        out[idx] = ((input-66+offset)%26)+66;

    } else if (96 < input && input < 123) { 
        // uppercase
        out[idx] = ((input-98+offset)%26)+98;
    } else {
        out[idx] = input;
    }
    std::cout << "Becomes: " << out[idx] << std::endl;

}

int choose_message_input_type() {
    int x;

    std::cout << "\nWelcome to the encryptor!\n\nPlease select from the options below\n1 = Type a message into the command line\n2 = Pass a message file location\n\nChoice: ";
    std::cin >> x;

    return x;
}

std::string get_command_line_message() {
    std::string message;

    std::cout << "\nEnter your message below\n########################\n\n";
    
    std::getline (std::cin, message);
    std::getline (std::cin, message);

    //if (sizeof(message) == 0) return "Bad input";

    std::cout << "Your message: " << message << std::endl;

    return message;
}

std::string get_text_file_content() {
    std::string content, filePath;

    std::cout << "\nEnter the file location below\n##############################\n" << std::endl;
    std::cin >> filePath;

    if (sizeof(filePath) == 0) exit(0);

    // create read file
    // check if file exists and is open
    // read file contents into a string

    return content;
}

int cipherSelection() {
    /*
        Caesar: 
        Affine:
        Vingere:
    */

   int selection;

   std::cout 
        << "\nSelect the cipher type below\n"
        << "1 = Caesar Cipher\n"
        << "2 = Affine Cipher\n"
        << "3 = Vingere Cipher\n\nChoice: ";

    std::cin >> selection; // add error checking

    return selection;
}

int main() {
    /*

        ### ENCRYPTOR ###

        1. Input a message from command line or submit a text file (or allow them to create a new vim file, open vim for them)
        2. Select the cipher you want 
        3. Confirm the cipher parameters
        4. Export encrypted message to a file or to clipboard


    */
    std::string messagePlain, messageEncrypted;
    int inputType, cipherType;
    char again;

    do {
        inputType = choose_message_input_type();
        messagePlain = get_command_line_message(); // use branchless approach
        cipherType = cipherSelection();

        switch (cipherType) {
            case 1:
                std::cout << "Caesar Cipher" << std::endl;
                messageEncrypted = caesarCipher(messagePlain);
                std::cout << "Result: " << messageEncrypted << std::endl;
                break;
            case 2: 
                break;
            case 3:
                break;
            default:
                std::cout << "Default case was raised by: " << cipherType << std::endl;
                break;
        }
        std::cout << "Would you like to go again (y/n)? ";
        std::cin >> again;
    } while (again == 'y');

    

    return 0;
}