#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int rez=0;
	map <string, bool> used;

	int option_index = -1;
	const char* short_options = "hlvV::?";
	
	const struct option long_options[] = {
	//no argument            0
	//required argument      1
	//optional argument      2
	
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
	{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };
    


	while ((val = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (val){
		case 'h': {
			if (used["h"] == false) {
				printf("help\n"); 
				used["h"] = true;
			} 
			break;
		}
		case 'l': {
			if (used["l"] == false) {
				printf("list\n"); 
				used["l"] = true;
			}
			break;
		}
		case 'v': {
			if (used["v"] == false) {
				printf("version\n"); 
				used["v"] = true;
			}
			break;
		}
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("value\n"); 
					used["V"] = true;
				} else {
					printf("value\n", optarg); 
					used["V"] = true;
				}
				
			}
			break;
		}
		case '?': default: {
				printf("not found\n", val);
				break;
			}
        };
		option_index = -1;
	};
};

