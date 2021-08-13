#include <iostream>
#include <string>

constexpr int rows = 4;

std::string ceasar_encrypt(std::string normal_text, int key);
std::string ceasar_decrypt(std::string cipher_text, int key);

std::string permutation_encrypt(std::string normal_text, int cols);
std::string permutation_decrypt(std::string cipher_text, int cols);

int main()
{
    // ====== TASK #1 ======
    std::string text;
    int key;
    std::cout << "Input text: ";
    std::getline(std::cin, text);
    std::cout << "Input key (1-26): ";
    std::cin >> key;
    std::string encrypted_text = ceasar_encrypt(text, key);
    std::cout << "Encrypted text: " << encrypted_text << std::endl;
    std::string decrypted_text = ceasar_decrypt(encrypted_text, key);
    std::cout << "Decrypted text: " << decrypted_text << std::endl;

    std::cin.clear();
    std::cin.ignore();

    // ====== TASK #2 ======
    std::string text2;
    std::cout << "Input text: ";
    std::getline(std::cin, text2);
    int cols =  text2.length() / rows + 1;
    std::string encrypted_text2 = permutation_encrypt(text2, cols);
    std::cout << "Encrypted text: " << encrypted_text2 << std::endl;
    std::string decrypted_text2 = permutation_decrypt(encrypted_text2, cols);
    std::cout << "Decrypted text: " << decrypted_text2 << std::endl;

    return 0;
}

std::string ceasar_encrypt(std::string normal_text, int key)
{
    std::string cipher_text = "";
    for(const auto& ch : normal_text)
    {
        cipher_text += char(ch + key);
    }
    return cipher_text;
}

std::string ceasar_decrypt(std::string cipher_text, int key)
{
    std::string text = "";
    for(const auto& ch : cipher_text)
    {
        text += char(ch - key);
    }
    return text;
}

std::string permutation_encrypt(std::string normal_text, int cols)
{
    char** mx = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        mx[i] = new char[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            mx[i][j] = 0;
        }
    }

    int i = 0;
    int j = 0;
    for(const char& ch : normal_text)
    {
        if(j == cols)
        {
            j = 0;
            i++;
        }
        mx[i][j++] = ch;
    }

    std::string cipher_text = "";
    for(int j = cols - 1; j >= 0; --j)
    {
        for(int i = 0; i < rows; ++i)
        {
            cipher_text += mx[i][j];
        }
    }

    for(int i = 0; i < rows; ++i)
    {
        delete [] mx[i];
    }
    delete [] mx;

    return  cipher_text;
}

std::string permutation_decrypt(std::string cipher_text, int cols)
{
    char** mx = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        mx[i] = new char[cols];
    }

    int i = 0;
    int j = cols - 1;
    for(const char& ch : cipher_text)
    {
        if(i == rows)
        {
            i = 0;
            j--;
        }
        mx[i++][j] = ch;
    }

    std::string text = "";
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(mx[i][j] != 0)
                text += mx[i][j];
        }
    }

    for(int i = 0; i < rows; ++i)
    {
        delete [] mx[i];
    }
    delete [] mx;

    return  text;
}

