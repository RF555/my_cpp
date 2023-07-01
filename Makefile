all: q1 q2 q3 q4 q5 q6 q7 q8 q9

q1: q1.cpp
	clang++ -g ./q1.cpp -o "q1"
	printf "\n"
	./q1

q2: q2.cpp
	clang++ -g ./q2.cpp -o "q2"
	printf "\n"
	./q2

q3: q3.cpp
	clang++ -g ./q3.cpp -o "q3"
	printf "\n"
	./q3

q4: q4.cpp
	clang++ -g ./q4.cpp -o "q4"
	printf "\n"
	./q4

q5: q5.cpp
	clang++ -g ./q5.cpp -o "q5"
	printf "\n"
	./q5

q6: q6.cpp
	clang++ -g ./q6.cpp -o "q6"
	printf "\n"
	./q6

q7: q7.cpp
	clang++ -g ./q7.cpp -o "q7"
	printf "\n"
	./q7

q8: q8.cpp
	clang++ -g ./q8.cpp -o "q8"
	printf "\n"
	./q8

q9: q9.cpp
	clang++ -g ./q9.cpp -o "q9"
	printf "\n"
	./q9

clean:
	rm -f q1 q2 q3 q4 q5 q6 q7 q8 q9