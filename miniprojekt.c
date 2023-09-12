#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createCFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        printf("A '%s' fájl már létezik. Nem hozzuk létre újra.\n", filename);
        fclose(file);
        return;
    }

    file = fopen(filename, "w");
    if (!file) {
        perror("Hiba a fájl létrehozásakor");
        return;
    }

    fprintf(file, "#include <stdio.h>\n\n");
    fprintf(file, "int main() {\n");
    fprintf(file, "    printf(\"Hello, World!\\n\");\n");
    fprintf(file, "    return 0;\n");
    fprintf(file, "}\n");

    fclose(file);

    printf("A '%s' fájl létrehozva és az alap C program beleírva.\n", filename);
}

void createJavaFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        printf("A '%s' fájl már létezik. Nem hozzuk létre újra.\n", filename);
        fclose(file);
        return;
    }

    file = fopen(filename, "w");
    if (!file) {
        perror("Hiba a fájl létrehozásakor");
        return;
    }

    fprintf(file, "public class Main {\n");
    fprintf(file, "    public static void main(String[] args) {\n");
    fprintf(file, "        System.out.println(\"Hello, World!\");\n");
    fprintf(file, "    }\n");
    fprintf(file, "}\n");

    fclose(file);

    printf("A '%s' fájl létrehozva és az alap Java program beleírva.\n", filename);
}

void createBashScript(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        printf("A '%s' fájl már létezik. Nem hozzuk létre újra.\n", filename);
        fclose(file);
        return;
    }

    file = fopen(filename, "w");
    if (!file) {
        perror("Hiba a fájl létrehozásakor");
        return;
    }

    fprintf(file, "#!/bin/bash\n");
    fprintf(file, "echo \"Hello, World!\"\n");

    fclose(file);

    system("chmod +x filename");

    printf("A '%s' fájl létrehozva és az alap Bash parancs beleírva.\n", filename);
}

void printFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Hiba a fájl megnyitásakor");
        return;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2 || strcmp(argv[1], "alap") == 0) {
        printf("alap v0.0.1\n");
        puts("");
        printf("Használat: <nyelv>\n");
        puts("");
        printf("Elérhető nyelvek:\n");
        puts("");
        printf("* c         - C alap program (main.c)\n");
        printf("* java      - Java alap program (Main.java)\n");
        printf("* sh        - Bash alap program (main.sh)\n");
        puts("");
        return 1;
    }

    char *nyelv = argv[1];
    int stdoutFlag = 0;

    if (argc == 3 && strcmp(argv[2], "--stdout") == 0) {
        stdoutFlag = 1;
    }

    if (strcmp(nyelv, "c") == 0) {
        createCFile("main.c");
    } else if (strcmp(nyelv, "java") == 0) {
        createJavaFile("Main.java");
    } else if (strcmp(nyelv, "sh") == 0) {
        createBashScript("main.sh");
    } else {
        printf("Ismeretlen nyelv: %s\n", nyelv);
        return 1;
    }

    if (stdoutFlag) {
        if (strcmp(nyelv, "c") == 0) {
            printFileContent("main.c");
        } else if (strcmp(nyelv, "java") == 0) {
            printFileContent("Main.java");
        } else if (strcmp(nyelv, "sh") == 0) {
            printFileContent("main.sh");
        }
    }

    return 0;
}
