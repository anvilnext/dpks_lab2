#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"

using namespace std;

int main(int argc, char* argv[]) {

	//number of arguments
	const int num = 4;

	//short arguments
	const char* args = ":hlv::V:";

	//long arguments that correspond to short
	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},
		{"list", no_argument, 0, 'l'},
		{"version", optional_argument, 0, 'v'},
		{"value", required_argument, 0, 'V'},
		{ 0, 0, 0, 0 }
	};

	//counter and element index
	int a;
	int index;

	//variables to keep output for arguments unique
	bool trigger_h = false;
	bool trigger_l = false;
	bool trigger_v = false;
	bool trigger_V = false;

	//cycle with getopt_long
	while ((a = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (a) {
		case 'h': {
			if (trigger_h == false)
			{
				printf("Arg: Help\n");
				trigger_h = true;
			}
			break;
		};

		case 'l': {
			if (trigger_l == false)
			{
				printf("Arg: List\n");
				trigger_l = true;
			}
			break;
		};

		case 'v': {
			if (trigger_v == false)
			{
				if (optarg == NULL)
				{
					printf("Arg: Version\n");
					trigger_v = true;
				}
				else
				{
					printf("Arg: Version = %s\n", optarg);
					trigger_v = true;
				}
			}
			break;
		};

		case 'V': {
			if (trigger_V == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("Missing argument for -V (--value)\n");
					break;
				}
				else
				{
					printf("Arg: Value = %s\n", optarg);
					trigger_V = true;
				}
			}
			break;
		};

		case '?': {
			printf("Unknown option: %c\n", optopt);
			break;
		}

		case ':': {
			printf("Missing argument for %c\n", optopt);
			break;
		}
		};
	};
	return 0;
};
