#include "�ryptography.h"


// ������� ��� �������� ������ � ������������
const vector<int> IP = { 1, 5, 2, 0, 3, 7, 4, 6 };    // I�: { 2 6 3 1 4 8 5 7 }
const vector<int> IP_1 = { 3, 0, 2, 4, 6, 1, 7, 5 };  // I�^-1: { 4 1 3 5 7 2 8 6 }
const vector<int> P10 = { 2, 4, 1, 6, 3, 9, 0, 8, 7, 5 };     // �10: { 3 5 2 7 4 10 1 9 8 6 }
const vector<int> P8 = { 5, 2, 6, 3, 7, 4, 9, 8 };    // �8: { 6 3 7 4 8 5 10 9}
const vector<int> P4 = { 1, 3, 2, 0 };    // �4: { 2 4 3 1 }
const vector<int> EP = { 3, 0, 1, 2, 1, 2, 3, 0 };    // E/P: { 4 1 2 3 2 3 4 1}
const int S0[4][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 1} };
const int S1[4][4] = { {1, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3} };

// ����������� ����
const bit_10_t KEY("1010000010");


// ������� ��� �������� ������ � ������������
template<size_t N, size_t M> std::bitset<M> permute(const std::bitset<N>& value, const vector<int>& table) {

    /*  N - ���-�� ����� � ��������, � ������� �� ����� �������� ( � ������� 10-������ ���� )
        M - ���-�� ����� ��������� �������� ( � ������� �������, � �������� 8 ��� )
    */

    std::bitset<M> result;

    // ������������ ������� ������� � ������������ �������� ������������ :)
    /*      
            !!! C���� ������ ���(������� ���) ����� ������ 0,
            � ����� ����� ���(������� ���) ����� ������ N - 1 ��� std::bitset<N>

            ������� ���������� �������� ������� �������� (������ ������)
    */ 
    for (int i = 0; i < table.size(); i++) {
        result[M - 1 - i] = value[N - 1 - table[i]];
    }

    return result;
}


template<size_t N> std::bitset<N> �yclic_shift_left(std::bitset<N>& key, const int& shift) {
    const int bytes = N / 2;

    // �������� ����� �������� (������ 5 ���) � ��������� ����������� ����� ����� �� ���� �������
    std::bitset<bytes> key_left_half(key.to_string().substr(0, bytes));

    cout << "����� �������� �����: " << key_left_half << '\n' << '\n';

    key_left_half = key_left_half << shift | key_left_half >> (5 - shift);

    // �������� ����� �������� (��������� 5 ���) � ��������� ����������� ����� ����� �� ���� �������
    std::bitset<bytes> key_right_half(key.to_string().substr(bytes, bytes));

    cout << "������ �������� �����: " << key_right_half << '\n' << '\n';

    key_right_half = key_right_half << shift | key_right_half >> (bytes - shift);

    // ���������� ��� ��������� � ���� ����
    key = (key_left_half.to_ulong() << bytes) | key_right_half.to_ulong();

    return key;
}



// ������� ��� ��������� ������
vector<bit_8_t> generate_keys() {
    vector<bit_8_t> keys(2);    // ��� �������� �� 8 ��� ������

    cout << "�������� ����: " << KEY << '\n' << '\n';


    bit_10_t key = permute<10, 10>(KEY, P10);
    cout << "������������ P10: " << key << '\n' << '\n';


    cout << "\n\t *** ����������� ����� ����� �� ���� ������� (������ �������� �����) ***\n";

    key = �yclic_shift_left<10>(key, 1);
    cout << "������������ ����: " << key << '\n' << '\n';


    cout << "\n\t **** ��������� ����� �1 ****\n\n";

    keys.at(0) = permute<10, 8>(key, P8);
    cout << "������������ P8: " << keys.at(0) << '\n';

    cout << "\t ���� �1 = " << keys.at(0) << '\n' << '\n';


    cout << "\n\t **** ��������� ����� �2 ****\n\n";


    cout << "\n\t *** ����������� ����� ����� �� ��� ������� (������ �������� �����) ***\n";

    key = �yclic_shift_left<10>(key, 2);
    cout << "������������ ����: " << key << '\n' << '\n';


    keys.at(1) = permute<10, 8>(key, P8);
    cout << "������������ P8: " << keys.at(1) << '\n';

    cout << "\t ���� �2 = " << keys.at(1) << '\n' << '\n';


    return keys;
}


int sbox(bit_4_t value, const int S[4][4]) {
    // �������� �������� ������ (������ ��� + ��������� ���)
    bit_2_t row_2(value.to_string().substr(0, 1) + value.to_string().substr(3, 1));
    cout << "�������� ������: " << row_2 << '\n' << '\n';

    // �������� �������� ������� (2 ���� ��-��������)
    bit_2_t col_2(value.to_string().substr(1, 2));
    cout << "�������� �������: " << col_2 << '\n' << '\n';

    int row = row_2.to_ulong();
    int col = col_2.to_ulong();

    return S[row][col];
}


// ������� ��� ���������� �������
bit_8_t encrypt_char(bit_8_t plaintext_8) {
    vector<bit_8_t> keys = generate_keys();

    cout << "����������� ��� �������: " << plaintext_8 << '\n' << '\n';

    plaintext_8 = permute<8, 8>(plaintext_8, IP);
    cout << "������������ IP: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** ���������� ���������� f ����� �1 ****";

    // �������� ������ �������� (��������� 4 ���)
    bit_4_t plaintext_right_IP(plaintext_8.to_string().substr(4, 4));
    plaintext_8 = permute<4, 8>(plaintext_right_IP, EP);
    cout << "������������ E/P(R): " << plaintext_8 << "\n\n";


    plaintext_8 = ( plaintext_8 ^ keys[0] );
    cout << "�������� XOR(E/P(R), k1): " << plaintext_8 << '\n' << '\n';


    // �������� ����� �������� (��������� 4 ���)
    bit_4_t plaintext_left(plaintext_8.to_string().substr(0, 4));
    // �������� ������ �������� (��������� 4 ���)
    bit_4_t plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "����� �����: " << plaintext_left << '\n' << '\n';
    cout << "������ �����: " << plaintext_right << '\n' << '\n';


    bit_2_t plaintext_left_2 = sbox(plaintext_left, S0);
    bit_2_t plaintext_right_2 = sbox(plaintext_right, S1);
    bit_4_t plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "��������� ������ S-������: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "������������ P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left ^ plaintext_4;
    cout << "�������� XOR(L, P4): " << plaintext_4 << '\n' << '\n';

    plaintext_8 = (plaintext_right_IP.to_ulong() << 4) | plaintext_4.to_ulong();
    cout << "������������ SW: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** ���������� ���������� f ����� �2 ****";

    bit_4_t plaintext_left_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    bit_4_t plaintext_right_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));

    plaintext_8 = permute<4, 8>(plaintext_right_main, EP);
    cout << "������������ E/P(R): " << plaintext_8 << "\n\n";

    plaintext_8 = (plaintext_8 ^ keys[1]);
    cout << "�������� XOR(E/P(R), k2): " << plaintext_8 << '\n' << '\n';


    plaintext_left = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "����� �����: " << plaintext_left << '\n' << '\n';
    cout << "������ �����: " << plaintext_right << '\n' << '\n';


    plaintext_left_2 = sbox(plaintext_left, S0);
    plaintext_right_2 = sbox(plaintext_right, S1);
    plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "��������� ������ S-������: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "������������ P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_main ^ plaintext_4;
    cout << "�������� XOR(L, P4): " << plaintext_4 << '\n' << '\n';


    plaintext_8 = (plaintext_4.to_ulong() << 4) | plaintext_right_main.to_ulong();
    cout << "������������ SW(XOR(L, P4), R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = permute<8, 8>(plaintext_8, IP_1);
    cout << "������������ IP^-1: " << plaintext_8 << '\n' << '\n';
   
    return plaintext_8;
}

// ������� ��� ������������� �������
//int decrypt_char(bit ciphertext) {
//    vector<bit_8_t> keys = generate_keys();
//    ciphertext = permute<>(ciphertext, IP, 8);
//    int left = ciphertext >> 4;
//    int right = ciphertext & 0x0F;
//    right = permute(right, EP, 8);
//    right = right ^ keys[1];
//    right = sbox(right >> 4, S0) << 2 | sbox(right & 0x0F, S1);
//    right = permute(right, P4, 4);
//    right = right ^ left;
//    int temp = right;
//    right = left;
//    left = temp;
//    right = permute(right, EP, 8);
//    right = right ^ keys[0];
//    right = sbox(right >> 4, S0) << 2 | sbox(right & 0x0F, S1);
//    right = permute(right, P4, 4);
//    right = right ^ left;
//    int plaintext = (right << 4) | left;
//    plaintext = permute(plaintext, IP_1, 8);
//    return plaintext;
//}


//// ������� ��� ���������� ������
//string encrypt_string(string plaintext) {
//    string ciphertext = "";
//    for (char c : plaintext) {
//        int cipherchar = encrypt_char(c);
//        ciphertext += static_cast<char>(cipherchar);
//    }
//    return ciphertext;
//}
//
//
//// ������� ��� ������������� ������
//string decrypt_string(string ciphertext) {
//    string plaintext = "";
//    for (char c : ciphertext) {
//        int plainchar = decrypt_char(c);
//        plaintext += static_cast<char>(plainchar);
//    }
//    return plaintext;
//}