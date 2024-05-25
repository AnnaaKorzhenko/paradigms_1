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

void textContainer_initialize(TextContainer* text) {
    text->current_size = 0;
    text->capasity = 100;
    text->buffer = (char*)malloc(text->capasity * sizeof(char));
    if(text->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

}
void memory_reallocate(TextContainer* text) {
    text->capasity += 100;
    text->buffer = (char*)realloc(text->buffer, text->capasity*sizeof(char));
    if(text->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

/*void memory_deallocate(char* text) {
    free(text);
}*/

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

char* get_text() {
    char c;
    TextContainer* input = (TextContainer*)malloc(sizeof(TextContainer));
    textContainer_initialize(input);
    printf("Enter text you want to append. When done, press '@'");
    while ((c = (char)getchar()) != '@') {
        while (input->current_size + 1 >= input->capasity){
            memory_reallocate(input);
        }
        input->buffer[input->current_size] = (char)c;
        input->current_size++;
    }
    input->buffer[input->current_size] = '\0';
    return input->buffer;
}

void append_text(TextContainer* text) {
    char* text_to_append = get_text();
    printf("Enter text you want to append:\n");
    printf("Text appended\n");
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
    TextContainer text;
    textContainer_initialize(&text);
    int command;
    do {
        command = get_command();
        switch (command) {
            case 1: {
                /*append_text(&text);*/
                char* input;
                input = get_text();
                printf(input);
                printf("IT WOOOOOOOOORKS");
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