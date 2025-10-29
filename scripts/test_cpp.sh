#!/bin/bash

ALL=$1        # True or False
PROBLEM=$2    # Problem number (if ALL=False)

cd cpp || { echo "cpp directory not found"; exit 1; }

# Function to test a single problem
run_tests() {
    local name=$1
    local test_dir="../tests/$name"
    local exe="./$name.o"

    if [ ! -d "$test_dir" ]; then
        echo "No test folder found for problem $name"
        return
    fi

    echo "Testing problem $name..."

    # Compile
    g++ -O2 "$name.cpp" -o "$name".o
    if [ $? -ne 0 ]; then
        echo "Compilation failed for $name.cpp"
        return
    fi

    # Iterate test cases
    for inp_file in "$test_dir"/*.inp; do
        test_num=$(basename "$inp_file" .inp)
        out_file="$test_dir/$test_num.out"
        ans_file="$test_dir/$test_num.ans"

        # Run executable
        "$exe" < "$inp_file" > "$out_file"

        # Compare outputs
        if ! diff -q -b -B --strip-trailing-cr "$out_file" "$ans_file" > /dev/null; then
            echo "Test $test_num failed"
            echo "   Differences:"
            diff "$out_file" "$ans_file"
            echo "   (stopping early)"
            return
        fi
    done

    echo "All tests passed for $name!"
}

# Run all problems or one
if [ "$ALL" = "True" ]; then
    for cpp_file in *.cpp; do
        problem_name="${cpp_file%.cpp}"
        run_tests "$problem_name"
        echo
    done
else
    if [ -z "$PROBLEM" ]; then
        echo "Please provide problem number when ALL=False"
        exit 1
    fi
    run_tests "$PROBLEM"
fi
