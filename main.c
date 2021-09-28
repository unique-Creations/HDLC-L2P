//
// @author Ernesto Ruiz
//
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

/* Initialize global variables */
int user_bits[8];
int user_bit_size;

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
 *  @brief Adds bit to user_bits array if in correct order.
 *         Increase user_bit_size if bit is added to array.
 */
void append_flag_bit(char c);

int main() {
    bool flag_detected = false;
    printf("Enter any key:\n");

    //TODO: if user enters a wrong key between flag input, start over.
    while (1) {
        char tmp;
        tmp = (char) getc(stdin);
        detect_flag(&flag_detected);
        if (tmp == '0' || tmp == '1') {
            append_flag_bit(tmp);
        }
        // If HDLC flag is detected, print input.
        if (flag_detected) {
            putchar(tmp);
        }
    }
}

void detect_flag(bool *f) {
    // Check if flag has been received from user.
    if (user_bit_size == 8) {
        *f = !*f;
        user_bit_size = 0;
        printf("\nFlag has been detected\n");
    }
}

void append_flag_bit(char c) {
    int tmp = c - '0';
    if (tmp == flag[user_bit_size]) {
        user_bits[user_bit_size] = tmp;
        user_bit_size += 1;
    } else {
        user_bit_size = 0;
    }
}

#pragma clang diagnostic pop