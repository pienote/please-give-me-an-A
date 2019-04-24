#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <vector>

class pipeline
{
	public:
		pipeline(bool f, char* filename);
		
		void init();
		void loop();
		void print_instructs();
		void print_regs();
		void stop();
	private:
		int counter;
		int cc;
		bool forward;
		std::ifstream in;
		
		int s[8];
		int t[10];
		
		std::vector<instruction> instructs;
		std::map<std::string, int> labels;
};

#endif