#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>

#define CAPASITY 100


struct TextContainer {
    char* buffer;
    int current_size;
    int capasity;
};
char* memory_allocate(TextContainer* text_to_allocte) {
    size_t length = strlen(text_to_allocte->buffer);
    char* pointer = (char*)malloc(length*sizeof(char));
    return pointer;
}
void textContainer_initialize(TextContainer* text) {
    text->buffer = NULL;
    text->current_size = 0;
    text->capasity = 100;
}
void memory_reallocate() {

}

void memory_deallocate(char* text) {
    free(text);
}

int get_command() {
    int command;
    printf("Enter 1 to append text to the end\n");
    printf("Enter 2 to start a new line\n");
    printf("Enter 3 to save text t file\n");
    printf("Enter 4 to load text from file\n");
    printf("Enter 5 to print text to the console\n");
    printf("Enter 6 to insert symbols at the specific line and index\n");
    printf("Enter 7 to serch for some piece of text\n");
    printf("Enter 8 to clear the console\n");
    printf("Enter 0 to exit\n>>>");
    scanf("%d", &command);
    return command;
}

/*char* get_text(TextContainer* text) {
    char c;
    char* entered_text = NULL;
    textContainer_initialize(text);
    printf("Enter text you want to append. When done, press 'enter'");
    c = getchar();
    while (c != '\n') {
        if ()
        }
         entered_text[text->current_size] = c;
    }

    /*char* input[];#3#
    int length;
    char* input = (char*)malloc(length*sizeof(char));
    scanf("%s", input);
    length = strlen(input);
    return input;#1#
    return entered_text;
}*/
void append_text(TextContainer* text) {
    /*char* text_to_append = get_text(text);
    printf("Enter text you want to append:\n");
    // smth else
    printf("Text appended\n");*/
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

int main() {/*
    TextContainer* text;
    textContainer_initialize(text);
    memory_allocate(text);*/
    int command;
    do {
        command = get_command();
        switch (command) {
            case 1: {
                /*append_text(text);*/
                break;
            }
            case 2: {
                start_new_line();
                break;
            }
            case 3: {
                save_to_file();
                break;
            }
            case 4: {
                load_from_file();
                break;
            }
            case 5: {
                print_text();
                break;
            }
            case 6: {
                insert_at_index();
                break;
            }
            case 7: {
                search();
                break;
            }
            case 8: {
                clear_console();
                break;
            }
            case 0: {
                printf("Exit! Have a good day1");
                break;
            }
            default: {
                printf("There is no such a command, sorry :(\n");
                break;
            }
        }
    } while (command != 0);
    return 0;
}