#include <iostream>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct programArguements {
    string some_str;
    int list[5];
    int integer;
    string file;
} program_args;

static const char *optString = "s:l:i:f:h?";

static const struct option longOpts[] = {
        { "some_str", required_argument, nullptr, 's'},
        { "help", no_argument, nullptr, 'h'},
        { "list", optional_argument, nullptr, 'l'},
        { "integer", optional_argument, nullptr, 'i'},
        { "file", optional_argument, nullptr, 'f'},
        {nullptr, no_argument, nullptr, 0}
};

void show_help()
{
    puts("Arguments: "
         "\nsome_str - enable some_str mode of program; "
         "\nhelp - display help "
         "\nlist - list of values "
         "\ninteger - optional flag "
         "\nfile - save result to file");
    exit ( EXIT_FAILURE );
}
void show_used_args()
{
    cout << "program_args.some_str = " << program_args.some_str << endl;
    cout << "program_args.list = " << program_args.list[0] << ", " <<
         program_args.list[1] << ", " <<
         program_args.list[2] << ", " <<
         program_args.list[3] << ", " <<
         program_args.list[4] << "." << endl;
    cout << "program_args.integer = " << program_args.integer << endl;
    cout << "program_args.file = " << program_args.file << endl;
}
int main( int argc, char *argv[] )
{
    int opt = 0;
    int longIndex = 0;
    program_args.some_str = "Hello everybody!";
    program_args.list[0] = 6;
    program_args.list[1] = 6;
    program_args.list[2] = 6;
    program_args.list[3] = 6;
    program_args.list[4] = 6;
    program_args.integer = 6;
    program_args.file = "log.txt";
    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    while( opt != -1 ) {
        switch( opt ) {
            case 'h':
                show_help();
                break;
            case 'i':
                program_args.integer = atoi(optarg);
                break;
            case 's':
                program_args.some_str = optarg;
                break;
            case 'l':
                program_args.list[0] = optarg[0] - '0';
                program_args.list[1] = optarg[2] - '0';
                program_args.list[2] = optarg[4] - '0';
                program_args.list[3] = optarg[6] - '0';
                program_args.list[4] = optarg[8] - '0';
                break;
            case 'f':
                program_args.file = optarg;
                break;
            case '?':
                break;
            default:
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }
    show_used_args();
    return EXIT_SUCCESS;
}