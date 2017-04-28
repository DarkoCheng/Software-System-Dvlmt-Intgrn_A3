#!/usr/bin/python

import os, sys

# open a fifo queue for reading, read 10 strings, close fifo
# reads text from another queue sent by the reader program
filename = "q1"
pipe = open(filename, "r")
line1 = pipe.readline() [:-1]
line = pipe.readline()
os.remove(filename)
f1 = file("q2", "w+")
str1 = "<HTML>\n\n\n"
str3 = "<head>\n<title>"
str4 = "</title>\n</head>\n\n<body>\n"
str5 = str3+line1+str4
str2 = "\n</body>\n\n</HTML>"
line = str1+str5+line+str2

# read info file
line1 = line1 + ".info"
f = open (line1)
while True:
	line2 = f.readline()
	if line2:
		line2 = line2.strip('\n')
		if line2[0] == 'I':
			str6 = line2[2:len(line)]
			str7 = "<I>"
			str8 = "</I>"
			str9 = str7+str6+str8
			line = line.replace(str6, str9)
			#f1.writelines(line);
		elif line2[0] == 'B':
			str6 = line2[2:len(line)]
			str7 = "<B>"
			str8 = "</B>"
			str9 = str7+str6+str8
			line = line.replace(str6, str9)
			#f1.writelines(line);
		elif line2[0] == 'U':
			str6 = line2[2:len(line)]
			str7 = "<U>"
			str8 = "</U>"
			str9 = str7+str6+str8
			line = line.replace(str6, str9)
			#f1.writelines(line);
	else:
		break;
f1.writelines(line);
f.close()
f1.close();


#print line