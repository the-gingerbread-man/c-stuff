### Expand
Takes an string "input," and outputs a string with shorthand notations (i.e. a-z) expanded into the full series of ASCII characters. A leading or trailing '-' should be taker literally, as part of the range to be expanded.

Example cases:
a-z -> abcdefghijklmnopqrstuvwxyz
abc-qrs -> abcdefghijklmnopqrs
a-g-z -> abcdefghijklmnopqrstuvwxyz
0-9 -> 012345689
--2 -> -./012
I know all of the letters from A-Z! -> I know all the letters from ABCDEFGHIJKLMNOPQRSTUVWXYZ!

Notes: Expand ranges of ASCII chars from '!' (33) to '~' (126)

Sub-functions:
expand-all: Implements the above functionality, and handles unusual cases such as "a-i-z" without duplicating the middle character.
expand: Takes a pointer to a string and two ASCII chars, and writes an expansion of the range between the ASCII chars to the string.

Algorithm:
1) Loop through "input" until a '-' character is found.
2) Isolate the section to be expanded ("a-q-r").
3) Write everything from the end of the last expansion to the character before the start of the current section to be expanded to the output.
4) Determine if the expansion is "unusual" by checking to see whether the character before range-start of the character following range-end is a '-'.
	If so, it is either a hyphen literal, to be treated as such, or a multipart range.
5) Call expand() to handle the simple range given.
6) expand() loops through each ASCII character between start and end and writes it to its' output string. It then adds a string terminator ('\0') and returns 0, indicating success.
7) The output from expand() is copied to the output string of expand-all().
8) Rinse and repeat.
