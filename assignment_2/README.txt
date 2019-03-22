Name
    MyCompress
Synopsis

    MyCompress <flag> [<input-filename>] [<output-filename>]

Description
    Compresses and decompresses text files.

    If no output filename is given it writes to standard output (stdout).
    If no input filename is given it reads from standard input (stdin).
    Options for <flag>
    -h  give this usage information and exit
    -c  compress the input file and write result to output file
    -d  decompress the input file and write result to output file

Example Usage
    MyCompress -c input.txt output.txt # compress input.txt to output.txt
    cat output.txt | MyCompress -d # read from stdin, decompress to stdout
