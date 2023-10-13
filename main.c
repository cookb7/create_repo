#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



int create_file() {
    FILE *file = fopen("/home/brendan/Templates/python_main_template.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    FILE *py_file = fopen("main.py", "w");
    if (py_file == NULL) {
        printf("Unable to open Python file.\n");
        return 1;
    }

    char c;

    while ((c = fgetc(file)) != EOF) {
        fputc(c, py_file);
    }
    fclose(file);
    fclose(py_file);

    return 0;
}

int create_git_repo() {
    const char* repo_path = "/home/brendan/Documents";

    if (chdir(repo_path) == 0) {

        int result = system("git init new_repo");

        if (result == 0) {
            printf("Git repo created at %s\n", repo_path);
        } else {
            printf("Failed to create repo.\n");
            return 1;
        }
    }
    return 0;
}

int move_file() {
    const char* repo_path = "/home/brendan/Documents/new_repo";

    
}


int main() {
    create_git_repo();
    create_file();
}