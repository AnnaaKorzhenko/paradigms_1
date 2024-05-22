#include <iostream>

#define INITSIZE 100

// memory_allocate(){}

// memory_deallocate(){}

int get_command() {
    return 1;
}

char get_text() {
    return 'a';
}
void append_text() {
    //
}

void start_new_line() {
    //
}

void save_to_file() {
    //
}

void load_from_file() {
    //
}

void print_text() {
    //
}

void insert_at_index() {
    //
}

void search() {
    //
}

void clear_console() {
    //
}

int main() {
    int command = get_command();
    do {
        switch (command) {
            case 1: {
                append_text();
            }
            case 2: {
                start_new_line();
            }
            case 3: {
                save_to_file();
            }
            case 4: {
                load_from_file();
            }
            case 5: {
                print_text();
            }
            case 6: {
                insert_at_index();
            }
            case 7: {
                search();
            }
            case 8: {
                clear_console();
            }
        }
    } while (1);
    return 0;
}
