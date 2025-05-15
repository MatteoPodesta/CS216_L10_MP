
**5/14/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
 * public repo
* 56, 58 function call for the sake of a function call? -1
*  73 const int& intObject    ints are not objects in C++ , why const int by ref?
*  79-81 waste of memory should have been static -2
* modularization: each menu option should have its own function with a possible exception of the QUIT case; as a rule of thumb, if a case in a switch has more than 2 statements, make it a function; -2
* does not compile -5
* inadequate and/ insufficient test data/ not all possible scenarios and edge cases have been tested; e.g., each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros, negative numbers, etc; must test all created functions -5
* uses “whole” see assignment -10
*  operator overload functions  implementation convoluted, redundant and inefficient -20
* poor Id(s)  and/or inconsistent naming convention; ids should be self-documenting and as short as possible; use verbs for functions and nouns for variables; use camel-casing for variables (errorMessage) enum & const should be in upper case with words separated by “_”, e.g., MAX_TERMS, PRINT_RECORDS; pointer variables should start with p( if single)  or pp( if double pointer); flags isValid ( clearly what true would mean); if copying – e.g rhsQueue or scrQueue ; do not use IDs that are same as or very similar to C++  keywords and functions; no need to call an array “array”- it is obvious -2
```text
            			Fraction cow(2, 3, 5);
			Fraction gambling(1, 4, 5);
			Fraction Cheese;
			Cheese = (cow - gambling);
```
