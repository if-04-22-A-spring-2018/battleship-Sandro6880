CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= battleship.h test_battleship.h test_file_setup.h shortcut.h

TEST = battleship
PROGRAM =

TESTOBJECT = battleship_test_driver.o
MAINOBJECT =
OBJS = shortcut.o battleship.o test_battleship.o test_file_setup.o

DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp battleship.cpp.sample battleship.cpp
	cp battleship.h.sample battleship.h

#sets project as assignment
setassignment:
	cp battleship.cpp.assignment battleship.cpp
	cp battleship.h.assignment battleship.h

# defines current state of project as sample solution
definesample:
	cp battleship.cpp battleship.cpp.sample
	cp battleship.h battleship.h.sample

# defines current sate of project as assignment
defineassignment:
	cp battleship.cpp battleship.cpp.assignment
	cp battleship.h battleship.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
