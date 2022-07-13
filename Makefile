build:
	g++ functions.h person.h problem.cpp -o exec_problem && ./exec_problem < test.txt

clean:
	rm exec_problem
