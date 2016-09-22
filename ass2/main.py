class Point(object):
    def __init__(self, wsv):
        elems = [elem for elem in wsv.split(" ")]
        self.x = elems[0]
        self.y = elems[1]
        self.z = elems[2]


def read_file(filename):
    with open(filename) as f:
        return [Point(line) for line in
                f.read().decode('utf-8').split("\n")[1:-1]]


def main():
    file_content = read_file("dataset.txt")


if __name__ == '__main__':
    main()
