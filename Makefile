SRC = main.cpp src/*.cpp src/keccak/*.c
TARGET = bin/parser
TEST_DIR = test

$(TARGET): $(SRC)
	g++ -std=c++11 $(SRC)
	rm src/*.gch
	mv a.out $(TARGET)

clean:
	rm -f $(TARGET)
	make clean -C $(TEST_DIR)

test:
	make -C $(TEST_DIR)
	# Run tests
	$(TEST_DIR)/testable_test
	$(TEST_DIR)/tools_test
	# Clean up
	make clean -C $(TEST_DIR)

check:
	cppcheck --enable=all --inconclusive --std=posix src

.PHONY: clean test
