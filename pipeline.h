#ifndef PIPELINE_H
#define PIPELINE_H

#include "instruction.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

class pipeline
{
	public:
		pipeline(bool f, char* filename);
		
		void init();
		void loop();
		bool parse_line(std::string line, int line_num);
		instruction parse_instruction(std::string instr, std::string p0, std::string p1, std::string p2);
		void print_instructs();
		void print_regs();
		void stop();
	private:
		unsigned int counter;
		int cc;
		bool forward;
		std::ifstream in;
		
		int s[8];
		int t[10];
		
		std::vector<std::string> lines;
		std::vector<instruction> instructions;
		std::map<std::string, int> labels;
		std::map<int*, int> stalled;
};

#endif