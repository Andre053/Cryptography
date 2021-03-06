#include <iostream>
#include <fstream>

// function declarations
std::string caesarCipher(std::string input);
void caesarEncrypt(int idx, int offset, std::string in, char out[]);
void affineEncrypt(int idx, int offset, std::string in, char out[], int a);
void vinegereEncrypt(int idx, std::string key, std::string in, char out[]);
int cipherSelection();
int choose_message_input_type();
std::string cipher(std::string input, int cipher);
std::string decipher(std::string input, int decipher);

//std::string get_text_file_content();
//std::string get_command_line_message();

char intToAscii(int i) {
    return '0' + i;
}

std::string cipher(std::string input, int cipher=1) {
    int offset, a;
    std::string key;
    char output[input.length()];

    if (cipher == 1 || cipher == 2) {
        std::cout << "Please enter an offset for the cipher" << std::endl;
        std::cin >> offset;
    } else {
        std::cout << "Please enter a key" << std::endl;
        std::cin >> key;
        if (key.length() <= input.length()) {
            // repeat key until lengths are equal
        } else {
            // truncate key
        }
    }

    

    std::cout << "\nEncoding '" << input << "/" << output << "' with offset: " << offset << std::endl;

    if (-26 > offset || offset > 26) exit(0);

    if (cipher == 2) {
        std::cout << "Please enter a value for a, which must be co-prime to 26\nEx. 3, 5, 7, 9, 11..." << std::endl;
        std::cin >> a;
    }

    for (int i=0; i<input.length(); i++) {
        switch (cipher) {
            case 1: 
                caesarEncrypt(i, offset, input, output);
                break;
            case 2:
                affineEncrypt(i, offset, input, output, a);
                break;
            case 3:
                vinegereEncrypt(i, key, input, output);
                break;
            default:
                break;
        }
    }
    std::cout << "Encryption finished" << std::endl;
    std::string s(output);
    return s;

}

void caesarEncrypt(int idx, int offset, std::string in, char out[]) {

    // char is an ASCII representation
    // lowercase letters: 65-90
    // uppercase letters: 97-122

    char input = (unsigned char)in[idx];

    if (64 < input && input < 91) { 
        // lowercase
        out[idx] = ((input-66+offset)%26)+66;

    } else if (96 < input && input < 123) { 
        // uppercase
        out[idx] = ((input-98+offset)%26)+98;
    } else {
        out[idx] = input;
    }
}

void affineEncrypt(int idx, int offset, std::string in, char out[], int a = 1) {
    // b is 26, a must be coprime, pick 7
    char input = (unsigned char)in[idx];
    

    // check if a is co-prime to 26

    if (64 < input && input < 91) { 
        // lowercase
        out[idx] = (a*(input-66)+offset)%26+66;

    } else if (96 < input && input < 123) { 
        // uppercase
        out[idx] = ((a*(input-98)+offset)%26)+98;
    } else {
        out[idx] = input;
    }
}

void vinegereEncrypt(int idx, std::string key, std::string in, char out[]) {

    /*
        user must also pass a keyword that is 
        repeated until the num of characters
        equals the input length

        algebrarically: C = (M+K)mod26

    */

   char input = (unsigned char)in[idx];
   char keyChar = (unsigned char)key[idx];

   if (64 < input && input < 91) { 
        // lowercase
        out[idx] = ((input-66)+keyChar)%26+66;

    } else if (96 < input && input < 123) { 
        // uppercase
        out[idx] = (((input-98)+keyChar)%26)+98;
    } else {
        out[idx] = input;
    }

}

std::string decipher(std::string input, int decipher=1) {
    std::cout << "Deciphering type " << decipher << std::endl;
    std::string s;

    return s;
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
    
    // fix this from needing two getlines
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
    std::string message, messageEncrypted, messageDecrypted;
    int inputType, encryptType, input, decryptType;
    char again;
    bool encrypt = true;

    do {
        std::cout << "Would you like to encrypt or decrypt (e/d)?" << std::endl;
        std::cin >> input;
        std::cin >> input;

        inputType = choose_message_input_type();
        message = get_command_line_message(); // use branchless approach

        if (input == 'e') {
            
            encryptType = cipherSelection();

            messageEncrypted = cipher(message, encryptType);
            std::cout << "Result: " << messageEncrypted << std::endl;
        }

        if (input == 'd') {
            decryptType = cipherSelection();

            messageDecrypted = decipher(message, decryptType);
            std::cout << "Result: " << messageDecrypted << std::endl;
        }

        std::cout << "Would you like to go again (y/n)? ";
        std::cin >> again;

    } while (again == 'y');

    

    return 0;
}