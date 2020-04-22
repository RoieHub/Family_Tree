CXX=clang++-9
CXXFLAGS=-std=c++2a

all: a.out
	./a.out

a.out: Fnode.o FamilyTree.o
	$(CXX) $(CXXFLAGS) FamilyTree.o -o a.out

Fnode.o: Fnode.cpp Fnode.hpp
	$(CXX) $(CXXFLAGS) --compile Fnode.cpp -o Fnode.o

FamilyTree.o:FamilyTree.cpp FamilyTree.hpp Fnode.hpp
	$(CXX) $(CXXFLAGS) --compile FamilyTree.cpp -o FamilyTree.o



clean:
	rm -f *.o a.out

