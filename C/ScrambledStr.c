#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* getSubStr(char* str,int startInd, int lastInd) {
    char* substr = malloc(strlen(str) + 1);
    int c = 0;
    for(int i = startInd; i <= lastInd; i++ ) {
        substr[c] = str[i];
        c++;
    }
    substr[c] = '\0';
    return substr;
}

bool solve(char* a,char* b) {
    if(strcmp(a,b) == 0) return true;
    if(strlen(a) <= 1 || strlen(b) <= 1) return false;

    int n = strlen(a);
    for(int i = 1; i < n; i++) { //Need to start the for loop from index 1 to make a substring otherwise it will cause stackoverflow
    
        //a = gr eat -> b = ate gr first condition checks the scramble when swaps happened and getting substring.
        //so 'gr' of a checks with 'gr' of b and 'eat' of a checks with 'ate' of b.
        bool cond1 = solve(getSubStr(a,0,i), getSubStr(b,n - i, i)) && solve(getSubStr(a,i ,n - i), getSubStr(b,0, n - i));

        //a = gr eat -> b = gr eat first condition checks the scramble when swaps does not happened and getting substring.
        //so 'gr' of a checks with 'gr' of b and 'eat' of a checks with 'eat' of b.
        bool cond2 = solve(getSubStr(a,0,i), getSubStr(b,0, i)) && solve(getSubStr(a,i ,n - i), getSubStr(b,i, n - i));
        if(cond1 || cond2)
            return true;
    } 
    return false;
}

int main() {
    char* a = "coder";
    char* b = "ocder";
    char* ss = "This is a scramble string";
    char* notSS = "This is NOT a scramble string";
    if(solve(a,b) == true) {
        printf("true");
    }
    else {
        printf("false");
    }
    return 0;
}