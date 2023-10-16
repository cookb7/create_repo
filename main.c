#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>



int create_file(char *repo_name) {
    FILE *file = fopen("/home/brendan/Templates/python_main_template.txt", "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    char current_path[1024];
    if (getcwd(current_path, sizeof(current_path)) == NULL) {
        perror("getcwd() error\n");
        return 1;
    }

    char repo_path[1024] = "/home/brendan/Documents/";
    strcat(repo_path, repo_name);
    
    if (chdir(repo_path) == 0) {
        printf("Directory changed.\n");
    } else {
        printf("Unable to change directory.\n");
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

    if (chdir(current_path) == 0) {
        printf("Directory changed back.\n");
    } else {
        printf("Unable to change directory back.\n");
        return 1;
    }

    return 0;
}

int create_git_repo(char *repo_name) {
    const char* repo_path = "/home/brendan/Documents";
    char current_path[1024];
    char git_call[1024] = "git init ";

    if (getcwd(current_path, sizeof(current_path)) == NULL) {
        perror("getcwd() error\n");
        return 1;
    }

    if (chdir(repo_path) == 0) {

        strcat(git_call, repo_name);

        int result = system(git_call);

        if (result == 0) {
            printf("Git repo created at %s\n", repo_path);
        } else {
            printf("Failed to create repo.\n");
            return 1;
        }

        if (chdir(current_path) != 0) {
            printf("Failed to change back to current directory.\n");
        }
    } else {
        printf("Failed to change to repo destination.\n");
        return 1;
    }

    return 0;
}

int main() {
    char repo_name[100];
    printf("Enter name of repo you would like to create: ");
    scanf("%s", repo_name);
    create_git_repo(repo_name);
    create_file(repo_name);
}