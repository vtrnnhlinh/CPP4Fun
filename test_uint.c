#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>  // Include this header for PRIu8 macro

int main() {
    uint8_t num_of_assists = 3;
    uint8_t assistVal = 0x06;  // 11 in decimal
    num_of_assists = assistVal / 10;  // Integer division of 11 by 10, result is 1

    uint8_t pas_assist_level = (uint8_t)(assistVal - num_of_assists * 10);
    printf("%" PRIu8 "\n", num_of_assists);  // Correct format specifier usage with PRIu8
    printf("%" PRIu8 "\n", pas_assist_level);
    return 0;
}
