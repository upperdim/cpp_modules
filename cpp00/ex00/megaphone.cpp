#include <iostream>
#include <cctype> // islower(), toupper()

static void	convertToUpper(char *s) {
	int i = 0;
	while (s[i] != '\0') {
		if (std::islower(s[i]))
			s[i] = std::toupper(s[i]);
		++i;
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		convertToUpper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
}
