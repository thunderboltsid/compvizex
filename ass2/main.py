import sys
import math
import numpy


class Point(object):
    def __init__(self, x: float, y: float, z: float) -> None:
        self.x = x
        self.y = y
        self.z = z

    def __sub__(self, other):
        x = self.x - other.x
        y = self.y - other.y
        z = self.z - other.z
        return Point(x, y, z)


class Dataset(object):
    def __init__(self, filename: str) -> None:
        with open(filename) as f:
            self.points = [Point(*[float(point) for point in line.split(" ")])
                           for line in f.read().split("\n")[1:-1]]

    def __len__(self) -> int:
        return len(self.points)

    @property
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


def main(filename: str) -> None:
    points = Dataset(filename)
    mean = points.mean
    S = numpy.zeros((3, 3))
    for idx, point in enumerate(points.points):
        points.points[idx] = point - mean
        arr = numpy.array([points.points[idx:idx + 1][0].x,
                           points.points[idx:idx + 1][0].y,
                           points.points[idx:idx + 1][0].z])
        S += numpy.dot(arr.T, arr)
    (eigenvalue, eigenvector) = numpy.linalg.eig(S)
    minimal_eigenvector = eigenvector[:, numpy.argmin(eigenvalue)]
    dot_product = numpy.dot(minimal_eigenvector.T,
                            numpy.array([mean.x, mean.y, mean.z]))
    print(dot_product)


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        raise Exception("Usage: main.py filename.txt")
