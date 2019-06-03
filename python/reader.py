import re

class Reader:
    def __init__(self):
        self.dict = {}

    def read(self, filepath):
        print(filepath)
        file = open(filepath, "r")
        for line in file:
            for word in line.split():
                new_word = self.remove_specials(word)
                if not self.is_empty(new_word):
                    new_word = new_word.lower()
                    print(new_word)
                    self.increment(new_word)


    def increment(self, word):
        if self.dict.__contains__(word):
            self.dict[word] = self.dict[word] + 1
        else:
            self.dict[word] = 1


    def is_empty(self, word):
        return len(word) < 1


    def remove_specials(self, word):
        return re.sub("[^a-zA-Z]", '', word)


    def print(self):
        for key, value in self.dict.items():
            print("Key: {0}, Value: {1}".format(key, value))
        print("{0} different keys".format(len(self.dict)))