EXECUTABLE := ex05circlelist
INSTRUCTOR_MAIN := instructor_main
SRC_DIR := .
OBJ_DIR := .
LDFLAGS :=
CPPFLAGS :=
CXXFLAGS :=

all: CNode.h CircleList.h OutOfBoundsException.cpp CircleListMain.cpp
	g++ -o $(EXECUTABLE) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test-all: test01out.txt test02out.txt test03out.txt test04out.txt test05out.txt test06out.txt

test01out.txt:
	./$(EXECUTABLE) < test1in.txt > test1out.txt
	diff -i -B test1out.txt test1expected.txt

test02out.txt:
	./$(EXECUTABLE) < test2in.txt > test2out.txt
	diff -i -B test2out.txt test2expected.txt

test03out.txt:
	./$(EXECUTABLE) < test3in.txt > test3out.txt
	diff -i -B test3out.txt test3expected.txt

test04out.txt:
	./$(EXECUTABLE) < test4in.txt > test4out.txt
	diff -i -B test4out.txt test4expected.txt

test05out.txt:
	./$(EXECUTABLE) < test5in.txt > test5out.txt
	diff -i -B test5out.txt test5expected.txt

test06out.txt:
	./$(EXECUTABLE) < test6in.txt > test6out.txt
	diff -i -B test6out.txt test6expected.txt

# Delete dependent files
# You can type "make clean" before committing to Git
clean:
	rm -f $(EXECUTABLE)
	rm -f *.o
	rm -f *out.txt

# Default target: Link obj.files to get executable
catch2-runner: CircleList.o  Catch2TestRunner.o
	g++ -o $(CATCH2_RUNNER) $^
	./$(CATCH2_RUNNER)
