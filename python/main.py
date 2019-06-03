import sys
from reader import Reader

def main():
    filepath = sys.argv[1]
    reader = Reader()
    reader.read(filepath)
    reader.print()


if __name__ == "__main__":
    main()