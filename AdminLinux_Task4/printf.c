#include <unistd.h>   
#include <string.h>


void print(const char *message)
{
    size_t length = strlen(message);
    write(1, message, length);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        const char *error_message = "Error: No string provided.\n";
        write(2, error_message, strlen(error_message));
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print(argv[i]);
        if (i < argc - 1) {
            print(" ");
        }
    } 
   
   
    print("\n");

    return 0;
}
