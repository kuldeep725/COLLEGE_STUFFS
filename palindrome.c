#include<stdio.h>
#include<string.h>

int NoMatch (char *s, char *t) {

    int i;
    int j;

    for (i = 0; i < strlen(s); i++) {
        for (j = 0; j < strlen(t); j++) {
            if (s[i] == t[j]) {
                return 0;
            }
        }
        j = i;
        for (j = i + 1; j < strlen(s); j++) {
            if (s[i] == s[j])
                return 0;
        }
    }
    return 1;

}

int doesNotExist (char *t, char c) {

    int i;
    for (i = 0; i < strlen(t); i++) {
        if (t[i] == c)
            return 0;
    }
    return 1;

}

int mostTypicalCondition (char *s, char *t) {

    int i;
    int j;
    int flag;
    int count = 0;
    char *ptr;

    for (i = 0; i < strlen(s); i++) {
        flag = 0;
        for (j = 0; j < strlen(t); j++) {
            if (s[i] == t[j]) {
                flag = 1;
                while (ptr = strchr(t, t[j]))
                    strcpy(ptr, ptr + 1);
                break;
            }
        }
        if (flag == 0) {
            count++;
        }

    }
    printf("count = %d\n", count);
    printf("t = %s\n", t);
    if (ptr == NULL) {
        if (count >= 1) {
            return 1;
        }

    }
    else return 0;
}
int main () {

    int test;
    scanf("%d", &test);

    char s[500];
    char t[500];
    int temp[26];

    while (test--) {

        scanf("%s", s);
        scanf("%s", t);

        if (strstr (t, s) != NULL) {
            printf("1B\n");
        }
        else if (NoMatch (s, t)) {
            printf("2B\n");
        }
        else {
            int i = 0;

            while (i < 26) temp[i++] = 0;

            int flag = 1;
            for (i = 0; i < strlen(s); i++) {

                temp[s[i]-'a']++;
                //printf("temp[%c] = %d\n", s[i], temp[s[i]-'a']);
                if (temp[s[i]-'a'] > 1) {
                    if (doesNotExist(t, s[i])) {
                        printf("1A\n");
                        flag = 0;
                        break;
                    }
                    else {
                        printf("Hello\n");
                        if (mostTypicalCondition (s, t)) {
                            flag = 0;
                            printf("2A\n");
                            break;
                        }
                    }
                }

            }
            if (flag)
                printf("3B\n");
        }

    }

    return 0;
}
