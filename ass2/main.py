import sys


class Vector(object):
    def __init__(self, x: float, y: float, z: float):
        self.x = x
        self.y = y
        self.z = z

    @property
    def magnitude(self) -> float:
        yield

    @property
    def direction(self) -> float:
        yield


class Point(object):
    def __init__(self, x: float, y: float, z: float):
        self.x = x
        self.y = y
        self.z = z

    def vector(self) -> Vector:
        return Vector(self.x, self.y, self.z)


class Dataset(object):
    def __init__(self, filename: str):
        with open(filename) as f:
            self.points = [Point(*[float(point) for point in line.split(" ")])
                           for line in f.read().split("\n")[1:-1]]

    def __len__(self) -> int:
        return len(self.points)

    def mean(self) -> Point:
        mean_x = sum([point.x for point in self.points]) / len(
                [point.x for point in self.points])
        mean_y = sum([point.y for point in self.points]) / len(
                [point.y for point in self.points])
        mean_z = sum([point.z for point in self.points]) / len(
                [point.z for point in self.points])
        return Point(mean_x, mean_y, mean_z)

    def __getitem__(self, item):
        return self.points[item]


def main(filename: str) -> int:
    file_content = Dataset(filename)
    import pdb;
    pdb.set_trace()
    return 0


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        raise Exception("Usage: main.py dataset.txt")
