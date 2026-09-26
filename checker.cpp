#include <iostream>
#include <string>
#include <vector>
#include "assignment_1.h"

using namespace std;

bool checkVectorInt(const vector<int>& actual,
                    const vector<int>& expected,
                    const string& testName) {
    if (actual == expected) {
        cout << "[PASS] " << testName << '\n';
        return true;
    }

    cout << "[FAIL] " << testName << '\n';
    cout << "  Expected: ";
    for (size_t i = 0; i < expected.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << expected[i];
    }
    cout << '\n';

    cout << "  Received: ";
    for (size_t i = 0; i < actual.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << actual[i];
    }
    cout << '\n';

    return false;
}

bool checkVectorString(const vector<string>& actual,
                       const vector<string>& expected,
                       const string& testName) {
    if (actual == expected) {
        cout << "[PASS] " << testName << '\n';
        return true;
    }

    cout << "[FAIL] " << testName << '\n';
    cout << "  Expected:\n";
    for (const string& value : expected) {
        cout << "    " << value << '\n';
    }

    cout << "  Received:\n";
    for (const string& value : actual) {
        cout << "    " << value << '\n';
    }

    return false;
}

bool checkString(const string& actual,
                 const string& expected,
                 const string& testName) {
    if (actual == expected) {
        cout << "[PASS] " << testName << '\n';
        return true;
    }

    cout << "[FAIL] " << testName << '\n';
    cout << "  Expected: " << expected << '\n';
    cout << "  Received: " << actual << '\n';
    return false;
}

bool test_as_1_1() {
    bool allPassed = true;

	// [example 1, 2, 3]
    {
        vector<int> input = {3, 9, 7, 5, 4};
        const vector<int> expected = {3, 4, 5, 7, 9};
        as_1_1(static_cast<int>(input.size()), input);
        allPassed = checkVectorInt(input, expected, "as_1_1 Example 1") && allPassed;
    }

    {
        vector<int> input = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        as_1_1(static_cast<int>(input.size()), input);
        allPassed = checkVectorInt(input, expected, "as_1_1 Example 2") && allPassed;
    }

    {
        vector<int> input = {100, 9867, 545, -80, -123, 456};
        const vector<int> expected = {-123, -80, 100, 456, 545, 9867};
        as_1_1(static_cast<int>(input.size()), input);
        allPassed = checkVectorInt(input, expected, "as_1_1 Example 3") && allPassed;
    }

	// (Hidden) [example 4,5,6]

    return allPassed;
}

bool test_as_1_2() {
    bool allPassed = true;
    
    
	//[example 1, 2, 3]
    {
        vector<string> input = {"banana", "apple", "cherry"};
        const vector<string> expected = {"apple", "banana", "cherry"};
        as_1_2(static_cast<int>(input.size()), input);
        allPassed = checkVectorString(input, expected, "as_1_2 Example 1") && allPassed;
    }

    {
        vector<string> input = {"10", "2", "1", "20", "3"};
        const vector<string> expected = {"1", "10", "2", "20", "3"};
        as_1_2(static_cast<int>(input.size()), input);
        allPassed = checkVectorString(input, expected, "as_1_2 Example 2") && allPassed;
    }

    {
        vector<string> input = {"aa", "10a", "a", "100", "bb", "bc"};
        const vector<string> expected = {"100", "10a", "a", "aa", "bb", "bc"};
        as_1_2(static_cast<int>(input.size()), input);
        allPassed = checkVectorString(input, expected, "as_1_2 Example 3") && allPassed;
    }
    
    //(Hidden) [example 4, 5, 6]

    return allPassed;
}

bool test_as_1_3() {
    bool allPassed = true;

	// [example 1, 2, 3]
    allPassed = checkString(
        as_1_3(2, 10, "101"),
        "5",
        "as_1_3 Example 1"
    ) && allPassed;

    allPassed = checkString(
        as_1_3(10, 2, "91"),
        "1011011",
        "as_1_3 Example 2"
    ) && allPassed;

    allPassed = checkString(
        as_1_3(10, 10, "12345"),
        "12345",
        "as_1_3 Example 3"
    ) && allPassed;

    return allPassed;
}

bool test_as_1_4() {
    bool allPassed = true;

	// [example 1, 2, 3]
    allPassed = checkString(
        as_1_4(2, 16, "1011"),
        "B",
        "as_1_4 Example 1"
    ) && allPassed;

    allPassed = checkString(
        as_1_4(10, 7, "91"),
        "160",
        "as_1_4 Example 2"
    ) && allPassed;

    allPassed = checkString(
        as_1_4(16, 15, "ABEFCDEAF"),
        "1301DC45D9",
        "as_1_4 Example 3"
    ) && allPassed;


	//(Hidden) [example 4, 5, 6, 7]
    return allPassed;
}

int main() {
    cout << "========================================\n";
    cout << "Assignment 1 Checker\n";
    cout << "========================================\n\n";

    cout << "[Problem 1] Number Sorting\n";
    const bool result1 = test_as_1_1();
    cout << '\n';

    cout << "[Problem 2] Lexicographical Sorting\n";
    const bool result2 = test_as_1_2();
    cout << '\n';

    cout << "[Problem 3] Base Conversion Easy\n";
    const bool result3 = test_as_1_3();
    cout << '\n';

    cout << "[Problem 4] Base Conversion Hard\n";
    const bool result4 = test_as_1_4();
    cout << '\n';

    const bool allPassed = result1 && result2 && result3 && result4;

    cout << "========================================\n";
    if (allPassed) {
        cout << "All public tests passed.\n";
    } else {
        cout << "Some public tests failed.\n";
    }
    cout << "========================================\n";

    return allPassed ? 0 : 1;
}
