EXECUTABLE := ex08balancedtrees
INSTRUCTOR_MAIN := instructor_main
SRC_DIR := .
OBJ_DIR := .
LDFLAGS :=
CPPFLAGS :=
CXXFLAGS :=

all: Node.cpp main.cpp
	g++ -o $(EXECUTABLE) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test-all: test01out.txt

test01out.txt:
	./$(EXECUTABLE) < ex08-balanced-trees-testcases/test01in.txt > test01out.txt
	diff -i -B test01out.txt ex08-balanced-trees-testcases/test01expected.txt

# Delete dependent files
# You can type "make clean" before committing to Git
clean:
	rm -f $(EXECUTABLE)
	rm -f *.o
	rm -f *out.txt