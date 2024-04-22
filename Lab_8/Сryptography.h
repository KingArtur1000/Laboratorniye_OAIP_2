#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <utility>


using std::vector;
using std::string;
using std::cout;

using bit_10_t = std::bitset<10>;
using bit_8_t = std::bitset<8>;
using bit_5_t = std::bitset<5>;
using bit_4_t = std::bitset<4>;
using bit_2_t = std::bitset<2>;

vector<bit_8_t> generate_keys();	// Функция для генерации подключей
template <size_t N, size_t M> std::bitset<M> permute(const std::bitset<N>& value, const vector<int>& table);	// Функции для операций замены и перестановки
int sbox(bit_4_t value, const int S[4][4]);
bit_8_t encrypt_char(bit_8_t plaintext);	// Функция для шифрования символа
//int decrypt_char(int ciphertext);	// Функция для расшифрования символа
//string encrypt_string(string plaintext);	// Функция для шифрования строки
//string decrypt_string(string ciphertext);	// Функция для расшифрования строки