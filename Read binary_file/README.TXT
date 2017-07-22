Summary
=======
    Parse a binary file and output a text summary.

Constraints
===========
    - Code must be written in C or C++.
    - No third party libraries may be used (e.g.: Boost, Microsoft Runtime Library, etc.)
    - Use only the C or C++ standard libraries (including STL).

Files Provided
==============
    test1.bin: example binary file #1
    test2.bin: example binary file #2
    test3.bin: example binary file #3

    test1.out: example output expected for test1.bin

Files Expected
==============
    file_parser.c / file_parser.cpp
    file_parser.h

Details
=======
    Several example binary files are provided that follow the structure described below.  Write a program that takes a filename as its only command line argument and prints the results to std out formatted as follows:
        - The first line of the output should be whether or not the checksum passed ("Checksum passed", "Checksum failed")
        - If the checksum passed, the rest of the file will contain the parsed data.  Print label value pairs separated by a colon for each field, one per line (all numbers should be represented as decimals).
        - An expected output file is provided for the first binary file to demonstrate format.

    File structure (Little Endian):

        size: 4 bytes
        entry count: 2 bytes
        --- entry ---
        first name length: 4 bytes
        first name: first name length bytes
        last name length: 4 bytes
        last name: last name length bytes
        flags: 1 byte
        * age: 1 byte
        * height: 1 byte
        -------------
        zero padding: x bytes
        checksum: 4 bytes

        * = optional

    Field descriptions:

        size: Total number of bytes in the file

        entry count: Number of entries in the file

        entry: 
            first name length: Number of characters in the following first name string since it is not NULL terminated
            first name: Non-null terminate string
            last name length: Number of characters in the following last name string since it is not NULL terminated
            last name: Non-null terminate string
            flags: Bit mask which indicates presence of either age or height fields.  1: age field present, 2: height field present
            age: Age in years.  Optional field.
            height: Height in inches.  Optional field.

        zero padding - The file is zero padded to ensure 4 byte alignment.

        checksum: This value is calculated by summing every four bytes of the data (not including the actual checksum value)
