#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LED_PATH "/sys/class/leds/input8::capslock/brightness"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [0 to turn off, 1 to turn on]\n", argv[0]);
        return 1;
    }

    // Open the brightness file for writing
    FILE *fp = fopen(LED_PATH, "w");
    if (fp == NULL) {
        perror("Error opening LED brightness file");
        return 1;
    }

    // Check the argument and write the appropriate value
    if (strcmp(argv[1], "1") == 0) {
        fprintf(fp, "1");
    } else if (strcmp(argv[1], "0") == 0) {
        fprintf(fp, "0");
    } else {
        fprintf(stderr, "Invalid argument. Use 0 to turn off or 1 to turn on.\n");
        fclose(fp);
        return 1;
    }

    printf("Caps Lock LED has been %s.\n", (argv[1][0] == '1') ? "turned on" : "turned off");

    fclose(fp);
    return 0;
}
