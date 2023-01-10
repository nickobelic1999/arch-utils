//
// Created by nickobelic1999 on 12/1/22.
//

#include <iostream>

#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct passwd *pw;
    uid_t uid;
    int c;

    getpwuid(uid);
    pw = getpwuid (uid);
    if (pw)
    {
        puts (pw->pw_name);
        exit (EXIT_SUCCESS);
    }



    return 0;
}
