//
// @author Ernesto Ruiz
//
#include <stdio.h>
#include <stdbool.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

/* Initialize global variables */
int flag_bit_idx;

/* Integer array of HDLC flag
 * flag: 01111110
 * */
const int flag[] = {0, 1, 1, 1, 1, 1, 1, 0};

/**
 * @param f boolean flag state
 * @brief check whether flag has been received from user.
 * @return boolean value of whether flag has been
 */
void detect_flag(bool *f);

/**
 * @param c user character that is to be converted to int.
 * @brief Adds bit to user_bits array if in correct order.
 *        Increase flag_bit_idx if bit is added to array.
 */
void append_flag_bit(char c);

/**
 *
 * @param c char to verify whether bit value has been entered.
 * @brief is_bit checks whether the char entered by user is 1 or 0 and returns integer
 *        integer as a boolean value after verification.
 * @return integer value 1 if char is either 1 or 0 else return integer is 0
 */
int is_bit(char c);

int main() {
    bool flag_detected = false;
    printf("Enter any key:\n");

    while (1) {
        char tmp;
        tmp = (char) getc(stdin);
        detect_flag(&flag_detected);
        if (is_bit(tmp)) {
            append_flag_bit(tmp);
        } else if (tmp > '1'){
            flag_bit_idx = 0;
        }
        // If HDLC flag is detected, print input.
        if (flag_detected) {
            putchar(tmp);
        }
    }
}

void detect_flag(bool *f) {
    // Check if flag has been received from user.
    if (flag_bit_idx == 8) {
        *f = !*f;
        flag_bit_idx = 0;
        printf("\n--Flag detected--\n");
    }
}

void append_flag_bit(char c) {
    int tmp = c - '0';
    if (tmp == flag[flag_bit_idx]) {
        flag_bit_idx += 1;
    } else if (tmp != flag[flag_bit_idx]){
        flag_bit_idx = 0;
    }
}

int is_bit(char c){
    if(c >= '0' && c <= '1'){
        return 1;
    }
    return 0;
}
#pragma clang diagnostic pop