
def main():
    trials = input('')
    for i in range(int(trials)):
        recording = input('')
        line = input('')
        sounds = []
        fox = []
        recording = recording.split(' ')
        while not line in 'what does the fox say?':
            line = line.split(' ')
            sounds.append(line[2])
            line = input('')
        
        fox = [x for x in recording if x not in sounds]
        fox = ' '.join(fox)
        print(fox)
        
if __name__ == '__main__':
    main()
