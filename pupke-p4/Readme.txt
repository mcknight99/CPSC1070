Samuel Pupke
C16563633
spupke@clemson.edu / spupke@g.clemson.edu

Usage of PhoneNum:
$ executableName.exe <inputFile> <outputFile> <optional flags>
Default use cases invlove the <inputFile> containing sequences of T9 presses whose conversion to words happens in the <outputFile>

These optional flags can be included in the command line:
-l : flips the <inputFile> to be words or phreases that will be translated into T9 presses that is converted to the <outputFile>
-h : brings up a short help menu (a version of this readme)

Sample Usage:
$ ./PhoneNum.exe input1.txt output1.txt
$ ./PhoneNum.exe input2.txt -L output2.txt
