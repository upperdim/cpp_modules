/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:33:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/20 07:49:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[]) {
	// Get 3 arguments <filename>, <targetStr>, <replacementStr>
	if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <target string> <replacement string>" << std::endl;
        return 0;
    }
	
	std::string filename = argv[1];
	std::string newFilename = filename + ".replace";
	std::string targetStr = argv[2];
	std::string replacementStr = argv[3];
	
	// Open file <filename> (FORBIDDEN: C file manipulation functions)
	std::ifstream ifs(filename.c_str());
	if (!ifs) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
        return EXIT_FAILURE;
	}
	
	// Replace all strings <s1> with <s2> (FORBIDDEN: std::string::replace())
	std::stringstream strStream;
	strStream << ifs.rdbuf();
	ifs.close();
	std::string buffer = strStream.str();

	size_t i = 0;
	i = buffer.find(targetStr, i);   // look for a match
	while (i != std::string::npos) { // if match is found
		// Found a match, handle
		buffer.erase(i, targetStr.length());
		buffer.insert(i,replacementStr);
		i += replacementStr.length();
		
		// Look for the next match
		i = buffer.find(targetStr, i);
	}
	
	// Save file <filename>.replace	(FORBIDDEN: C file manipulation functions)
	std::ofstream ofs(newFilename.c_str());
	if (!ofs) {
        std::cerr << "Error: Could not create file " << newFilename << std::endl;
        return EXIT_FAILURE;
    }

	ofs << buffer;
	ofs.close();
}
