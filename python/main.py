import sys
from reader import Reader

def main():
    filepath = sys.argv[1]
    reader = Reader()
    reader.read(filepath)
    # reader.print()
    reader.print_statistic()


if __name__ == "__main__":
    main()
