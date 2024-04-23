#include "Сryptography.h"


// Таблицы для операций замены и перестановки
const vector<int> IP = { 1, 5, 2, 0, 3, 7, 4, 6 };    // IР: { 2 6 3 1 4 8 5 7 }
const vector<int> IP_1 = { 3, 0, 2, 4, 6, 1, 7, 5 };  // IР^-1: { 4 1 3 5 7 2 8 6 }
const vector<int> P10 = { 2, 4, 1, 6, 3, 9, 0, 8, 7, 5 };     // Р10: { 3 5 2 7 4 10 1 9 8 6 }
const vector<int> P8 = { 5, 2, 6, 3, 7, 4, 9, 8 };    // Р8: { 6 3 7 4 8 5 10 9}
const vector<int> P4 = { 1, 3, 2, 0 };    // Р4: { 2 4 3 1 }
const vector<int> EP = { 3, 0, 1, 2, 1, 2, 3, 0 };    // E/P: { 4 1 2 3 2 3 4 1}
const int S0[4][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 1} };
const int S1[4][4] = { {1, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3} };

// Статический ключ
const bit_10_t KEY("0000010010");


// Функция для операций замены и перестановки
template<size_t N, size_t M> std::bitset<M> permute(const std::bitset<N>& value, const vector<int>& table) {

    /*  N - кол-во битов у значения, с которым мы будем работать ( к примеру 10-битный ключ )
        M - кол-во битов выходного значения ( к примеру подключ, у которого 8 бит )
    */

    std::bitset<M> result;

    // Перестановка каждого символа в соответствии заданной перестановки :)
    /*      
            !!! Cамый правый бит(младший бит) имеет индекс 0,
            а самый левый бит(старший бит) имеет индекс N - 1 для std::bitset<N>

            Поэтому используем обратный порядок перебора (справа налево)
    */ 
    for (int i = 0; i < table.size(); i++) {
        result[M - 1 - i] = value[N - 1 - table.at(i)];
    }

    return result;
}


template<size_t N> std::bitset<N> сyclic_shift_left(std::bitset<N>& key, const int& shift) {
    const int bytes = N / 2;

    // Получаем левую половину (первые 5 бит) и выполняем циклический сдвиг влево на одну позицию
    std::bitset<bytes> key_left_half(key.to_string().substr(0, bytes));

    cout << "Левая половина ключа: " << key_left_half << '\n' << '\n';

    key_left_half = key_left_half << shift | key_left_half >> (bytes - shift);

    // Получаем левую половину (последние 5 бит) и выполняем циклический сдвиг влево на одну позицию
    std::bitset<bytes> key_right_half(key.to_string().substr(bytes, bytes));

    cout << "Правая половина ключа: " << key_right_half << '\n' << '\n';

    key_right_half = key_right_half << shift | key_right_half >> (bytes - shift);

    // Объединяем две половинки в один ключ
    key = (key_left_half.to_ulong() << bytes) | key_right_half.to_ulong();

    return key;
}



// Функция для генерации ключей
vector<bit_8_t> generate_keys() {
    vector<bit_8_t> keys(2);    // Два подключа на 8 бит каждый

    cout << "Заданный ключ: " << KEY << '\n' << '\n';


    bit_10_t key = permute<10, 10>(KEY, P10);
    cout << "Перестановка P10: " << key << '\n' << '\n';


    cout << "\n\t *** Циклический свдиг влево на одну позицию (каждой половины ключа) ***\n";

    key = сyclic_shift_left<10>(key, 1);
    cout << "Объединенный ключ: " << key << '\n' << '\n';


    cout << "\n\t **** Генерация ключа №1 ****\n\n";

    keys.at(0) = permute<10, 8>(key, P8);
    cout << "Перестановка P8: " << keys.at(0) << '\n' << '\n';

    cout << "\t Ключ №1 = " << keys.at(0) << '\n' << '\n' << '\n';


    cout << "\n\t **** Генерация ключа №2 ****\n\n";


    cout << "\n\t *** Циклический свдиг влево на две позицию (каждой половины ключа) ***\n";

    key = сyclic_shift_left<10>(key, 2);
    cout << "Объединенный ключ: " << key << '\n' << '\n';


    keys.at(1) = permute<10, 8>(key, P8);
    cout << "Перестановка P8: " << keys.at(1) << '\n' << '\n';

    cout << "\t Ключ №2 = " << keys.at(1) << '\n' << '\n' << '\n';


    return keys;
}


int sbox(bit_4_t value, const int S[4][4]) {
    // Получаем двоичную строку (первый бит + последний бит)
    bit_2_t row_2(value.to_string().substr(0, 1) + value.to_string().substr(3, 1));
    cout << "Двоичная строка: " << row_2 << '\n' << '\n';

    // Получаем двоичный столбец (2 бита по-середине)
    bit_2_t col_2(value.to_string().substr(1, 2));
    cout << "Двоичный столбец: " << col_2 << '\n' << '\n';

    int row = row_2.to_ulong();
    int col = col_2.to_ulong();

    return S[row][col];
}


// Функция для шифрования символа
bit_8_t encrypt_char(bit_8_t plaintext_8) {
    vector<bit_8_t> keys = generate_keys();

    cout << "Изначальный код символа: " << plaintext_8 << '\n' << '\n';

    plaintext_8 = permute<8, 8>(plaintext_8, IP);
    cout << "Перестановка IP: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** Вычисление шифрование f1 ****\n\n";

    // Получаем правую половину (последние 4 бит)
    bit_4_t plaintext_left_IP(plaintext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t plaintext_right_IP(plaintext_8.to_string().substr(4, 4));
    plaintext_8 = permute<4, 8>(plaintext_right_IP, EP);
    cout << "Перестановка E/P(R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = ( plaintext_8 ^ keys[0] );
    cout << "Операция XOR(E/P(R), k1): " << plaintext_8 << '\n' << '\n';


    // Получаем левую половину (последние 4 бит)
    bit_4_t plaintext_left(plaintext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << plaintext_left << '\n' << '\n';
    cout << "Правая часть: " << plaintext_right << '\n' << '\n';


    bit_2_t plaintext_left_2 = sbox(plaintext_left, S0);
    bit_2_t plaintext_right_2 = sbox(plaintext_right, S1);
    bit_4_t plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "Результат работы S-матриц: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "Перестановка P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_IP ^ plaintext_4;
    cout << "Операция XOR(L, P4): " << plaintext_4 << '\n' << '\n';

    plaintext_8 = (plaintext_right_IP.to_ulong() << 4) | plaintext_4.to_ulong();
    cout << "Перестановка SW: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** Вычисление шифрование f2 ****";

    bit_4_t plaintext_left_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    bit_4_t plaintext_right_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));

    plaintext_8 = permute<4, 8>(plaintext_right_main, EP);
    cout << "Перестановка E/P(R): " << plaintext_8 << '\n' << '\n';

    plaintext_8 = (plaintext_8 ^ keys[1]);
    cout << "Операция XOR(E/P(R), k2): " << plaintext_8 << '\n' << '\n';


    plaintext_left = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << plaintext_left << '\n' << '\n';
    cout << "Правая часть: " << plaintext_right << '\n' << '\n';


    plaintext_left_2 = sbox(plaintext_left, S0);
    plaintext_right_2 = sbox(plaintext_right, S1);
    plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "Результат работы S-матриц: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "Перестановка P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_main ^ plaintext_4;
    cout << "Операция XOR(L, P4): " << plaintext_4 << '\n' << '\n';


    plaintext_8 = (plaintext_4.to_ulong() << 4) | plaintext_right_main.to_ulong();
    cout << "Перестановка SW(XOR(L, P4), R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = permute<8, 8>(plaintext_8, IP_1);
    cout << "Перестановка IP^-1: " << plaintext_8 << '\n' << '\n';
   
    return plaintext_8;
}


// Функция для расшифрования символа
bit_8_t decrypt_char(bit_8_t ciphertext_8) {
    vector<bit_8_t> keys = generate_keys();

    cout << "\tИзначальный код зашифрованного символа: " << ciphertext_8 << '\n' << '\n';


    cout << "\n\t**** Вычисление расшифрование f1 ****\n";

    ciphertext_8 = permute<8, 8>(ciphertext_8, IP);
    cout << "Перестановка IP: " << ciphertext_8 << '\n' << '\n';

    bit_4_t ciphertext_left_IP = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    bit_4_t ciphertext_right_IP = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));

    cout << "Левая часть: " << ciphertext_left_IP << '\n';
    cout << "Правая часть: " << ciphertext_right_IP << '\n' << '\n';

    ciphertext_8 = permute<4, 8>(ciphertext_right_IP, EP);
    cout << "Перестановка EP: " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = ciphertext_8 ^ keys.at(1);
    cout << "Операция XOR(L, P4): " << ciphertext_8 << '\n' << '\n';

    bit_4_t ciphertext_left = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    bit_4_t ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));

    cout << "Левая часть: " << ciphertext_left << '\n';
    cout << "Правая часть: " << ciphertext_right << '\n' << '\n';

    bit_2_t ciphertext_left_2 = sbox(ciphertext_left, S0);
    bit_2_t ciphertext_right_2 = sbox(ciphertext_right, S1);
    bit_4_t ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "Результат работы S-матриц: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "Перестановка P4: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = ciphertext_4 ^ ciphertext_left_IP;
    cout << "Операция XOR(L, P4): " << ciphertext_4 << '\n' << '\n';

    cout << ciphertext_right_IP << '\n';
    cout << ciphertext_4 << '\n';

    ciphertext_8 = (ciphertext_right_IP.to_ulong() << 4 | ciphertext_4.to_ulong());
    cout << "Перестановка SW: " << ciphertext_8 << '\n' << '\n';



    cout << "\n\t**** Вычисление расшифрование f2 ****\n";

    bit_4_t ciphertext_left_begin = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    bit_4_t ciphertext_right_begin = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));


    ciphertext_8 = permute<4, 8>(ciphertext_right_begin, EP);
    cout << "Перестановка E/P(R): " << ciphertext_8 << '\n' << '\n';


    ciphertext_8 = (ciphertext_8 ^ keys.at(0));
    cout << "Операция XOR(E/P(R), k2): " << ciphertext_8 << '\n' << '\n';


    ciphertext_left = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << ciphertext_left << '\n' << '\n';
    cout << "Правая часть: " << ciphertext_right << '\n' << '\n';


    ciphertext_left_2 = sbox(ciphertext_left, S0);
    ciphertext_right_2 = sbox(ciphertext_right, S1);
    ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "Результат работы S-матриц: " << ciphertext_4 << '\n' << '\n';


    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "Перестановка P4: " << ciphertext_4 << '\n' << '\n';


    ciphertext_4 = ciphertext_4 ^ ciphertext_left_begin;
    cout << "Операция XOR(L, P4): " << ciphertext_4 << '\n' << '\n';


    ciphertext_8 = (ciphertext_4.to_ulong() << 4) | ciphertext_right_begin.to_ulong();
    cout << "Перестановка SW(XOR(L, P4), R): " << ciphertext_8 << '\n' << '\n';


    ciphertext_8 = permute<8, 8>(ciphertext_8, IP_1);
    cout << "Перестановка IP^-1: " << ciphertext_8 << '\n' << '\n';


    return ciphertext_8;
}



// Функция для шифрования строки
string encrypt_string(string& plaintext) {
    string ciphertext = "";
    int i = 1;

    for (bit_8_t c : plaintext) {

        cout << "\n\n\t\t*************** Шифрование символа №" << i << " ***************" << '\n' << '\n' << '\n';

        bit_8_t cipherchar = encrypt_char(c);
        ciphertext += static_cast<char>(cipherchar.to_ulong());

        i++;
    }

    return ciphertext;
}


// Функция для расшифрования строки
string decrypt_string(string& ciphertext) {
    string plaintext = "";
    int i = 1;

    for (char c : ciphertext) {
        cout << "\n\n\t\t*************** Расшифрование символа №" << i << " ***************" << '\n' << '\n' << '\n';

        bit_8_t plainchar = decrypt_char(c);
        plaintext += static_cast<char>(plainchar.to_ulong());

        i++;
    }

    return plaintext;
}