#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void usage(char* cmd){
    fprintf(stderr,"usage: \n");
    fprintf(stderr, " %s -h        :show help\n", cmd);
    fprintf(stderr, " %s -b        :say good-bye\n", cmd);
    fprintf(stderr, " %s -n <name> :greeting to <name>\n", cmd);
}

int main(int argc, char* argv[]){
    int opt;
    char* greeting = "Hello, ";
    char* target = "World";

    int option_index = 0;
    printf("%d", argc);
    printf("%s", argv[1]);
    struct option long_option[]={
        {"bye", 0,0, 'b'},{"help",0,0,'h'},{"name",1,0,'n'},{0,0,0,0}
    };
    while((opt=getopt_long(argc,argv,"bhn:",long_option,&option_index)) != -1)
    {
        switch(opt)
        {
            case 'b':
            greeting = "Good-bye, ";
            break;

            case 'n':
            target=optarg;
            break;

            case 'h': /*fall-through */
            default:
            usage(argv[0]);
            return EXIT_FAILURE;


        }
    }
    printf("%s%s!\n", greeting,target);
    return EXIT_SUCCESS;
}