#Jealous of Mirko’s position as head of the village, Borko stormed into his tent 
#and tried to demonstrate Mirko’s incompetence for leadership with a trick.

#Borko puts three opaque cups onto the table next to each other (opening facing down) 
#and a small ball under the leftmost cup. He then swaps two cups in one of three possible ways a number of times.
#Mirko has to tell which cup the ball ends up under.

#Wise Mirko grins with his arms crossed while Borko struggles to move the cups faster and faster. 
#What Borko does not know is that programmers in the back are recording all his moves and will use 
#a simple program to determine where the ball is. Write that program.

#Input
#The first and only line contains a non-empty string of at most 50 characters, Borko’s moves. 
#Each of the characters is ‘A’, ‘B’ or ‘C’ (without quote marks).

#Output
#Output the index of the cup under which the ball is:
#1 if it is under the left cup, 2 if it is under the middle cup or 3 if it is under the right cup.

def main():
    trik = input()
    cups = [1, 0, 0]
    for i in range(len(trik)):
        if trik[i] == 'A':
            cups[0], cups[1] = cups[1], cups[0]
        elif trik[i] == 'B':
            cups[1], cups[2] = cups[2], cups[1]
        elif trik[i] == 'C':
            cups[2], cups[0] = cups[0], cups[2]
    if cups[0]:
        print(1)
    elif cups[1]:
        print(2)
    elif cups[2]:
        print(3)
    
if __name__ == '__main__':
    main()
    
