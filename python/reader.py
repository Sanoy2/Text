import re

class Reader:
    def __init__(self):
        self.dict = {}

    def read(self, filepath):
        # print(filepath)
        file = open(filepath, "r")
        for line in file:
            for word in line.split():
                new_word = self.remove_specials(word)
                if not self.is_empty(new_word):
                    new_word = new_word.lower()
                    # print(new_word)
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
        number_of_words = 0
        for key, value in self.dict.items():
            number_of_words = number_of_words + value
            print("Key: {0}, Value: {1}".format(key, value))

    
    def number_of_different_words(self):
        return len(self.dict)


    def number_of_words(self):
        number_of_words = 0
        for key, value in self.dict.items():
            number_of_words = number_of_words + value
        return number_of_words


    def print_statistic(self):
        print("{0} different keys".format(self.number_of_different_words()))
        print("{0} words in text".format(self.number_of_words()))