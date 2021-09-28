//
// @author Ernesto Ruiz
//
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/* flag enum to detect*/
enum flag {b7 = 0, b6 = 1, b5 = 1, b4 = 1, b3 = 1, b2 = 1, b1 = 1, b0 = 0};

/**
 *
 * @param c character user inputs
 * @param f boolean flag state
 * @return boolean value of whether flag has been
 */
void detect_flag(char c, bool *f);

int main(){
    bool flag_detected = false;
    printf("Enter any key: ");

    char tmp;
    tmp = getc(stdin);
    detect_flag(tmp, &flag_detected);
    if (flag_detected){
        putchar(tmp);
    }

    return 0;
}

void detect_flag(char c, bool *f){

}