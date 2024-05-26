#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>


struct TextContainer {
    char* buffer;
    int current_size;
    int capasity;
};

TextContainer* textContainer_initialize() {
    TextContainer* text = (TextContainer*)malloc(sizeof(TextContainer));
    text->current_size = 0;
    text->capasity = 100;
    text->buffer = (char*)malloc(text->capasity * sizeof(char));
    if(text->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(text);
        exit(1);
    }
    return text;
}
void memory_reallocate(TextContainer* text) {
    text->capasity += 100;
    free(text->buffer);
    text->buffer = (char*)malloc(text->capasity*sizeof(char));
    if(text->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

int get_command(){
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

TextContainer* get_text() {
    char c;
    TextContainer* input = textContainer_initialize();
    printf("Enter text you want to append. When done, press '@'");
    while ((c = (char)getchar()) != '@') {
        while (input->current_size + 1 > input->capasity){
            memory_reallocate(input);
        }
        if (c != '\n') {
            input->buffer[input->current_size] = (char)c;
            input->current_size++;
        }
    }
    input->buffer[input->current_size] = '\0';
    return input;
}

void append_text(TextContainer* existing_text, TextContainer* text_to_append) {
    strcpy(existing_text->buffer+existing_text->current_size, text_to_append->buffer);
    existing_text->current_size += text_to_append->current_size;
    printf("Text appended\n");
    free(text_to_append->buffer);
    free(text_to_append);
}

void start_new_line(TextContainer* existing_text) {
    strcpy(existing_text->buffer+existing_text->current_size, "\n");
    printf("New line started\n");
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
    int command;
    TextContainer* text_storage = textContainer_initialize();
    do {
        command = get_command();
        switch (command) {
            case 1: {
                TextContainer* text_to_append = get_text();
                append_text(text_storage, text_to_append);
                break;
            }
            case 2: {
                start_new_line(text_storage);
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