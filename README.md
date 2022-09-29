# Compiler Design Lab

### Basic:
|SL| 	Problem	 | 	Source Code	 | 	
| -- | 	--------	 | 	--------	 | 	
| 1 | Count number of words, letters, digits, and other characters	| 	<a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/basic/count-word-letter-digit-character.cpp">Code</a>	|
| 2 | Separates letters, digits, and other characters	| 	<a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/basic/separate-letter-digit-character.cpp">Code</a>	|
| 3 | Count how many vowels and consonents are there?	| 	<a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/basic/count-vowel-consonent.cpp">Code</a>	|
| 4 | Find out which vowels and consonents are existed in the above string?	| 	<a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/basic/saparate-vowel-consonent.cpp">Code</a>	|
| 5 | Divide the given string into two separete string, where one string only contains the words started with vowel, and other contains the words started with consonent.	| 	<a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/basic/substring-vowel-consonent.cpp">Code</a> |


### Lexical Analyzer
| SL |Problem | Source Code |
| -- |--------| --------- |
| 1 | Lexical Analyzer | <a href="https://github.com/fahimahammed/compiler-design-lab/blob/main/lexical-analyzer/lexical-analyzer.cpp">Code</a> |
| 2 | Build a lexical analyzer implementing the following regualar expressions: | <a href="#">Code</a> |
|  | a) Integer Variable = (i-nI-N)(a-zA-Z0-9) |  |
|  | b) ShortInt Number = (1-9) / (1-9)(0-9) / (1-9)(0-9)(0-9) / (1-9)(0-9)(0-9)(0-9) |  |
|  | c) LongInt Number = (1-9)(0-9)(0-9)(0-9)+ |  |
|  | d) Float Variable = (a-hA-Ho-zO-Z)(a-zA-Z)-9 |  |
|  | e) Float Number = 0.(0-9)(0-9) / (1-9)(0-9)*.(0-9)(0-9) |  |
|  | f) Double Number = 0.(0-9)(0-9)(0-9)+ / (1-9)(0-9)*.(0-9)(0-9)(0-9)+ |  |
|  | g) Character Variable = ch_(a-zA-Z0-9)(a-zA-Z0-9)* |  |
|  | h) Binary Variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)* |  |
|  | i) Binary Number = 0(0 / 1)(0 / 1)* |  |
|  | Invalid input or Undefined = Otherwise |  |
| 3 | Write a program to recognize C which converts a word of C++ Program to its equivalent token: i) Keyword, ii) Indentifier, iii) Operator & iv) Constant | <a href="#">Code</a> |
| 4 | Write a program to generate a syntax tree for the sentence `a+b*c` with the following grammer: `E -> E+E / E-E / E*E / E/E / (E) / a / b / c | <a href="#">Code</a> |
| 5 | Write a program which checks a validity of C++ expression derived by the following grammer: E -> E A E / (E) / ID; A -> + / - / * / /; ID -> any valid identifier / any valid integer  |<a href="#">Code</a> |
| 6 | Write a program that converts the c++ expression to an intermeditate code of Post-fix notation form. | <a href="#">Code</a> |